///Meet Shank, the artificial Tic Tac Toe god.

#include <iostream>
#include <cmath>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

char userChoice = 'S';

void fillBoard  (char board[ROWS][COLS]);
void showBoard  (char board[ROWS][COLS]);
void getChoice  (char board[ROWS][COLS], bool playerToggle);
bool gameOver   (char board[ROWS][COLS]);
void chooseAI   ();
void BoChoice   (char board[ROWS][COLS], bool playerToggle);
void ShankChoice(char board[ROWS][COLS], bool playerToggle);

int main()
{
    char board[ROWS][COLS];
    bool playerToggle = false;

    fillBoard(board);
    showBoard(board);

    chooseAI();
    showBoard(board);

    while (!gameOver(board))
    {
        getChoice(board, playerToggle);
        showBoard(board);
        playerToggle = !playerToggle;
    }

    return 0;
}

void fillBoard(char b[ROWS][COLS])
{
    for (int i=0; i<ROWS; i++)
    {
        for (int j=0; j<COLS; j++)
        {
            b[i][j] = '*';                  /// fill board with *
        }
    }
    return;
}

void showBoard(char b[ROWS][COLS])
{
    cout << "  1 2 3" << endl;
    for (int i=0; i<ROWS; i++)
    {
        cout << i+1 << " ";
        for (int j=0; j<COLS; j++)
        {
            cout << b[i][j] << " ";         /// show board, space separated and numbered
        }
        cout << endl;
    }
}

void getChoice(char b[][COLS], bool playerToggle)
{
    string player;
    char c;
    int row, col;

    if(userChoice == 'N' || userChoice == 'n')
    {
        if(playerToggle == false)
        {
            player = "Player 1";
            c = 'X';
        }
        else
        {
            player = "Player 2";
            c = 'O';
        }
    }

    if (userChoice == 'B' || userChoice == 'b')
    {
        BoChoice(b, playerToggle);
        return;
    }

    if (userChoice == 'S' || userChoice == 's')
    {
        ShankChoice(b, playerToggle);
        return;
    }


    do
    {
        do
        {
            cout << player << ", Row: ";///prompt the current player to enter the row
            cin  >> row;
        }while(row < 1 || row > 3);  ///range for row is invalid?

        do
        {
            cout << player << ", Column: ";///prompt the current player to enter the column
            cin  >> col;
        }while(col < 1 || col > 3);  ///range for col is invalid?

    }while((b[row-1][col-1] == 'X') || (b[row-1][col-1] == 'O'));  ///the chosen cell is an X or an O?

    if(b[row-1][col-1] == '*')
    {
        b[row-1][col-1] = c;
    }
}

bool gameOver(char b[][COLS])
{
    bool gameOver = false;

    if((b[0][0] == 'X' && b[0][1] == 'X' && b[0][2] == 'X') /// X rows
    || (b[1][0] == 'X' && b[1][1] == 'X' && b[1][2] == 'X') /// X rows
    || (b[2][0] == 'X' && b[2][1] == 'X' && b[2][2] == 'X') /// X rows
    || (b[0][0] == 'X' && b[1][0] == 'X' && b[2][0] == 'X') /// X cols
    || (b[0][1] == 'X' && b[1][1] == 'X' && b[2][1] == 'X') /// X cols
    || (b[0][2] == 'X' && b[1][2] == 'X' && b[2][2] == 'X') /// X cols
    || (b[0][0] == 'X' && b[1][1] == 'X' && b[2][2] == 'X') /// X \ diag
    || (b[2][0] == 'X' && b[1][1] == 'X' && b[0][2] == 'X'))/// X / diag
    {
        cout << "Player 1 wins!" << endl;
        gameOver = true;
    }
    else if((b[0][0] == 'O' && b[0][1] == 'O' && b[0][2] == 'O') /// O rows
         || (b[1][0] == 'O' && b[1][1] == 'O' && b[1][2] == 'O') /// O rows
         || (b[2][0] == 'O' && b[2][1] == 'O' && b[2][2] == 'O') /// O rows
         || (b[0][0] == 'O' && b[1][0] == 'O' && b[2][0] == 'O') /// O cols
         || (b[0][1] == 'O' && b[1][1] == 'O' && b[2][1] == 'O') /// O cols
         || (b[0][2] == 'O' && b[1][2] == 'O' && b[2][2] == 'O') /// O cols
         || (b[0][0] == 'O' && b[1][1] == 'O' && b[2][2] == 'O') /// O \ diag
         || (b[2][0] == 'O' && b[1][1] == 'O' && b[0][2] == 'O'))/// O / diag
    {
        cout << "AI wins!" << endl;
        gameOver = true;
    }
    else if(b[0][0] != '*' && b[0][1] != '*' && b[0][2] != '*'  /// All spots either X or O
         && b[1][0] != '*' && b[1][1] != '*' && b[1][2] != '*'
         && b[2][0] != '*' && b[2][1] != '*' && b[2][2] != '*') /// Tie
    {
        cout << "Tie!" << endl;
        gameOver = true;
    }

    return gameOver;
}


