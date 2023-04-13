#include "Custom.h"

//#include "Noob.h"

void CustomMode::CustomPlay(int row, int col, account& newAccount, int mode, int RemoveType){
	SettingGame::clearConsole();
	
	if(row * col < 2){
		std::cout << "You look like a Magikarp -_-";
		BG::drawBG(129);
		Sleep(5000);
		return;
	}
	int CompleteCells = 0;
	int Type = rand() % 152;
	if(!Type)
		Type++;
	
	Board A(row, col, 150);
	
	while(!A.checkBoard())
		A.suffleBoard();
		
	int Score = 0;
    int X = 0, Y = 0, oldX = 0, oldY = 0;
    if((row * col) % 2 == 1)
    	CompleteCells++;

    bool choose = false;
    int Xchoose, Ychoose;
	
	std::pair<int, int> p, q;
	p = {0, 0};
    q = {0, 0};
            	

    
    sound::start();
    
	SettingGame::setColor(BLACK, WHITE);
	BG::drawBG(Type);
    A.drawBoard(mode);
	
	SettingGame::setColor(BLACK, LIGHTYELLOW);
	SettingGame::gotoXY(150, 14);
	std::cout << "Hi, ";
	SettingGame::setColor(BLACK, YELLOW);
	std::cout << newAccount.Name;
	SettingGame::setColor(BLACK, LIGHTYELLOW);
	SettingGame::gotoXY(150, 16);
	std::cout << "Your score: " << Score;
	SettingGame::gotoXY(150, 18);
	std::cout << "Press 'F' to get suggestion";
	
	SettingGame::gotoXY(155, 20);
	std::cout << "(-500 points)";
	
	SettingGame::gotoXY(150, 22);
	std::cout << "Press 'R' to shuffe board";
	
	SettingGame::gotoXY(155, 24);
	std::cout << "(-400 points)";
	
    SettingGame::setColor(BLACK, GREEN);
    A.drawCells(A._board[0][0], 0, 0, mode);
    SettingGame::setColor(BLACK, WHITE);
    
    while(CompleteCells != row * col){
        switch(SettingGame::getConsoleInput()){
            case KEY_UP:{
            	sound::choose();
              	 while(true){
               		if(X == 0){
               			if(Y == 0){
               				X = row - 1;
               				Y = col - 1;
						   }
						else{
							X = row - 1;
							Y--;
						}
					}
					else 
						X--;
					
					if(A._board[X][Y] != -1)
						break;
			   }
               break;
            }

            case KEY_DOWN:{
            	sound::choose();
                while(true){
                	if(X == row - 1){
                		if(Y == col - 1){
                			X = 0;
                			Y = 0;
						}
						else{
							X = 0;
							Y++;
						}
					}
					else
						X++;
					
					if(A._board[X][Y] != -1)
						break;
				}
                break;
            }

            case KEY_LEFT:{
            	sound::choose();
                while(true){
                	if(Y == 0){
                		if(X == 0){
                			X = row - 1;
                			Y = col - 1;
						}
						else{
							X--;
							Y = col - 1;							
						}
					}
					else
						Y--;
                	
                	if(A._board[X][Y] != -1)
						break;
				}
                break;
            }

            case KEY_RIGHT:{
            	sound::choose();
                while(true){
					if(Y == col - 1){
						if(X == row - 1){
							X = 0;
							Y = 0;
						}
						else{
							X++;
							Y = 0;
						}
					}
					else
						Y++;
					
					if(A._board[X][Y] != -1)
						break;	
				}
                break;
            }

            case KEY_SPACE:{
                if(!choose && A._board[X][Y] != -1){
                	sound::choose();
                    Xchoose = X;
                    Ychoose = Y;
                    choose = true;

                }
                
                else if(choose && A._board[X][Y] != -1){
                    SettingGame::setColor(BLACK, RED);
                    A.drawCells(A._board[X][Y], X, Y, 1);
                    std::vector<std::pair<int,int>> Path;
                    
                    if((Xchoose != X || Ychoose != Y) && A.Board::canConnect(std::make_pair(X, Y), std::make_pair(Xchoose, Ychoose), Path)){
						sound::correct();
						CompleteCells += 2;
						Score += 200;
						if(!mode)
							Score += 200;
						if(RemoveType < 0 && 4 < RemoveType)
							Score += 100;
						A.drawLine(Path);
						Sleep(20);
						
						switch(RemoveType){
							case 0:{
								A.removeBoard_0({X, Y}, {Xchoose, Ychoose});
								break;
							}
							case 1:{
								A.removeBoard_1({X, Y}, {Xchoose, Ychoose});
								break;
							}
							case 2:{
								A.removeBoard_2({X, Y}, {Xchoose, Ychoose});
								break;
							}
							case 3:{
								A.removeBoard_3({X, Y}, {Xchoose, Ychoose});
								break;
							}
							case 4:{
								A.removeBoard_4({X, Y}, {Xchoose, Ychoose});
								break;
							}
							default:{
								int tmp = rand() % 5;
								switch(tmp){
									case 0:{
										A.removeBoard_0({X, Y}, {Xchoose, Ychoose});
										break;
									}
									case 1:{
										A.removeBoard_1({X, Y}, {Xchoose, Ychoose});
										break;
									}
									case 2:{
										A.removeBoard_2({X, Y}, {Xchoose, Ychoose});
										break;
									}
									case 3:{
										A.removeBoard_3({X, Y}, {Xchoose, Ychoose});
										break;
									}
									case 4:{
										A.removeBoard_4({X, Y}, {Xchoose, Ychoose});
										break;
									}
								}
								break;
							}    	
                   		}
                   		choose = false;
                    }
                    else{
                    	sound::wrong();
                    	
                        choose = false;
                    }
                    
                    while(CompleteCells != row * col && !A.checkBoard())
                    	A.suffleBoard();
                    	
                    SettingGame::setColor(BLACK, WHITE);
                    SettingGame::clearConsole();
                    SettingGame::setColor(BLACK, LIGHTYELLOW);
					SettingGame::gotoXY(150, 14);
					std::cout << "Hi, ";
					SettingGame::setColor(BLACK, YELLOW);
					std::cout << newAccount.Name;
					SettingGame::setColor(BLACK, LIGHTYELLOW);
					SettingGame::gotoXY(150, 16);
					std::cout << "Your score: " << Score;
					SettingGame::gotoXY(150, 18);
					std::cout << "Press 'F' to get suggestion";
					
					SettingGame::gotoXY(155, 20);
					std::cout << "(-500 points)";
					
					SettingGame::gotoXY(150, 22);
					std::cout << "Press 'R' to shuffe board";
					
					SettingGame::gotoXY(155, 24);
					std::cout << "(-400 points)";

                    SettingGame::setColor(BLACK, WHITE);
                    BG::drawBG(Type);
                    A.drawBoard(mode);
                    
                    
                    SettingGame::setColor(BLACK, WHITE);
                    A.drawCells(A._board[oldX][oldY], oldX, oldY, mode);
                    SettingGame::setColor(BLACK, GREEN);				// Ô đang tr
                    A.drawCells(A._board[X][Y], X, Y, 1);
                    oldX = X;
                    oldY = Y;
                }
                break;
            }

            case KEY_ESC:{
                return;
            }
            
            case KEY_SUGGEST:{
            	sound::choose();
            	A.Board::suggestBoard(p, q);
            	SettingGame::setColor(BLACK, YELLOW);
            	A.drawCells(A._board[p.first][p.second], p.first, p.second, 1);
            	SettingGame::setColor(BLACK, YELLOW);
				A.drawCells(A._board[q.first][q.second], q.first, q.second, 1);
				SettingGame::setColor(BLACK, WHITE);
				Score -= 500;
				SettingGame::setColor(BLACK, LIGHTYELLOW);
				SettingGame::gotoXY(150, 16);
				std::cout << "Your score: " << Score;
				SettingGame::setColor(BLACK, WHITE);
				break;
			}
			
			case KEY_SHUFFLE:{
				sound::choose();
				Score -= 300;
				SettingGame::setColor(BLACK, LIGHTYELLOW);
				SettingGame::gotoXY(150, 16);
				std::cout << "Your score: " << Score;
				SettingGame::setColor(BLACK, WHITE);
				A.Board::suffleBoard();
				A.drawBoard(mode);
				break;
			}
        }
		
        if(X != oldX || Y != oldY){
            SettingGame::setColor(BLACK, WHITE);
            SettingGame::setColor(BLACK, WHITE);
            A.drawBoard(mode);
            
            SettingGame::setColor(BLACK, WHITE);
            A.drawCells(A._board[oldX][oldY], oldX, oldY, mode);
            SettingGame::setColor(BLACK, GREEN);				// Ô đang trỏ vào
            A.drawCells(A._board[X][Y], X, Y, 1);
            oldX = X;
            oldY = Y;
        }

        if(choose){
            SettingGame::setColor(BLACK, RED);				// Ô đang được chọn
            A.drawCells(A._board[Xchoose][Ychoose], Xchoose, Ychoose, 1);
            SettingGame::setColor(BLACK, WHITE);
        }
        Sleep(50);
        
    }

    
    
    SettingGame::clearConsole();
    SettingGame::setColor(BLACK, LIGHTYELLOW);
    BG::drawBG(Type);
    Menu::printVictory(Score);
    sound::victory();
    newAccount.Score = Score;
    newAccount.Mode = 3;
    
    for(int i = 0; i < 152; i++)
    	newAccount.pokemon[i] = 0;
    newAccount.pokemon[Type]++;
	
	
	account a[100];
	int stt = 0;
	bool saved = 0;
    //	Truyen du lieu tu file
	std::ifstream ifs3("rank.txt", std::ios::in);
    while(!ifs3.eof()){
        ifs3 >> a[stt].Name;
        ifs3.ignore();
        ifs3 >> a[stt].Pass;
        ifs3.ignore();
        ifs3 >> a[stt].Mode;
        ifs3.ignore();
        ifs3 >> a[stt].Score;
        ifs3.ignore();
        for(int i = 0; i < 152; i++)
            ifs3 >> a[stt].pokemon[i];
        ifs3.ignore();
        stt++;
    }
    stt--;
    ifs3.close();
    
    for(int i = 0; i < stt; i++){
        if(strcmp(newAccount.Name, a[i].Name) == 0){
            saved = 1;
            a[i].pokemon[Type]++;
            if(newAccount.Score > a[i].Score){
                a[i].Mode = newAccount.Mode;
                a[i].Score = newAccount.Score;
            }
            break;
        }
    }
    if(!saved){
        a[stt] = newAccount;
        stt++;
    }
    
    for(int i = 0; i < stt - 1; i++)
		for(int j = i + 1; j < stt; j++)
			if(a[i].Score < a[j].Score){
					std::swap(a[i], a[j]);
			}
	
	std::ofstream ofs3("rank.txt", std::ios::out);
        for(int i = 0; i < stt; i++){
			ofs3 << a[i].Name << std::endl;
        	ofs3 << a[i].Pass << std::endl;
        	ofs3 << a[i].Mode << std::endl;
        	ofs3 << a[i].Score << std::endl;
        	for(int j = 0; j < 152; j++)
                ofs3 << a[i].pokemon[j] << " ";
            ofs3 << std::endl;
        }
	ofs3.close();

    SettingGame::clearConsole();

}