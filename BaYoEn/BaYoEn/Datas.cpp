#include "Bayoen.h"

Datas::Datas()
{
	init();
}

void Datas::New_Block()
{
	int sel = rand() % 2;
	vector<int> n_b_p;
	COORD pos = { 20, 21 };//
	if (new_block_position.size() == 0)
	{
		stadium[6][0] = block[sel];
		n_b_p.push_back(6);
		n_b_p.push_back(0);
		new_block_position.push_back(n_b_p);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//
		cout << "Debug Datas.New_Block : " << new_block_position.size();//
	}
	else if (new_block_position.size() == 1)
	{
		stadium[new_block_position[0][0]][new_block_position[0][1] - 1] = block[sel];
		n_b_p.push_back(new_block_position[0][0]);
		n_b_p.push_back(new_block_position[0][1] - 1);
		new_block_position.push_back(n_b_p);
		new_block_mode = 1;
	}
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
	block.push_back(' ');
	block.push_back('S');
	block.push_back('T');
	block.push_back('O');
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

int Datas::Get_new_block_mode()
{
	return new_block_mode;
}

void Datas::Put_new_block_mode(int tmp)
{
	new_block_mode = tmp;
}

void Datas::Print_Block()
{
	COORD pos;
	for (int i = 0; i < 11; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			pos = { k * 2, i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << stadium[k * 2][i];
		}
	}
}

vector<char> Datas::Get_block()
{
	return block;
}

void Datas::Put_block(vector<char> b)
{
	block = b;
}