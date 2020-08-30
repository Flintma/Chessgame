#include<string>
#include"chesspiece.h"
using namespace std;
#ifndef KNIGHT_H
#define KNIGHT_H

class knight :public chesspiece {
public:
	
	~knight(void);
	knight(int);


	string name;
	int player;


};

#endif