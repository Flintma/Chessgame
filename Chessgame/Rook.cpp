#include "Rook.h"
#include<string>




rook::~rook(void)
{
}

rook::rook(int p) :chesspiece(p,"Rook") {

	name = "Rook";
	player = p;

}