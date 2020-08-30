#include<string>
#include"chesspiece.h"
using namespace std;
#ifndef QUEEN_H
#define QUEEN_H

class queen :public chesspiece {
public:
	
	~queen(void);
	queen(int);


	string name;
	int player;


};
#endif