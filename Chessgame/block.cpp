#include "Block.h"


Block::Block(void)
{
	piece = nullptr;
}

Block::Block(chesspiece* p) {

	piece = p;

}


Block::~Block(void)
{
}
