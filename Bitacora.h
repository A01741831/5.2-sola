/*                            Act 2.3 Actividad Integral de Conceptos B�sicos
                        y Algoritmos Fundamentales (Evidencia en equipo Competencia)
                                Anna Sof�a Ram�rez Castro - A00574296
                                Vanessa Cerda Carrillo - A01612852
                                Ana Maria Rodriguez Pe�a - A01741831

                                                                                                13/10/2024 */
#ifndef BITACORA_H
#define BITACORA_H
#include "Registro.h"
#include "MyLinkedList.h"


class Bitacora
{
    private:
        int size; // # de elementos almacenados en la hash table
        int sizeA; // Tama�o del arreglo
        MyLinkedList* tabla; // Arreglo de listas enlazadas
        void rehashing(); // Se llama cuando al hacer el put el factor de carga es mayor a 0.75. Crecer arr a 2n+1 y copiar elementos.
        int getPos(string key);
        bool isEmpty();

        void swapD(vector<Registro>& info, int i, int j);
        void quickSort(vector<Registro>& info);
        void quickSort(vector<Registro>& info, int ini, int fin);
        int particion(vector<Registro>& info, int ini, int fin);

    public:
        Bitacora();

        void put(string key, Registro value); //insertFirst
        Registro get(string key); //getAt
        void remove(string key); //removeAt
        void leer();
        void busqueda();
        void consultaOtraIP();

        virtual ~Bitacora();
};

#endif // BITACORA_H
