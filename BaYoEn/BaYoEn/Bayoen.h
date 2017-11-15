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
	vector<vector<char>> stadium;//
	vector<vector<int>> new_block_position;//
	vector<int> x_highest;//
	Block block;
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
};

class Control
{
public:
	Control();
	void Down_Left();
	void Down_Right();
	void Down_Up();
	void Down_Down();
	void Delete_Block();
	void Stack_Block();
};

class Block
{
private:
	Datas datas;
	vector<char> block;
public:
	Block();
	vector<char> Get_block();
	void Put_block(vector<char>);
	void Print_Block();
};

#endif