#ifndef HEADER_H
#define HEADER_H

/////all the Libraries
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include <windows.h>
#include <conio.h> 


///////////////////////////////
using namespace std;


/////////////////////ALL THE HEADER FILES//////////////////////////////////////////
#include"functions.h"
#include"admin.h"
#include"employee.h"
#include"customer.h"


void buttons();
void Play_Games();
void TIK_TAK_TOE();
void whack_a_mole();
void Guess_The_NUM();
void random_mole_position(int& moleRow, int& moleCol , int ROWS , int COLS);
void Display(char board[][4], int moleRow, int moleCol , int ROWS , int COLS);
void Print_Board(char board[3][3]);
bool Check_Win(char board[3][3], char player);
bool CHECK_BOARD(char board[3][3]);



 
 #endif