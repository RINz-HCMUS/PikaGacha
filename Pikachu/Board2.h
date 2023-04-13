#pragma once

#include "SettingGame.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <deque>

#ifndef BOARD2_H
#define BOARD2_H
// Node của linked list
struct Node{
	int data;				
	Node* pNext;
	
	int getLength(Node*&);			// Hàm lấy độ dài Linked List
	int getPos(Node*&, int);		// Hàm lấy giá trị tại 1 vị trí của Linked List
	
	void addPos(Node*&, int, int);	// Hàm thêm giá trị tại 1 vị trí của Linked List
	void setPos(Node*&, int, int);	// Hàm gán giá trị tại 1 vị trí của Linked List
	void removePos(Node*&, int);	// Hàm xóa tại 1 vị trí của Linked List
	void removeAll(Node*&);			// Hàm xóa toàn bộ Linked list
};

	
struct Board2{
	
		int n_row, n_column;			// số hàng, số cột
		int n_type;						// số kiểu kí tự
		const int left = 11, top = 5;	// vị trí góc trái trên của bảng
		Node** _board2;					// array of Linked list
		
		// constuctor và destructor	
		Board2(int ,int ,int);
		~Board2();
		
		// Hàm lấy giá trị
		int getCell(int, int);			// Hàm lấy giá trị tại ô (i, j)
		int getLengthInRow(int);		// Hàm lấy độ dài 1 hàng của mảng
		
		// Hàm thực thi
		void removeCell(int, int);		// Hàm xóa 1 ô của bảng
		void initBoard(int, int, int);	// Hàm khởi tạo của bảng
		void suffleBoard();				// Hàm đảo lại bảng
		void suggestBoard(std::pair <int, int> &start, std::pair <int, int> &end);	// Hàm đưa ra gợi ý 2 ô có thể nối được
		void removeBoard(std::pair <int, int> start, std::pair <int, int> end);		// Hàm xóa 2 ô được chọn
		
		// Hàm kiểm tra tính logic của game
		bool canConnect(std::pair<int, int> start, std::pair<int, int> end, std::vector<std::pair<int, int> > &path); // Hàm kiểm tra 2 ô có thể nối được không
		std::vector <std::pair<int, int> > findPath(std::pair<int, int> start, std::pair<int, int> end);	// Hàm trả về đường đi từ ô start đến ô end
		bool checkBoard();	// Hàm kiểm tra bảng còn 2 ô nào nối được với nhau không
		
		// Hàm vẽ
		void drawCells(int, int, int);							// Hàm vẽ 1 ô 
		void drawBoard();										// Hàm vẽ bảng
		void drawLine(std::vector<std::pair<int, int> > path);	// Hàm vẽ đường nối của 2 ô 
		
};

#endif // BOARD2_H