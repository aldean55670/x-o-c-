#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int x;
int o = 0;
int count = 0;
bool check_win()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }
    return false;
}

void world()
{
    system("cls");
    // cout << "_____________________\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    // cout << "|__"<<board[0][0]<<"__|___"<<board[0][1]<<"___|__"<<board[0][2]<<"__|\n";
    // cout << "|__"<<board[1][0]<<"__|___"<<board[1][1]<<"___|__"<<board[1][2]<<"__|\n";
    // cout << "|__"<<board[2][0]<<"__|___"<<board[2][1]<<"___|__"<<board[2][2]<<"__|\n";
}

void game()
{
    world();
    while (1)
    {
        cout << "X : ";
        cin >> x;
        if (x < 0 || x > 9)
        {
            do
            {
                cout << "put number from (1) to (9) \n";
                cout << "X :";
                cin >> x;
            } while (x < 0 || x > 9);
        }

        if (x == o)
        {

            do
            {
                cout << "the space is busy \n";
                cout << "X :";
                cin >> x;
            } while (x == o || x == x);
        }

        // space of   x اماكن العب
        // space of   x اماكن العب
        int row = (x - 1) / 3;
        int col = (x - 1) % 3;

        for (int i = 0; i < 9; i++)
        {

            if (x == i + 1)
            {
                board[row][col] = 'x';
            }
        }
        count++;
        world();
        // becuse you win

        if (check_win())
        {
            cout << "X is win!" << endl;
            break;
        }
        if (count == 9)
        {
            cout << "drow" << endl;
            break;
        }

        cout << "O : ";
        cin >> o;

        if (o < 0 || o > 9)
        {

            do
            {
                cout << "put number from (1) to (9) \n";
                cout << "o :";
                cin >> o;
            } while (o < 0 || o > 9);
        }

        if (o == x)
        {

            do
            {
                cout << "the space is busy \n";
                cout << "o :";
                cin >> o;
            } while (o == x);
        }

        // space of   o اماكن العب
        int ro = (o - 1) / 3;
        int co = (o - 1) % 3;

        for (int i = 0; i < 9; i++)
        {

            if (o == i + 1)
            {
                board[ro][co] = 'o';
            }
        }
        if (check_win())
        {
            cout << "O is win!" << endl;
            break;
        }
        count++;
        world();
        if (count == 9)
        {
            cout << "drow" << endl;
            break;
        }
    }
}
int main()
{
    game();
    string name;
    if (check_win())
    {
        cout << "what's your name ? ";
        cin >> name;
        cout << name << " is king  \n ";
    }
}
