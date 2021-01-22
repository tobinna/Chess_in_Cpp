
#include <stdlib.h>
#include "chess.h"


#include <iomanip>
#include <iostream>
#include <cmath>

void Board::setBoard()
{
  int numMoves = 0;
	square[0][0].piececolour(R, WH);
	square[1][0].piececolour(N, WH);
	square[2][0].piececolour(B, WH);
	square[3][0].piececolour(Q, WH);
	square[4][0].piececolour(K, WH);
	square[5][0].piececolour(B, WH);
	square[6][0].piececolour(N, WH);
	square[7][0].piececolour(R, WH);

	square[0][7].piececolour(R, BL);
	square[1][7].piececolour(N, BL);
	square[2][7].piececolour(B, BL);
	square[3][7].piececolour(Q, BL);
	square[4][7].piececolour(K, BL);
	square[5][7].piececolour(B, BL);
	square[6][7].piececolour(N, BL);
	square[7][7].piececolour(R, BL);

	for (int i = 0; i < 8; i++)
	{
		square[i][1].piececolour(P, WH);
		square[i][6].piececolour(P, BL);

	}
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			square[j][i].piececolour(E, NO);

	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			square[i][j].setX(i);
			square[i][j].setY(j);
		}

}

void Board::printBoard() {
	
	std::cout << "   0  1  2  3  4  5  6  7 \n";
  
	for (int i = 0; i < 8; i++)
	{
		std::cout << " " << i ;
		for (int j = 0; j < 8; j++)
		{
			Piece p = square[i][j].getPiece();
			Colour c = square[i][j].getColour();

			switch (p)
			{
			case K: 
        if (c==WH ){
          std::cout << " K " ;
          }
        else
          std::cout << " k ";
      	break;
			case Q: 
        if (c==WH ){
          std::cout << " Q " ;
          }
        else
          std::cout << " q ";
				break;
			case B:
      if (c==WH ){
          std::cout << " B " ;
          }
        else
          std::cout << " b ";
				break;
			case N:
      if (c==WH ){
          std::cout << " H " ;
          }
        else
          std::cout << " h ";
				break;
			case R: 
      if (c==WH ){
          std::cout << " R " ;
          }
        else
          std::cout << " r ";
				break;
			case P: 
      if (c==WH){
          std::cout << " P " ;
          }
        else
          std::cout << " p ";
				break;
			case E: 
      std::cout << "   ";
				break;
			default: 
      std::cout << "ERROR";
				break;
			}

		}
    std::cout << "\n";
    }
std::cout << "   0  1  2  3  4  5  6  7 \n";
}



bool Board::makeMove(int x1, int y1, int x2, int y2) {
	
	Square* start = getSquare(x1, y1);
	Square* end = getSquare(x2, y2);

	if (start->getColour() == end->getColour() && end->getColour() != NO)
	{
		std::cout << "Dont land on your own Piece!\n";
		return false;
	}
  
 
	switch (start->getPiece())
	{
	case K: 
  return moveKing(start, end);
		break;
	case Q: 
  return moveQueen(start, end);
		break;
	case B: 
  return moveBishop(start, end);
		break;
	case N: 
  return moveKnight(start, end);
		break;
	case R: 
  return moveRook(start, end);
		break;
	case P: 
  return movePawn(start, end);
		break;
	case E: 
  std::cout << "There is no Piece there\n";
  return false;
		break;
	default: 
  std::cout << "Something went wrong \n";
		break;
	}
  
  
  
	return false;
}



void Board::testread(std::string& a){
  
 
  try{
    int y1 = a[0] - 48;
		int x1 = a[1] - 48;
		int y2 = a[2] - 48;
		int x2 = a[3] - 48;
    if(a == "new"){
      throw('r');
    }
    
    else if(x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>8){
      throw(1);
    }
    
    
    else std::cout<<"The input has been tried\n";
    }
    catch(int){
      std::cout<< "These inputs are beyond the bounds or invalid, try again:\n";
      std::cin>> a;
      testread(a);
    }
    
    
    catch(char){
      std::cout<< "The game has been reset\n It is the White's turn\n";
      setBoard();
      printBoard();
      std::cout << "Enter your move:\n";
      turn = WH;
      std::cin>>a;
      testread(a);
    }
 
    
  }




