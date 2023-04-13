#include "Board2.h"


/* HÀM CỦA NODE*/

int Node::getLength(Node* &pHead)
{
	Node* cur = pHead;
	int count = 0;
	while (cur)
	{
		cur = cur->pNext;
		count++;		
	}
	return count;
}

int Node::getPos(Node* &pHead, int pos)
{
	Node* cur = pHead;
	int n = Node::getLength(pHead);
	if (pos + 1 > n) 
		return -1;
	
	for (int i = 0; i < pos; i++)
		cur = cur->pNext;
	return cur->data;
}

void Node::addPos(Node* &pHead, int data, int pos)
{
	Node* newNode = new Node;
	newNode->data = data;
	
	if (pos == 0)
	{
		newNode->pNext = pHead;
		pHead = newNode;
		return;
	}
	
	Node* cur = pHead;
	for (int i = 0; i < pos - 1 && cur; i++)
	{
		cur = cur->pNext;
	}
	
	if (!cur) return;
	
	newNode->pNext = cur->pNext;
	cur->pNext = newNode;
}

void Node::setPos(Node* &pHead, int data, int pos)
{
	Node* cur = pHead;
	int n = Node::getLength(pHead);
	if (pos + 1 > n) return;
	
	for (int i = 0; i < pos; i++)
	{
		cur = cur->pNext;	
	}
	cur->data = data;
}
void Node::removePos(Node* &pHead, int pos)
{
	if(pHead == NULL)
		return;
	if (pos == 0)
	{
		Node* tmp = pHead;
		pHead = pHead->pNext;
		delete tmp;
		return;
	}
	
	Node* cur = pHead;
	int n = Node::getLength(pHead);
	if (pos + 1 > n) return;
	for (int i = 0; i < pos - 1; i++)
		cur = cur->pNext;
	Node* tmp = cur->pNext;
	cur->pNext = cur->pNext->pNext;
	delete tmp;
}

void Node::removeAll(Node* &pHead)
{
	Node* cur = pHead;
	Node* next = NULL;
	while (cur)
	{
		next = cur->pNext;
		delete cur;
		cur = next;
	}
	pHead = NULL;
}

/* HÀM CỦA BOARD2 */


// Constructor and Destructor

Board2::Board2(int _n_row, int _n_column, int _n_type)
{
	n_row = _n_row;
	n_column = _n_column;
	n_type = _n_type;
	
	_board2 = new Node * [n_row];
	for (int i = 0; i < n_row; i++)
		_board2[i] = NULL;
	Board2::initBoard(n_row, n_column, n_type);
	
}

Board2::~Board2()
{
	for (int i = 0; i < n_row; i++)
	{
		_board2[i]->removeAll(_board2[i]);
		delete _board2[i];		
	}
	delete [] _board2;
}

// Các hàm trả về giá trị

int Board2::getCell(int _x, int _y)
{
	return _board2[_x]->Node::getPos(_board2[_x], _y);
}

int Board2::getLengthInRow(int _x)
{
	return _board2[_x]->getLength(_board2[_x]);
}
// Các hàm thực thi


void Board2::removeCell(int _x, int _y)
{
	_board2[_x]->removePos(_board2[_x], _y);
}

void Board2::removeBoard(std::pair <int,int> start, std::pair <int,int> end)
{
	if (start.first == end.first)
		if (start.second < end.second)
			swap(start, end);
	Board2::removeCell(start.first, start.second);
	Board2::removeCell(end.first, end.second);
}

void Board2::initBoard(int _n_row, int _n_column, int _n_type)
{
	
	srand(unsigned(time(NULL)));
	
	// tạo 1 mảng đếm số lượng mỗi loại ký tự
	int *count = new int[_n_row];
	for (int i = 0; i < _n_row; i++)	
		count[i] = 0;
	
	
	int n_flag = _n_row * _n_column / 2;
	// lặp lại n_flag lần để đảm bảo luôn tồn tại 2 ô có ký tự giống nhau
	// mỗi lần lặp tạo 1 giá trị cho type và random vị trí 2 lần
	while (n_flag--)
	{
		int type = rand() % _n_type;
		int i, time = 2;
		while (time)
		{
			i = rand() % _n_row;
			
			if (count[i] != _n_column)
			{
				count[i]++;
				_board2[i]->addPos(_board2[i], type, 0);
				time--;
			}
		}
	}
	
	delete [] count;
}

