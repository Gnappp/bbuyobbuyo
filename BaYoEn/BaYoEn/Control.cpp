#include "Bayoen.h"

Control::Control()
{
}
void Control::Down_Left()
{
	char block_tmp;
	vector<vector<int>> new_block_position_tmp;
	vector<vector<char>> stadium_tmp;
	new_block_position_tmp = datas.Get_new_block_position();
	stadium_tmp = datas.Get_stadium();
	if (new_block_position_tmp.size() != 0)
	{
		block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
		stadium_tmp[new_block_position_tmp[0][0]] [new_block_position_tmp[0][1]] = ' ';
		new_block_position_tmp[0][0] = new_block_position_tmp[0][0] - 2;
		stadium_tmp[new_block_position_tmp[0][0]] [new_block_position_tmp[0][1]] = block_tmp;
		if (new_block_position_tmp.size() == 2)
		{
			block_tmp = stadium_tmp[new_block_position_tmp[1][0]] [new_block_position_tmp[1][1]];
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
			new_block_position_tmp[1][0] = new_block_position_tmp[1][0] - 2;
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;
		}
	}
	datas.Put_new_block_position(new_block_position_tmp);
	datas.Put_stadium(stadium_tmp);
}

void Control::Down_Right()
{
	char block_tmp;
	vector<vector<int>> new_block_position_tmp;
	vector<vector<char>> stadium_tmp;
	new_block_position_tmp = datas.Get_new_block_position();
	stadium_tmp = datas.Get_stadium();
	if (new_block_position_tmp.size() != 0){
		block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
		stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = ' ';
		new_block_position_tmp[0][0] = new_block_position_tmp[0][0] + 2;
		stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;
		if (new_block_position_tmp.size() == 2)
		{
			block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
			new_block_position_tmp[1][0] = new_block_position_tmp[1][0] + 2;
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;
		}
	}
	datas.Put_new_block_position(new_block_position_tmp);
	datas.Put_stadium(stadium_tmp);
}

void Control::Down_Up()
{
	char block_tmp;
	vector<vector<int>> new_block_position_tmp; //[n][m] m = 0는 x, m = 1는 y
	vector<int> position_swap;
	vector<vector<char>> stadium_tmp;
	new_block_position_tmp = datas.Get_new_block_position();
	stadium_tmp = datas.Get_stadium();
	if (new_block_position_tmp.size() == 2){
		switch (datas.Get_new_block_mode())
		{
		case 1:
			block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
			new_block_position_tmp[1][0] = new_block_position_tmp[1][0] + 2;
			new_block_position_tmp[1][1] = new_block_position_tmp[1][1] + 1;
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;

			datas.Put_new_block_mode(2);

			datas.Put_new_block_position(new_block_position_tmp);
			datas.Put_stadium(stadium_tmp);
			break;
		case 2:
			block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
			stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = ' ';
			new_block_position_tmp[0][1] = new_block_position_tmp[0][1] - 1;
			stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;

			block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
			new_block_position_tmp[1][0] = new_block_position_tmp[1][0] - 2;
			stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;

			position_swap = new_block_position_tmp[0];
			new_block_position_tmp[0] = new_block_position_tmp[1];
			new_block_position_tmp[1] = position_swap;

			datas.Put_new_block_mode(1);

			datas.Put_new_block_position(new_block_position_tmp);
			datas.Put_stadium(stadium_tmp);
			break;
		}
	}
}

void Control::Down_Down()
{
	COORD pos = { 20, 22 };//
	char block_tmp;
	vector<vector<int>> new_block_position_tmp = datas.Get_new_block_position();
	vector<int> position_swap;
	vector<vector<char>> stadium_tmp = datas.Get_stadium();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//
	cout << "Debug Control.Down_Down : "<<datas.Get_new_block_position().size();//
	
	if (new_block_position_tmp.size() != 0)
	{
		block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
		stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = ' ';
		new_block_position_tmp[0][1] = new_block_position_tmp[0][1] + 1;
		stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;
		if (new_block_position_tmp.size() == 2)
		{
			block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
			new_block_position_tmp[1][1] = new_block_position_tmp[1][1] + 1;
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;
		}
	}
	datas.Put_new_block_position(new_block_position_tmp);
	datas.Put_stadium(stadium_tmp);
}

void Control::Delete_Block()
{
	vector<vector<char>> stadium_tmp = datas.Get_stadium();
	vector<COORD> check;
	vector<int> x_highest_tmp = datas.Get_x_highest();
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < x_highest_tmp[i]; k++)
		{
			COORD coord = { i, k };
			check = Check_Block(coord, check, stadium_tmp[coord.X][coord.Y]);
			if (check.size()>3)
			{
				//check에 있는 좌표들 공백처리하기
				for (int i = 0; i < check.size(); i++);
				{
					stadium_tmp[check[i].X][check[i].Y] = ' ';
				}
				Fill_Block();
				i = 0;
				k = 0;
				break;
			}
		}
	}
}

