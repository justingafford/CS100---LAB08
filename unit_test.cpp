#include "base.hpp"
#include "base_factory.hpp"
#include "scifactory.hpp"
#include "doublefactory.hpp"
#include "precisionfactory.hpp"
#include "scirand.hpp"
#include "precisionrand.hpp"
#include "doublerand.hpp"
#include "sciop.hpp"
#include "precisionop.hpp"
#include "doubleop.hpp"
#include "Op.hpp"
#include "Rand.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"
#include "menu.hpp"
#include "command.hpp"
#include <iostream>
#include "gtest/gtest.h"

TEST(CommandsTests, InitialTest)  {
    Op* op = new Op(69);
    InitialCommand* cmd = new InitialCommand(op);
    EXPECT_EQ(cmd->stringify(),"69.000000");
    EXPECT_EQ(cmd->get_root()->evaluate(), 69.000000);
    EXPECT_EQ(cmd->execute(), 69.000000);
}

TEST(CommandsTests, AddTest)  {
    Op* op1 = new Op(4);
    Op* op2 = new Op(6);
    Add* add1 = new Add(op1,op2);
    InitialCommand* cmd = new InitialCommand(op1);
    AddCommand* cmd2 = new AddCommand(cmd,add1);
    EXPECT_EQ(cmd2->stringify(),"4.000000 + 4.000000 + 6.000000");
    EXPECT_EQ(cmd2->get_root()->evaluate(), 14.000000);
    EXPECT_EQ(cmd2->execute(), 14.000000);
    
}

TEST(CommandsTests, SubTests)  {
    Op* op1 = new Op(9);
    Op* op2 = new Op(6);
    Sub* sub1 = new Sub(op1,op2);
    InitialCommand* cmd = new InitialCommand(op1);
    SubCommand* cmd2 = new SubCommand(cmd,sub1);
    EXPECT_EQ(cmd2->stringify(),"9.000000 - 9.000000 - 6.000000");
    EXPECT_EQ(cmd2->get_root()->evaluate(), 6.000000);
    EXPECT_EQ(cmd2->execute(), 6.000000);
}

TEST(CommandsTests, MultTest)  {
    Op* op1 = new Op(4);
    Op* op2 = new Op(2);
    Mult* mult1 = new Mult(op1,op2);
    InitialCommand* cmd = new InitialCommand(op1);
    MultCommand* cmd2 = new MultCommand(cmd,mult1);
    EXPECT_EQ(cmd2->stringify(),"4.000000 * 4.000000 * 2.000000");
    EXPECT_EQ(cmd2->get_root()->evaluate(), 32.000000);
    EXPECT_EQ(cmd2->execute(), 32.000000);
}

TEST(CommandsTests, DivTest)  {
    Op* op1 = new Op(6);
    Op* op2 = new Op(2);
    Div* div1 = new Div(op1,op2);
    InitialCommand* cmd = new InitialCommand(op1);
    DivCommand* cmd2 = new DivCommand(cmd,div1);
    EXPECT_EQ(cmd2->stringify(),"6.000000 / 6.000000 / 2.000000");
    EXPECT_EQ(cmd2->get_root()->evaluate(), 2.000000);
    EXPECT_EQ(cmd2->execute(), 2.000000);
}

TEST(CommandsTests, PowTest)  {
    Op* op1 = new Op(2);
    Op* op2 = new Op(2);
    Pow* pow1 = new Pow(op1,op2);
    InitialCommand* cmd = new InitialCommand(op1);
    PowCommand* cmd2 = new PowCommand(cmd,pow1);
    EXPECT_EQ(cmd2->stringify(),"2.000000 ** 2.000000 ** 2.000000");
    EXPECT_EQ(cmd2->get_root()->evaluate(), 16.000000);
    EXPECT_EQ(cmd2->execute(), 16.000000);
}

TEST(MenuTests, AddGetCommandTest)  {
    Menu* menu = new Menu;
    Op* op = new Op(4);
    InitialCommand* cmd = new InitialCommand(op);
    EXPECT_EQ(menu->initialized(),False);
    menu->add_command(cmd);
    EXPECT_EQ(menu->initialized(),True;
    EXPECT_EQ(menu->get_command()->stringify(),"4.000000");
    EXPECT_EQ(menu->get_command()->execute(), 4.000000);
    EXPECT_EQ(menu->execute(),"4.000000");
    EXPECT_EQ(menu->stringify(),"4.000000");
}

TEST(MenuTests, UndoRedoTest)  {
    Menu* menu = new Menu;
    Op* op1 = new Op(4);
    Op* op2 = new Op(6);
    Add* add1 = new Add(op1,op2);
    InitialCommand* cmd = new InitialCommand(op1);
    AddCommand* cmd2 = new AddCommand(cmd,add1);
    EXPECT_EQ(menu->initialized(),False);
    menu->add_command(cmd);
    EXPECT_EQ(menu->initialized(),True);
    menu->add_command(cmd2);
    EXPECT_EQ(menu->initialized(),True);
    EXPECT_EQ(menu->get_command()->execute(),14.000000);
    EXPECT_EQ(menu->get_command()->stringify(),"4.000000 + 4.000000 + 6.000000");
    EXPECT_EQ(menu->execute(),"14.000000");
    EXPECT_EQ(menu->stringify(),"4.000000 + 4.000000 + 6.000000");
    
    menu->undo();
    EXPECT_EQ(menu->initialized(),True);
    EXPECT_EQ(menu->get_command()->stringify(),"4.000000");
    EXPECT_EQ(menu->get_command()->execute(),4.000000);
    EXPECT_EQ(menu->execute(),"4.000000");
    EXPECT_EQ(menu->stringify(),"4.000000");
    menu->redo();
    EXPECT_EQ(menu->initialized(),True);
    EXPECT_EQ(menu->get_command()->execute(),14.000000);
    EXPECT_EQ(menu->get_command()->stringify(),"4.000000 + 4.000000 + 6.000000");
    EXPECT_EQ(menu->execute(),"14.000000");
    cout << "Outputting execute: " << menu -> execute() << endl;
    EXPECT_EQ(menu->stringify(),"4.000000 + 4.000000 + 6.000000");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
