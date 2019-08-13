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
    float obtenerPorcentaje(std::string porcentajeTXT){
        int a = porcentajeTXT.find(%);
        return  std::substr(0,a);}
    int calcularTiempoEnMeses(std::string tiempoTXT) {
        int a = tiempoTXT.find("A");
        float b = std::stof(tiempoTXT);
        if (a == 0)
            return (b * 12);
        
        return (b);}
    float calcularInteresMensual(float balance, float tasaAnual){
    return 0;}
public
CalculoPrestamo(){
    monto = 0;            
}
CalculoPrestamo( int64_t ){
    monto = 0;            
}

//std::string reporte = reporte + "Texto \n"

    
        
};


#endif //CALCULOPRESTAMO_CALCULOPRESTAMO_H
