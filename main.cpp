#include <iostream>
#include "CalculoPrestamo.h"

int main() {  
    CalculoPrestamo calculoPrestamo(500);
    std::cout << calculoPrestamo.reporteCalculoPrestamo("1A", "8,40%") << std::endl;
    return 0;
}