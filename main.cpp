/*                            Act 2.3 Actividad Integral de Conceptos B�sicos
                        y Algoritmos Fundamentales (Evidencia en equipo Competencia)
                                Anna Sof�a Ram�rez Castro - A00574296
                                Vanessa Cerda Carrillo - A01612852
                                Ana Maria Rodriguez Pe�a - A01741831

                                                                                                13/10/2024 */
#include "Bitacora.h"
#include "Registro.h"
#include <iostream>

using namespace std;

int main()
{
    Bitacora datos;
    cout<<"Leyendo archivo."<<endl;
    datos.leer();
    cout<<"Archivo leido."<<endl;

    cout<<"\nBUSQUEDAS"<<endl;
    datos.busqueda();

    return 0;
}
