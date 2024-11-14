/*                            Act 2.3 Actividad Integral de Conceptos B�sicos
                        y Algoritmos Fundamentales (Evidencia en equipo Competencia)
                                Anna Sof�a Ram�rez Castro - A00574296
                                Vanessa Cerda Carrillo - A01612852
                                Ana Maria Rodriguez Pe�a - A01741831

                                                                                                13/10/2024 */
#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>

using namespace std;

class Registro
{
    private:
        int mes;
        string mesS;
        int dia;
        string hora;
        //string IP;
        //***int IPnum[5];
        //string razon;

    public:
        Registro();
        //Registro(int mes,string mesS,int dia,string hora,string IP,string razon);
        Registro(int mes,string mesS,int dia,string hora);

        //gets
        int getMes();
        string getMesS();
        int getDia();
        string getHora();
        /*string getIP();
        string getRazon();*/

        int mesANum(string mesTemp);
        //bool operator<(Registro val);

        //void IPANum(string IPTemp);
        bool operator<(Registro val);
        //bool operator>=(Registro val);

};

#endif // REGISTRO_H
