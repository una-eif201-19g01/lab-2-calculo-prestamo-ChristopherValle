//
// Created by Maikol Guzman  on 2019-08-08.
//

#ifndef CALCULOPRESTAMO_CALCULOPRESTAMO_H
#define CALCULOPRESTAMO_CALCULOPRESTAMO_H


#include <cstdint>
#include <string>

class CalculoPrestamo{
private:
    float monto;
    float obtenerPorcentaje(std::string porcentajeTXT);
    int calcularTiempoEnMeses(std::string tiempoTXT);
    float calcularTiempoEnMeses(std::string tiempoTXT);
public:
    CalculoPrestamo();
    CalculoPrestamo(int64_t monto);
    reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT);
    float getMonto();
    void setMonto();
};

    
#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H