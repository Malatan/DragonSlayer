//
// Created by Administrator on 07/10/2020.
//

#include <gtest/gtest.h>
#include "classTT.h"

using testing::Eq;

namespace {
class ClassDeclaration : public  testing::Test{
public:
    classTT obj;
    ClassDeclaration(){
        obj;
    }
};
}
TEST_F(ClassDeclaration, Test1){
    ASSERT_EQ("a"," ");
}
TEST_F(ClassDeclaration, Test2){
    ASSERT_EQ("b"," ");
}