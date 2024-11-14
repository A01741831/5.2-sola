/*                            Act 2.3 Actividad Integral de Conceptos B�sicos
                        y Algoritmos Fundamentales (Evidencia en equipo Competencia)
                                Anna Sof�a Ram�rez Castro - A00574296
                                Vanessa Cerda Carrillo - A01612852
                                Ana Maria Rodriguez Pe�a - A01741831

                                                                                                13/10/2024 */
#include "Registro.h"
#include <iostream>
#include <unordered_map>

Registro::Registro()
{
    mes=0;
    mesS="";
    dia=0;
    hora="";
    /*IP="";
    razon="";*/

}

Registro::Registro(int mes,string mesS,int dia,string hora)
{
    this->mesS=mesS;
    this->dia=dia;
    this->hora=hora;
    mesANum("");
}

int Registro::getMes()
{
    return mes;
}

string Registro::getMesS()
{
    return mesS;
}

int Registro::getDia()
{
    return dia;
}

string Registro::getHora()
{
    return hora;
}

/*string Registro::getIP()
{
    return IP;
}

string Registro::getRazon()
{
    return razon;
}*/

int Registro::mesANum(string mesTemp)
{
    /*if (mesTemp=="") {
        mesTemp=mesS;
    }
    unordered_map<string,int> meses={
    {"Jan",1}, {"Feb",2}, {"Mar",3}, {"Apr",4}, {"May",5}, {"Jun",6}, {"Jul",7}, {"Aug",8}, {"Sep",9}, {"Oct",10}, {"Nov",11}, {"Dec",12}
    };

    mes=meses[mesTemp];*/
    if(mesTemp.empty()) {
        mesTemp=mesS;
    }

    unordered_map<string, int>meses={
        {"Jan",1},{"Feb",2},{"Mar",3},{"Apr",4},{"May",5},{"Jun",6},{"Jul",7},{"Aug",8},{"Sep",9},{"Oct",10},{"Nov",11},{"Dec",12}
    };

    auto it=meses.find(mesTemp);
    if(it!=meses.end()) {
        return it->second;
    }else{
        // Lanzar una excepción o retornar un valor de error si el mes no es válido
        throw invalid_argument("Mes inválido: " + mesTemp);
    }
}

bool Registro::operator<(Registro val) //! COMPARAR CON HORA
{

    if (mes==val.mes) {
        return dia<val.dia;
    }
    else {
        return mes<val.mes;
    }
}