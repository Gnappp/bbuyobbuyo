#include "Bayoen.h"

Control::Control()
{
	x_limit = datas.Get_x_limit();
	y_limit = datas.Get_y_limit();
}
void Control::Down_Left()
{
	char block_tmp;
	vector<vector<int>> new_block_position_tmp;
	vector<vector<char>> stadium_tmp;
	new_block_position_tmp = datas.Get_new_block_position();
	stadium_tmp = datas.Get_stadium();
	if (new_block_position_tmp[0][0] != 0 && stadium_tmp[new_block_position_tmp[0][0] - 2][new_block_position_tmp[0][1]] == ' ')
	{
		if (new_block_position_tmp.size() != 0)
		{
			block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
			stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = ' ';
			new_block_position_tmp[0][0] = new_block_position_tmp[0][0] - 2;
			stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;
			if (new_block_position_tmp.size() == 2)
			{
				block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
				stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
				new_block_position_tmp[1][0] = new_block_position_tmp[1][0] - 2;
				stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;
			}
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
	if (datas.Get_new_block_mode() == 2)
	{
		if (new_block_position_tmp[1][0] < (x_limit * 2) - 2 && stadium_tmp[new_block_position_tmp[1][0] + 2][new_block_position_tmp[1][1]] == ' ')
		{
			if (new_block_position_tmp.size() != 0)
			{
				if (new_block_position_tmp.size() == 2)
				{
					block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
					stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
					new_block_position_tmp[1][0] = new_block_position_tmp[1][0] + 2;
					stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;
				}
				block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
				stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = ' ';
				new_block_position_tmp[0][0] = new_block_position_tmp[0][0] + 2;
				stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;
			}

		}
	}
	else //new_block_position.size()가 1일때는 움직이지 않고 new_block_mode가 2일땐 중심이 new_block_mode[1][0]이기때문에 나눴다.
	{
		if (new_block_position_tmp[0][0] < (x_limit * 2) - 2 && stadium_tmp[new_block_position_tmp[0][0] + 2][new_block_position_tmp[0][1]] == ' ')
		{
			if (new_block_position_tmp.size() != 0)
			{
				if (new_block_position_tmp.size() == 2)
				{
					block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
					stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
					new_block_position_tmp[1][0] = new_block_position_tmp[1][0] + 2;
					stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;
				}
				block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
				stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = ' ';
				new_block_position_tmp[0][0] = new_block_position_tmp[0][0] + 2;
				stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;
			}

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
	if (new_block_position_tmp[0][0] < (x_limit * 2) - 2 || new_block_position_tmp[1][0] < (x_limit * 2) - 2)
	{

		if (new_block_position_tmp.size() == 2)
		{
			switch (datas.Get_new_block_mode())
			{
			case 1:
				if (stadium_tmp[new_block_position_tmp[0][0] + 2][new_block_position_tmp[0][1]] == ' ')
				{
					block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
					stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
					new_block_position_tmp[1][0] = new_block_position_tmp[1][0] + 2;
					new_block_position_tmp[1][1] = new_block_position_tmp[1][1] + 1;
					stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;

					datas.Put_new_block_mode(2);

					datas.Put_new_block_position(new_block_position_tmp);
					datas.Put_stadium(stadium_tmp);
				}
				break;
			case 2:
				block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
				stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = ' ';
				new_block_position_tmp[0][1] = new_block_position_tmp[0][1] - 1;
				stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;

				block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
				stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
				new_block_position_tmp[1][0] = new_block_position_tmp[1][0] - 2;
				stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;

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
}

void Control::Down_Down()
{
	char block_tmp;
	vector<vector<int>> new_block_position_tmp = datas.Get_new_block_position();
	vector<int> position_swap;
	vector<vector<char>> stadium_tmp = datas.Get_stadium();

	

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
	
	for (int i = x_limit-1; i >= 0; i--)
	{
		for (int k = y_limit-1; k >= x_highest_tmp[i]; k--)
		{
			COORD coord = { i*2, k };
			check.clear();
			if (stadium_tmp[i * 2][k] != ' ')
			{
				check = Check_Block(coord, check, stadium_tmp[i*2][k]);
				if (check.size()>3)
				{
					
					//check에 있는 좌표들 공백처리하기
					for (int j = 0; j < check.size(); j++)
					{
						stadium_tmp[check[j].X][check[j].Y] = ' ';
					}
					datas.Put_stadium(stadium_tmp);
					
					datas.Print_Block();
					Fill_Block(check);
					x_highest_tmp = datas.Get_x_highest();
					Sleep(150);
					stadium_tmp = datas.Get_stadium();
					datas.Print_Block();
					i = x_limit - 1;
					k = y_limit - 1;
					break;
				}
			}
		}
	}
}

void Control::Fill_Block(vector<COORD> check)
{
	COORD pos = { 20, 22 };
	vector<vector<char>> stadium_tmp = datas.Get_stadium();
	vector<int> x_highest_tmp = datas.Get_x_highest();
	vector<int> empty_check; //빈공간 x좌표
	vector<char> char_tmp; // empty_check의 x좌표의 문자열 넣기
	vector<vector<char>> change_char; // char_tmp를 empty_check만큼 넣기
	vector<vector<char>> change_char_high;

	for (int i = 0; i < check.size(); i++)
	{
		empty_check.push_back(check[i].X);
	}
	
	sort(empty_check.begin(), empty_check.end());
	empty_check.erase(unique(empty_check.begin(), empty_check.end()), empty_check.end());

	for (int i = 0; i < empty_check.size(); i++) //빈공간 제외하고 문자열 넣기
	{
		for (int k = 0; k < y_limit ; k++)
		{
			if (stadium_tmp[empty_check[i]][k] != ' ')
			{
				char_tmp.push_back(stadium_tmp[empty_check[i]][k]);
			}
		}
		change_char.push_back(char_tmp);
		char_tmp.clear();
	}
	
	change_char_high = change_char;

	for (int i = 0; i < change_char.size(); i++)
	{
		char_tmp.clear();
		for (int k = change_char[i].size(); k < y_limit; k++)
		{
			char_tmp.push_back(' ');
		}
		for (int k = 0; k < change_char[i].size(); k++)
		{
			char_tmp.push_back(change_char[i][k]);
		}
		change_char[i] = char_tmp;
	}
	

	for (int i = 0; i < empty_check.size(); i++) //빈공간 x좌표를 이용하여 stadium을 수정한다.
	{
			stadium_tmp[empty_check[i]] = change_char[i];
			x_highest_tmp[empty_check[i]/2] = 11 - change_char_high[i].size();
	}
	
	datas.Put_stadium(stadium_tmp);
	datas.Put_x_highest(x_highest_tmp);
}

vector<COORD> Control::Check_Block(COORD coord,vector<COORD> coord_check,char block)
{
	COORD pos = { 20, 23 };
	vector<vector<char>> stadium_tmp = datas.Get_stadium();
	COORD coord_tmp;
	vector<int> x_highest = datas.Get_x_highest();
	
	for (int i = 0; i < coord_check.size(); i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//
	cout << "Debug Check_Block k : " << coord_check.size();//
		if (coord_check[i].X == coord.X && coord_check[i].Y == coord.Y)
		{
			return coord_check;
		}
	}
	if (stadium_tmp[coord.X][coord.Y] != ' ' && stadium_tmp[coord.X][coord.Y] == block)
	{
		coord_check.push_back(coord);
		coord_tmp = coord;
		if (coord.X < (x_limit-1)*2) //right
		{
			coord_tmp.X += 2;
			coord_check = Check_Block(coord_tmp, coord_check, block);
			coord_tmp = coord;
		}
		if (coord.X > 0) //left
		{
			coord_tmp.X -= 2;
			coord_check = Check_Block(coord_tmp, coord_check, block);
			coord_tmp = coord;
		}
		if (coord.Y < y_limit-1)
		{
			coord_tmp.Y += 1;
			coord_check = Check_Block(coord_tmp, coord_check, block);
			coord_tmp = coord;
		}
		if (coord.Y > 0)
		{
			coord_tmp.Y -= 1;
			coord_check = Check_Block(coord_tmp, coord_check, block);
			coord_tmp = coord;
		}
		return coord_check;
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
			x_highest_tmp[new_block_position_tmp[0][0] / 2] -= 2;
			new_block_position_tmp.clear();
			datas.Put_new_block_position(new_block_position_tmp);
			datas.Put_x_highest(x_highest_tmp);
			Delete_Block();
			return true;
		}
		else return false;
		break;
	case 2:
		if (new_block_position_tmp[0][1] + 1 == x_highest_tmp[new_block_position_tmp[0][0] / 2])
		{
			x_highest_tmp[new_block_position_tmp[0][0] / 2] -= 1;
			block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
			x_highest_tmp[new_block_position_tmp[1][0] / 2] -= 1;
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
			new_block_position_tmp[1][1] = x_highest_tmp[new_block_position_tmp[1][0] / 2];
			stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;
			new_block_position_tmp.clear();
			datas.Put_new_block_position(new_block_position_tmp);
			datas.Put_x_highest(x_highest_tmp);
			datas.Put_new_block_mode(1);
			datas.Put_stadium(stadium_tmp);
			datas.Print_Block();
			Delete_Block();
			return true;
		}
		else if (new_block_position_tmp[1][1] + 1 == x_highest_tmp[new_block_position_tmp[1][0] / 2])
		{
			x_highest_tmp[new_block_position_tmp[1][0] / 2] -= 1;
			block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
			x_highest_tmp[new_block_position_tmp[0][0] / 2] -= 1;
			stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = ' ';
			new_block_position_tmp[0][1] = x_highest_tmp[new_block_position_tmp[0][0] / 2];
			stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;
			new_block_position_tmp.clear();
			datas.Put_new_block_position(new_block_position_tmp);
			datas.Put_x_highest(x_highest_tmp);
			datas.Put_new_block_mode(1);
			datas.Put_stadium(stadium_tmp);
			datas.Print_Block();
			Delete_Block();
			return true;
		}
		else return false;
		break;
	default:
		return false;
	}
}

