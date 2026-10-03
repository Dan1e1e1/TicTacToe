
#include <iostream>
#include <cstring>

using namespace std;

int reset_turn(int &turn) {
  cout << "\n";
  if (turn == 1) {
    turn = 0;
  } else {
    turn = 1;
  }
  return turn;
}
int reset(char (&board)[4][4], int &times, int &turn) {
	board[0][0] = ' ';
	board[0][1] = '1';
	board[0][2] = '2';
	board[0][3] = '3';

	board[1][0] = 'a';
	board[1][1] = ' ';
	board[1][2] = ' ';
	board[1][3] = ' ';

    board[2][0] = 'b';
	board[2][1] = ' ';
	board[2][2] = ' ';
	board[2][3] = ' ';

	board[3][0] = 'c';
	board[3][1] = ' ';
	board[3][2] = ' ';
	board[3][3] = ' ';

	times = 0;
	turn = 1;
	return times, turn;
}

int x_win(int &x_points, bool &game, char (&board)[4][4], int &times, int &turn) {
  cout << "X wins!";
  cout << "\n";
  x_points++;
  cout << "X has " << x_points << " points" << "\n";
  cout << "do you want to play again?(y, n)" << "\n";
  char again;
  cin >> again;
  if (again == 'n') {
    game = false;
  } else {
    cout << "lets play again";
	reset(board, times, turn);

  }
  return x_points;
}
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
  int times = 0;
  int turn = 1;
  int x_points = 0;
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
		  //make sure the input is a or b or c to make sure that you dont skip a turn.
	      while (input != 'a' && input != 'b' && input != 'c') {
			cout << "Choose a valid letter a - b - c \n";
			cout << "Choose a letter(a, b, c): ";
			cin >> input;
		  }
          cout << "Choose a number (1,2,3): ";
          cin >> input1;
		  //make sure the input is between 1 and 3 to make sure you dont skip a turn.
	      while (input1 < 1 || input1 > 3) {
		    cout << "That was not a valid number, choose a number between 1 and 3 \n";
		    cout << "Choose a number (1, 2, 3): ";
		    cin >> input1;
          } 

          if (input == 'a') {
            if (input1 == 1) {
              if (board[1][1] == ' ') {
                board[1][1] = turn1;
				times++;
              } else {
    	        cout << "fail";
                reset_turn(turn);
	        }
	      }
            if (input1 == 2) {
              if (board[1][2] == ' ') {
                board[1][2] = turn1;
				times++;
              } else {
                cout << "fail";
                reset_turn(turn);
	        }
	      }
            if (input1 == 3) {
              if (board[1][3] == ' ') {
                board[1][3] = turn1;
				times++;
              } else {
                cout << "fail";
                reset_turn(turn);
                }
              }
	  }
	  else if (input == 'b') {
	    if (input1 == 1) {
	      if (board[2][1] == ' ') {
	        board[2][1] = turn1;
			times++;
	      } else {
		cout << "fail";
		reset_turn(turn);
	        }
	      }
	    if (input1 == 2) {
	      if (board[2][2] == ' ') {
	        board[2][2] = turn1;
			times++;
	      } else {
		cout << "fail";
		reset_turn(turn);
	        }
	      }
	    if (input1 == 3) {
	      if (board[2][3] == ' ') {
	        board[2][3] = turn1;
			times++;
	      } else {
		cout << "fail";
		reset_turn(turn);
	      }
	    }
	  }
	  else if (input == 'c') {
	    if (input1 == 1) {
	      if (board[3][1] == ' ') {
	        board[3][1] = turn1;
			times++;
	      } else {
		cout << "fail";
		reset_turn(turn);
	        }
	      }
	    if (input1 == 2) {
	      if (board[3][2] == ' ') {
	        board[3][2] = turn1;
			times++;
	      } else {
		cout << "fail";
		reset_turn(turn);
	        }
	      }
	    if (input1 == 3) {
	      if (board[3][3] == ' ') {
	        board[3][3] = turn1;
			times++;
	      } else {
		cout << "fail";
		reset_turn(turn);
	        }
	      }
          }
	  //printing board
          for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
              cout << board[i][j];
	    	}
	    	cout << "\n";
	}
      }
      //eventual win conditions
    if (times >= 9) {
		cout << "tie";
		game = false;
	}
	bool run_once = true;
	for (int i = 0; i < rows; i++) {
	  for (int j = 0; j < cols; j++) {
	    if (run_once == true) {
	      //Horizontal
	      if (board[1][1] == 'X' && board[1][2] == 'X' && board[1][3] == 'X') {
		run_once = false;
		x_win(x_points, game, board, times, turn);
	      } else if (board[2][1] == 'X' && board[2][2] == 'X' && board[2][3] == 'X') {
	        run_once = false;
		x_win(x_points, game, board, times, turn);
	      } else if (board[3][1] == 'X' && board[3][2] == 'X' && board[3][3] == 'X') {
		run_once = false;
		x_win(x_points, game, board, times, turn);
	      }
	    //Vertial
	      if (board[1][1] == 'X' && board[2][1] == 'X' && board[3][1] == 'X') {
                run_once = false;
		x_win(x_points, game, board, times, turn);
              } else if (board[1][2] == 'X' && board[2][2] == 'X' && board[3][2] == 'X') {
                run_once = false;
		x_win(x_points, game, board, times, turn);
              } else if (board[1][3] == 'X' && board[2][3] == 'X' && board[3][3] == 'X') {
                run_once = false;
		x_win(x_points, game, board, times, turn);
              }
	    //Diagonals
	      if (board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X') {
                run_once = false;
		x_win(x_points, game, board, times, turn);
              } else if (board[3][1] == 'X' && board[2][2] == 'X' && board[1][3] == 'X') {
                run_once = false;
		x_win(x_points, game, board, times, turn);
              }
	    }



	}
      }
    con = false;
    }
  }
}
}
