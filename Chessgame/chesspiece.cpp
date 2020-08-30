#include "chesspiece.h"





chesspiece::~chesspiece(void)
{
}

chesspiece::chesspiece(int p,string m) {	//type player

	player = p;
	name = m;
}