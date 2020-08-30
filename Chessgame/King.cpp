#include "King.h"
#include<string>




king::~king(void)
{
}

king::king(int p) :chesspiece(p,"King") {

	name = "King";
	player = p;

}