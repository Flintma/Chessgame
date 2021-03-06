using namespace std;

#include <iostream>
#include"Display.h"
#include"Block.h"


void Display(Block block[8][8]) {

	char displayBoard[38][53] = {

	{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '||', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', '8', ' ', '||', ' ', ' ', 'R', ' ', ' ', '|', ' ', ' ', 'N', ' ', ' ', '|', ' ', ' ', 'B', ' ', ' ', '|', ' ', ' ', 'Q', ' ', ' ', '|', ' ', ' ', 'K', ' ', ' ', '|', ' ', ' ', 'B', ' ', ' ', '|', ' ', ' ', 'N', ' ', ' ', '|', ' ', ' ', 'R', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', '7', ' ', '||', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', '6', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', '5', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', '4', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', '3', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', '2', ' ', '||', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '|', ' ', ' ', 'P', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '|', '-', '-', '-', '-', '-', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', '1', ' ', '||', ' ', ' ', 'R', ' ', ' ', '|', ' ', ' ', 'N', ' ', ' ', '|', ' ', ' ', 'B', ' ', ' ', '|', ' ', ' ', 'Q', ' ', ' ', '|', ' ', ' ', 'K', ' ', ' ', '|', ' ', ' ', 'B', ' ', ' ', '|', ' ', ' ', 'N', ' ', ' ', '|', ' ', ' ', 'R', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '||'},
	{' ', ' ', ' ', ' ', '||',  '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-','||'},


	};

	//Covert the board into block for the row
	int row1 = 31;
	int row2= 27;
	int row3= 23;
	int row4= 19;
	int row5= 15;
	int row6= 11;
	int row7= 7;
	int row8= 3;

	//Covert the board into block for the column
	int Clm1 = 7;
	int Clm2= 13;
	int Clm3= 19;
	int Clm4= 25;
	int Clm5= 31;
	int Clm6= 37;
	int Clm7= 43;
	int Clm8= 49;

	int tempRow = 0;
	int tempColumn = 0;

	//Update piece location
	for (int i = 0; i < 8; i++) {

		if (i == 0)
			tempRow = row1;
		else if (i == 1)
			tempRow = row2;
		else if (i == 2)
			tempRow = row3;
		else if (i == 3)
			tempRow = row4;
		else if (i == 4)
			tempRow = row5;
		else if (i == 5)
			tempRow = row6;
		else if (i == 6)
			tempRow = row7;
		else
			tempRow = row8;



		for (int j = 0; j < 8; j++) {

			if (j == 0)
				tempColumn = Clm1;
			else if (j == 1)
				tempColumn = Clm2;
			else if (j == 2)
				tempColumn = Clm3;
			else if (j == 3)
				tempColumn = Clm4;
			else if (j == 4)
				tempColumn = Clm5;
			else if (j == 5)
				tempColumn = Clm6;
			else if (j == 6)
				tempColumn = Clm7;
			else
				tempColumn = Clm8;

			
			if (block[i][j].piece == nullptr)
				displayBoard[tempRow][tempColumn] = ' ';

			else if (block[i][j].piece->name.compare("Pawn") == 0)
				displayBoard[tempRow][tempColumn] = 'P';

			else if (block[i][j].piece->name.compare("King") == 0)
				displayBoard[tempRow][tempColumn] = 'K';

			else if (block[i][j].piece->name.compare("Queen") == 0)
				displayBoard[tempRow][tempColumn] = 'Q';

			else if (block[i][j].piece->name.compare("Bishop") == 0)
				displayBoard[tempRow][tempColumn] = 'B';

			else if (block[i][j].piece->name.compare("Knight") == 0)
				displayBoard[tempRow][tempColumn] = 'N';

			else if (block[i][j].piece->name.compare("Rook") == 0)
				displayBoard[tempRow][tempColumn] = 'R';

		}
	}




	for (int i = 0; i < 34; i++) {

		cout << endl;

		for (int j = 0; j < 53; j++) {

			cout << displayBoard[i][j];

		}
	}

	cout << endl;

}