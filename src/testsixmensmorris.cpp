#include <gtest/gtest.h> 	  			 	 
#include "SixMensMorrisBoard.h"

//USE MACROS 

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
    EXPECT_EQ(board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_R);
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R), 6);
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W), 6);
    EXPECT_EQ(board.PlayerAtPosition(0), SIX_MENS_MORRIS_EMPTY);
    EXPECT_EQ(board.PlayerAtPosition(12), SIX_MENS_MORRIS_EMPTY);
    EXPECT_FALSE(board.CanMove(SIX_MENS_MORRIS_PLAYER_R, 3));
    EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 3, 4));
    EXPECT_FALSE(board.CanMove(SIX_MENS_MORRIS_PLAYER_W, 8));
    EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 8, 12));
    EXPECT_FALSE(board.GameOver());
}

TEST(SixMensMorrisBoardTest, SetBoardTest){
    // Needs to test that setting board is correct
    const char Positions[16] = {  SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W
    };

    const char Previous[16] = {   SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W

    };
    const int unplaced[SIX_MENS_MORRIS_PLAYERS] = {2, 2};

    CSixMensMorrisBoard board(SIX_MENS_MORRIS_PLAYER_W, unplaced, Positions, Previous);

    EXPECT_EQ(board.PlayerAtPosition(1), SIX_MENS_MORRIS_PLAYER_R);
    EXPECT_EQ(board.PlayerAtPosition(2), SIX_MENS_MORRIS_PLAYER_R);
    EXPECT_EQ(board.PlayerAtPosition(5), SIX_MENS_MORRIS_PLAYER_R);
    EXPECT_EQ(board.PlayerAtPosition(6), SIX_MENS_MORRIS_PLAYER_R);
    EXPECT_EQ(board.PlayerAtPosition(13), SIX_MENS_MORRIS_EMPTY);
    EXPECT_EQ(board.PlayerAtPosition(15), SIX_MENS_MORRIS_PLAYER_W);
    EXPECT_EQ(board.PlayerAtPosition(7), SIX_MENS_MORRIS_PLAYER_W);
    EXPECT_EQ(board.PlayerAtPosition(12), SIX_MENS_MORRIS_PLAYER_W);
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R), 2);
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W), 2);
    EXPECT_EQ(board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_W);
    EXPECT_FALSE(board.GameOver());

}

TEST(SixMensMorrisBoardTest, ResetBoardTest){
    // Needs to test that resetting to default board is correct // check unplacedpieces
    CSixMensMorrisBoard board;

    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 1));
    EXPECT_EQ(board.PlayerAtPosition(1), SIX_MENS_MORRIS_PLAYER_R);
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R), 5);
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W), 6);

    board.ResetBoard();
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


    EXPECT_EQ(board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_R);
    EXPECT_EQ(board.PlayerAtPosition(1), SIX_MENS_MORRIS_EMPTY);
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W), 6);
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R), 6);

}

TEST(SixMensMorrisBoardTest, PlacementTest){
    // Needs to test that normal placement is correct /
    // has been adjusted for the change of ability to remove once a mill has been created after placing
    CSixMensMorrisBoard board;
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 0)); 
    EXPECT_EQ(board.PlayerAtPosition(0), SIX_MENS_MORRIS_PLAYER_R); //position 0 should now be R
    EXPECT_FALSE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 0)); //false because 0 is not an empty position
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 1));
    EXPECT_EQ(board.PlayerAtPosition(1), SIX_MENS_MORRIS_PLAYER_W); 
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 6));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 10));
    EXPECT_FALSE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 14)); //false because it is not w/s turn
    EXPECT_FALSE(board.CanRemove(SIX_MENS_MORRIS_PLAYER_W)); //mill has not been formed, cannot remove
    EXPECT_FALSE(board.CanRemove(SIX_MENS_MORRIS_PLAYER_R)); //mill has not been formed, cannot remove
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 13)); //MILL HAS BEEN CREATED, TURN SHOULD STAY R ***************************

//    std::cout<<(std::string(board))<<std::endl;

//    std::cout<<(board.PlayerTurn())<<std::endl; // SHOULD PRINT R

    EXPECT_TRUE(board.CanRemove(SIX_MENS_MORRIS_PLAYER_R)); 
    EXPECT_TRUE(board.Remove(SIX_MENS_MORRIS_PLAYER_R, 1)); 

    EXPECT_EQ(board.PlayerAtPosition(1), SIX_MENS_MORRIS_EMPTY); // position 1 should now be empty

    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 2));

    EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 6, 7)); //not able to move during plaement phase
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 9));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 15));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 11));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 14));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 5));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 3));
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R), 0);
    EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W), 0);
    EXPECT_FALSE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 1)); //no more unplaced pieces, cannot place
}

