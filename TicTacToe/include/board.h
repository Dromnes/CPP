/*
 * File:   board.h
 * Author: Kodemikkel
 *
 * Created on 2. april 2016, 18:42
 */

#ifndef BOARD_H
#define	BOARD_H

#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

class Game {

  public:
    Game() {
      getInput();
    }

  private:
    char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player = 1;

    void restartGame() {
      this->square[1] = '1';
      this->square[2] = '2';
      this->square[3] = '3';
      this->square[4] = '4';
      this->square[5] = '5';
      this->square[6] = '6';
      this->square[7] = '7';
      this->square[8] = '8';
      this->square[9] = '9';
      this->player = 1;
      this->getInput();
    }
    
    void drawBoard() {
      cout <<                   "     |   "       <<       "  |     " << endl;
      cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
      cout <<                   "_____|___"       <<       "__|_____" << endl;
      cout <<                   "     |   "       <<       "  |     " << endl;
      cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
      cout <<                   "_____|___"       <<       "__|_____" << endl;
      cout <<                   "     |   "       <<       "  |     " << endl;
      cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
      cout <<                   "     |   "       <<       "  |     " << endl;
    };

    int checkGameState() {
      if(square[1] == square[2] && square [2] == square[3]) {
        return 1;
      } else if(square[4] == square[5] && square [5] == square[6]) {
        return 1;
      } else if(square[7] == square[8] && square [8] == square[9]) {
        return 1;
      } else if(square[1] == square[5] && square [5] == square[9]) {
        return 1;
      } else if(square[3] == square[5] && square [5] == square[7]) {
        return 1;
      } else if(square[1] == square[4] && square [4] == square[7]) {
        return 1;
      } else if(square[2] == square[5] && square [5] == square[8]) {
        return 1;
      } else if(square[3] == square[6] && square [6] == square[9]) {
        return 1;
      } else if(square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' && square[5]!='6' && square[1]!='6' && square[7]!='7' && square[8]!='8' && square[9]!='9') {
        return -1;
      } else {
        return 0;
      };
    };

    int getInput() {
      int position;
      int gameState = checkGameState();
      this->drawBoard();
      if(gameState == 0) {
        cout << "Player " << this->player << ", enter the square you want to place your mark in." << endl;
        posLabel:
          cin >> position;
          if(!(cin) || (this->square[position] == 'X') || (this->square[position] == 'O') || (position > sizeof(square)) || (position < 1)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid position, please try again." << endl;
            goto posLabel;
          } else {
            this->placeMark(this->player, position);
          }
      } else if(gameState == -1) {
        cout << "Game draw! Would you like to restart? (Y/N)" << endl;
      } else {
        cout << "Player " << this->player-- << " has won! Would you like to restart? (Y/N)" << endl;
      }
      int character;
        while(true) {
        switch((character = getch())) {
          case 89:
            this->restartGame();
            break;
          case 121:
            this->restartGame();
            break;
          default:
            return 0;
        }
      }
    };

    void placeMark(int player, int pos) {
      char mark = (this->player == 1)?'X':'O';
      square[pos] = mark;
      (this->player == 1) ? this->player++ : this->player--;
      this->getInput();
    };
};

#endif	/* BOARD_H */
