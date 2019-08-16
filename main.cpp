#include <iostream>
#include "CalculoPrestamo.h"

int main() {
    float amt = 100;
    CalculoPrestamo calculoPrestamo(amt);
    std::cout<<CalculoPrestamo.reporteCalculoPrestamo("3A", "0.25%") << std::endl;
    return 0;
}