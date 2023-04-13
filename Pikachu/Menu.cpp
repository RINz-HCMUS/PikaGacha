#include "Menu.h"

const string Menu::optionMenu[5] = {"PLAY", "TUTORIAL", "LEADERBOARD", "ABOUT GAME", "EXIT"};

const string Menu::optionPlay[4] = {"NOOB", "PRO ", "CUSTOM", "BACK"};

const string Menu::optionCustom[4] = {"ROW", "COLUNM", "PLAY", "BACK"};

void Menu::printLOGIN(){
	SettingGame::clearConsole();
	SettingGame::setColor(BLACK, WHITE);
    cout << R"(
    
   /$$      /$$ /$$$$$$$$ /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$       /$$$$$$$$ /$$$$$$
  | $$  /$ | $$| $$_____/| $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/      |__  $$__//$$__  $$
  | $$ /$$$| $$| $$      | $$      | $$  \__/| $$  \ $$| $$$$  /$$$$| $$               | $$  | $$  \ $$
  | $$/$$ $$ $$| $$$$$   | $$      | $$      | $$  | $$| $$ $$/$$ $$| $$$$$            | $$  | $$  | $$
  | $$$$_  $$$$| $$__/   | $$      | $$      | $$  | $$| $$  $$$| $$| $$__/            | $$  | $$  | $$
  | $$$/ \  $$$| $$      | $$      | $$    $$| $$  | $$| $$\  $ | $$| $$               | $$  | $$  | $$
  | $$/   \  $$| $$$$$$$$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \/  | $$| $$$$$$$$         | $$  |  $$$$$$/
  |__/     \__/|________/|________/ \______/  \______/ |__/     |__/|________/         |__/   \______/
)" << std::endl;


	SettingGame::setColor(BLACK, YELLOW);
	cout << R"(
   /$$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$   /$$$$$$  /$$   /$$ /$$   /$$        /$$$$$$  /$$        /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$  /$$$$$$
  | $$__  $$|_  $$_/| $$  /$$/ /$$__  $$ /$$__  $$| $$  | $$| $$  | $$       /$$__  $$| $$       /$$__  $$ /$$__  $$ /$$__  $$|_  $$_/ /$$__  $$
  | $$  \ $$  | $$  | $$ /$$/ | $$  \ $$| $$  \__/| $$  | $$| $$  | $$      | $$  \__/| $$      | $$  \ $$| $$  \__/| $$  \__/  | $$  | $$  \__/
  | $$$$$$$/  | $$  | $$$$$/  | $$$$$$$$| $$      | $$$$$$$$| $$  | $$      | $$      | $$      | $$$$$$$$|  $$$$$$ |  $$$$$$   | $$  | $$
  | $$____/   | $$  | $$  $$  | $$__  $$| $$      | $$__  $$| $$  | $$      | $$      | $$      | $$__  $$ \____  $$ \____  $$  | $$  | $$
  | $$        | $$  | $$\  $$ | $$  | $$| $$    $$| $$  | $$| $$  | $$      | $$    $$| $$      | $$  | $$ /$$  \ $$ /$$  \ $$  | $$  | $$    $$
  | $$       /$$$$$$| $$ \  $$| $$  | $$|  $$$$$$/| $$  | $$|  $$$$$$/      |  $$$$$$/| $$$$$$$$| $$  | $$|  $$$$$$/|  $$$$$$/ /$$$$$$|  $$$$$$/
  |__/      |______/|__/  \__/|__/  |__/ \______/ |__/  |__/ \______/        \______/ |________/|__/  |__/ \______/  \______/ |______/ \______/
)" << std::endl;

	SettingGame::setColor(BLACK, LIGHTBLUE);
	
    cout << R"(

     _____ _____ _____ _   _   _____ _   _
    / ____|_   _/ ____| \ | | |_   _| \ | |
   | (___   | || |  __|  \| |   | | |  \| |
    \___ \  | || | |_ | . ` |   | | | . ` |
    ____) |_| || |__| | |\  |  _| |_| |\  |
   |_____/|_____\_____|_| \_|_|_____|_| \_|  _ _____
     ___     / ____|_   _/ ____| \ | | | |  | |  __ \
    ( _ )   | (___   | || |  __|  \| | | |  | | |__) |
    / _ \/\  \___ \  | || | |_ | . ` | | |  | |  ___/
   | (_>  <  ____) |_| || |__| | |\  | | |__| | |
    \___/\/ |_____/|_____\_____|_| \_|  \____/|_|
)" << endl;


	SettingGame::setColor(BLACK, BLUE);
	SettingGame::gotoXY(70, 26);
	std::cout << "USERNAME: ";
	
	SettingGame::gotoXY(70, 30);
	std::cout << "PASSWORD: ";

	
}

void Menu::printLogo(){
	SettingGame::clearConsole();

	SettingGame::setColor(BLACK, YELLOW);
	// pokemon 44x 5;
	std::cout << R"(

   /$$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$   /$$$$$$  /$$   /$$ /$$   /$$        /$$$$$$  /$$        /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$  /$$$$$$
  | $$__  $$|_  $$_/| $$  /$$/ /$$__  $$ /$$__  $$| $$  | $$| $$  | $$       /$$__  $$| $$       /$$__  $$ /$$__  $$ /$$__  $$|_  $$_/ /$$__  $$
  | $$  \ $$  | $$  | $$ /$$/ | $$  \ $$| $$  \__/| $$  | $$| $$  | $$      | $$  \__/| $$      | $$  \ $$| $$  \__/| $$  \__/  | $$  | $$  \__/
  | $$$$$$$/  | $$  | $$$$$/  | $$$$$$$$| $$      | $$$$$$$$| $$  | $$      | $$      | $$      | $$$$$$$$|  $$$$$$ |  $$$$$$   | $$  | $$
  | $$____/   | $$  | $$  $$  | $$__  $$| $$      | $$__  $$| $$  | $$      | $$      | $$      | $$__  $$ \____  $$ \____  $$  | $$  | $$
  | $$        | $$  | $$\  $$ | $$  | $$| $$    $$| $$  | $$| $$  | $$      | $$    $$| $$      | $$  | $$ /$$  \ $$ /$$  \ $$  | $$  | $$    $$
  | $$       /$$$$$$| $$ \  $$| $$  | $$|  $$$$$$/| $$  | $$|  $$$$$$/      |  $$$$$$/| $$$$$$$$| $$  | $$|  $$$$$$/|  $$$$$$/ /$$$$$$|  $$$$$$/
  |__/      |______/|__/  \__/|__/  |__/ \______/ |__/  |__/ \______/        \______/ |________/|__/  |__/ \______/  \______/ |______/ \______/	
	)";

}

void Menu::printLeaderBoard(account newAccount){

	int NoX = 5, NameX = 20, ModeX = 50, ScoreX = 70, PokeX = 90;  
	///
	
	int ranking = -1, num_pokedex[101];
	int noPokemon[152];
	for(int i = 0; i < 101; i++) num_pokedex[i] = 0;
	
	///
	
	account accountList[101];
	int stt = 0;
	
	std::ifstream fs;
	ifstream ifs("rank.txt", ios::in);
    while(!ifs.eof() && stt < 101){
        ifs >> accountList[stt].Name;
        ifs.ignore();
        ifs >> accountList[stt].Pass;
        ifs.ignore();
        ifs >> accountList[stt].Mode;
        ifs.ignore();
        ifs >> accountList[stt].Score;
        ifs.ignore();
        for(int i = 0; i < 152; i++){
        	ifs >> accountList[stt].pokemon[i];
        	if(accountList[stt].pokemon[i])
        		num_pokedex[stt]++;
        }
        ifs.ignore();
        stt++;
    }
    ifs.close();
	stt--;
	
	SettingGame::clearConsole();
	sound::leaderboard();
    SettingGame::setColor(BLACK, YELLOW);
	cout << R"(
   /$$       /$$$$$$$$  /$$$$$$  /$$$$$$$  /$$$$$$$$ /$$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$ 
  | $$      | $$_____/ /$$__  $$| $$__  $$| $$_____/| $$__  $$| $$__  $$ /$$__  $$ /$$__  $$| $$__  $$| $$__  $$
  | $$      | $$      | $$  \ $$| $$  \ $$| $$      | $$  \ $$| $$  \ $$| $$  \ $$| $$  \ $$| $$  \ $$| $$  \ $$
  | $$      | $$$$$   | $$$$$$$$| $$  | $$| $$$$$   | $$$$$$$/| $$$$$$$ | $$  | $$| $$$$$$$$| $$$$$$$/| $$  | $$
  | $$      | $$__/   | $$__  $$| $$  | $$| $$__/   | $$__  $$| $$__  $$| $$  | $$| $$__  $$| $$__  $$| $$  | $$
  | $$      | $$      | $$  | $$| $$  | $$| $$      | $$  \ $$| $$  \ $$| $$  | $$| $$  | $$| $$  \ $$| $$  | $$
  | $$$$$$$$| $$$$$$$$| $$  | $$| $$$$$$$/| $$$$$$$$| $$  | $$| $$$$$$$/|  $$$$$$/| $$  | $$| $$  | $$| $$$$$$$/
  |________/|________/|__/  |__/|_______/ |________/|__/  |__/|_______/  \______/ |__/  |__/|__/  |__/|_______/ 
               
			                                                                                                                                                                                                                                                                                                                                
	)";

    SettingGame::setColor(BLACK, WHITE);
    SettingGame::gotoXY(NoX, 12);
    std::cout << "No.";

	SettingGame::gotoXY(NameX, 12);
	std::cout << "NAME";

	SettingGame::gotoXY(ModeX, 12);
	std::cout << "MODE";

	SettingGame::gotoXY(ScoreX, 12);
	std::cout << "SCORE";
	
	SettingGame::gotoXY(PokeX, 12);
	std::cout << "Pokemon Collect";
	
	SettingGame::gotoXY(NoX, 33);
	std::cout << "YOUR RANK:";
	
	for(int i = 0; i < stt; i++){
		if(i < 11){
			SettingGame::gotoXY(ModeX, 14 + i * 2);
			switch(accountList[i].Mode){
				case 1:{
				    SettingGame::gotoXY(ModeX, 14 + i * 2);
					SettingGame::setColor(BLACK, WHITE);
					std::cout << "NOOB";
					break;
				}
				case 2:{
				    SettingGame::gotoXY(ModeX, 14 + i * 2);
					SettingGame::setColor(BLACK, YELLOW);
					std::cout << "PRO";
					break;
				}
				case 3:{
					SettingGame::setColor(BLACK, RED);
					SettingGame::gotoXY(ModeX, 14 + i * 2);
					std::cout << "CUSTOM";
					break;
				}
			}
	        SettingGame::gotoXY(NoX , 14 + i * 2);
	        std::cout << (i + 1);
	
			SettingGame::gotoXY(NameX, 14 + i * 2);
			std::cout << accountList[i].Name;
	
			SettingGame::gotoXY(ScoreX, 14 + i * 2);
			std::cout << accountList[i].Score;
			
			SettingGame::gotoXY(PokeX + 7, 14 + i * 2);
			std::cout << num_pokedex[i];
		}
		
		if(strcmp(newAccount.Name, accountList[i].Name) == 0)
			ranking = i;
			
	}
	
	if(ranking != -1){
			switch(accountList[ranking].Mode){
				case 1:{
					SettingGame::setColor(BLACK, WHITE);
					break;
				}
				case 2:{
					SettingGame::setColor(BLACK, YELLOW);
					break;
				}
				case 3:{
					SettingGame::setColor(BLACK, RED);
					break;
				}
			}
									
			SettingGame::gotoXY(NoX , 35);
	        std::cout << (ranking + 1);
	
			SettingGame::gotoXY(NameX, 35);
			std::cout << accountList[ranking].Name;
	
			SettingGame::gotoXY(ScoreX, 35);
			std::cout << accountList[ranking].Score;
			
			SettingGame::gotoXY(PokeX + 7, 35);
			std::cout << num_pokedex[ranking];
	}
	
	else{
			SettingGame::gotoXY(NoX , 35);
	        std::cout << "UNRANKED";
	
			SettingGame::gotoXY(NameX, 35);
			std::cout << newAccount.Name;
	
			SettingGame::gotoXY(ScoreX, 35);
			std::cout << 0;
			
			SettingGame::gotoXY(PokeX + 7, 35);
			std::cout << 0;	
			
			for(int i = 0; i < 152; i++)
				noPokemon[i] = 0;
	}
	SettingGame::setColor(BLACK, WHITE);
	SettingGame::gotoXY(15, 40);
	std::cout << "Press ENTER to view your Pokedex.";
    SettingGame::gotoXY(60, 40);
	std::cout << "Press ESC to back.";
	while(true)
	switch(SettingGame::getConsoleInput()){
		case KEY_ESC:{
			return;
		}
		case KEY_SPACE:{
			if(ranking != -1)
				Menu::printPokedex(num_pokedex[ranking], accountList[ranking].pokemon);
			else
				Menu::printPokedex(0, noPokemon);
			sound::leaderboard();
			break;
		}
	}
}

void Menu::printPokedex(int num, int pokedex[]){
	sound::pokedexTheme();
	SettingGame::setColor(BLACK, WHITE);
	
	int i = 1;
	string name[152] = {"", "Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard", "Squirtle", "Wartortle", "Blastoise", "Caterpie", "Metapod", 
							"Butterfree", "Weedle", "Kakuna", "Beedrill", "Pidgey", "Pidgeotto", "Pidgeot", "Rattata", "Raticate", "Spearow", "Fearow", "Ekans", "Arbok",
							"Pikachu", "Raichu", "Sandshrew", "Sandslash", "NidoranΓÖÇ", "Nidorina", "Nidoqueen", "NidoranΓÖé", "Nidorino", "Nidoking", "Clefairy", 
							"Clefable", "Vulpix", "Ninetales", "Jigglypuff", "Wigglytuff", "Zubat", "Golbat", "Oddish", "Gloom", "Vileplume", "Paras", "Parasect", 
							"Venonat", "Venomoth", "Diglett", "Dugtrio", "Meowth", "Persian", "Psyduck", "Golduck", "Mankey", "Primeape", "Growlithe", "Arcanine", 
							"Poliwag", "Poliwhirl", "Poliwrath", "Abra", "Kadabra", "Alakazam", "Machop", "Machoke", "Machamp", "Bellsprout", "Weepinbell", "Victreebel",
							"Tentacool", "Tentacruel", "Geodude", "Graveler", "Golem", "Ponyta", "Rapidash", "Slowpoke", "Slowbro", "Magnemite", "Magneton", "Farfetch'd",
							"Doduo", "Dodrio", "Seel", "Dewgong", "Grimer", "Muk", "Shellder", "Cloyster", "Gastly", "Haunter", "Gengar", "Onix", "Drowzee", "Hypno", 
							"Krabby", "Kingler", "Voltorb", "Electrode", "Exeggcute", "Exeggutor", "Cubone", "Marowak", "Hitmonlee", "Hitmonchan", "Lickitung", "Koffing",
							"Weezing", "Rhyhorn", "Rhydon", "Chansey", "Tangela", "Kangaskhan", "Horsea", "Seadra", "Goldeen", "Seaking", "Staryu", "Starmie", "Mr.Mime",
						    "Scyther", "Jynx", "Electabuzz", "Magmar", "Pinsir", "Tauros", "Magikarp", "Gyarados", "Lapras", "Ditto", "Eevee", "Vaporeon", 
							"Jolteon", "Flareon", "Porygon", "Omanyte", "Omastar", "Kabuto", "Kabutops", "Aerodactyl", "Snorlax", "Articuno", "Zapdos", "Moltres", 
							"Dratini", "Dragonair", "Dragonite", "Mewtwo", "Mew"};
							 
	while(true){
		if(i == 144 && pokedex[i] == 1){
			SettingGame::clearConsole();
			SettingGame::setColor(BLACK, LIGHTYELLOW);
			SettingGame::gotoXY(130, 30);
			std::cout << "You have ";
			SettingGame::setColor(BLACK, RED);
			std::cout << num;
			SettingGame::setColor(BLACK, LIGHTYELLOW);
			std::cout << " pokemons / 151 pokemons.";
			SettingGame::gotoXY(130, 32);
			SettingGame::setColor(BLACK, LIGHTAQUA);
			std:: cout << "Pokemon #" << i << ": " << name[i];	
		}
		else{
			SettingGame::clearConsole();
			SettingGame::setColor(BLACK, LIGHTYELLOW);
			SettingGame::gotoXY(5, 4);
			std::cout << "You have ";
			SettingGame::setColor(BLACK, RED);
			std::cout << num;
			SettingGame::setColor(BLACK, LIGHTYELLOW);
			std::cout << " pokemons / 151 pokemons.";
			SettingGame::gotoXY(5, 5);
			SettingGame::setColor(BLACK, LIGHTAQUA);
			std:: cout << "Pokemon #" << i << ": " << name[i];
		}
		SettingGame::setColor(BLACK, WHITE);	
		if(pokedex[i])
			BG::drawBG(i);
		else
			Menu::printNotOwned();
			
		switch(SettingGame::getConsoleInput()){
			case KEY_RIGHT:{
				i++;
				break;
			}
			case KEY_LEFT:{
				i--;
				break;
			}
			case KEY_ESC:{
				return;
			}
			
		}
		
		if(i == 152)
			i = 1;
		else if(i == 0)
			i = 151;
	}
	
}

void Menu::printNotOwned(){
	SettingGame::setColor(BLACK, WHITE);
	std::cout << R"(
					
					
					
					
					
					  _.--,-```-.      _.--,-```-.      _.--,-```-.    
					 /    /      '.   /    /      '.   /    /      '.  
					/  ../         ; /  ../         ; /  ../         ; 
					\  ``\  .``-    '\  ``\  .``-    '\  ``\  .``-    '
					 \ ___\/    \   : \ ___\/    \   : \ ___\/    \   :
					       \    :   |       \    :   |       \    :   |
					       |    ;  .        |    ;  .        |    ;  . 
					      ;   ;   :        ;   ;   :        ;   ;   :  
					     /   :   :        /   :   :        /   :   :   
					     `---'.  |        `---'.  |        `---'.  |   
					      `--..`;          `--..`;          `--..`;    
					    .--,_            .--,_            .--,_        
					    |    |`.         |    |`.         |    |`.     
					    `-- -`, ;        `-- -`, ;        `-- -`, ;    
					      '---`"           '---`"           '---`"     					                                                   
	)";
}

