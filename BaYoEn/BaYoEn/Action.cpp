#include "Bayoen.h"

Action::Action()
{
	init();
}

void Action::Start_Game()
{
	
	while (1)
	{
		if (datas.Get_new_block_position().size() < 2)
		{
			Create_Blcok();
		}
		for (int i = 0; i < 20; i++)
		{
			
			if (GetKeyState(VK_LEFT) & 0x0800)
				control.Down_Left();
			if (GetKeyState(VK_RIGHT) & 0x0800)
				control.Down_Right();
			if (GetKeyState(VK_DOWN) & 0x0800)
				break;
			if (GetKeyState(VK_UP) & 0x0800)
				control.Down_Up();
			datas.Print_Block();
			Sleep(50);
		}
		datas.Print_Block();
		control.Stack_Block();
		datas.Print_Block();
		//if (datas.Get_new_block_position().size()>0)
			control.Down_Down();
		datas.Print_Block();
	}
}

void Action::Create_Blcok()
{
	datas.New_Block();
	datas.Print_Block();
}

void Action::init()
{
	COORD pos;
	for (int i = 0; i < 13; i++){
		if (i % 2 == 0){
			pos = { i, 11 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "¦¬¦¬";
		}
	}
	for (int i = 0; i < 11 + 1; i++){
		if (11 != i){
			pos = { 13, i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "¦­";
		}
		if (11 == i){
			pos = { 13, i };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "¦°";
		}
	}
}