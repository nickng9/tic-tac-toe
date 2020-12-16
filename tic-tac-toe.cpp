// Project: Live tic tac toe game (on a 4 by 4 board) played between two players
// Purpose: Create a live playable game of tic tac toe with active stat trackers, using 2D array and employs top down functional structure.

#include <iostream>
using namespace std;

bool check_result();
//PURPOSE:Checks array values for win condition for rows, columns, and diagonals
//INPUTS:none
//RETURNS:true boolean if win condition is met for either X or O

void display_result(int& xw, int& ow, int& xl, int& ol);
//PURPOSE:Outputs message based on which player has won
//INPUTS: xw- X wins, ol- O losses, etc.
//RETURNS:none

void draw_board();
//PURPOSE: Outputs the updated "game board" after every round
//INPUTS:none
//RETURNS:none

void user_input();
//PURPOSE:Takes user input within the permitted range of values
//INPUTS:none
//RETURNS:none

void start_tictactoe_simulation();
//PURPOSE: Invokes other functions to simulate tic tac toe game
//INPUTS: none
//RETURNS: none

int main() {
   
    start_tictactoe_simulation();
}

// initializing global variable for string 2D array holding the 16 positional values

string board[4][4] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" };
string resetboard[4][4] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" };
bool player_1_turn = true;

void draw_board() { // function to create a multidimensional array holding the board values
     // initializing the array
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " "; // outputting the board
        }
        cout << endl;
    }
}

// user input / position function
void user_input() {
    int user_input = 0;
    cout << "Make your move: ";
    cin >> user_input;

    // while loop for the input checking if it's out of the boundaries of the array
    while (user_input <= 0 || user_input >= 17) {
        cout << "Invalid, enter another number" << endl;
        cin >> user_input; // 
    }

    // while loop for the input checking if the position is already occupied
    while (board[user_input / 4][user_input % 4 - 1] == "O" || board[user_input / 4][user_input % 4 - 1] == "X") {
        cout << "Invalid, enter another number" << endl;
        cin >> user_input;
    }

    // bool for checking who's turn it is
    if (player_1_turn == true) {
        board[user_input / 4][user_input % 4 - 1] = "X";
        player_1_turn = false; // switching X/O
    }
    else {
        board[user_input / 4][user_input % 4 - 1] = "O";
        player_1_turn = true; // switching X/O
    }
}

// calls all of the functions and will be the primary function invoked in int main
void start_tictactoe_simulation() {

    int X_wins = 0, O_wins = 0, X_losses = 0, O_losses = 0, ties = 0;                             // stores amount of wins, losses, etc.
    bool play_game = true;                                                                        // boolean for user input for game replay
    char repeat;                                                                                  // User input for game replay
    int tie_counter = 0;

    while (play_game)
    {
        draw_board();
        while (1) {
            tie_counter++;
            user_input();
            bool check = check_result();
            draw_board();
            if (check) {
                display_result(X_wins, O_wins, X_losses, O_losses);
                break;
            }
            if (tie_counter == 16) {
                ties++;
                cout << "Game has tied. \n";
                break;
            }
        }

        // After game has finished, prompts user for replay
        cout << "Do you want to play again? (Y/N)\n";
        cin >> repeat;
        if (repeat == 'Y') {
            // reset board
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    board[i][j] = resetboard[i][j]; // resets the board to a cleaned 1-16 board
            // reset tie counter
            tie_counter = 0;
            play_game = true;
        }
        else {
            play_game = false;
        }
            
    }

    // displays results
    cout << "Player X has won " << X_wins << " times and lost " << X_losses << " times. \n"
         << "Player O has won " << O_wins << " times and lost " << O_losses << " times. \n"
         << "Game has tied " << ties << " times";

}

// boolean value looking for various win conditions
bool check_result()
{
    // horizontal wins
    for (int index = 0; index < 4; index++) {
        if (((board[index][0] == "X") && (board[index][1] == "X") && (board[index][2] == "X") && (board[index][3] == "X"))
            || ((board[index][0] == "O") && (board[index][1] == "O") && (board[index][2] == "O") && (board[index][3] == "O")))
            return true;
    
    }

    // vertical wins
    for (int index = 0; index < 4; index++) {
        if (((board[0][index] == "X") && (board[1][index] == "X") && (board[2][index] == "X") && (board[3][index] == "X"))
            || ((board[0][index] == "O") && (board[1][index] == "O") && (board[2][index] == "O") && (board[3][index] == "O")))
            return true;
        
    }

    // diagonal from top left
    if (((board[0][0] == "X") && (board[1][1] == "X") && (board[2][2] == "X") && (board[3][3] == "X"))
        || ((board[0][0] == "O") && (board[1][1] == "O") && (board[2][2] == "O") && (board[3][3] == "O")))
        return true;
    
    // diagonal from top right
    if (((board[0][3] == "X") && (board[1][2] == "X") && (board[2][1] == "X") && (board[3][0] == "X"))
        || ((board[0][3] == "O") && (board[1][2] == "O") && (board[2][1] == "O") && (board[3][0] == "O")))
        return true;
    
    return false;
}

// final output displayed when the players choose to end the session (keeps count of wins, losses of both players)
void display_result(int& xw, int& ow, int& xl, int& ol)
{
    if (player_1_turn == true) {
        cout << "O wins, congratulations!" << endl;
        ow++;
        xl++;
    } else if (player_1_turn == false) {
        cout << "X wins, congratulations!" << endl;
        xw++;
        ol++;
    }
}