void Menu::printAboutGame(){
	SettingGame::clearConsole();

	    std::cout << R"(
    /$$$$$$  /$$$$$$$   /$$$$$$  /$$   /$$ /$$$$$$$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$
   /$$__  $$| $$__  $$ /$$__  $$| $$  | $$|__  $$__/       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/
  | $$  \ $$| $$  \ $$| $$  \ $$| $$  | $$   | $$         | $$  \__/| $$  \ $$| $$$$  /$$$$| $$
  | $$$$$$$$| $$$$$$$ | $$  | $$| $$  | $$   | $$         | $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$
  | $$__  $$| $$__  $$| $$  | $$| $$  | $$   | $$         | $$|_  $$| $$__  $$| $$  $$$| $$| $$__/
  | $$  | $$| $$  \ $$| $$  | $$| $$  | $$   | $$         | $$  \ $$| $$  | $$| $$\  $ | $$| $$
  | $$  | $$| $$$$$$$/|  $$$$$$/|  $$$$$$/   | $$         |  $$$$$$/| $$  | $$| $$ \/  | $$| $$$$$$$$
  |__/  |__/|_______/  \______/  \______/    |__/          \______/ |__/  |__/|__/     |__/|________/


    PIKACHU CLASSIC is inspired by the classic Pikachu game combined with new and attractive features such as CUSTOM MODE and POKEDEX.

    	CUSTOM MODE allows you to customize the parameters of the game screen such as board size, board linkage, and new and unique stealth mode!

    	POKEDEX is not just a classic Pikachu game, now you can capture Pokemon in your gameplay! Use your luck and skills to catch all 151 Pokemon!

	
	  /_\  _   _| |_| |__   ___  _ __  (_)_ __  / _| ___  _ __ _ __ ___   __ _| |_(_) ___  _ __
	 //_\\| | | | __| '_ \ / _ \| '__| | | '_ \| |_ / _ \| '__| '_ ` _ \ / _` | __| |/ _ \| '_ \
	/  _  \ |_| | |_| | | | (_) | |    | | | | |  _| (_) | |  | | | | | | (_| | |_| | (_) | | | |
	\_/ \_/\__,_|\__|_| |_|\___/|_|    |_|_| |_|_|  \___/|_|  |_| |_| |_|\__,_|\__|_|\___/|_| |_|

			Vo Huu Tuan  22127439
			Ho Minh Dang 22127050
        
		Game belongs to the Programming Techniques project | HCMUS

     )";
	while(SettingGame::getConsoleInput() != KEY_ESC);
}

