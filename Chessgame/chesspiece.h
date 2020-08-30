#include<string>
#ifndef CHESSPIECE_H
#define CHESSPIECE_H


using namespace std;


class chesspiece  {
public:
	
	~chesspiece(void);
	chesspiece(int,string);

	
	int player;
	string name;
	
};

#endif // !CHESSPIECE_H