void Control::Fill_Block()
{
	vector<vector<char>> stadium_tmp = datas.Get_stadium();
	vector<int> x_highest_tmp = datas.Get_x_highest();
	vector<int> empty_check; //빈공간 x좌표
	vector<char> char_tmp; // empty_check의 x좌표의 문자열 넣기
	vector<vector<char>> change_char; // char_tmp를 empty_check만큼 넣기
	for (int i = 0; i < x_highest_tmp.size(); i++) //빈 공간의 x좌표 찾기
	{
		for (int k = 0; k < x_highest_tmp[i]; k++)
		{
			if (stadium_tmp[i * 2][k] == ' ')
			{
				empty_check.push_back(i);
				break;
			}
		}
	}

	for (int i = 0; i < empty_check.size(); i++) //빈공간 제외하고 문자열 넣기
	{
		for (int k = 0; k < x_highest_tmp[i]; k++)
		{
			if (stadium_tmp[empty_check[i]*2][k] != ' ')
			{
				char_tmp.push_back(stadium_tmp[empty_check[i] * 2][k]);
			}
		}
		change_char.push_back(char_tmp);
	}

	for (int i = 0; i < empty_check.size(); i++) //빈공간 x좌표를 이용하여 stadium을 수정한다.
	{
			stadium_tmp[empty_check[i * 2]] = change_char[i];
			x_highest_tmp[empty_check[i]] = change_char[i].size();
	}
	datas.Put_stadium(stadium_tmp);
	datas.Put_x_highest(x_highest_tmp);
}

vector<COORD> Control::Check_Block(COORD coord,vector<COORD> coord_check,char block)
{
	vector<vector<char>> stadium_tmp = datas.Get_stadium();
	COORD coord_tmp;
	for (int i = 0; i < coord_check.size(); i++)
	{
		if (coord.X == coord_check[i].Y && coord.Y == coord_check[i].Y)
		{
			return coord_check;
		}
	}
	if (stadium_tmp[coord.X][coord.Y] == block)
	{
		coord_check.push_back(coord);
		coord_tmp = coord;
		if (coord_tmp.X < 10) //right
		{
			coord_tmp.X += 2;
			coord_check = Check_Block(coord_tmp, coord_check, block);
		}
		if (coord_tmp.X > 0) //left
		{
			coord_tmp.X -= 2;
			coord_check = Check_Block(coord_tmp, coord_check, block);
		}
		if (coord_tmp.Y < 11)
		{
			coord_tmp.Y += 1;
			coord_check = Check_Block(coord_tmp, coord_check, block);
		}
		if (coord_tmp.Y > 0)
		{
			coord_tmp.Y -= 1;
			coord_check = Check_Block(coord_tmp, coord_check, block);
		}
	}
	else
		return coord_check;
}
bool Control::Stack_Block()
{
	char block_tmp;
	vector<int> x_highest_tmp = datas.Get_x_highest();
	vector<vector<int>> new_block_position_tmp = datas.Get_new_block_position();
	vector<vector<char>> stadium_tmp = datas.Get_stadium();
	int new_block_mode = datas.Get_new_block_mode();
	switch (new_block_mode)
	{
	case 1:
		if (new_block_position_tmp[0][1] + 1 == x_highest_tmp[new_block_position_tmp[0][0] / 2])
		{
			x_highest_tmp[new_block_position_tmp[0][0] / 2] += 2;
			new_block_position_tmp.clear();
			datas.Put_new_block_position(new_block_position_tmp);
			datas.Put_x_highest(x_highest_tmp);
			return true;
		}
		else return false;
		break;
	case 2:
		if (new_block_position_tmp[0][1] + 1 == x_highest_tmp[new_block_position_tmp[0][0] / 2])
		{
			x_highest_tmp[new_block_position_tmp[0][0] / 2] += 1;
			block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
			x_highest_tmp[new_block_position_tmp[1][0] / 2] += 1;
			new_block_position_tmp[1][1] = x_highest_tmp[new_block_position_tmp[1][0] / 2];
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;
			new_block_position_tmp.clear();
			datas.Put_new_block_position(new_block_position_tmp);
			datas.Put_x_highest(x_highest_tmp);
			datas.Put_stadium(stadium_tmp);
			return true;
		}
		else if (new_block_position_tmp[1][1] + 1 == x_highest_tmp[new_block_position_tmp[1][0] / 2])
		{
			x_highest_tmp[new_block_position_tmp[1][0] / 2] += 1;
			block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
			x_highest_tmp[new_block_position_tmp[0][0] / 2] += 1;
			new_block_position_tmp[0][1] = x_highest_tmp[new_block_position_tmp[0][0] / 2];
			stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;
			new_block_position_tmp.clear();
			datas.Put_new_block_position(new_block_position_tmp);
			datas.Put_x_highest(x_highest_tmp);
			datas.Put_stadium(stadium_tmp);
			return true;
		}
		else return false;
		break;
	default:
		break;
	}
}

Datas Control::Get_Datas()
{
	return datas;
}
void Control::Put_Datas(Datas data)
{
	datas = data;
}
