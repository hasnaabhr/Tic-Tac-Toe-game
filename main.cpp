#include<iostream>
#include<string>
using namespace std;


char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int row;
int column;
char TokenChar = 'x';
string  name_of_player1 = " ", name_of_player2 = " ";
bool draw = false;
int count;
void drawboard()
{


    cout << "|--------------------|\n";

    cout << "|" << board[0][0] << "     |   " << board[0][1] << "  |   " << board[0][2] << "  | " << "\n";
    cout << "|------|------|------|\n";

    cout << "|      |      |      |\n";
    cout << "|" << board[1][0] << "     |   " << board[1][1] << "  |   " << board[1][2] << "  | " << "\n";
    cout << "|------|------|------|\n";

    cout << "|      |      |      |\n";
    cout << "|" << board[2][0] << "     |  " << board[2][1] << "   |   " << board[2][2] << "  | " << "\n";
    cout << "|--------------------|\n";

}
void YourTurn()
{
    int number = 1;
 ++count;
    if (TokenChar == 'x')
    {
        cout << "Enter a number between[1,9] (inclusive)\n";
        cout << " It is X Turn\n";
        cin >> number;}
    if (TokenChar== 'O')
    {
        cout << "Enter a number between[1,9] (inclusive)\n";
        cout << " It is O Turn\n";
        cin >> number;}
switch(number)
{
    case 1:row = 0;column = 0;break;
    case 2:row = 0;column = 1;break;
    case 3:row = 0;column = 2;break;
    case 4:row = 1;column = 0;break;
    case 5 :row = 1;column = 1;break;
    case 6:row = 1;column = 2;break;
    case 7:row = 2;column = 0;break;
    case 8:row = 2;column = 1;break;
    case 9 :row = 2;column = 2;break;
    default:cout<<"Invalid Input\n";
        system("pause");
        count--;
        break;
}
    //check if there is a space or not
    if (TokenChar == 'x' && board[row][column] != 'x' && board[row][column] != 'O')
    {
        board[row][column] = 'x';
        TokenChar = 'O';
    }
    else if (TokenChar == 'O' && board[row][column] != 'x' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        TokenChar = 'x';
    }
    else
    {
        "There is no empty space\n";

        YourTurn();
    }
    drawboard();
}
bool WhoIsTheWinner()
{
    for (int i = 0; i < 3; i++)
    {

        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return false;
    }
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'x' && board[i][j] != 'O')
            {
                return true;
            }
        }
    }
    draw = true;
    return false;
}
DisPlay()
{
     while (1)
    {
        cout << "Enter The name of the first player : \n";
        cin >> name_of_player1;
        cout << "Enter The name of the second player : \n";
        cin >> name_of_player2;
        cout << name_of_player1 << " : is the first player so,he/she will play first\n";
        cout << name_of_player2 << " : is the second player so,he/she will play second\n";
     while (WhoIsTheWinner())
        {
            drawboard();
            YourTurn();
            WhoIsTheWinner();
            cout << "\n";
        }
        if (TokenChar == 'x' && draw == false)
        {
            cout <<"O is the winner .";
            break; }
        else if (TokenChar == 'O' && draw == false)
        {
            cout<<"X is the winner .";
            break;}
        else if (count == 9)
        {
            cout << "draw .";
            break;}}
}
int main()
{
    int choice;
Start:
    DisPlay();

    cout << "Do you want to play game ?\n ";
    cout<<"Enter 0 to exit,1 to continue\n";
    cin >> choice;
    if (choice ==1)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = i * 3 + (j + 1) + 48;
            }
        }
       count = 0;
        TokenChar = 'x';
goto Start;
    }

    else
    {
        return 0;
    }

    return 0;
}
