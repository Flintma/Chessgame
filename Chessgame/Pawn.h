#include<string>
#include"chesspiece.h"
#ifndef PAWN_H
#define PAWN_H
using namespace std;


class pawn:public chesspiece {
public:
	
	~pawn(void);
	pawn(int);


	string name;
	int player;


};

#endif