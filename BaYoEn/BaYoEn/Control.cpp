#include "Bayoen.h"

Control::Control(){}
void Control::Down_Left()
{
	char block_tmp;
	vector<vector<int>> new_block_position_tmp;
	vector<vector<char>> stadium_tmp;
	new_block_position_tmp = datas.Get_new_block_position();
	stadium_tmp = datas.Get_stadium();
	if (new_block_position_tmp[0][0] != 0){
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
	if (new_block_position_tmp[0][0] != 0){
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
	vector<vector<int>> new_block_position_tmp;
	vector<int> position_swap;
	vector<vector<char>> stadium_tmp;
	new_block_position_tmp = datas.Get_new_block_position();
	stadium_tmp = datas.Get_stadium();
	if (new_block_position_tmp.size == 2){
		switch (datas.Get_new_block_mode)
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
		}
	}
}

void Control::Down_Down()
{
	char block_tmp;
	vector<vector<int>> new_block_position_tmp;
	vector<int> position_swap;
	vector<vector<char>> stadium_tmp;
	new_block_position_tmp = datas.Get_new_block_position();
	stadium_tmp = datas.Get_stadium();

	block_tmp = stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]];
	stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = ' ';
	new_block_position_tmp[0][1] = new_block_position_tmp[0][1] + 1;
	stadium_tmp[new_block_position_tmp[0][0]][new_block_position_tmp[0][1]] = block_tmp;

	block_tmp = stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]];
	stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = ' ';
	new_block_position_tmp[1][1] = new_block_position_tmp[1][1] + 1;
	stadium_tmp[new_block_position_tmp[1][0]][new_block_position_tmp[1][1]] = block_tmp;

	datas.Put_new_block_position(new_block_position_tmp);
	datas.Put_stadium(stadium_tmp);
}

void Control::Delete_Block()
{

}
	void Stack_Block();
