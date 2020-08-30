#include<string>
#include"chesspiece.h"
using namespace std;
#ifndef KING_H
#define KING_H

class king :public chesspiece {
public:
	
	~king(void);
	king(int);


	string name;
	int player;


};
#endif