#include "application.h"
#include "chess.h"



application::application(){
  std::cout << "Welcome to the land of chess" << "\n";
}

void application :: run(){
  Board first;
	std::string yeep;
	char game = 'o';
	
	std::cout << "Enter a key to begin the game\n";
	std::cin >> yeep;

   
	while(game == 'o'){
		first.setBoard();
    while (first.playGame());
		std::cout << "Do you want to play again? (y for yes, anything else for no) press 'a' to review the moves ";
		std::cin >> yeep;

    if (yeep != "y")
			game = 'f';
	}
}
void application::test(){
  Board a;
  a.testPieces(1,2,4,5,R,WH);
}

application::~application(){}