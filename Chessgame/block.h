#pragma once
#include "chesspiece.h"
#ifndef BLOCK_H
#define BLOCK_H
class Block
{
public:
	Block(void);
	~Block(void);

	chesspiece* piece;	

	Block(chesspiece*);
};
#endif