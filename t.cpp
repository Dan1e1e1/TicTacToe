
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
  int rows = 4;
  int cols = 4;

  bool game = true;
  int turn = 1;
  char turn1 = 'X';
  while (game == true) {
    if (turn == 1) {
      turn1 = 'X';
      turn--;
    } else {
      turn1 = 'O';
      turn++;
    }
    bool con = true;
    while (con == true) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          char input;
          int input1;
          cout << "Choose the letter a letter (a,b,c): ";
          cin >> input;
          cout << "Choose a nmuber (1,2,3): ";
          cin >> input1;
	  if (input == 'a') {
	    if (input1 == 1) {
	      if (board[1][1] == ' ') {
                board[1][1] = turn1;
                con = false;
	      } else {
                cout << "fail";
                con = false;
	      }
	    }
	      if (input1 == 2) {
	        board[1][2] = turn1;
	    }
	      if (input1 == 3) {
	        board[1][3] = turn1;
	    }
	      cout << board[i][j];
	  }
	  else if (input == 'b') {
	    if (input1 == 1) {
	      board[2][1] = turn1;
	    }
	    if (input1 == 2) {
	      board[2][2] = turn1;
	    }
	    if (input1 == 3) {
	      board[2][3] = turn1;
	    }
	    cout << board[i][j];
	  }
	  else if (input == 'c') {
	    if (input1 == 1) {
	      board[3][1] = turn1;
	    }
	    if (input1 == 2) {
	      board[3][2] = turn1;
	    }
	    if (input1 == 3) {
	      board[3][3] = turn1;
	    }
	  }
	  cout << board[i][j];
	}
	//Formatting the printing so its in a 4x4
	cout << "\n";
      }
      //stop infinite loop
      con = false;
    }
  }
}