void Board2::suffleBoard()
{
	// khởi tạo 1 mảng để lưu số lượng ký tự mỗi loại
	int *countType = new int [n_type];
	// khởi tạo 1 mảng để lưu số ký tự 1 dòng
	int *nPerRow = new int [n_row];


	for (int i = 0; i < n_row; i++)
		nPerRow[i] = Board2::getLengthInRow(i);
	
	for (int i = 0; i < n_type; i++)
		countType[i] = 0;
	
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < nPerRow[i]; j++)
		{
			countType[Board2::getCell(i, j)]++;
		}	
		_board2[i]->removeAll(_board2[i]);

	}
	
	
	
	srand(unsigned(time(NULL)));
	int i = 0;
	for (int type = 0; type < n_type; type++)
	{
		while (countType[type] != 0)
		{
			i = rand() % n_row;
			if (nPerRow[i] != 0)
			{
				_board2[i]->addPos(_board2[i], type, 0);
				nPerRow[i]--;
				countType[type]--;
			}
		}
	}
	
	
	delete []nPerRow;
	delete []countType;
}

void Board2::suggestBoard(std::pair <int,int> &start, std::pair <int,int> &end)
{
	// kiểm tra từng cặp 2 ô trong bảng, nếu 2 ô đó nối được với nhau thì trả về giá trị cho start end
	std::vector<std::pair<int,int>> path;
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_column; j++)
		{
			start = {i, j};
			if (Board2::getCell(i, j) == -1) 
				continue;
			else
			{
				for (int ii = 0; ii < n_row; ii++)
				{
					for (int jj = 0; jj < n_column; jj++)
					{
						end = {ii, jj};
						if (start == end) continue;
						if (Board2::canConnect(start, end, path))
							return;
					}
				}
			}
		}
	}
	return;	
}

// Hàm logic game
bool Board2::canConnect(std::pair<int,int> start, std::pair<int,int> end, std::vector<std::pair<int,int>> &path)
{
	if (start == end) return false;
	if (Board2::getCell(start.first, start.second) != Board2::getCell(end.first, end.second))
		return false;
		
	path = Board2::findPath(start, end);
	// do hàm path trả về các ô tại những lần đổi hướng và 2 đầu mút
	// do đó nếu số lượng của path là 2, 3, 4 thì 2 ô nối với nhau hợp lệ	
	if (2 <= path.size() && path.size() <= 4) return true;
	return false;
}

std::vector <std::pair<int,int>> Board2::findPath(std::pair<int,int> start, std::pair<int,int> end)
{
	// thảm khảo từ nguồn "https://codelearn.io/sharing/huong-dan-lam-game-bang-cocos2d-x-phan-2"

	// nâng tọa độ của start và end lên 1 do trong bảng mới các vị trí của mảng cũ tăng 1
	start.first += 1;
	start.second += 1;
	end.first += 1;
	end.second += 1;
	
	// khởi tạo mảng bao lên extra_board[n_row+2][n_column+2]
	int **extra_board = new int*[n_row + 2];
	for (int i = 0; i < n_row + 2; i++)
		extra_board[i] = new int [n_column + 2];
	for (int i = 0; i < n_row + 2; i++)
		for (int j = 0; j < n_column + 2;j++)	
			extra_board[i][j] = -1;
	for (int i = 0; i < n_row; i++)
		for (int j = 0; j < n_column;j++)
		{
			int type = Board2::getCell(i, j);
			if (type != -1)
				extra_board[i+1][j+1] = type;
		}
		
	// BFS
	// 2 mảng const thể hiện 4 hướng di chuyển trên bảng
	const int dx[4] = {-1, 0, 1, 0};
	const int dy[4] = {0, 1, 0, -1};
	


	// khởi tạo mảng backtrack đường đi
	std::pair<int,int> **trace = new std::pair<int,int> *[n_row + 2];
	for (int i = 0; i < n_row + 2; i++)
		trace[i] = new std::pair<int,int> [n_column + 2];
	for (int i = 0; i < n_row + 2; i++)
		for (int j = 0; j < n_column + 2;j++)
			trace[i][j] = {-1, -1};
			
	// Đặt giá trị ban đầu của start = {-2,-2} để đánh dấu vị trí bắt đầu tìm được đường đi khi quay ngược lại
	trace[start.first][start.second] = {-2, -2}; 

	// Cho 2 ô start và end có thể đi được
	extra_board[start.first][start.second] = -1;
	extra_board[end.first][end.second] = -1;

	std::deque<std::pair<int,int>> q;
	q.push_back(start);
	while(!q.empty())
	{
		std::pair<int,int> cur = q.front();
		q.pop_front();

		if (cur == end) break;// Nếu có đường đi tới ô end thì thoát vòng while

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			// nếu vị trí mới (nx, ny) nằm trong bảng extra_board và ô (nx, ny) có thể đi được thì lặp vòng while)
			while (0 <= nx && nx < n_row + 2 && 0 <= ny && ny < n_column + 2 && extra_board[nx][ny] == -1)
			{
				// nếu ô (nx, ny) chưa được đi tới thì tiếp tục
				if (trace[nx][ny].first == -1)
				{
					q.push_back({nx, ny});
					trace[nx][ny] = cur;
				}
				// tiếp tục đi tới theo cho tới khi không đi được nữa 
				nx += dx[i];
				ny += dy[i];
			}
		}
	}
	
	// Tìm đường đi
	std::pair<int,int> cur = end;
	std::vector<std::pair<int,int>> res;
	// nếu mà có đường đi tới end vì thực hiện
	if (trace[end.first][end.second].first != -1)
	{
		// thực hiện tới khi cur = start do start.first = -2;
		while (cur.first != -2) 
		{
			res.push_back({cur.first - 1, cur.second - 1});
			cur = trace[cur.first][cur.second];
		}
	}
	
	for (int i = 0; i < n_row + 2; i++)
	{
		delete [] extra_board[i];	
		delete [] trace[i];	
	}
	delete [] extra_board;
	delete [] trace;
	
	return res;
}

