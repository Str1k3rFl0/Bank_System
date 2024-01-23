#include "Menu.h"

void Functions::setColor(unsigned char color)
{
    SetConsoleTextAttribute( GetStdHandle ( STD_OUTPUT_HANDLE ), color);
}

void Functions::gotoxy(int x, int y)
{
    static HANDLE h = nullptr;
    if (!h)
    {
        h = GetStdHandle( STD_OUTPUT_HANDLE );
    }
    COORD c = { x, y };
    SetConsoleCursorPosition( h, c );
}

void Functions::treePattern()
{
    int height { 3 };
    int width { 4 };
    int space { width * 5 };
    int r { 1 };
    int m { 1 };
    gotoxy(0.5f, 5);
    for (r = 1; r <= height; r++)
    {
        for (int i { m }; i <= width; i++)
        {
            for (int j { space }; j >= i; j--)
            {
                std::cout << " ";
            }
            for (int k { 1 }; k <= i; k++)
            {
                std::cout << "* ";
            }
            std::cout << '\n';
        }
        m += 2;
        width += 2;
    }

    for (int i { 1 }; i <= 4; i++)
    {
        for (int j { space - 3 }; j >= 1; j--)
        {
            std::cout << " ";
        }
        for (int k = 1; k <= 4; k++)
        {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

void Functions::marginsPattern(int x, int y)
{
    for (int i { 0 }; i < x; i++)
    {
        for (int j { 0 }; j < y; j++)
        {
            if (i <= 1 || i >= x - 2)
            {
                std::cout << '*';
            }
            else
            {
                if (j <= 1 || j >= y - 2)
                {
                    std::cout << '*';
                }
                else
                {
                    std::cout << ' ';
                }
            }
        }
        std::cout << '\n';
    }
}

void Functions::euroASCII()
{
    gotoxy(80, 5);
    std::cout << R"(
                                                                                            _.-------._
                                                                                        _-'_.------._ `-_
                                                                                      _- _-          `-_/
                                                                                     -  -
                                                                                 ___/  /______________
                                                                                /___  .______________/
                                                                                 ___| |_____________
                                                                                /___  .____________/
                                                                                    \  \
                                                                                     -_ -_             /|
                                                                                       -_ -._        _- |
                                                                                         -._ `------'_./
                                                                                            `-------'    )";
}

void Functions::credits()
{
    system("cls");
    marginsPattern(29, 120);
    gotoxy(37, 11);
    std::cout << "With 30 years of experience on the banking market." << std::endl;
    gotoxy(37, 12);
    std::cout << "Hipodrom Bank is positioned on the market of those" << std::endl;
    gotoxy(37, 13);
    std::cout << "best banks in the World." << std::endl;
    gotoxy(2, 26);
    std::cout << "Press Enter to go to main menu...";
    _getch();
}

void Menu::mainMenu()
{
    char ch{};

    do
    {
        system("cls");
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        euroASCII();
        treePattern();

        gotoxy(45, 6);
        std::cout << "=======================";
        gotoxy(45, 8);
        std::cout << "     HIPODROM BANK     ";
        gotoxy(45, 10);
        std::cout << "=======================";
        gotoxy(50, 13);
        setColor( 0x0A );
        std::cout << "[1] MAIN MENU" << std::endl;
        gotoxy(50, 14);
        setColor( 0x07 );
        std::cout << "[2] CREDITS" << std::endl;
        gotoxy(50, 15);
        setColor( 0x0B );
        std::cout << "[0] EXIT" << std::endl;
        gotoxy(2, 28);
        std::cout << "Choose an option :: ";
        std::cin >> ch;
        system("cls");
        switch (ch)
        {
            case '1': secondMenu(); break;
            case '2': credits(); break;
            case '0': exit(0);
            default: std::cout << "\a";
        }
    } while (ch != '0');
}

void Menu::secondMenu()
{
    char ch{};

    srand(static_cast<unsigned int>(time(nullptr)));

    do
    {
        system("cls");
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        marginsPattern(29, 120);

        gotoxy(45, 6);
        std::cout << "=======================";
        gotoxy(45, 8);
        std::cout << "     HIPODROM BANK     ";
        gotoxy(45, 10);
        std::cout << "=======================";
        gotoxy(50, 13);
        setColor( 0x0A );
        std::cout << "[1] CREATE ACCOUNT" << std::endl;
        gotoxy(50, 14);
        setColor( 0x0C );
        std::cout << "[2] SHOW ACCOUNT" << std::endl;
        gotoxy(50, 15);
        setColor( 0x0E );
        std::cout << "[3] DELETE ACCOUNT" << std::endl;
        gotoxy(50, 16);
        setColor( 0x0D );
        std::cout << "[4] DELETE ALL ACCOUNTS" << std::endl;
        gotoxy(50, 17);
        setColor( 0x07 );
        std::cout << "[5] CONVERTER" << std::endl;
        gotoxy(50, 18);
        setColor( 0x0B );
        std::cout << "[0] BACK TO MENU" << std::endl;
        gotoxy(2, 26);
        std::cout << "Choose an option :: ";
        std::cin >> ch;
        system("cls");
        switch (ch)
        {
            case '1': createAccount(); break;
            case '2': showAccount(); break;
            case '3': deleteAccount(); break;
            case '4': deleteAll(); break;
            case '5': convertValue(); break;
            case '0': break;
            default: std::cout << "\a";
        }
    } while (ch != '0');
}