void Menu::printButton(int _x, int _y, int Cells, int type, COORD Pos){
	SettingGame::setColor(BLACK, WHITE);
	for(int manyCells = 0; manyCells < Cells; manyCells++){
		for(int i = 0; i < 5; i++){
			_y ++;
			if(_y == Pos.Y)
				SettingGame::setColor(WHITE, BLACK);

			int tmp = _x - 1;
			for(int j = 0; j < 21; j++){
				tmp++;
				SettingGame::gotoXY(tmp, _y);
				if(i == 0 || i == 4 || j == 0 || j == 20)
//					std::cout << "*";
					putchar('*');
				else
//					std::cout << " ";
					putchar(' ');
			}
			if(i == 2 ){
				if(type == 1){
					SettingGame::gotoXY(_x + 11 - optionMenu[manyCells].size() / 2, _y);
					std::cout << optionMenu[manyCells];
				}
				else if(type == 2){
					SettingGame::gotoXY(_x + 11 - optionPlay[manyCells].size() / 2, _y);
					std::cout << optionPlay[manyCells];
				}
				else if(type == 3){
					SettingGame::gotoXY(_x + 11 - optionCustom[manyCells].size() / 2, _y);
					std::cout << optionPlay[manyCells];
				}
			}
		}
		SettingGame::setColor(BLACK, WHITE);
		_y++;
	}
}

