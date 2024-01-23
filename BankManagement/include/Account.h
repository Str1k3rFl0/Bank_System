#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <chrono>
#include <string>
#include <random>

class Account
{
protected:
    std::string _firName;
    std::string _secName;

    std::string _PIN;
    std::string _cvc;

    std::string _numCard;
    std::stringstream _numCardStream;

    std::string _expDate;
    std::stringstream _expDateStream;

public:
    std::string enterPIN();
    std::string genPIN();
    std::string genCVC();
    std::string genNumCard();
    std::string genExpDate();
    void createAccount();
    void showAccount();
    void deleteAccount();
    void deleteAll();
};

#endif // ACCOUNT_H