bool Board2::checkBoard()
{
	// kiểm tra từng cặp 2 ô xem nó có thể nối với nhau không 
	// nếu có thì trả về true
	std::vector<std::pair<int,int>> path;
	std::pair <int,int> start, end;
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_column; j++)
		{
			start = {i, j};
			if (Board2::getCell(i, j) == -1) 
				continue;
			else
			{
				for (int ii = 0; ii < n_row; ii++)
				{
					for (int jj = 0; jj < n_column; jj++)
					{
						end = {ii, jj};
						if (start == end) continue;
						if (Board2::canConnect(start, end, path))
							return true;
					}
				}
			}
		}
	}
	return false;
}


// hàm vẽ

void Board2::drawCells(int type, int y, int x){
    if(type == -1)
        return;
	
	int textcolor = type % 16;
	if(!textcolor) textcolor++;

    int RowCell = 5, ColCell = 11; // kích thước ô

    for(int i = 0; i < RowCell; i++)
        for(int j = 0; j < ColCell; j++){
            if((i == 0 || i == RowCell - 1) && j != 0 && j != ColCell -1){
                SettingGame::gotoXY(x * ColCell + j + left, y * RowCell + i + top);
                 putchar('-');
            }

            else if((j == 0 || j == ColCell - 1) && i != 0 && i != RowCell - 1){
                SettingGame::gotoXY(x * ColCell + j + left, y * RowCell + i + top);
				putchar('|');
            }
            else{
                SettingGame::gotoXY(x * ColCell + j + left, y * RowCell + i + top);
				putchar(' ');
            }
        }
    SettingGame::gotoXY(x * ColCell + ColCell / 2 + left, y * RowCell + RowCell / 2 + top);
    SettingGame::setColor(BLACK, textcolor);
	putchar(type + 32);
	SettingGame::setColor(BLACK, WHITE);
}

void Board2::drawBoard()
{
	for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_column; j++)
            drawCells(Board2::getCell(i, j), i, j);
    }
}

void Board2::drawLine(std::vector<std::pair<int,int>> path)
{
	int n = path.size();
	int RowCell = 5, ColCell = 11; // kích thước ô
	for (int i = 0; i < n - 1; i ++)
	{
		std::pair<int,int> start = path[i], end = path[i+1];
		// vẽ đường ngang
		if (start.first == end.first)
		{
			if (start.second > end.second)	
				swap(start, end);
			int dis2Cell = (end.second - start.second) * ColCell;
			for (int j = 1; j < dis2Cell; j+=2)
			{
				SettingGame::gotoXY(left + start.second * ColCell + (ColCell/2) + j, top + start.first * RowCell + (RowCell/2));
				SettingGame::setColor(BLACK, RED);
				putchar('*');
			}
		}
		// vẽ đường dọc
		else
		{
			if (start.first > end.first)
				swap(start, end);
				int dis2Cell = (end.first - start.first) * RowCell;
			for (int j = 1; j < dis2Cell; j++)
			{
				SettingGame::gotoXY(left + start.second * ColCell + (ColCell/2 ), top + start.first * RowCell + (RowCell/2) + j);
				SettingGame::setColor(BLACK, RED);
				putchar('*');		
			}
		}
	}
	SettingGame::setColor(BLACK, WHITE);
}