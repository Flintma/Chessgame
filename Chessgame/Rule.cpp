using namespace std;
#include<iostream>
#include<string>
#include"block.h"
#include <sstream>
#include<cstring>


bool Rule(string move, Block block[8][8], int p, static int pieceforp1, static int pieceforp2) {
	

    //Interperate movement
	stringstream tempstr;
	int alpha1;
	int num1;
	tempstr << move[1];
	tempstr >> num1;
	num1 = num1 - 1;
	tempstr.clear();
	int alpha2;
	int num2;
	tempstr << move[3];
	tempstr >> num2;
	num2 = num2 - 1;
	tempstr.clear();
	if (move[0] == 'a' || move[0] == 'A')
		alpha1 = 0;
	else if (move[0] == 'b' || move[0] == 'B')
		alpha1 = 1;
	else if (move[0] == 'c' || move[0] == 'C')
		alpha1 = 2;
	else if (move[0] == 'd' || move[0] == 'D')
		alpha1 = 3;
	else if (move[0] == 'e' || move[0] == 'E')
		alpha1 = 4;
	else if (move[0] == 'f' || move[0] == 'F')
		alpha1 = 5;
	else if (move[0] == 'g' || move[0] == 'G')
		alpha1 = 6;
	else if (move[0] == 'h' || move[0] == 'H')
		alpha1 = 7;
	else
		cout << "Wrong input format" << endl;

	if (move[2] == 'a' || move[0] == 'A')
		alpha2 = 0;
	else if (move[2] == 'b' || move[0] == 'B')
		alpha2 = 1;
	else if (move[2] == 'c' || move[0] == 'C')
		alpha2 = 2;
	else if (move[2] == 'd' || move[0] == 'D')
		alpha2 = 3;
	else if (move[2] == 'e' || move[0] == 'E')
		alpha2 = 4;
	else if (move[2] == 'f' || move[0] == 'F')
		alpha2 = 5;
	else if (move[2] == 'g' || move[0] == 'G')
		alpha2 = 6;
	else if (move[2] == 'h' || move[2] == 'H')
		alpha2 = 7;
	else
		cout << "Wrong input format" << endl;

	//Check input length
	if (move.length() != 4) {
		cout << "Need to input of length of 4 as the example(b2b4)" << endl;
		return false;
	}
	//Check input format
	if (move[0] != 'a' && move[0] != 'b' && move[0] != 'c' && move[0] != 'd' &&
		move[0] != 'e' && move[0] != 'f' && move[0] != 'g' && move[0] != 'h' && move[0] != 'A' && move[0] != 'B' && move[0] != 'C' && move[0] != 'D' &&
		move[0] != 'E' && move[0] != 'F' && move[0] != 'G' && move[0] != 'H') {
		cout << "first and third input need to be a character from a to h" << endl;
		return false;
	}
	if (move[2] != 'a' && move[2] != 'b' && move[2] != 'c' && move[2] != 'd' &&
		move[2] != 'e' && move[2] != 'f' && move[2] != 'g' && move[2] != 'h' && move[2] != 'A' && move[2] != 'B' && move[2] != 'C' && move[2] != 'D' &&
		move[2] != 'E' && move[2] != 'F' && move[2] != 'G' && move[2] != 'H') {
		cout << "first and third input need to be a character from a to h" << endl;
		return false;
	}
		if (move[1] != '0' && move[1] != '1' && move[1] != '2' && move[1] != '3' && move[1] != '4'
				&& move[1] != '5' && move[1] != '6' && move[1] != '7') {
			cout << "second and forth input need to be a number from 1 to 7" << endl;

				return false;

			}
		if (move[3] != '0' && move[3] != '1' && move[3] != '2' && move[3] != '3' && move[3] != '4'
			&& move[3] != '5' && move[3] != '6' && move[3] != '7') {
			cout << "second and forth input need to be a number from 1 to 7" << endl;

			return false;
		}

	


	//Compute row and column difference
	int Row_D = num1 - num2;
	int Clm_D = alpha1 - alpha2;

	if (block[num1][alpha1].piece == nullptr) {

		cout << "No chesspiece at the location\n" << endl;
		return false;

	}

	//Make sure the player is moving their own chess piece
	if (block[num1][alpha1].piece != nullptr && p != block[num1][alpha1].piece->player) {

		cout << "That's not your chesspiece.\n" << endl;

		return false; //Illegal move returen for the bool function...

	}

	// Make sure you don't have a chesspiece there
	if (block[num2][alpha2].piece != nullptr && p == block[num2][alpha2].piece->player) {

		cout << "You already have a chesspiece there.\n" << endl;

		return false;
	}



	//Rule for pawn(Player 1)
	//Define that first move can move 2 in row_D but not after
	if (block[num1][alpha1].piece->name.compare("Pawn") == 0 && p == 1) {


		if (num1 != 1 && Row_D <= -2) {

			cout << "Pawns can only move 2 spaces in the first move\n." << endl;
			return false;

		}



		//can't move back
		else if (Row_D >= 0) {

			cout << "Pawns can't move backward." << endl << endl;
			return false;

		}

		//can only move one column at a time
		else if (abs(Clm_D) > 1) {

			cout << "Illegal move.\n" << endl;
			return false;

		}

		//Make sure there is enemy chesspiece there to move in diagonal
		else if (abs(Clm_D) == 1 && Row_D == -1 && block[num2][alpha2].piece == nullptr) {

			cout << "Can't move in diagonal without an enemy chesspiece there.\n" << endl;
			return false;

		}

		//Make sure you can't move straight if there is an enemy chesspiece
		else if (Row_D == -1 && Clm_D == 0 && block[num2][alpha2].piece != nullptr && block[num2][alpha2].piece->player == 2) {

			cout << "Can't move straight with an enemy chesspiece there!\n" << endl;
			return false;

		}

		//Taking enemy chesspiece
		else if (Row_D == -1 && abs(Clm_D) == 1 && block[num2][alpha2].piece->player == 2) {

			cout << "Enemy's chesspiece[" << block[num2][alpha2].piece->name << "] is taken!" << endl;

			block[num2][alpha2].piece = block[num1][alpha1].piece;
			block[num1][alpha1].piece = nullptr;
			pieceforp2 = pieceforp2 - 1;


			return true;

		}

		//updating movement
		else {

			cout << "Legal Move!" << endl << endl;
			block[num2][alpha2].piece = block[num1][alpha1].piece;
			block[num1][alpha1].piece = nullptr;



			return true;

		}
	}


	//Pawn rule for player 2 same logic
	else if (block[num1][alpha1].piece->name.compare("Pawn") == 0 && p == 2) {

		if (num1 != 6 && Row_D >= 2) {

			cout << "Pawns can only move 2 spaces in the first move\n." << endl;
			return false;

		}



	

	//Can't move back
	else if (Row_D <= 0) {

		cout << "Pawns can't move backward." << endl << endl;
		return false;
		}

	//can only move one column at a time
	else if (abs(Clm_D) > 1) {

		cout << "Illegal move." << endl << endl;
		return false;

	}

	//Make sure there is enemy chesspiece there to move in diagonal

	else if (abs(Clm_D) == 1 && Row_D == 1 && block[num2][alpha2].piece == nullptr) {

		cout << "Can't move in diagonal without an enemy chesspiece there.\n" << endl;
		return false;

	}

	//Make sure you can't move straight if there is an enemy chesspiece
	else if (Row_D == 1 && Clm_D == 0 && block[num2][alpha2].piece != nullptr && block[num2][alpha2].piece->player == 1) {

		cout << "Can't move straight with an enemy chesspiece there!\n" << endl;
		return false;

	}

	//Taking enemy chesspiece
	else if (Row_D == 1 && abs(Clm_D) == 1 && block[num2][alpha2].piece->player == 1) {

		cout <<"Enemy's chesspiece["<< block[num2][alpha2].piece->name << "] is taken!" << endl << endl;

		block[num2][alpha2].piece = block[num1][alpha1].piece;	
		block[num1][alpha1].piece = nullptr;
		pieceforp1 = pieceforp1 - 1;

		return true;

	}

	//updating movement
	else {

		cout << "Move successful!" << endl << endl;
		block[num2][alpha2].piece = block[num1][alpha1].piece;
		block[num1][alpha1].piece = nullptr;



		return true;

	}
}

	else if (block[num1][alpha1].piece->name.compare("King") == 0) {

		//if they try to move more than one space at a time...
		if (abs(Row_D) > 1 || abs(Clm_D) > 1) {

			cout << "King can only move one space per each round!\n" << endl;
			return false;

		}


		if (block[num2][alpha2].piece != nullptr && block[num2][alpha2].piece->player != p) {

			cout << "Enemy's chesspiece[" << block[num2][alpha2].piece->name << "] is taken!" << endl << endl;

			block[num2][alpha2].piece = block[num1][alpha1].piece;
			block[num1][alpha1].piece = nullptr;
			if (p == 1)
				pieceforp2 = pieceforp2 - 1;
			else
				pieceforp1 = pieceforp1 - 1;
			

			return true;

		}

		else {

			cout << "Legal Move!" << endl << endl;
			block[num2][alpha2].piece = block[num1][alpha1].piece;
			block[num1][alpha1].piece = nullptr;

			

			return true;

		}
	}


	else if (block[num1][alpha1].piece->name.compare("Queen") == 0) {


		
		if (abs(Row_D) != abs(Clm_D) && Row_D != 0 && Clm_D != 0) {

			cout << "Queens can only move in straight or diagonal.\n" << endl ;
			return false;

		}

		//Check if there are chesspiece in the moving route
		if (Row_D > 0 && Clm_D > 0) {



			for (int i = num1 - 1; i > num2; i--) {

				for (int j = alpha1 - 1; j > alpha2; j--) {

					if (block[i][j].piece != nullptr) {

						cout << "There's a chesspiece in the route.\n"<< endl;
						return false;

					}
				}
			}
		}

		else if (Row_D < 0 && Clm_D < 0) {

			

			for (int i = num1 + 1; i < num2; i++) {

				for (int j = alpha1 + 1; j < alpha2; j++) {

					if (block[i][j].piece != nullptr) {

						cout << "There's a chesspiece in the route.\n" << endl;
						return false;

					}
				}
			}
		}

		else if (Row_D > 0 && Clm_D < 0) {

			

			for (int i = num1 - 1; i > num2; i--) {

				for (int j = alpha1 + 1; j < alpha2; j++) {

					if (block[i][j].piece != nullptr) {

						cout <<"There's a chesspiece in the route.\n" << endl;
						return false;

					}
				}
			}
		}

		else if (Row_D < 0 && Clm_D > 0) {

			

			for (int i = num1 + 1; i < num2; i++) {

				for (int j = alpha1 - 1; j > alpha2; j--) {

					if (block[i][j].piece != nullptr) {

						cout << "There's a chesspiece in the route.\n" << endl;
						return false;

					}
				}
			}
		}

		else if (Row_D == 0 && Clm_D > 0) {

		

			for (int i = alpha1 - 1; i > alpha2; i--) {

				if (block[num1][i].piece != nullptr) {

					cout << "There's a chesspiece in the route.\n" << endl;
					return false;

				}
			}
		}

		else if (Row_D == 0 && Clm_D < 0) {

			

			for (int i = alpha1 + 1; i < alpha2; i++) {

				if (block[num1][i].piece != nullptr) {

					cout << "There's a chesspiece in the route.\n" << endl;
					return false;

				}
			}
		}

		else if (Row_D > 0 && Clm_D == 0) {


			for (int i = num1 - 1; i > num2; i--) {

				if (block[i][alpha1].piece != nullptr) {

					cout << "There's a chesspiece in the route.\n" << endl;
					return false;

				}
			}
		}

		else if (Row_D < 0 && Clm_D == 0) {

		

			for (int i = num1 + 1; i < num2; i++) {

				if (block[i][alpha1].piece != nullptr) {

					cout << "There's a chesspiece in the route.\n" << endl;
					return false;

				}
			}
		}

		


		if (block[num2][alpha2].piece != nullptr && block[num2][alpha2].piece->player != p) {

			cout << "Enemy's chesspiece[" << block[num2][alpha2].piece->name << "] is taken!" << endl << endl;

			block[num2][alpha2].piece = block[num1][alpha1].piece;	//piece taken
			block[num1][alpha1].piece = nullptr;
			if (p == 1)
				pieceforp2 = pieceforp2 - 1;
			else
				pieceforp1 = pieceforp1 - 1;
			

			return true;

		}

		else {

			cout << "Legal Move!" << endl << endl;
			block[num2][alpha2].piece = block[num1][alpha1].piece;
			block[num1][alpha1].piece = nullptr;

			
			return true;

		}
	}

	else if (block[num1][alpha1].piece->name.compare("Knight") == 0) {

		
		if (abs(Row_D) * abs(Clm_D) != 2) {
			//Knight need to move in a pattern of 1*2
			cout << "Knights can't move like that." << endl << endl;
			return false;


		}

		if (block[num2][alpha2].piece != nullptr && block[num2][alpha2].piece->player != p) {

			cout << "Enemy's chesspiece[" << block[num2][alpha2].piece->name << "] is taken!" << endl << endl;

			block[num2][alpha2].piece = block[num1][alpha1].piece;	
			block[num1][alpha1].piece = nullptr;
			if (p == 1)
				pieceforp2 = pieceforp2 - 1;
			else
				pieceforp1 = pieceforp1 - 1;
			

			return true;

		}

		else {

			cout << "Legal Move!" << endl << endl;
			block[num2][alpha2].piece = block[num1][alpha1].piece;
			block[num1][alpha1].piece = nullptr;


			return true;

		}
	}

	else if (block[num1][alpha1].piece->name.compare("Bishop") == 0) {

		//Diagonal move only
		if (abs(Row_D) != abs(Clm_D)) {

			cout << "Bishops can only move in diagonal." << endl;
			return false;

		}

		//COLLISION CHECKING IF STATEMENTS
		if (Row_D > 0 && Clm_D > 0) {

			for (int i = num1 - 1; i > num2; i--) {

				for (int j = alpha1 - 1; j > alpha2; j--) {

					if (block[i][j].piece != nullptr) {

						cout << "There's a chesspiece in the route.\n" << endl;
						return false;

					}
				}
			}
		}

		else if (Row_D < 0 && Clm_D < 0) {

			for (int i = num1 + 1; i < num2; i++) {

				for (int j = alpha1 + 1; j < alpha2; j++) {

					if (block[i][j].piece != nullptr) {

						cout << "There's a chesspiece in the route.\n" << endl;
						return false;

					}
				}
			}
		}

		else if (Row_D > 0 && Clm_D < 0) {

			for (int i = num1 - 1; i > num2; i--) {

				for (int j = alpha1 + 1; j < alpha2; j++) {

					if (block[i][j].piece != nullptr) {

						cout << "There's a chesspiece in the route.\n" << endl;
						return false;

					}
				}
			}
		}

		else if (Row_D < 0 && Clm_D > 0) {

			for (int i = num1 + 1; i < num2; i++) {

				for (int j = alpha1 - 1; j > alpha2; j--) {

					if (block[i][j].piece != nullptr) {

						cout << "There's a chesspiece in the route.\n" << endl;
						return false;

					}
				}
			}
		}

		//STANDARD PIECE TAKING CODE (SAME FOR ALL PIECES FOR P1)
		if (block[num2][alpha2].piece != nullptr && block[num2][alpha2].piece->player != p) {

			cout << "Enemy's chesspiece[" << block[num2][alpha2].piece->name << "] is taken!" << endl << endl;

			block[num2][alpha2].piece = block[num1][alpha1].piece;	//piece taken
			block[num1][alpha1].piece = nullptr;
			if (p == 1)
				pieceforp2 = pieceforp2 - 1;
			else
				pieceforp1 = pieceforp1 - 1;
			

			return true;


		}

		else {

			cout << "Legal Move!" << endl << endl;
			block[num2][alpha2].piece = block[num1][alpha1].piece;
			block[num1][alpha1].piece = nullptr;

			

			return true;


		}
	}

	else if (block[num1][alpha1].piece->name.compare("Rook") == 0) {

		if (Row_D != 0 && Clm_D != 0) {

			cout << "Rooks can only move in straight" << endl << endl;
			return false;

		}

		//COLLISION CHECKING IF STATEMENTS
		if (Row_D == 0 && Clm_D > 0) {

			for (int i = alpha1 - 1; i > alpha2; i--) {

				if (block[num1][i].piece != nullptr) {

					cout << "There's a chesspiece in the route.\n" << endl;
					return false;

				}
			}
		}

		else if (Row_D == 0 && Clm_D < 0) {

			for (int i = alpha1 + 1; i < alpha2; i++) {

				if (block[num1][i].piece != nullptr) {

					cout << "There's a chesspiece in the route.\n" << endl;
					return false;

				}
			}
		}

		else if (Row_D > 0 && Clm_D == 0) {

			for (int i = num1 - 1; i > num2; i--) {

				if (block[i][alpha1].piece != nullptr) {

					cout << "There's a chesspiece in the route.\n" << endl;
					return false;

				}
			}
		}

		else if (Row_D < 0 && Clm_D == 0) {

			for (int i = num1 + 1; i < num2; i++) {

				if (block[i][alpha1].piece != nullptr) {

					cout << "There's a chesspiece in the route.\n" << endl;
					return false;

				}
			}
		}

		if (block[num2][alpha2].piece != nullptr && block[num2][alpha2].piece->player != p) {

			cout <<  "Enemy's chesspiece["  << block[num2][alpha2].piece->name <<"] is taken!" << endl << endl;

			block[num2][alpha2].piece = block[num1][alpha1].piece;	//piece taken
			block[num1][alpha1].piece = nullptr;
			if (p == 1)
				pieceforp2 = pieceforp2 - 1;
			else
				pieceforp1 = pieceforp1 - 1;
			

			return true;

		}

		else {

			cout << "Legal Move!" << endl << endl;
			block[num2][alpha2].piece = block[num1][alpha1].piece;
			block[num1][alpha1].piece = nullptr;

			

			return true;


		}
	}

	else return false;

}