bool Board::doMove() {
	
	std::string move;
	int x1, x2, y1, y2;
	bool stop = false;
	while (!stop)
	{
		if (turn == WH) {
      std::cout << "White's turn\n";
    }  
    else {
    std::cout << "Black's turn\n";
    }
		std::cout << "Type in your qo-ordinates (x1,y1 -> x2, y2) ie. (1222)\n";
    std::cout << "To reset the board, enter \"new\".\n"; 
    std::cout << "To quit the game, enter \"quit\".\n"; 
		std::cin >> move;
    
    

    testread(move);
    
  	y1 = move[0] - 48;
		x1 = move[1] - 48;
		y2 = move[2] - 48;
		x2 = move[3] - 48;

  
        
		if (getSquare(x1, y1)->getColour() == turn)
		{
			if (makeMove(x1, y1, x2, y2) == false)
			{
				std::cout << "This move is invalid\n.";
			}
			else{
        stop = true;
      }
		}
  
    
		else{
			std::cout << "Wrong player, try again.\n";
    }


	}
  
  addmoves(yeep);
  yeep++;
  

  	if (getSquare(x2, y2)->getPiece() == K){
		if (getSquare(x1, y1)->getColour() == WH)
		{
			std::cout << "WHITE WINS\n";
			return false;
		}
		else{
			std::cout << "BLACK WINS\n";
			return false;
		}
  }
	if (turn == BL)
		turn = WH;
	else{
		turn = BL;
  }
	return true;
  
}


bool Board::playGame()
{
	printBoard();
	return doMove();
}

bool Board::moveKing(Square* thisKing, Square* newSpace) 
{
		if (newSpace->getX() - thisKing->getX() == 1 || newSpace->getY() - thisKing->getY() == 1 || newSpace->getX() - thisKing->getX() == -1 || newSpace->getY() - thisKing->getY() == 1){
		
			newSpace->setSpace(thisKing);
			thisKing->setEmpty();
			return true;
		}
		else return false;
}
	

