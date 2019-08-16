//
// Created by Maikol Guzman  on 2019-08-08.
//
#include <string>
#include <iostream>
#include "CalculoPrestamo.h"

class CalculoPrestamo{
private:
    float monto;
    float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT){
        int a = porcentajeTXT.find("%");
        float porcentaje = std::stof(porcentajeTXT);
            if (a >= 0){
                porcentaje = std::stof(porcentajeTXT.substr(0,a))/100;
                return porcentaje;}
            else return porcentaje;}
    int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT) {
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
    float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual){
        float tasaMensual = tasaAnual / 12;
        float interes = (tasaMensual * balance);
        return interes;}
public:
    calculoPrestamo(){
    monto = 0;
}
 explicit calculoPrestamo( int64_t amt){
    monto = amt;        
}
 std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT){
     std::string reporte = "Prestamo por mes: \n";
     int tiempo = calcularTiempoEnMeses(tiempoTXT);
     float porcentaje = obtenerPorcentaje(porcentajeTXT);
     float balance = getMonto();
     float nuevoBalence = getMonto();
     float interesMensual = 0;
     for(int mes = 0; mes < tiempo; ++mes){
         interesMensual = calcularInteresMensual(nuevoBalence, porcentaje);
         balance = nuevoBalence;
         nuevoBalence = balance + interesMensual;
         reporte = reporte + std::to_string(float balance) + " \n";
        }
     return reporte;
    }
    float CalculoPrestamo::getMonto(){
        return monto;
    }
    void CalculoPrestamo::setMonto(float amt){
        monto = amt;
    }
};