TEST(SixMensMorrisBoardTest, PlacementMillTest){
    // Needs to test that placement creating a mill is correct with removal

    //NEEDS TO BE ADJUSTED FOR FIXED REMOVE FUNCTION

    CSixMensMorrisBoard board;
    board.Place(SIX_MENS_MORRIS_PLAYER_R, 0);
    board.Place(SIX_MENS_MORRIS_PLAYER_W, 1);
    board.Place(SIX_MENS_MORRIS_PLAYER_R, 6);
    board.Place(SIX_MENS_MORRIS_PLAYER_W, 2);
    board.Place(SIX_MENS_MORRIS_PLAYER_R, 13); //MILL CREATED, MUST REMOVE PIECE FROM W TO CONTINUE PLACEMENT

    EXPECT_EQ(board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_R); //IT IS R'S TURN BECAUSE A MILL HAS FORMED

    EXPECT_TRUE(board.CanRemove(SIX_MENS_MORRIS_PLAYER_R)); //can remove bc R has created a mill
    EXPECT_TRUE(board.Remove(SIX_MENS_MORRIS_PLAYER_R, 1));
    EXPECT_EQ(board.PlayerAtPosition(1), SIX_MENS_MORRIS_EMPTY); //should be empty after we remove W from 1
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 9)); 


//    std::cout<<(std::string(board))<<std::endl;
    EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 6, 7)); //cannot move during placement
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 10));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 3));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 4));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 5));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_R, 12));
    EXPECT_TRUE(board.Place(SIX_MENS_MORRIS_PLAYER_W, 15));
    
    EXPECT_TRUE(board.CanRemove(SIX_MENS_MORRIS_PLAYER_W)); //true because mill formed by W
    EXPECT_FALSE(board.Remove(SIX_MENS_MORRIS_PLAYER_W, 15)); //15 is not R, it's W
    EXPECT_TRUE(board.Remove(SIX_MENS_MORRIS_PLAYER_W, 13));
    EXPECT_FALSE(board.CanRemove(SIX_MENS_MORRIS_PLAYER_W)); //false because the mill has now been broken.

}

TEST(SixMensMorrisBoardTest, MoveTest){
    // Needs to test that movement is correct
    const char Positions[16] = {  SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W
    };

    const char Previous[16] = {   SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W

    };
    const int unplaced[SIX_MENS_MORRIS_PLAYERS] = {0, 0};

    CSixMensMorrisBoard board(SIX_MENS_MORRIS_PLAYER_R, unplaced, Positions, Previous);

//    std::cout<<(std::string(board))<<std::endl;


    EXPECT_FALSE(board.CanMove(SIX_MENS_MORRIS_PLAYER_W, 8));
    EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_W, 12, 8)); //false bc not W's turn
    EXPECT_TRUE(board.CanMove(SIX_MENS_MORRIS_PLAYER_R, 1));
    EXPECT_TRUE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 1, 0));
    EXPECT_EQ(board.PlayerAtPosition(0), SIX_MENS_MORRIS_PLAYER_R);

//    std::cout<<(std::string(board))<<std::endl;

    EXPECT_TRUE(board.CanMove(SIX_MENS_MORRIS_PLAYER_W, 12));
    EXPECT_TRUE(board.Move(SIX_MENS_MORRIS_PLAYER_W, 12, 8));
    EXPECT_EQ(board.PlayerAtPosition(8), SIX_MENS_MORRIS_PLAYER_W);
    EXPECT_FALSE(board.CanMove(SIX_MENS_MORRIS_PLAYER_R, 13));
    EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 14, 13)); //false bc 13 is not empty
    EXPECT_FALSE(board.CanMove(SIX_MENS_MORRIS_PLAYER_W, 12));
    EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 11, 12)); //false bc 11 is player R
    EXPECT_FALSE(board.CanMove(SIX_MENS_MORRIS_PLAYER_W, 3));
    EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 6, 3)); //false bc 3 is not adjacent to 6

}