void chooseAI()
{
    cout << endl << "Hello." << endl << endl << "Would you like to play against one of us? (Y/N): ";
    cin  >> userChoice;
    cout << endl;
    while ((userChoice != 'Y' && userChoice != 'y') && (userChoice != 'N' && userChoice != 'n'))
    {
        cout << "That wasn't one of the options." << endl << "Y or N?: ";
        cin >> userChoice;
    }
    if(userChoice == 'N' || userChoice == 'n')
    {
        cout << "Very well, have a great time playing with yourself." << endl;
    }
    if(userChoice == 'Y' || userChoice == 'y')
    {
        cout << "Good... Now, who would you like to play against, "
             << endl << "Bo or Shank? (B/S): ";
        cin  >> userChoice;

        while((userChoice != 'B' && userChoice != 'b') && (userChoice != 'S' && userChoice != 's'))
        {
            cout << "Try again. Bo or Shank? B or S?: ";
            cin  >> userChoice;
        }
        if(userChoice == 'B' || userChoice == 'b')
        {
            cout << "Okay. Good luck." << endl;
        }
        if (userChoice == 'S' || userChoice == 's')
        {
            cout << "Heheh. You won't win." << endl;
        }
    }
}

void BoChoice(char b[ROWS][COLS], bool playerToggle)
{
    string player;
    int row, col;
    char c;

    if(playerToggle == false)
        {
            player = "Player 1";
            c = 'X';
            do
            {
                do
                {
                    cout << player << ", Row: ";///prompt the current player to enter the row
                    cin  >> row;
                }while(row < 1 || row > 3);  ///range for row is invalid?

                do
                {
                    cout << player << ", Column: ";///prompt the current player to enter the column
                    cin  >> col;
                }while(col < 1 || col > 3);  ///range for col is invalid?

            }while((b[row-1][col-1] == 'X') || (b[row-1][col-1] == 'O'));  ///the chosen cell is an X or an O?

            if(b[row-1][col-1] == '*')
            {
                b[row-1][col-1] = c;
            }
        }
        else
        {
            player = "Bo";
            c = 'O';
            do
            {
                do
                {
                    cout << player << ", Row: ";///prompt the current player to enter the row
                    row = rand() % 3;
                }while(row < 1 || row > 3);  ///range for row is invalid?

                do
                {
                    cout << player << ", Column: ";///prompt the current player to enter the column
                    col = rand() % 3;
                }while(col < 1 || col > 3);  ///range for col is invalid?

            }while((b[row-1][col-1] == 'X') || (b[row-1][col-1] == 'O'));  ///the chosen cell is an X or an O?

            if(b[row-1][col-1] == '*')
            {
                b[row-1][col-1] = c;
            }
        }
}

