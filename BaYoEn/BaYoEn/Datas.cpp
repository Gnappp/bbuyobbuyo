#include "Bayoen.h"

Datas::Datas()
{
	init();
}

void Datas::New_Block()//
{
	int sel = rand() % 2;
	vector<char> b;
	b = block.Get_block();
	stadium[4][11] = b[sel];
}
void Datas::init()
{
	vector<char> tmp;
	for (int i = 0; i < 11; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			tmp.push_back(' ');
		}
		stadium.push_back(tmp);
		tmp.clear();
	}
	for (int i = 0; i < 6; i++)
	{
		x_highest.push_back(0);
	}
}
vector<vector<char>> Datas::Get_stadium()
{
	return stadium;
}
void Datas::Put_stadium(vector<vector<char>> tmp)
{
	stadium = tmp;
}
vector<vector<int>> Datas::Get_new_block_position()
{
	return new_block_position;
}
void Datas::Put_new_block_position(vector<vector<int>> tmp)
{
	new_block_position = tmp;
}
vector<int> Datas::Get_x_highest()
{
	return x_highest;
}
void Datas::Put_x_highest(vector<int> tmp)
{
	x_highest = tmp;
}