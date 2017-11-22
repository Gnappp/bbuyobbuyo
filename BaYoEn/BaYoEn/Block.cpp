#include "Bayoen.h"

Block::Block()
{
	Block::block.push_back(' ');
	Block::block.push_back('¡Ú');
	Block::block.push_back('¡á');
	Block::block.push_back('¡Ü');
}

void Block::Print_Block()
{
	COORD pos;
	for (int i = 0; i < 11; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			pos = { k*2, i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << datas.Get_stadium[k*2][i];
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