bool Board::moveQueen(Square* thisQueen, Square* thatSpace) 
{  
	int queenX = thisQueen->getX();
	int queenY = thisQueen->getY();
	int newX = thatSpace->getX();
	int newY = thatSpace->getY();
	
	int dx;
	int dy;

	bool invalid = false;
  if (queenX == newX) { 
        int dx = (queenY < newY) ? 1 : -1;

        for (int i = queenY + dx; i != newY; i += dx)
            if (square[queenX][i].getPiece() != E)
                return false;

    } else if (queenY == newY) { 
        int dy = (queenX < newX) ? 1 : -1;

        for (int i = queenX + dy; i != newX; i += dy)
            if (square[i][queenY].getPiece() != E)
                return false;
    } 
    //Bishop Rules
		
	if (invalid == false)
	{
		thatSpace->setSpace(thisQueen);
		thisQueen->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::moveBishop(Square* thisBishop, Square* newSpace) { 
	int bishopY = thisBishop->getX();
	int bishopX = thisBishop->getY();
	int newY = newSpace->getX();
	int newX = newSpace->getY();
  bool invalid = false;

  int movex = bishopX - newX;
  int movey = bishopY - newY;

  int dx = (bishopX - newX) / (abs(bishopX - newX));
  int dy =  (bishopY - newY) / (abs(bishopY - newY));

  // if (movex == movey || movex == -movey){


  //   for (int i = bishopY; i != newY; i += dy){
  //     for( int j = bishopX; i != newX; i += dx)
  //           if (square[i][j].getPiece() != E)
  //           std::cout<<"Cannot Hibbety hop1\n";
  //               return false;
  //       }
  // }
	
	
	if (invalid == false)
	{
		newSpace->setSpace(thisBishop);
		thisBishop->setEmpty();
		return true;
	}
	else
	{
    std::cout<<"nope";
		return false;
	}
}


bool Board::moveKnight(Square* thisKnight, Square* newSpace)
{
	
	int knightY = thisKnight->getX();
	int knightX = thisKnight->getY();
	int newY = newSpace->getX();
	int newX = newSpace->getY();

	if ((abs(knightX - newX) == 2 && abs(knightY - newY) == 1) || (abs(knightX - newX) == 1 && abs(knightY - newY) == 2))
	{
		newSpace->setSpace(thisKnight);
		thisKnight->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::moveRook(Square* thisRook, Square* newSpace)
{
	int rookY = thisRook->getX();
	int rookX = thisRook->getY();
	int newY = newSpace->getX();
	int newX = newSpace->getY();
	bool badmove = false;
  
	if (rookX == newX) { 
        int dx = (rookY < newY) ? 1 : -1;

        for (int i = rookY + dx; i != newY; i += dx){
            if (square[i][rookX].getPiece() != E)
            std::cout<<"cannot Hibbety hop1\n";
                return false;
        }
    } 
  else if (rookY == newY) { 
        int dy = (rookX < newX) ? 1 : -1;

        for (int i = rookX + dy; i != newX; i += dy)
            if (square[rookY][i].getPiece() != E){
            std::cout<<"cannot Hibbety hop\n";
                return false;
            }
  }
  else { 
      std::cout<< "Not valid\n";
        return false;
    }
    if (badmove == false)
	{
		newSpace->setSpace(thisRook);
		thisRook->setEmpty();
		return true;
	}
  else 
  return false;
}

bool Board::movePawn(Square* thisPawn, Square* newSpace) {
	using namespace std;
	bool invalid = false;
	int pawnY = thisPawn->getX();
	int pawnX = thisPawn->getY();
	int newY = newSpace->getX();
	int newX = newSpace->getY();


	if (thisPawn->getColour() == WH)
	{
    if (pawnY == newY && pawnX == 1 && newX - pawnX < 3 && newSpace->getColour() == NO){
      if(square[pawnY][2].getColour() != NO){
        cout << "You cannot jump over Pieces!\n";
        return false;
      }
      else
      newSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			return true;
     }

		if ((pawnY == newY && newX == pawnX + 1 && newSpace->getColour() == NO) || ((pawnY + 1 == newY || pawnY - 1 == newY) && pawnX + 1 == newX  && newSpace->getColour() == BL))
		{
			newSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			return true;
		}
	return false;
	}


	else
		if (thisPawn->getColour() == BL)
		{
    if (pawnY == newY && pawnX == 6 && pawnX - newX < 3 && newSpace->getColour() == NO){
      if(square[pawnY][5].getColour() != NO){
        cout << "You cannot jump over Pieces!\n";
        return false;
      }
      else
      newSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			return true;
    }
		if ((pawnY == newY && newX == pawnX - 1 && newSpace->getColour() == NO) || ((pawnY + 1 == newY || pawnY - 1 == newY) && pawnX - 1 == newX  && newSpace->getColour() == WH))
			{
				newSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
					return false;
		}
		else
			return false;
}

Square::Square()
{
	piece = E;
	colour = NO;
}

void Square::setSpace(Square* space)
{
	colour = space->getColour();
	piece = space->getPiece();
}

void Square::piececolour(Piece p, Colour c)
{
	piece = p;
	colour = c;

}

void Board:: addmoves(int a){
  node* temp = new node();
  temp-> data = a;
  temp -> next = NULL;

  if (head == NULL){
    head = temp;
    tail = temp;
  }
  else
    tail-> next = temp;
    tail = tail -> next;
}

void Board::printmoves(){
  node* temp = new node();
  temp = head;

  while(temp!=NULL){
    std::cout<<"this is the "<< temp->data<<"move\n";

  }
}


bool Board::testPieces(int x, int y, int move_x, int move_y, Piece testP, Colour testC) {

  for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			square[j][i].piececolour(E, NO);

	}
	switch(testP){
    case P:
    square[y][x].piececolour(P, testC);
    break;
    case K:
    square[y][x].piececolour(K, testC);
    break;
    case B:
    square[y][x].piececolour(B, testC);
    break;
    case N:
    square[y][x].piececolour(N, testC);
    break;
    case Q:
    square[y][x].piececolour(Q, testC);
    break;
    case R:
    square[y][x].piececolour(R, testC);
    break;
    default:
    std::cout<<"Error";
    break;
  }

  if (makeMove(9,9,9,9)!=false){
    return false;
  }
	
	return (true);
}




