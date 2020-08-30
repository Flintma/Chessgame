#include "Bishop.h"
#include<string>




bishop::~bishop(void)
{
}

bishop::bishop(int p) :chesspiece(p,"Bishop") {

	name = "Bishop";
	player = p;

}