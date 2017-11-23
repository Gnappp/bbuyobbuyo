#include "Bayoen.h"

Action::Action()
{}

void Action::Start_Game()
{
	COORD pos = { 20 , 20 };
	while (1)
	{
		if (datas.Get_new_block_position().size() < 2)
		{
				datas.New_Block();
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//
				cout << "Debug Action : " << datas.Get_new_block_position().size();//
				datas = control.Get_Datas();
				datas.Print_Block();
		}
		for (int i = 0; i < 20; i++)
		{
			
			if (GetKeyState(VK_LEFT) & 0x0800)
				control.Down_Left();
			if (GetKeyState(VK_RIGHT) & 0x0800)
				control.Down_Right();
			if (GetKeyState(VK_DOWN) & 0x0800)
				control.Down_Down();
			if (GetKeyState(VK_UP) & 0x0800)
				control.Down_Up();
			
			
			datas.Print_Block();
			Sleep(50);
		}
		//if (datas.Get_new_block_position().size() <0)
		control.Down_Down();
		datas.Print_Block();
	}
}