#pragma once
#include "SettingGame.h"
#include <iostream>

#ifndef BG_H
#define BG_H

struct BG{
	// Vị trí bắt đầu in
	int top, left;
	
	// Hàm in background
	static void drawBG(int);	
};

#endif // BG_H