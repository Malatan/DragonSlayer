//
// Created by Zheng on 07/10/2020.
//

#include <gtest/gtest.h>
#include "../Core/Game.h"

using testing::Eq;

class Tests : public  testing::Test{
private:

protected:
    Game* game;

    virtual void SetUp(){
        this->game = new Game();
    }
    virtual void TearDown() {
        delete this->game;
    }
public:

};
TEST_F(Tests, WindowIsOpen){
    ASSERT_EQ(game->getWindow()->isOpen(), true);
}