#include <iostream>
#include <stdlib.h>
using namespace std;

int choice, row, column;
char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
bool draw = false;

void display_game()
{

    system("cls");
    cout << "\t\t TIC TOE GAME" << endl;
    cout << "\t\t Player1 [X] \n\t\t Player2[O]" << endl
         << endl
         << endl;

    // Drawing Design
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";

    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";

    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << arr[2][0] << "  |  " << arr[2][1] << "  |  " << arr[2][2] << "  \n";
    cout << "\t\t     |     |     \n";
}

void player_turn()
{

    if (turn == 'X')
    {
        cout << "\n\t Player1 [X] turn:- ";
    }
    else
    {
        cout << "\n\t Player2 [O] turn:- ";
    }
    //cout<<"\n\n Player1 [X] turn:- ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    if (turn == 'X' && arr[row][column] != 'X' && arr[row][column] != 'O')
    {
        arr[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && arr[row][column] != 'X' && arr[row][column] != 'O')
    {
        arr[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Box already filled \n Please try again";
    }
    display_game();
}

bool gameover()
{
    //win
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] || arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
        {
            return false;
        }
    }

    //cross win
    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] || arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
    {
        return false;
    }
    // box not filled,remaining
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 'X' && arr[i][j] != 'O')
            {
                return true;
            }
        }
    }
    //draw
    draw = true;
    return false;
}

int main()
{

    while (gameover())
    {

        display_game();
        player_turn();
    }

    if (turn == 'X' && draw == false)
    {
        cout << " Player2 [O] Wins. Congratulations ";
    }
    else if (turn == 'O' && draw == false)
    {
        cout << " Player1 [X] Wins. Congratulations ";
    }
    else
    {
        cout << "Game Draw \n";
    }

    return 0;
}
