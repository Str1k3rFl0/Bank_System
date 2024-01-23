#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <conio.h>
#include <string>

class Converter
{
protected:
    std::string _curr1;
    std::string _curr2;
    double _amount1;
    double _amount2;

public:
    void getContinue();
    void convertValue();
};

#endif // CONVERTER_H
