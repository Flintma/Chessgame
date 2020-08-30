#include "Pawn.h"
#include<string>





pawn::~pawn(void)
{
}

pawn::pawn(int p):chesspiece(p,"Pawn") {	

	name = "Pawn";
	player = p;

}