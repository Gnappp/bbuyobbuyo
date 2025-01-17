#ifndef BAYOEN
#define BAYOEN

#include<iostream>
#include<windows.h>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>

using namespace std;


class Datas
{
private:
	vector<char> block;
	vector<vector<char>> stadium;//
	vector<vector<int>> new_block_position;//new_block_position[n][m] n=0 : first, n=1 : second, m=0 : x, m=1 : y
	vector<int> x_highest;//
	int x_limit;
	int y_limit;
	int new_block_mode;
	Datas();
public:
	static Datas& GetInctance();
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
	int Get_x_limit();
	int Get_y_limit();
	void Print_Block();
	
};

class Control
{
private:
	Datas& datas=datas.GetInctance();
	int x_limit;
	int y_limit;
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
	void Fill_Block(vector<COORD> check);
};



class Action
{
private:
	Datas& datas = datas.GetInctance();
	Control control;
public:
	Action();
	void Start_Game();
	void init();
	void Create_Blcok();
};
#endif