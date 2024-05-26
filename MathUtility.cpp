#include "MathUtility.h"

namespace ns
{

int factorial(const int& num)
{
    if (num < 0)
        throw std::invalid_argument("Argument to factorial() must be non-negative.");

    int fact {1};

    for (int i = num; i > 0; --i)
        fact *= i;
    
    return fact;
}

}