#include<string>
#include"chesspiece.h"
using namespace std;
#ifndef BISHOP_H
#define BISHOP_H

class bishop :public chesspiece {
public:
	
	~bishop(void);
	bishop(int);


	string name;
	int player;


};

#endif