TEST(SixMensMorrisBoardTest, MoveMillTest){
    // Needs to test that movement creating a mill is correct with removal
    const char Positions[16] = {  SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W
    };

    const char Previous[16] = {   SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W

    };
    const int unplaced[SIX_MENS_MORRIS_PLAYERS] = {0, 0};

    CSixMensMorrisBoard board(SIX_MENS_MORRIS_PLAYER_R, unplaced, Positions, Previous);

    EXPECT_TRUE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 6, 0)); //MILL CREATED, BUT TURN DIDN'T CHANGE

    EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_W, 4, 3)); //SHOULD NOT BE ABLE TO MOVE- NOT W'S TURN

    EXPECT_TRUE(board.Remove(SIX_MENS_MORRIS_PLAYER_R, 7));
    EXPECT_TRUE(board.Move(SIX_MENS_MORRIS_PLAYER_W, 4, 3));
    EXPECT_TRUE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 0, 6)); //PREVIOUS MILL UNFORMED
    EXPECT_TRUE(board.Move(SIX_MENS_MORRIS_PLAYER_W, 3, 7));
    EXPECT_TRUE(board.Move(SIX_MENS_MORRIS_PLAYER_R, 6, 0)); //SAME MILL RECREATED
    
    EXPECT_TRUE(board.Remove(SIX_MENS_MORRIS_PLAYER_R, 7));

//    std::cout<<(std::string(board))<<std::endl;

}
                                       
TEST(SixMensMorrisBoardTest, TwoPieceGameOverTest){
    // Needs to test that game over is correct when only two pieces left
    const char Positions[16] = {  SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY
    };

    const char Previous[16] = {  SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY
    };
        const int unplaced[SIX_MENS_MORRIS_PLAYERS] = {0, 0};
            CSixMensMorrisBoard board(SIX_MENS_MORRIS_PLAYER_R, unplaced, Positions, Previous);
            board.Remove(SIX_MENS_MORRIS_PLAYER_R,6);

    EXPECT_TRUE(board.GameOver());


    const char PositionsA[16] = {  SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W
    };

    const char PreviousA[16] = {   SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_W,
                        SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W

    };
    const int unplacedA[SIX_MENS_MORRIS_PLAYERS] = {0, 0};

    CSixMensMorrisBoard boardA(SIX_MENS_MORRIS_PLAYER_R, unplacedA, PositionsA, PreviousA);

    boardA.Remove(SIX_MENS_MORRIS_PLAYER_R,7);
    EXPECT_FALSE(boardA.GameOver());


    CSixMensMorrisBoard boardB;
    EXPECT_FALSE(boardB.GameOver());

}

TEST(SixMensMorrisBoardTest, NoMoveGameOverTest){
    // Needs to test that game over is correct when no movement allowed
      const char Positions[16] = {  SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,
        SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,
        SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_W,
        SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY
    };
      const char Previous[16] = {  SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,
        SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,
        SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_W,
        SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY
    };

    const int unplaced[SIX_MENS_MORRIS_PLAYERS] = {0, 0};

            CSixMensMorrisBoard board(SIX_MENS_MORRIS_PLAYER_R, unplaced, Positions, Previous);
             std::cout<<(std::string(board))<<std::endl;
                 EXPECT_FALSE(board.GameOver());

             board.Move(SIX_MENS_MORRIS_PLAYER_R, 0, 1);

            std::cout<<(std::string(board))<<std::endl;

            EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_W, 4, 5));
              EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_W, 5, 4));
                EXPECT_FALSE(board.Move(SIX_MENS_MORRIS_PLAYER_W, 12, 8));
           


    EXPECT_TRUE(board.GameOver());

   
}

TEST(SixMensMorrisBoardTest, BadParametersTest){
    // Needs to test that correct return upon bad parameters
      const char Positions[16] = {  SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,
        SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,
        SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_W,
        SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY
    };
      const char Previous[16] = {  SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,
        SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,
        SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_PLAYER_W,SIX_MENS_MORRIS_PLAYER_W,
        SIX_MENS_MORRIS_EMPTY,SIX_MENS_MORRIS_PLAYER_R,SIX_MENS_MORRIS_EMPTY
    };

    const int unplaced[SIX_MENS_MORRIS_PLAYERS] = {0, 0};

            CSixMensMorrisBoard board(SIX_MENS_MORRIS_PLAYER_R, unplaced, Positions, Previous);
             EXPECT_FALSE(board.Remove(SIX_MENS_MORRIS_PLAYER_R,17));
             EXPECT_EQ(board.PlayerAtPosition(20),'\0');
            EXPECT_EQ(board.UnplacedPieces('Q'),-1);



}