void Menu::printMenu(account& newAccount){
	SettingGame::clearConsole();
	int Row = 21, Col = 12; // kích thước ô
	short _x = 66 - Row / 2, _y = 20 - Col / 2;
	//Kẻ ô
	COORD Pos = {56, 15};
	COORD oldPos = {0, 0};
	sound::theme();
	while(true){
		if(oldPos.X != Pos.X || oldPos.Y != Pos.Y){
			SettingGame::clearConsole();
			Menu::printLogo();
			Menu::printButton(_x, _y, 5, 1, Pos);
		}
		else
			oldPos = Pos;

		switch(SettingGame::getConsoleInput()){
			case KEY_UP:{
				if(0 <= Pos.Y - 1)
					Pos.Y = max(15, Pos.Y - 6);
				break;
			}
			case KEY_DOWN:{
					Pos.Y = min(Pos.Y + 6, 39);
				break;
			}

			case KEY_SPACE:{
				if(Pos.Y == 0) break;
				SettingGame::clearConsole();
					switch(Pos.Y){
						case 15:{
							Menu::printGameMode(newAccount);
							sound::theme();
							break;
						}
						case 21:{
							Menu::printTutorial();
							break;
						}
						case 27:{
							Menu::printLeaderBoard(newAccount);
							sound::theme();
							break;
						}
						case 33:{
							Menu::printAboutGame();
							break;
						}
						case 39:{
							exit(0);
						}
					}

				break;
			}
			default:
				break;
		}
	Menu::Slow();
	}
}

