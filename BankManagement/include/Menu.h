#ifndef MENU_H
#define MENU_H

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctime>

#include "Converter.h"
#include "Account.h"

class Functions
{
public:
    void setColor(unsigned char color);
    void gotoxy(int x, int y);
    void treePattern();
    void marginsPattern(int x, int y);
    void euroASCII();
    void credits();
};

class Menu : public Functions, public Converter, public Account
{
public:
    void mainMenu();
    void secondMenu();
};

#endif // MENU_H
