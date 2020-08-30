#include "Knight.h"
#include<string>



knight::~knight(void)
{
}

knight::knight(int p) :chesspiece(p,"Knight") {

	name = "Knight";
	player = p;

}