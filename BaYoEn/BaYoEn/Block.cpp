#include "Bayoen.h"

Block::Block()
{
	Block::block.push_back(' ');
	Block::block.push_back('¡Ú');
	Block::block.push_back('¡á');
	Block::block.push_back('¡Ü');
}

void Print_Block()
{
	COORD pos;
	for (int i = 0; i < 12; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			pos = { i, k };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << datas.Get_stadium[i][k];
		}
	}
}

vector<char> Block::Get_block()
{
	return Block::block;
}

void Block:: Put_block(vector<char> b)
{
	Block::block = b;
}