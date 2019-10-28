#include <gtest/gtest.h> 	  			 	 
#include "SixMensMorrisBoard.h"

TEST(SixMensMorrisBoardTest, DefaultBoardTest){
    // Needs to test that default board is correct
    CSixMensMorrisBoard board;
    EXPECT_EQ(std::string(board), 
">RU:6 RC:0  WU:6 WC:0\n"
"o---------o---------o      0---1---2\n"
"|         |         |      | 3-4-5 |\n"
"|         |         |      6-7   8-9\n"
"|    o----o----o    |      | A-B-C |\n"
"|    |         |    |      D---E---F\n"
"|    |         |    |        LEGEND\n"
"o----o         o----o\n"
"|    |         |    |\n"
"|    |         |    |\n"
"|    o----o----o    |\n"
"|         |         |\n"
"|         |         |\n"
"o---------o---------o\n");
}

TEST(SixMensMorrisBoardTest, SetBoardTest){
    // Needs to test that setting board is correct
}

TEST(SixMensMorrisBoardTest, ResetBoardTest){
    // Needs to test that resetting to default board is correct
}

TEST(SixMensMorrisBoardTest, PlacementTest){
    // Needs to test that normal placement is correct
}

TEST(SixMensMorrisBoardTest, PlacementMillTest){
    // Needs to test that placement creating a mill is correct with removal
}

TEST(SixMensMorrisBoardTest, MoveTest){
    // Needs to test that movement is correct
}

TEST(SixMensMorrisBoardTest, MoveMillTest){
    // Needs to test that movement creating a mill is correct with removal
}
                                       
TEST(SixMensMorrisBoardTest, TwoPieceGameOverTest){
    // Needs to test that game over is correct when only two pieces left
}

TEST(SixMensMorrisBoardTest, NoMoveGameOverTest){
    // Needs to test that game over is correct when no movement allowed
}

TEST(SixMensMorrisBoardTest, BadParametersTest){
    // Needs to test that correct return upon bad parameters
}

