#include <fstream>
#include "SettingGame.h"
#include "Board2.h"
#include "Menu.h"

int main()
{
	SettingGame::setUpConsole();
	Menu MainMenu;
	
	//	Khoi tao
	account newAccount; // account đang đăng nhập
	account a[100];	// danh sách account đã tạo
	int stt = 0;	// số lượng account đã tạo
    int loginComplete = 0;	// trạng thái đăng nhập  0: đăng kí / 1: đăng nhập thành công / 2: đăng nhập lại

    //	Truyen du lieu tu file
	std::ifstream ifs("rank.txt", std::ios::in);
    while(!ifs.eof()){
        ifs >> a[stt].Name;
        ifs.ignore();
        ifs >> a[stt].Pass;
        ifs.ignore();
        ifs >> a[stt].Mode;
        ifs.ignore();
        ifs >> a[stt].Score;
        ifs.ignore();
        for(int i = 0; i < 152; i++)
            ifs >> a[stt].pokemon[i];
        ifs.ignore();
        stt++;
    }
    stt--;
    ifs.close();
    
	//xử lý đăng nhập	
	while(loginComplete != 1){
		loginComplete = 0;
		MainMenu.printLOGIN();
		SettingGame::setCursorInput(1); // Bật hiển thị con trỏ
		
		string s = "";
		
		// The first time
		SettingGame::setColor(BLACK, RED);
		SettingGame::gotoXY(85, 24);
		std::cout << "Input Name";
	
		SettingGame::setColor(BLACK, WHITE);
		SettingGame::gotoXY(85, 26);
		std::cin >> s;
	
		SettingGame::setColor(BLACK, BLACK);
		SettingGame::gotoXY(85, 24);
		std::cout << "          ";
		
		// xử lý username không hợp lệ
	    while(s.size() > 15 || s == ""){
	        SettingGame::clearConsole();
	        MainMenu.printLOGIN();
	        SettingGame::setColor(BLACK, RED);
	        SettingGame::gotoXY(85, 24);
			cout << "The account name must not be empty and must not exceed 15 English characters.";
			SettingGame::gotoXY(85, 26);
			SettingGame::setColor(BLACK, BLACK);
			for(int i = 0; i < s.size(); i++)
				putchar(' ');			
			SettingGame::gotoXY(85, 26);
			SettingGame::setColor(BLACK, WHITE);
		    cin.ignore();
			cin >> s;
	    }
	    
		SettingGame::setColor(BLACK, BLACK);
	    SettingGame::gotoXY(85, 24);
		cout << "                                                                              ";
		
		strcpy(newAccount.Name, s.c_str());
		
		
		SettingGame::setColor(BLACK, RED); 
	    SettingGame::gotoXY(85, 24);
		std::cout << "Input Pass";
		SettingGame::gotoXY(85, 30);
		SettingGame::setColor(BLACK, WHITE);
	    cin.ignore();
		cin >> s;
		SettingGame::setColor(BLACK, BLACK);
		SettingGame::gotoXY(85, 24);
		std::cout << "          ";
		
		// xử lý password không hợp lệ
		while(s.size() > 15 || s == ""){
	        SettingGame::clearConsole();
	        MainMenu.printLOGIN();
	        SettingGame::setColor(BLACK, RED);
	        SettingGame::gotoXY(85, 24);
	        cout << "The account password must not be empty and must not exceed 15 character.";
	    	SettingGame::gotoXY(85, 30);
			SettingGame::setColor(BLACK, BLACK);
			for(int i = 0; i < s.size(); i++)
				putchar(' ');
	        
			SettingGame::setColor(BLACK, WHITE); 
	        SettingGame::gotoXY(85, 30);
	        cin.ignore();
			cin >> s;
	    }
	    
	    SettingGame::setColor(BLACK, BLACK);
	    SettingGame::gotoXY(85, 24);
		cout << "                                                                         ";
	    strcpy(newAccount.Pass, s.c_str());    
	    
	    // kiểm tra xem account đã được tạo chưa
		for(int i = 0; i < stt; i++){
			if(loginComplete == 1)
				break;
			// Neu tai khoan ton tai
	        if(strcmp(a[i].Name, newAccount.Name) == 0){
	        	// check password
	            if(strcmp(a[i].Pass, newAccount.Pass) == 0){
				SettingGame::setColor(BLACK, RED);
	            SettingGame::gotoXY(85, 24);
					cout << "LOGIN COMPLETE!";
					loginComplete = 1;
	            }
	
	            else{
	                int tmp = 3;
	                while(tmp){
						SettingGame::setColor(BLACK, RED);
	           			SettingGame::gotoXY(85, 24);
						cout << "Wrong password. Try agian." << tmp << " times left.\n";
						SettingGame::gotoXY(85, 30);
						SettingGame::setColor(BLACK, BLACK);
						for(int i = 0; i < s.size(); i++)
							putchar(' ');
							
						SettingGame::setColor(BLACK, WHITE);
	                    SettingGame::gotoXY(85, 30);
						cin.ignore();
	                    cin >> s;
	                    if(strcmp(a[i].Pass, s.c_str()) == 0){
	                    	strcpy(newAccount.Pass, a[i].Pass);
							break; 
						}
	                     else
	                        tmp--;
	                }
	                if(tmp == 0){
	                    SettingGame::setColor(BLACK, BLACK);
	    	    		SettingGame::gotoXY(85, 24);
						cout << "   				                             		";
						SettingGame::setColor(BLACK, RED);
	           			SettingGame::gotoXY(85, 24);
						cout << "You have entered the wrong password too many times!";
	                    loginComplete = 2;
	                }
	                else{
					
		                SettingGame::setColor(BLACK, BLACK);
	    		    	SettingGame::gotoXY(85, 24);
						cout << "   		                         				";
						SettingGame::setColor(BLACK, RED);
	           			SettingGame::gotoXY(85, 24);
	            	    cout << "LOGIN COMPLETE!";
	                	loginComplete = 1;
	                }
	            }
	        }
	    }
	    
	    // Đăng ký
	    if(loginComplete == 0){
	    SettingGame::setColor(BLACK, RED);
		SettingGame::gotoXY(75, 24);	
	    cout << "Don't have this accound. Do you want sign in it? (1: YES / 0: NO)\n";
	    SettingGame::setColor(BLACK, WHITE);
		SettingGame::gotoXY(75, 25);
		cin >> s;
		
		while(true)
	        if(s == "YES" || s == "1"){
	        	SettingGame::gotoXY(75, 25);
	            cout << "Your account was created! Have fun.";
				loginComplete = 1;
				newAccount.Mode = 0;
				newAccount.Score = 0;
	        	Sleep(500);
	            break;
	        }
	        
	        else if(s == "NO" || s == "0"){
	        	SettingGame::gotoXY(75, 25);
	            cout << "Please login again!";
	            Sleep(500);
	            break;
	        }
	        else{
				MainMenu.printLOGIN();
				SettingGame::setColor(BLACK, WHITE);
	        	SettingGame::gotoXY(85, 26);
	        	cout << newAccount.Name;
				
				SettingGame::gotoXY(85, 30);
	        	cout << newAccount.Pass;
	
	   			SettingGame::setColor(BLACK, RED);
				SettingGame::gotoXY(75, 24);	
	    		cout << "Don't have this accound. Do you want sign in it? (1: YES / 0: NO)\n";       	
	    		
	        	SettingGame::gotoXY(75, 25);
	            cin >> s;
	        }
	  	}
	}
	SettingGame::setCursorInput(0); // Tắt  hiển thị con trỏ
	// Bắt đầu game
	while(true)
		MainMenu.printMenu(newAccount);
}
