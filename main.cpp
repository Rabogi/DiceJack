#include <iostream>
#include "lib/dice.h"
#include "lib/Table.h"
#include "lib/player.h"

using ConsoleTable = samilton::ConsoleTable;

void gotoxy(int x, int y);
void PlayTurn(player &CPlayer);
void ShowScoreBoard(player &Player1, player &Player2);
void Pass(player &Player);
void PrintMenu(player &Player1, player &Player2);

int Dcount, Dsides, target = 0;
bool turn = true; // true 1 false 2

ConsoleTable table(1, 1, samilton::Alignment::centre);

int main()
{
    system("cls");

    table.clear();
    table[0][0] = "Enter first player name";
    table[0][1] = "                       ";
    std::cout << table;
    gotoxy(29, 2);
    std::string name = "";
    std::cin >> name;
    auto Player1 = player(name);

    system("cls");
    table.clear();
    table[0][0] = "Enter second player name";
    table[0][1] = "                       ";
    std::cout << table;
    gotoxy(30, 2);
    std::cin >> name;
    auto Player2 = player(name);

    system("cls");
    table.clear();
    table[0][0] = "Rule set";
    table[0][1] = "Value";
    table[1][0] = "Dice count";
    table[1][1] = "";
    table[2][0] = "Dice sides";
    table[2][1] = "";
    table[3][0] = "Target";
    table[3][1] = "";
    std::cout << table;
    gotoxy(16, 4);
    std::cin >> Dcount;
    gotoxy(16, 6);
    std::cin >> Dsides;
    gotoxy(16, 8);
    std::cin >> target;
    system("cls");

    while (Player1.Passed == false || Player2.Passed == false)
    {
        system("cls");
        PrintMenu(Player1, Player2);
        int choice = 0;
        std::cin >> choice;
        if (turn == true)
        {
            switch (choice)
            {
            case 1:
                PlayTurn(Player1);
                break;
            case 2:
                Pass(Player1);
                turn = !turn;
                break;
            }
        }
        else
        {
            switch (choice)
            {
            case 1:
                PlayTurn(Player2);
                break;
            case 2:
                Pass(Player2);
                turn = !turn;
                break;
            }
        }
        if(Player1.Passed == false && Player2.Passed == false)
            turn = !turn;
    }
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void PlayTurn(player &CPlayer)
{
    auto d = dice(Dsides);
    for (int i = 0; i < Dcount; ++i)
    {
        CPlayer.setScore(CPlayer.getScore() + d.roll());
    }
}

void ShowScoreBoard(player &Player1, player &Player2)
{
    table.clear();
    table[0][0] = "Name";
    table[0][1] = "Score";
    table[1][0] = Player1.getName();
    table[1][1] = to_string(Player1.getScore());
    table[2][0] = Player2.getName();
    table[2][1] = to_string(Player2.getScore());
    table[3][0] = "Target";
    table[3][1] = to_string(target);

    std::cout << table;
}

void Pass(player &Player)
{
    Player.Passed = true;
}

void PrintMenu(player &Player1, player &Player2)
{
    ShowScoreBoard(Player1, Player2);
    table.clear();
    switch (turn)
    {
    case true:
        table[0][0] = Player1.getName() + "'s turn";
        break;
    case false:
        table[0][0] = Player2.getName() + "'s turn";
        break;

    default:

        break;
    }
    table[1][0] = "(1) Roll";
    table[2][0] = "(2) Pass";
    std::cout << table;

    table.clear();
    table[0][0] = "Your choice";
    table[0][1] = "           ";
    std::cout << table;
    gotoxy(17, 18);
}
