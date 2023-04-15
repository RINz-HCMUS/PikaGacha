#pragma once
#include "SettingGame.h"

//#pragma comment(lib, "winmm.lib")
struct sound{
	// âm thanh khi di chuyển
	static void choose();
	
	// âm thanh khi chọn đúng
	static void correct();
	
	// âm thanh khi vào LEADERBOARD
	static void leaderboard();
	
	//âm thanh khi bắt đầu màn chơi
	static void start();
	
	// âm thanh khi chọn sai
	static void wrong();
	
	// âm thanh khi chiến thắng
	static void victory();
	
	// âm thanh ở Menu chính
	static void theme();
	
	// âm thanh khi vào POKEDEX
	static void pokedexTheme();
	
	// tắt âm
	static void off();
};