void Menu::printTutorial(){
	SettingGame::setColor(BLACK, LIGHTAQUA);
	
    std::cout << R"(
   /$$$$$$$$ /$$   /$$ /$$$$$$$$ /$$$$$$  /$$$$$$$  /$$$$$$  /$$$$$$  /$$
  |__  $$__/| $$  | $$|__  $$__//$$__  $$| $$__  $$|_  $$_/ /$$__  $$| $$
     | $$   | $$  | $$   | $$  | $$  \ $$| $$  \ $$  | $$  | $$  \ $$| $$
     | $$   | $$  | $$   | $$  | $$  | $$| $$$$$$$/  | $$  | $$$$$$$$| $$
     | $$   | $$  | $$   | $$  | $$  | $$| $$__  $$  | $$  | $$__  $$| $$
     | $$   | $$  | $$   | $$  | $$  | $$| $$  \ $$  | $$  | $$  | $$| $$
     | $$   |  $$$$$$/   | $$  |  $$$$$$/| $$  | $$ /$$$$$$| $$  | $$| $$$$$$$$
     |__/    \______/    |__/   \______/ |__/  |__/|______/|__/  |__/|________/

	)";
	
	SettingGame::setColor(BLACK, YELLOW);
	
    std::cout << R"(
	   _                                    
	  (_)_ __     __ _  __ _ _ __ ___   ___ 
	  | | '_ \   / _` |/ _` | '_ ` _ \ / _ \
	  | | | | | | (_| | (_| | | | | | |  __/
	  |_|_| |_|  \__, |\__,_|_| |_| |_|\___|
	             |___/                     
	)";
	
	SettingGame::setColor(BLACK, WHITE);
	
    std::cout << R"(
	        
		Use the UP/LEFT/DOWN/RIGHT arrow keys  or WASD to move.
        
		Use the SPACE or ENTER key to select.
        
		Use the F key for a hint. However, it will deduct some points.
        
		Use the R key to shuffle the board. However, it will deduct some points.
        
		Use the ESC key to exit or back.
	)";
	
	SettingGame::setColor(BLACK, YELLOW);
	
    std::cout << R"(
	   _                     _            _           
	  (_)_ __    _ __   ___ | | _____  __| | _____  __
	  | | '_ \  | '_ \ / _ \| |/ / _ \/ _` |/ _ \ \/ /
	  | | | | | | |_) | (_) |   <  __/ (_| |  __/>  < 
	  |_|_| |_| | .__/ \___/|_|\_\___|\__,_|\___/_/\_\
	            |_|                     
	)";
	SettingGame::setColor(BLACK, WHITE);
	
    std::cout << R"(		
	
		Use the LEFT/RIGHT arrow keys to switch to another Pokemon.
		
		Use the ESC key to exit.	             
     )";


	while(SettingGame::getConsoleInput() != KEY_ESC);
}

