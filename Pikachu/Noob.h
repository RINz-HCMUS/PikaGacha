#pragma once
#include "SettingGame.h"
#include "BG.h"
#include "Menu.h"
#include "Board.h"
#include "Sound.h"

#ifndef NOOBMODE_H
#define NOOBMODE_H

struct NoobMode{
    // Khởi tạo bảng
    Board A; // 6, 6, 26
    //~Board A;
	
	// Số ô đã hoàn thành (xóa)
	int CompleteCells;
    
	// Hàm thực thi
    static void NoobPlay(account&);
	
};
#endif // NOOBMODE_H

