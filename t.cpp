//Daniel Michael 10/2/26 Tic Tac Toe
//This program allows the user to play tic tac toe by entering a letter and then a number that corresponds to the postion they want.
//This program keeps track of how many wins each player has and accounts for ties. When the game ends, the user will be asked if they
//want to play again, and if they do, the board will reset and they can play a new game.
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
int reset(char (&board)[4][4], int &times, int &turn, bool &won) {
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
	won = false;
	return times, turn, won;
}

int x_win(int &x_points, int o_points, bool &game, char (&board)[4][4], int &times, int &turn, bool &won) {
  cout << "X wins!";
  cout << "\n";
  x_points++;
  cout << "X has " << x_points << " points" << "\n";
  cout << "O has " << o_points << " points \n";
  cout << "do you want to play again?(y, n)" << "\n";
  char again;
  cin >> again;
  if (again == 'n') {
    game = false;
  } else {
    cout << "lets play again \n";
	reset(board, times, turn, won);

  }
  return x_points;
}
int o_win(int &o_points, int x_points, bool &game, char (&board)[4][4], int &times, int &turn, bool &won) {
  cout << "O wins!";
  cout << "\n";
  o_points++;
  cout << "X has "  << x_points << " points \n" ;
  cout << "O has " << o_points << " points" << "\n";
  cout << "do you want to play again?(y, n)" << "\n";
  char again;
  cin >> again;
  if (again == 'n') {
    game = false;
  } else {
    cout << "lets play again \n";
	reset(board, times, turn, won);

  }
  return o_points;
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
  int o_points = 0;
  char turn1 = 'X';
  bool won = false;
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
          cout << "Choose a letter (a,b,c): ";
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
    	        cout << "Try again that was invalid";
                reset_turn(turn);
	        }
	      }
            if (input1 == 2) {
              if (board[1][2] == ' ') {
                board[1][2] = turn1;
				times++;
              } else {
                cout << "Try again that was invalid";
                reset_turn(turn);
	        }
	      }
            if (input1 == 3) {
              if (board[1][3] == ' ') {
                board[1][3] = turn1;
				times++;
              } else {
                cout << "Try again that was invalid";
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
		cout << "Try again that was invalid";
		reset_turn(turn);
	        }
	      }
	    if (input1 == 2) {
	      if (board[2][2] == ' ') {
	        board[2][2] = turn1;
			times++;
	      } else {
		cout << "Try again that was invalid";
		reset_turn(turn);
	        }
	      }
	    if (input1 == 3) {
	      if (board[2][3] == ' ') {
	        board[2][3] = turn1;
			times++;
	      } else {
		cout << "Try again that was invalid";
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
		cout << "Try again that was invalid";
		reset_turn(turn);
	        }
	      }
	    if (input1 == 2) {
	      if (board[3][2] == ' ') {
	        board[3][2] = turn1;
			times++;
	      } else {
		cout << "Try again that was invalid";
		reset_turn(turn);
	        }
	      }
	    if (input1 == 3) {
	      if (board[3][3] == ' ') {
	        board[3][3] = turn1;
			times++;
	      } else {
		cout << "Try again that was invalid";
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
    //Ties
    if (times >= 9) {
		if (won == false) {
		  cout << "tie \n";
		  cout << "X has "  << x_points << " points \n" ;
		  cout << "O has " << o_points << " points \n";
		  cout << "do you want to play again?(y, n)" << "\n";
  	 	  char again;
 		  cin >> again;
  		  if (again == 'n') {
             game = false;
  		  } else {
   		    cout << "lets play again \n";
			reset(board, times, turn, won);
		  }
		}
	}
	//make sure that when you win you only get 1 point.
	bool run_once = true;
	for (int i = 0; i < rows; i++) {
	  for (int j = 0; j < cols; j++) {
	    if (run_once == true && turn1 == 'X') {
	      //Horizontal
	      if (board[1][1] == 'X' && board[1][2] == 'X' && board[1][3] == 'X') {
		run_once = false;
		x_win(x_points, o_points, game, board, times, turn, won);
		     won = true;
	      } else if (board[2][1] == 'X' && board[2][2] == 'X' && board[2][3] == 'X') {
	        run_once = false;
		x_win(x_points, o_points, game, board, times, turn, won);
			  won = true;
	      } else if (board[3][1] == 'X' && board[3][2] == 'X' && board[3][3] == 'X') {
		run_once = false;
		x_win(x_points, o_points, game, board, times, turn, won);
			  won = true;
	      }
	    //Vertial
	      if (board[1][1] == 'X' && board[2][1] == 'X' && board[3][1] == 'X') {
                run_once = false;
		x_win(x_points, o_points, game, board, times, turn, won);
			  won = true;
              } else if (board[1][2] == 'X' && board[2][2] == 'X' && board[3][2] == 'X') {
                run_once = false;
		x_win(x_points, o_points, game, board, times, turn, won);
			  won = true;
              } else if (board[1][3] == 'X' && board[2][3] == 'X' && board[3][3] == 'X') {
                run_once = false;
		x_win(x_points, o_points, game, board, times, turn, won);
			  won = true;
              }
	    //Diagonals
	      if (board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X') {
                run_once = false;
		x_win(x_points, o_points, game, board, times, turn, won);
			  won = true;
              } else if (board[3][1] == 'X' && board[2][2] == 'X' && board[1][3] == 'X') {
                run_once = false;
		x_win(x_points, o_points, game, board, times, turn, won);
			  won = true;
              }
	    }
	  if (run_once == true && turn1 == 'O') {
	      //Horizontal
	      if (board[1][1] == 'O' && board[1][2] == 'O' && board[1][3] == 'O') {
		run_once = false;
		o_win(o_points, x_points, game, board, times, turn, won);
		     won = true;
	      } else if (board[2][1] == 'O' && board[2][2] == 'O' && board[2][3] == 'O') {
	        run_once = false;
		o_win(o_points, x_points, game, board, times, turn, won);
			  won = true;
	      } else if (board[3][1] == 'O' && board[3][2] == 'O' && board[3][3] == 'O') {
		run_once = false;
		o_win(o_points, x_points, game, board, times, turn, won);
			  won = true;
	      }
	    //Vertial
	      if (board[1][1] == 'O' && board[2][1] == 'O' && board[3][1] == 'O') {
                run_once = false;
		o_win(o_points, x_points, game, board, times, turn, won);
			  won = true;
              } else if (board[1][2] == 'O' && board[2][2] == 'O' && board[3][2] == 'O') {
                run_once = false;
		o_win(o_points, x_points, game, board, times, turn, won);
			  won = true;
              } else if (board[1][3] == 'O' && board[2][3] == 'O' && board[3][3] == 'O') {
                run_once = false;
		o_win(o_points, x_points, game, board, times, turn, won);
			  won = true;
              }
	    //Diagonals
	      if (board[1][1] == 'O' && board[2][2] == 'O' && board[3][3] == 'O') {
                run_once = false;
		o_win(o_points, x_points, game, board, times, turn, won);
			  won = true;
              } else if (board[3][1] == 'O' && board[2][2] == 'O' && board[1][3] == 'O') {
                run_once = false;
		o_win(o_points, x_points, game, board, times, turn, won);
			  won = true;
              }
	    }



	}
      }
    con = false;
    }
  }
}
}
