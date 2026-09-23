
#include <iostream>
#include <cstring>

using namespace std;
int main() {
  char board[4][4] = {
    {' ', '1', '2', '3'},
    {'a', ' ' , ' ', ' '},
    {'b', ' ', ' ', ' '},
    {'c', ' ', ' ', ' '}
  };
  char a1 = board[1][1];
  char a2 = board[1][2];
  char a3 = board[1][3];

  char b1 = board[2][1];
  char b2 = board[2][2];
  char b3 = board[2][3];

  char c1 = board[3][1];
  char c2 = board[3][2];
  char c3 = board[3][3];

  int rows = 4;
  int cols = 4;

  char game = true;
  int turn = 0;
  char turn1 = 'X';
  while (game == true) {
    turn++;
    if (turn = 1) {
      turn1 = 'X';
    } else {
      turn1 = 'O';
    }
    char input;
    int input1;
    cout << "Choose the letter a letter (a,b,c): ";
    cin >> input;
    cout << "Choose a nmuber (1,2,3): ";
    cin >> input1;
    int con = true;
    while (con == true) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (input == 'a') {
            if (input1 == 1) {
              board[1][1] = turn1;
  	      cout << board[i][j];
	      con = false;
	    }
	  }
	}
	//Formatting the printing so its in a 4x4
	cout << "\n";
      }
    }
  }
}
