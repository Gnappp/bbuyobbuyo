#ifndef BAYOEN
#define BAYOEN

#include<iostream>
#include<windows.h>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;


class Datas
{
private:
	vector<char> block;
	vector<vector<char>> stadium;//
	vector<vector<int>> new_block_position;//new_block_position[n][m] n=0 : first, n=1 : second, m=0 : x, m=1 : y
	vector<int> x_highest;//
	int new_block_mode;
public:
	Datas();
	void New_Block(); //
	void init();
	vector<vector<char>> Get_stadium();
	void Put_stadium(vector<vector<char>> );
	vector<vector<int>> Get_new_block_position();
	void Put_new_block_position(vector<vector<int>> );
	vector<int> Get_x_highest();
	void Put_x_highest(vector<int> );
	int Get_new_block_mode();
	void Put_new_block_mode(int);
	void Print_Block();
	vector<char> Get_block();
	void Put_block(vector<char>);
};

class Control
{
private:
	Datas datas;
public:
	Control();
	void Down_Left();
	void Down_Right();
	void Down_Up();
	void Down_Down();
	void Delete_Block();
	vector<COORD> Check_Block(COORD ,vector<COORD> , char );
	void Auto_Down();
	bool Stack_Block();
	void Fill_Block();
	Datas Get_Datas();
	void Put_Datas(Datas);
};



class Action
{
private:
	Datas datas;
	Control control;
public:
	Action();
	void Start_Game();
};
#endif