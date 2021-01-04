//
// Created by Administrator on 23/12/2020.
//

#include <gtest/gtest.h>
#include "../Core/Game.h"

using testing::Eq;

class PlayerTests : public  testing::Test{
protected:
    Game* game;
    Player* player;
    GameState* gState;

    void SetUp() override{
        game = new Game(true);
        auto mainmenu = dynamic_cast<MainMenuState*>(game->getTopState());
        mainmenu->startGame();
        gState = dynamic_cast<GameState*>(game->getTopState());
        player = gState->getPlayer().get();
        game->testRun();
    }
    void TearDown() override {
        delete game;
    }
};

TEST_F(PlayerTests, HitBoxBoundsCheck){
    ASSERT_GT(player->getHitboxComponent()->getGlobalBounds().width, 30.f);
    ASSERT_GT(player->getHitboxComponent()->getGlobalBounds().height, 60.f);
    ASSERT_TRUE(player->getGlobalBounds().intersects(player->getHitboxComponent()->getGlobalBounds()));
}

TEST_F(PlayerTests, CollisionBoxCheck){
    ASSERT_GT(player->getCollisionBoxComponent()->getCollisionEllipse().getGlobalBounds().width, 0.f);
    ASSERT_GT(player->getCollisionBoxComponent()->getCollisionEllipse().getGlobalBounds().height, 0.f);
    ASSERT_TRUE(player->getHitboxComponent()->getGlobalBounds().intersects(
            player->getCollisionBoxComponent()->getCollisionEllipse().getGlobalBounds()));
}

TEST_F(PlayerTests, MovementCheck){
    //up check
    sf::Vector2f previous = player->getCenter();
    float move_time = 0.2f;
    while(move_time > 0.f){
        player->move(game->getDt(), 0.f, -1.f);
        move_time -= game->getDt();
        game->testRun(true);
    }
    ASSERT_LT(player->getCenter().y, previous.y);

    //down check
    previous = player->getCenter();
    move_time = 0.2f;
    while(move_time > 0.f){
        player->move(game->getDt(), 0.f, 1.f);
        move_time -= game->getDt();
        game->testRun();
    }
    ASSERT_GT(player->getCenter().y, previous.y);

    //left check
    previous = player->getCenter();
    move_time = 0.2f;
    while(move_time > 0.f){
        player->move(game->getDt(), -1.f, 0.f);
        move_time -= game->getDt();
        game->testRun();
    }
    ASSERT_LT(player->getCenter().x, previous.x);

    //right check
    previous = player->getCenter();
    move_time = 0.2f;
    while(move_time > 0.f){
        player->move(game->getDt(), 1.f, 0.f);
        move_time -= game->getDt();
        game->testRun();
    }
    ASSERT_GT(player->getCenter().x, previous.x);
}

TEST_F(PlayerTests, MoveToCheck){
    float test_time = 3.f;
    sf::Vector2f target_point = {player->getPosition().x + 80.f, player->getPosition().y + 50.f};
    while(test_time > 0.f){
        test_time -= game->getDt();
        player->clearTargetPoints();
        player->addTargetPoint(target_point);
        game->testRun();
        if(player->getMovementComponent()->getState(IDLE))
            break;
    }
    ASSERT_TRUE(player->getHitboxComponent()->getCenterRect().contains(target_point));
}

TEST_F(PlayerTests, MaxSpeedCheck){
    float test_time = 3.f;
    while(test_time > 0.f){
        test_time -= game->getDt();
        float before_speed = player->getMovementComponent()->getVelocity().x;
        player->move(game->getDt(), 1.f, 0.f);
        game->testRun();
        float after_speed = player->getMovementComponent()->getVelocity().x;
        if(after_speed == before_speed){
            break;
        }
    }
    ASSERT_LE(player->getMovementComponent()->getVelocity().x, player->getMovementComponent()->getMaxVelocity());
}

TEST_F(PlayerTests, WorldBoundsCollisionCheck){
    player->setPosition(1.f, 1.f);
    sf::Vector2f origin = {0.f, 0.f};
    float test_time = 1.5f;
    while(test_time > 0.f){
        test_time -= game->getDt();
        player->move(game->getDt(), -1.f, 0.f);
        game->testRun();
    }
    test_time = 1.5f;
    while(test_time > 0.f){
        test_time -= game->getDt();
        player->move(game->getDt(), 0.f, -1.f);
        game->testRun();
    }
    player->stopVelocity();
    ASSERT_GE(player->getCollisionBoxComponent()->getPosition().x, origin.x);
    ASSERT_GE(player->getCollisionBoxComponent()->getPosition().y, origin.y);
}

TEST_F(PlayerTests, NotTraversableTileCollisionCheck){
    player->setPosition(700.f, 1.f);
    sf::Vector2f test_tile = {800.f, 0.f};
    float test_time = 1.5f;
    while(test_time > 0.f){
        test_time -= game->getDt();
        player->move(game->getDt(), 1.f, 0.f);
        game->testRun();
    }
    player->stopVelocity();
    game->testRun();
    ASSERT_LT(player->getCollisionBoxComponent()->getPosition().x, test_tile.x);
}

TEST_F(PlayerTests, NpcInteractCheck){
    player->addTargetPoint(gState->getNpc(0)->getHitboxComponent()->getCenter());
    float test_time = 3.0f;
    while(test_time > 0.f){
        test_time -= game->getDt();
        game->testRun();
        if(player->getMovementComponent()->getState(IDLE))
            break;
    }
    ASSERT_TRUE(gState->getInteractNpc() != NO_NPC);
}

TEST_F(PlayerTests, EnemyInteractCheck){
    gState->spawnEnemy(player->getPosition().x + 100.f, player->getPosition().y, SKELETON);
    player->addTargetPoint(gState->getEnemy(0)->getHitboxComponent()->getCenter());
    float test_time = 2.5f;
    while(test_time > 0.f){
        test_time -= game->getDt();
        game->testRun(true);
        if(game->getTopState()->getStateEnum() == BATTLE_STATE){
            break;
        }
    }
    ASSERT_TRUE(game->getTopState()->getStateEnum() == BATTLE_STATE);
}