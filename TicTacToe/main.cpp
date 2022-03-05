//
//  main.cpp
//  TicTacToe
//
//  Created by Robert Black on 07/02/2021.
//

#include <iostream>

using namespace std;

//Player ID constants and veriables.
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
char lastPlayer = PLAYER_O;
char currentPlayer = PLAYER_X;

//Board dimentions variables.
int numOfRows = 3;
int numberOfCols = 3;
char boardSquares[3][3] = {};

//Game control counters.
int turnNumber = 1;
int playerInputMove = 0;

//Game control variables
int cords[2];

//Game control booleans.
bool renderBoard = true;

void getCoordinatesFromSquareNum(int squareNumber, int* cords) {
    
    switch (squareNumber) {
        case 1:
            cords[0] = 0;
            cords[1] = 0;
            break;
            
        case 2:
            cords[0] = 0;
            cords[1] = 1;
            break;
            
        case 3:
            cords[0] = 0;
            cords[1] = 2;
            break;
            
        case 4:
            cords[0] = 1;
            cords[1] = 0;
            break;
            
        case 5:
            cords[0] = 1;
            cords[1] = 1;
            break;
            
        case 6:
            cords[0] = 1;
            cords[1] = 2;
            break;
            
        case 7:
            cords[0] = 2;
            cords[1] = 0;
            break;
            
        case 8:
            cords[0] = 2;
            cords[1] = 1;
            break;
            
        case 9:
            cords[0] = 2;
            cords[1] = 2;
            break;
            
        default:
            break;
            
    }
    
}

bool checkForEndGame(int turnNumber, char player) {
    
    bool retVal = false;
    
    //Check if any player has won i.e. either three 'X' or 'Y'
    //in a row and return true.
    if (boardSquares[0][0] == boardSquares[0][1] && boardSquares[0][0] == boardSquares[0][2]) {

        cout << "Win on top row for player " << player << endl;
        cout << endl;
        retVal = true;

    } else if (boardSquares[1][0] == boardSquares[1][1] && boardSquares[1][0] == boardSquares[1][2]) {

        cout << "Win on middle row for player " << player << endl;
        cout << endl;
        retVal = true;

    } else if (boardSquares[2][0] == boardSquares[2][1] && boardSquares[2][0] == boardSquares[2][2]) {

        cout << "Win on bottom row for player " << player << endl;
        cout << endl;
        retVal = true;

    } else if (boardSquares[0][0] == boardSquares[1][0] && boardSquares[0][0] == boardSquares[2][0]) {

        cout << "Win on left column for player " << player << endl;
        cout << endl;
        retVal = true;

    } else if (boardSquares[0][1] == boardSquares[1][1] && boardSquares[0][1] == boardSquares[2][1]) {

        cout << "Win on middle column for player " << player << endl;
        cout << endl;
        retVal = true;

    } else if (boardSquares[0][2] == boardSquares[1][2] && boardSquares[0][2] == boardSquares[2][2]) {

        cout << "Win on right column for player " << player << endl;
        cout << endl;
        retVal = true;

    } else if (boardSquares[0][0] == boardSquares[1][1] && boardSquares[0][0] == boardSquares[2][2]) {

        cout << "Win on right diagonal for player " << player << endl;
        cout << endl;
        retVal = true;

    } else if (boardSquares[0][2] == boardSquares[1][1] && boardSquares[0][2] == boardSquares[2][0]) {

        cout << "Win on left diagonal for player " << player << endl;
        cout << endl;
        retVal = true;

    }
    
    //Called when 9 moves have happened.  This returns true at
    //10 so the final games board is drawn.
    if (turnNumber == 10) {
        
        cout << "The game is stalemate, no one has won." << endl;
        cout << endl;
        retVal = true;
        
    }
    
    return retVal;
    
}

void getPlayerChoice(char player) {
    
    cout << "Player " << currentPlayer << " enter a number between 1 and 9: \n";
    cout << endl;
    cin >> playerInputMove;
    
    int squareCounter = 1;
    
    for (int x = 0; x < 3; x++) {
        
        for (int y = 0; y < 3; y++) {
            
            if (playerInputMove == squareCounter) {
                
                //Checks if this move has already bee played.
                if (boardSquares[x][y] == PLAYER_X
                    || boardSquares[x][y] == PLAYER_O) {
                    
                    cout << "That square is not available. Try again." << endl;
                    cout << endl;
                
                } else {
                    
                    //Records the plays in the boardSquares array.
                    boardSquares[x][y] = currentPlayer;
                    
                    //counts one of the plays.
                    turnNumber++;
                    
                    //If statement to switch players on each move.
                    if (currentPlayer == PLAYER_X) {
                        currentPlayer = PLAYER_O;
                        lastPlayer = PLAYER_X;
                    } else {
                        currentPlayer = PLAYER_X;
                        lastPlayer = PLAYER_O;
                        
                    }
                        
                }
                
            }
                
            squareCounter++;
            
        }
        
    }
    
}

void initGame() {
    
    //Creat gameboard array and populate it with different
    //irrelavant chars for the win check.
    char charCounter = 49;
    
    for (int x = 0; x < 3; x++) {
        
        for (int y = 0; y < 3; y++) {
            
            boardSquares[x][y] = (char)charCounter;
            charCounter++;
            
        }
        
    }
    
}

void displayBoard() {
    
    //Announce the current state of the games board.
    cout << endl;
    cout << "Current board state: Player picked square " << playerInputMove  << endl;
    cout << endl;
    
    //Render the games board.
    for (int x = 0; x < numOfRows; x++) {

        //Draw the top board of the games board and
        //top of every row.
        cout << "    +-+-+-+" << endl;

        for (int y = 0; y < numberOfCols; y++) {

            if (y == 0) {
                    
                cout << "    |" << boardSquares[x][y];
                
            } else if (y < numberOfCols - 1) {
                
                cout << "|" << boardSquares[x][y];
                
            } else {
                
                cout << "|" << boardSquares[x][y] << "|" << endl;
            }

        }

        //Draw the bottom boarder of the game board.
        if (x >= numOfRows - 1) {
            
            cout << "    +-+-+-+" << endl;
            
        }
        
    }
    
    cout << endl;
    
}

int main(int argc, const char * argv[]) {
    
    //Initalise the board
    initGame();
    
    //Game loop started, this will exit upon 9 moves indicating
    //no more moves can be made and the game is stalemate.
    while (true) {
        
        //Displayes the game board.
        displayBoard();
        
        //Ends the game loop is a win or max moves have occured.
        bool isGameOver = checkForEndGame(turnNumber, lastPlayer);
        
        //Checks if win or stalemate and ends the game if so or
        //continues to player choices.
        if (isGameOver) {
            
            break;
            
        } else {
            
            getPlayerChoice(lastPlayer);
            
        }

    }
    
    return 0;
}
