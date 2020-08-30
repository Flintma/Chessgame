#include "Queen.h"
#include<string>





queen::~queen(void)
{
}

queen::queen(int p) :chesspiece(p,"Queen") {

	name = "Queen";
	player = p;

}