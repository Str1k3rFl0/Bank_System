#include "Account.h"

std::string Account::enterPIN()
{
    std::cout << "\nEnter your PIN :: ";
    std::string pin;
    std::cin >> pin;

    return pin;
}

std::string Account::genPIN()
{
    std::string gPin;
    for (std::size_t i { 0 }; i < 4; ++i)
    {
        gPin += std::to_string(rand() % 10);
    }

    return gPin;
}

std::string Account::genCVC()
{
    std::string gCVC;
    for (std::size_t i { 0 }; i < 3; ++i)
    {
        gCVC += std::to_string(rand() % 10);
    }

    return gCVC;
}

std::string Account::genNumCard()
{
    int n1 = rand() % 9999;
    int n2 = rand() % 9999;
    int n3 = rand() % 9999;
    int n4 = rand() % 9999;
    _numCardStream << std::setw(4) << std::setfill('0') << n1 << ' '
                   << std::setw(4) << n2 << ' '
                   << std::setw(4) << n3 << ' '
                   << std::setw(4) << n4 << std::endl;
    _numCard = _numCardStream.str();
    _numCardStream.str("");

    return _numCard;
}

std::string Account::genExpDate()
{
    std::mt19937_64 mt{static_cast<unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count())};
    std::uniform_int_distribution<int> dist{1, 12};
    std::mt19937 mt1{static_cast<unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count())};
    std::uniform_int_distribution<int> dist1{24, 32};
    _expDateStream << std::setw(2) << std::setfill('0') << dist(mt) << "/" << std::setw(2) << std::setfill('0') << dist1(mt1) << '\n';
    _expDate = _expDateStream.str();
    _expDateStream.str("");

    return _expDate;
}

void Account::createAccount()
{
    std::cout << "\nEnter your first name :: ";
    std::cin >> _firName;

    std::cout << "Enter your second name :: ";
    std::cin >> _secName;

    std::cout << "\nWait to generate your Card Number...\n";
    _numCard = genNumCard();
    Sleep(1200);
    std::cout << "\t[+]Card Number :: " << _numCard << '\n';

    std::cout << "\nWait to generate your Exp. Date...\n";
    _expDate = genExpDate();
    Sleep(1100);
    for (std::size_t i { 0 }; i < 1; ++i)
    {
        std::cout << "\t[+]Exp. Date :: " << _expDate << '\n';
    }

    std::cout << "\nWait to generate your CVC code...\n";
    _cvc = genCVC();
    Sleep(1000);
    std::cout << "\t[+]CVC code :: " << _cvc << '\n';

    std::cout << "\nWait to generate your PIN...\n";
    _PIN = genPIN();
    Sleep(1500);
    std::cout << "\t[+]PIN :: " << _PIN << '\n';

    std::ofstream myFile("database.txt", std::ios::app);
    if (!myFile.is_open())
    {
        std::cerr << "\nYour file can't be opened!" << '\n';
        exit(EXIT_FAILURE);
    }

    myFile << _firName << " " << _secName << " " << _PIN << " "
           << _expDate << " " << _cvc << " " << _numCard << "\n";
    myFile.close();

    std::cout << "\n\nYour account has been created...";
    std::cout << "\nPress ENTER to continue...";
    _getch();
}

void Account::showAccount()
{
    std::string searchPIN { enterPIN() };

    std::ifstream myFile("database.txt");
    if (!myFile.is_open())
    {
        std::cerr << "\nYour file can't be opened!" << '\n';
        exit(EXIT_FAILURE);
    }

    Account acc;
    bool accFound { false };

    while (myFile >> acc._firName >> acc._secName >> acc._PIN >> acc._expDate >> acc._cvc)
    {

        std::getline(myFile >> std::ws, acc._numCard);

        if (acc._PIN == searchPIN)
        {
            accFound = true;
            break;
        }
    }

    myFile.close();

    if (accFound)
    {
        std::cout << "\nFirst name  :: " << acc._firName << "\n";
        std::cout << "\nSecond name :: " << acc._secName << "\n";
        std::cout << "\nPIN :: " << acc._PIN << "\n";
        std::cout << "\nCVC :: " << acc._cvc << "\n";
        std::cout << "\nExp. Date:: " << acc._expDate << "\n";
        std::cout << "\nCard Number :: " << acc._numCard << "\n";
    }
    else
    {
        std::cout << "\nYour PIN isn't founded!" << '\n';
    }

    std::cout << "\nPress ENTER to continue...";
    _getch();
}

void Account::deleteAccount()
{
    std::string searchPIN { enterPIN() };

    std::ifstream myFile("database.txt");
    if (!myFile.is_open())
    {
        std::cerr << "\nYour file can't be opened!" << '\n';
        exit(EXIT_FAILURE);
    }

    std::ofstream myTempFile("temp.txt");
    if (!myFile.is_open())
    {
        std::cerr << "\nYour temp file can't be opened!" << '\n';
        exit(EXIT_FAILURE);
    }

    Account acc;
    bool accFound { false };

    while (myFile >> acc._firName >> acc._secName >> acc._PIN >> acc._expDate >> acc._cvc)
    {
        std::getline(myFile >> std::ws, acc._numCard);

        if (acc._PIN == searchPIN)
        {
            accFound = true;
            continue;
        }

        myTempFile << acc._firName << " " << acc._secName << " " << acc._PIN
                   << " " << acc._expDate << " " << acc._cvc << " " << acc._numCard << '\n';
    }

    myFile.close();
    myTempFile.close();

    if (std::rename("temp.txt", "database.txt") != 0)
    {
        std::cerr << "\nCan't rename the file!\n";
        exit(EXIT_FAILURE);
    }

    if (accFound)
    {
        std::cout << "\nThis account has been deleted with succes!\n";
    }
    else
    {
        std::cout << "\nCan't found this account\n";
    }
}

void Account::deleteAll()
{
    std::ofstream myFile("database.txt", std::ofstream::trunc);

    if (!myFile.is_open())
    {
        std::cerr << "\nYour file can't be opened!" << '\n';
        exit(EXIT_FAILURE);
    }

    myFile.close();

    std::cout << "\nAll accounts has been deleted!" << '\n';
    std::cout << "Press ENTER to continue...";
    _getch();
}