void Menu::printGameMode(account& newAccount){
	COORD Pos = {56, 15};
	COORD oldPos = {0, 0};
	int Row = 21, Col = 12;
	short _x = 66 - Row / 2, _y = 20 - Col / 2;

	SettingGame::clearConsole();
	Menu::printLogo();
	Menu::printButton(_x, _y, 4, 2, Pos);
	bool out = false;
	while(!out){
		if(oldPos.X != Pos.X || oldPos.Y != Pos.Y){
			SettingGame::clearConsole();
			Menu::printLogo();
			Menu::printButton(_x, _y, 4, 2, Pos);
		}
		else
			oldPos = Pos;

		switch(SettingGame::getConsoleInput()){
//			sound::choose();
			case KEY_UP:{
				Pos.Y = max(15, Pos.Y - 6);
				break;
			}

			case KEY_DOWN:{
				Pos.Y = min(Pos.Y + 6, 33);
				break;
			}

			case KEY_SPACE:{
				if(Pos.Y == 0) break;
				SettingGame::clearConsole();
					switch(Pos.Y){
						case 15:{
							newAccount.Mode = 1;
							NoobMode::NoobPlay(newAccount);
							sound::theme();
							break;
						}
						case 21:{
							newAccount.Mode = 2;
							ProMode::ProPlay(newAccount);
							sound::theme();
							break;
						}
						case 27:{
//							Menu::printCustomMode();
							int row, col, mode, RemoveType;
							std::cout << "Input Row (Max = 7):  ";
							cin >> row;
							std::cout << "Input Col (Max = 12): ";
							cin >> col;
							std::cout << "Hidden mode (1: Yes / 0: NO)\n";
							cin >> mode;
							std::cout 	<< "Removal method:\n"
									  	<< "0. Normal\n"
										<< "1. Slide to the left\n"
										<< "2. Slide up\n"
										<< "3. Slide to the right\n"
										<< "4. Slide down\n"
										<< "Others: Random\n"
										<< "Your choice: ";
							std::cin >> RemoveType;
							newAccount.Mode = 3;
							CustomMode::CustomPlay(row, col, newAccount, !mode, RemoveType);
							sound::theme();
							break;
						}
						case 33:{
							out = true;
							break;
						}
					}
//
//				break;
			}
			default:
				break;
		}
		
	
	}
}

