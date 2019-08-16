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



 std::string CalculoPrestamo::reporteCalculoPrestamo(std::string tiempoTXT, std::string porcentajeTXT){
     std::string reporte = "Prestamo por mes: \n";
     int tiempo = calcularTiempoEnMeses(tiempoTXT);
     float porcentaje = obtenerPorcentaje(porcentajeTXT);
     float balance = getMonto();
     float nuevoBalance = getMonto();
     float interesMensual = 0;
     for(int mes = 0; mes < tiempo; ++mes){
         interesMensual = calcularInteresMensual(nuevoBalance, porcentaje);
         balance = nuevoBalance;
         nuevoBalance = balance + interesMensual;
         std::string mon = std::to_string(balance);
         reporte = reporte + mon + " \n";
        }
     return reporte;
    }
    float CalculoPrestamo::getMonto(){
        return monto;
    }
    void CalculoPrestamo::setMonto(float amt){
        CalculoPrestamo::monto = amt;
    }
