#pragma once
#include <windows.h>
#include <iostream>
void Press_WASD() {
	int a = rand() % 4;
	switch (a)
	{
	case 0:
		keybd_event(87, 0, 0, 0);//W
		break;
	case 1:
		keybd_event(65, 0, 0, 0);//A
		break;
	case 2:
		keybd_event(83, 0, 0, 0);//S
		break;
	case 3:
		keybd_event(68, 0, 0, 0);//D
	}
}
void Press_R() {
	keybd_event(82, 0, 0, 0);
}
void press_F() {
	keybd_event(70, 0, 0, 0);
}