void ShankChoice(char b[ROWS][COLS], bool playerToggle)
{
    string player;
    int row, col;
    char c;

    if(playerToggle == false)
        {
            player = "Player 1";
            c = 'X';
            do
            {
                do
                {
                    cout << player << ", Row: ";///prompt the current player to enter the row
                    cin  >> row;
                }while(row < 1 || row > 3);  ///range for row is invalid?

                do
                {
                    cout << player << ", Column: ";///prompt the current player to enter the column
                    cin  >> col;
                }while(col < 1 || col > 3);  ///range for col is invalid?

            }while((b[row-1][col-1] == 'X') || (b[row-1][col-1] == 'O'));  ///the chosen cell is an X or an O?

            if(b[row-1][col-1] == '*')
            {
                b[row-1][col-1] = c;
            }
        }
        else
        {
            player = "Shank";
            c = 'O';
            cout << player << endl;

            ///X in center and catty corner to O
            if(b[1][1] == 'X' && b[0][0] == c && b[2][2] == 'X' && b[0][1] == '*' && b[0][2] == '*' && b[1][2] == '*'
                && b[2][1] == '*' && b[2][0] == '*' && b[1][0] == '*')
                    b[0][2] = c;

            ///self win get:
            if(((b[0][0] == c && b[0][1] == c) || (b[1][2] == c && b[2][2] == c)
                || (b[2][0] == c && b[1][1] == c)) && b[0][2] == '*')
                b[0][2] = c;
            else if(((b[0][0] == c && b[0][2] == c) || (b[1][1] == c && b[2][1] == c)) && b[0][1] == '*')
                b[0][1] = c;
            else if(((b[0][1] == c && b[0][2] == c) || (b[1][0] == c && b[2][0] == c)
                || (b[2][2] == c && b[1][1] == c)) && b[0][0] == '*')
                b[0][0] = c;
            else if(((b[1][0] == c && b[1][1] == c) || (b[0][2] == c && b[2][2] == c)) && b[1][2] == '*')
                b[1][2] = c;
            else if(((b[1][0] == c && b[1][2] == c) || (b[0][1] == c && b[2][1] == c)) && b[1][1] == '*')
                b[1][1] = c;
            else if(((b[1][1] == c && b[1][2] == c) || (b[0][0] == c && b[2][0] == c)) && b[1][0] == '*')
                b[1][0] = c;
            else if(((b[2][0] == c && b[2][1] == c) || (b[1][2] == c && b[0][2] == c)
                || (b[0][0] == c && b[1][1] == c)) && b[2][2] == '*')
                b[2][2] = c;
            else if(((b[2][0] == c && b[2][2] == c) || (b[0][1] == c && b[1][1] == c)) && b[2][1] == '*')
                b[2][1] = c;
            else if(((b[2][1] == c && b[2][2] == c) || (b[1][0] == c && b[0][0] == c)
                || (b[0][2] == c && b[1][1] == c)) && b[2][0] == '*')
            {
                b[2][0] = c;
                return;
            }

            ///opponent win blocks:
            if(((b[0][0] == 'X' && b[0][1] == 'X') || (b[2][2] == 'X' && b[1][2] == 'X')
                || b[2][0] == 'X' && b[1][1] == 'X') && b[0][2] == '*')
                b[0][2] = c;                                                                     ///0,2
            else if(((b[0][2] == 'X' && b[0][1] == 'X') || (b[1][0] == 'X' && b[2][0] == 'X')
                || (b[2][2] == 'X' && b[1][1] == 'X')) && b[0][0] == '*')
                b[0][0] = c;                                                                     ///0,0
            else if(((b[1][1] == 'X' && b[2][1] == 'X') || (b[0][0] == 'X' && b[0][2] == 'X'))
                && b[0][1] == '*')
                b[0][1] = c;                                                                     ///0,1
            else if(((b[0][0] == 'X' && b[1][0] == 'X') || (b[2][1] == 'X' && b[2][2] == 'X')
                || (b[0][2] == 'X' && b[1][1] == 'X')) && b[2][0] == '*')
                b[2][0] = c;                                                                     ///2,0
            else if(((b[0][2] == 'X' && b[1][2] == 'X') || (b[2][0] == 'X' && b[2][1] == 'X')
                || (b[0][0] == 'X' && b[1][1] == 'X')) && b[2][2] == '*')
                b[2][2] = c;                                                                     ///2,2
            else if(((b[1][1] == 'X' && b[0][1] == 'X') || (b[2][0] == 'X' && b[2][2] == 'X'))
                && b[2][1] == '*')
                b[2][1] = c;                                                                     ///2,1
            else if(((b[1][0] == 'X' && b[1][1] == 'X') || (b[0][2] == 'X' && b[2][2] == 'X'))
                && b[1][2] == '*')
                b[1][2] = c;                                                                     ///1,2
            else if(((b[1][1] == 'X' && b[1][2] == 'X') || (b[0][0] == 'X' && b[2][0] == 'X'))
                && b[1][0] == '*')
            {
                b[1][0] = c;                                                                     ///1,0
                return;
            }

            ///one X on a corner, the other on an edge
            if(((b[0][0] == 'X')
                &&  b[0][1] == 'X' || b[1][2] == 'X' || b[2][1] == 'X' || b[1][0] == 'X') && b[2][2] == '*')
                b[2][2] = c;
            else if(((b[0][2] == 'X')
                &&  b[0][1] == 'X' || b[1][2] == 'X' || b[2][1] == 'X' || b[1][0] == 'X') && b[2][0] == '*')
                b[2][0] = c;
            else if(((b[2][2] == 'X')
                &&  b[0][1] == 'X' || b[1][2] == 'X' || b[2][1] == 'X' || b[1][0] == 'X') && b[0][0] == '*')
                b[0][0] = c;
            else if(((b[2][0] == 'X')
                &&  b[0][1] == 'X' || b[1][2] == 'X' || b[2][1] == 'X' || b[1][0] == 'X') && b[0][2] == '*')
            {
                b[0][2] = c;
                return;
            }

            ///both X on edge squares, bordering corner
            if(b[0][1] == 'X' && b[1][2] == 'X' && b[0][2] == '*')
                b[0][2] = c;
            else if(b[2][1] == 'X' && b[1][2] == 'X' && b[2][2] == '*')
                b[2][2] = c;
            else if(b[2][1] == 'X' && b[1][0] == 'X' && b[2][0] == '*')
                b[2][0] = c;
            else if(b[0][1] == 'X' && b[1][2] == 'X' && b[0][0] == '*')
            {
                b[0][0] = c;
                return;
            }

            ///both X on edge squares, not bordering corner
            if(b[0][1] == 'X' && b[2][1] == 'X' && (b[1][0] == '*' || b[1][2] == '*'))
            {
                if(b[1][0] == '*')
                {
                    b[1][0] = c;
                }
                else
                {
                    b[1][2] = c;
                }
            }
            else if(b[1][0] == 'X' && b[1][2] == 'X' && (b[0][1] == '*' || b[2][1] == '*'))
            {
                if(b[0][1] == '*')
                {
                    b[0][1] = c;
                }
                else
                {
                    b[2][1] = c;
                }
                return;
            }

            ///catty cornered Xs
            if((b[0][0] == 'X' && b[2][2] == 'X')
                && (b[0][1] == '*' || b[1][2] == '*' || b[2][1] == '*' || b[1][0] == '*'))
            {
                if(b[0][1] == '*')
                    b[0][1] = c;
                else if(b[1][2] == '*')
                    b[1][2] = c;
                else if(b[2][1] == '*')
                    b[2][1] = c;
                else
                    b[1][0] = c;
            }
            else if((b[2][0] == 'X' && b[0][2] == 'X')
                && (b[0][1] == '*' || b[1][2] == '*' || b[2][1] == '*' || b[1][0] == '*'))
            {
                if(b[0][1] == '*')
                    b[0][1] = c;
                else if(b[1][2] == '*')
                    b[1][2] = c;
                else if(b[2][1] == '*')
                    b[2][1] = c;
                else
                {
                    b[1][0] = c;
                    return;
                }
            }

            ///first move
            if(b[1][1] == '*')
                b[1][1] = c;
            else if(b[0][0] == '*')
                b[0][0] = c;
            else if(b[0][2] == '*')
                b[0][2] = c;
            else if(b[2][2] == '*')
                b[2][2] = c;
            else if(b[2][0] == '*')
                b[2][0] = c;
        }
}
