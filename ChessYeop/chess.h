#pragma once
#include "node.h"

#include <iostream>
#include <cmath>
#include <string>

enum Piece {K = 0, Q, B, N, R, P, E};
enum Colour {WH = 0 , BL, NO};

class Square
{
	
	Piece piece;
	Colour colour;
	int x, y;
  Square *next;
public:
  
	void setSpace(Square*);
	void setEmpty(){
	colour = NO;
	piece = E;
}

	void piececolour(Piece, Colour);
	Piece getPiece(){
    return piece;
  }
	Colour getColour(){
	return colour;
}
	void setX(int X){
     x = X; 
    }
	void setY(int Y){
     y = Y;
    }
	int getX(){
   return x; 
   }
	int getY(){
   return y; 
   }
	Square();
  void add_move(int x, int y, int x_n, int y_n, Colour colour);
  //struct moves* head;
  
};

class Board
{
  int yeep = 0;
  void printmoves();
  void testread(std::string& a);
	Colour turn=WH;
	bool moveKing(Square* thisKing, Square* thatSpace);
	bool moveQueen(Square* thisQueen, Square* thatSpace);
	bool moveBishop(Square* thisBishop, Square* thatSpace);
	bool moveKnight(Square* thisKnight, Square* thatSpace);
	bool moveRook(Square* thisRook, Square* thatSpace);
	bool movePawn(Square* thisPawn, Square* thatSpace);
	bool makeMove(int x1, int y1, int x2, int y2);
	void printBoard();

  
public:
  
  node* head, *tail;
  void addmoves(int a);
  Square square[8][8];
  Square* getSquare(int x, int y) {
		return &square[x][y];
	}
	void setSquare(Square * s, int x, int y){
		square[x][y]=*s;
	}
  void printMoves(int a);
  
	bool doMove();
	
	void setBoard();
	bool playGame();
  bool testPieces(int x, int y, int move_x, int move_y, Piece testP, Colour testC);
  
};
