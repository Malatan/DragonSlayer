//
// Created by Zheng on 07/10/2020.
//

#include <gtest/gtest.h>
#include "../Core/Game.h"

using testing::Eq;

class Tests : public  testing::Test{
protected:
    Game* game;
    void SetUp() override{
        game = new Game(true);
        game->testRun();
    }
    void TearDown() override {
        delete game;
    }
};

TEST_F(Tests, StartWindow){
    ASSERT_EQ(game->getWindow()->isOpen(), true);
}

TEST_F(Tests, StartMainMenu){
    ASSERT_EQ(game->getTopState()->getStateEnum(), MAINMENU_STATE);
}

TEST_F(Tests, StartGame){
    auto mainmenu = dynamic_cast<MainMenuState*>(game->getTopState());
    mainmenu->startGame();
    ASSERT_EQ(game->getTopState()->getStateEnum(), GAME_STATE);
}
