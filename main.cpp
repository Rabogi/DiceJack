#include <iostream>
#include "lib/dice.h"
#include "lib/Table.h"
#include "lib/player.h"

using ConsoleTable = samilton::ConsoleTable;

void gotoxy(int x,int y);

int main(){
    system("cls");
    ConsoleTable table(1, 1, samilton::Alignment::centre);

    table[0][0] = "Enter first player name";
    table[0][1] = "                       ";
	std::cout << table;
    gotoxy(29,2);
    std::string name = "";
    std::cin >>  name;

    auto Player1 = player(name);
    system("cls");

    table[0][0] = "Enter second player name";
    table[0][1] = "                       ";
	std::cout << table;
    gotoxy(30,2);
    std::cin >>  name;
    auto Player2 = player(name);
    system("cls");

    table[0][0] = "Rule set";
    table[0][1] = "Value";
    table[1][0] = "Dice count";
    table[1][1] = "";
    table[2][0] = "Dice sides";
    table[2][1] = "";
    table[3][0] = "Target";
    table[3][1] = "";
    std::cout << table;
    int count,sides,target = 0;
    gotoxy(16,4);
    std::cin >>  count;
    gotoxy(16,6);
    std::cin >>  sides;
    gotoxy(16,8);
    std::cin >>  target;
    system("cls");
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}