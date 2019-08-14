//
// Created by Maikol Guzman  on 2019-08-08.
//

#include <iostream>
#include "CalculoPrestamo.h"

class CalculoPrestamo{
private:
    float monto;
    float obtenerPorcentaje(std::string porcentajeTXT){
        int a = porcentajeTXT.find("%");
        float porcentaje = std::stof(porcentajeTXT);
            if (a >= 0){
                porcentaje = std::stof(porcentajeTXT.substr(0,a))/100;
                return porcentaje;}
            else return porcentaje;}
    int calcularTiempoEnMeses(std::string tiempoTXT) {
        int findano = tiempoTXT.find("A");
        int findmes = tiempoTXT.find("M");
        int tiempo = 0;
        if (findano > 0){
            int ano = 0;
            ano = std::stoi(tiempoTXT.substr(0,findano));
            tiempo = ano * 12;
            return tiempo;}
        else
            tiempo = std::stoi(tiempoTXT.substr(0,findmes));
            return tiempo;}
    float calcularInteresMensual(float balance, float tasaAnual){
    return 0;}
public
    calculoPrestamo(){
    monto = 0;
}
 explicit calculoPrestamo( int64_t amt){
    monto = amt;            
}
 

//std::string reporte = reporte + "Texto \n"

    
        
};