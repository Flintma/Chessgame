/////////////////////////////////////////////////////////
//                  CHESS GAME!                        //
//                                                     //
//                                                     //
//       AERSP 460 ADVANCED COMPUTER PROGRAMMING       //
//                      PSU                            //
//                       Q                             //
//                                                     //
/////////////////////////////////////////////////////////
/*Notes:
1 : Only Human player VS Human player is developed;
2 : All the rules are coded in the Rule.h instead of coded in different chesspiece object since there are rules can be used for all the objects and some rules are depend on the player on different side;
3 : Different sides are presented by player 1 or player 2.
*/

#include<iostream>
#include <cstdlib>
#include <Windows.h>

#include"chessgame.h"
#include"Pawn.h"
#include"Knight.h"
#include"Bishop.h"
#include"Rook.h"
#include"Queen.h"
#include"King.h"
#include"block.h"
#include"Display.h"
#include"Rule.h"





int main() {


	//Make pawns for player 1 and 2
	pawn p11(1);
	pawn p12(1);
	pawn p13(1);
	pawn p14(1);
	pawn p15(1);
	pawn p16(1);
	pawn p17(1);
	pawn p18(1);
	pawn p21(2);
	pawn p22(2);
	pawn p23(2);
	pawn p24(2);
	pawn p25(2);
	pawn p26(2);
	pawn p27(2);
	pawn p28(2);

	//Make knights for player 1 and 2
	knight kn11(1);
	knight kn12(1);
	knight kn21(2);
	knight kn22(2);

	//Make bishops for player 1 and 2
	bishop b11(1);
	bishop b12(1);
	bishop b21(2);
	bishop b22(2);

	//Make rooks for player 1 and 2
	rook r11(1);
	rook r12(1);
	rook r21(2);
	rook r22(2);

	//Make queens for player 1 and 2
	queen q1(1);
	queen q2(2);

	//Make kings for player 1 and 2
	king k1(1);
	king k2(2);

	//creat array of blocks in the board
	Block block[8][8];

	//Initializing game
	block[0][0].piece = &r11;
	block[0][1].piece = &kn11;
	block[0][2].piece = &b11;
	block[0][3].piece = &q1;
	block[0][4].piece = &k1;
	block[0][5].piece = &b12;
	block[0][6].piece = &kn12;
	block[0][7].piece = &r12;
	block[1][0].piece = &p11;
	block[1][1].piece = &p12;
	block[1][2].piece = &p13;
	block[1][3].piece = &p14;
	block[1][4].piece = &p15;
	block[1][5].piece = &p16;
	block[1][6].piece = &p17;
	block[1][7].piece = &p18;
	block[7][0].piece = &r21;
	block[7][1].piece = &kn21;
	block[7][2].piece = &b21;
	block[7][3].piece = &q2;
	block[7][4].piece = &k2;
	block[7][5].piece = &b22;
	block[7][6].piece = &kn22;
	block[7][7].piece = &r22;
	block[6][0].piece = &p21;
	block[6][1].piece = &p22;
	block[6][2].piece = &p23;
	block[6][3].piece = &p24;
	block[6][4].piece = &p25;
	block[6][5].piece = &p26;
	block[6][6].piece = &p27;
	block[6][7].piece = &p28;



	//Record pieces for each player
	static int pieceforp1 = 16;
	static int pieceforp2 = 16;

	////Preset Player
	int p=2 ;

	
	//Store Move
	string move;
	
	
	
	///////////////////////////////////////////GAME LOOP//////////////////////////////////////////////////
	while (true) {



		//switch player
		if (p == 1)
			p = 2;
		else
			p = 1;
	
	
		//refresh display
		system("cls");

		//Display chessboard
		Display(block);

		//Enter move
		cout << "Player[" << p <<"]  "<< "Your move is:[ie:b2b4(Meaning to move the chesspiece from b2 to b4)] \n" << endl;
		getline(cin, move);
	

	//Judge whether the movement is legal or not
	while (Rule(move, block, p,  pieceforp1,  pieceforp2) == false) {

		cout << "Your move is illegal, please re-enter: " << endl;
		getline(cin, move);

	}
	if (pieceforp1 == 0) {
		cout << "Player 2 win!" << endl;
		break;
	}
	else if (pieceforp2 == 0) {
		cout << "Player 1 win!" << endl;
		break;
	}


	}
	return 0;

}
