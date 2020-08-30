#include<string>
#include"chesspiece.h"
using namespace std;
#ifndef ROOK_H
#define ROOK_H

class rook :public chesspiece {
public:
	
	~rook(void);
	rook(int);


	string name;
	int player;


};

#endif