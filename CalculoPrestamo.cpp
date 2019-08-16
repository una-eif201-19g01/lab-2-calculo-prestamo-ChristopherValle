//
// Created by Maikol Guzman  on 2019-08-08.
//
// Christopher Valle Peraza
//
#include <string>
#include <iostream>
#include "CalculoPrestamo.h"

    CalculoPrestamo::CalculoPrestamo() {}
    CalculoPrestamo::CalculoPrestamo(int64_t amt) : monto(amt) {}  

    float CalculoPrestamo::obtenerPorcentaje(std::string porcentajeTXT){
        int porc = porcentajeTXT.find("%");
        float porcentaje = std::stof(porcentajeTXT);
            if (porc >= 0){
                porcentaje = std::stof(porcentajeTXT.substr(0,porc))/100;
                return porcentaje;
            }
            else return porcentaje;
    }
    int CalculoPrestamo::calcularTiempoEnMeses(std::string tiempoTXT) {
        int findAno = tiempoTXT.find("A");
        int findMes = tiempoTXT.find("M");
        int tiempo = 0;
        if (findAno > 0){
            int ano = 0;
            ano = std::stoi(tiempoTXT.substr(0,findAno));
            tiempo = ano * 12;
            return tiempo;
        }
        else
            tiempo = std::stoi(tiempoTXT.substr(0,findMes));
            return tiempo;
    }
    float CalculoPrestamo::calcularInteresMensual(float balance, float tasaAnual){
        float tasaMensual = tasaAnual / 12;
        float interes = (tasaMensual * balance);
        return interes;
    }


    std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT){
        std::string reporte = "Calcular Prestamo: \n";
        int tiempo = calcularTiempoEnMeses(tiempoTXT);
        float porcentaje = obtenerPorcentaje(porcentajeTXT);
        float balance = getMonto();
        float nuevoBalance = getMonto();
        float interesMensual = 0;
        for(int mes = 1; mes <= tiempo; ++mes){
            interesMensual = calcularInteresMensual(nuevoBalance, porcentaje);
            balance = nuevoBalance;
            nuevoBalance = balance + interesMensual;
            std::string mon = std::to_string(balance);
            reporte = "Tasa [" + std::to_string(porcentaje) + "], Mes[" + std::to_string(mes) + "], Balance inicial[" +  std::to_string(balance) + "], Balance Nuevo[" +  std::to_string(nuevoBalance) + "], Interes [" +  std::to_string(interesMensual) + "], Balance Nuevo[" + std::to_string(nuevoBalance) + "]\n";
        }
     return reporte;
    }
    float CalculoPrestamo::getMonto(){
        return monto;
    }
    void CalculoPrestamo::setMonto(float amt){
        CalculoPrestamo::monto = amt;
    }
