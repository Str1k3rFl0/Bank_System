#include "Converter.h"

void Converter::getContinue()
{
    std::cout << "\n\nPress ENTER to go to main menu...";
    _getch();
}

void Converter::convertValue()
{
    system("cls");
    std::cout << "\n==========================\n";
    std::cout << "\n         CONVERT          \n";
    std::cout << "\n==========================\n";
    std::cout << "Enter an currency [RON, EURO, USD] :: ";
    std::cin >> _curr1;
    std::cout << "Enter an currency to convert with " << _curr1 << " :: ";
    std::cin >> _curr2;
    std::cout << "Enter amount money to convert :: ";
    std::cin >> _amount1;

    if (_curr1 == "RON")
    {
        if (_curr2 == "EURO")
        {
            _amount2 = _amount1 * .23;
            std::cout << _amount1 << " RON is equal to " << _amount2 << " EURO";
            getContinue();
        }
        else if (_curr2 == "USD")
        {
            _amount2 = _amount1 * .25;
            std::cout << _amount1 << " RON is equal to " << _amount2 << " USD";
            getContinue();
        }
    }

    if (_curr1 == "EURO")
    {
        if (_curr2 == "RON")
        {
            _amount2 = _amount1 * 4.98;
            std::cout << _amount1 << " EURO is equal to " << _amount2 << " RON";
            getContinue();
        }
        else if (_curr2 == "USD")
        {
            _amount2 = _amount1 * 1.08;
            std::cout << _amount1 << " EURO is equal to " << _amount2 << " USD";
            getContinue();
        }
    }

    if (_curr1 == "USD")
    {
        if (_curr2 == "RON")
        {
            _amount2 = _amount1 * 4.80;
            std::cout << _amount1 << " USD is equal to " << _amount2 << " RON";
            getContinue();
        }
        else if (_curr2 == "EURO")
        {
            _amount2 = _amount1 * 0.97;
            std::cout << _amount1 << " USD is equal to " << _amount2 << " EURO";
            getContinue();
        }
    }
}