void Menu::printVictory(int score){	
	SettingGame::setColor(BLACK, YELLOW);
    SettingGame::gotoXY(60, 8);
    std::cout << R"(
    
    
    
    
											 /$$    /$$ /$$$$$$  /$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$$  /$$     /$$
											| $$   | $$|_  $$_/ /$$__  $$|__  $$__//$$__  $$| $$__  $$|  $$   /$$/
											| $$   | $$  | $$  | $$  \__/   | $$  | $$  \ $$| $$  \ $$ \  $$ /$$/
											|  $$ / $$/  | $$  | $$         | $$  | $$  | $$| $$$$$$$/  \  $$$$/
											 \  $$ $$/   | $$  | $$         | $$  | $$  | $$| $$__  $$   \  $$/
											  \  $$$/    | $$  | $$    $$   | $$  | $$  | $$| $$  \ $$    | $$
											   \  $/    /$$$$$$|  $$$$$$/   | $$  |  $$$$$$/| $$  | $$    | $$
											    \_/    |______/ \______/    |__/   \______/ |__/  |__/    |__/

	)" << "\n";
	
	SettingGame::gotoXY(110, 27);
	SettingGame::setColor(BLACK, YELLOW);
	std::cout << "YOUR SCORE: " << score;
}

void Menu::Slow(){
	Sleep(100);
}

void Menu::Exit(){
	exit(0);
}
