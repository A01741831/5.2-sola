/*                            Act 2.3 Actividad Integral de Conceptos B�sicos
                        y Algoritmos Fundamentales (Evidencia en equipo Competencia)
                                Anna Sof�a Ram�rez Castro - A00574296
                                Vanessa Cerda Carrillo - A01612852
                                Ana Maria Rodriguez Pe�a - A01741831

                                                                                                13/10/2024 */
#include "Bitacora.h"
#include "Registro.h"
#include "MyLinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <functional>
#include <cmath>

using namespace std;

Bitacora::Bitacora() // Complejidad: O(1) (no depende de par�metros variables)
{
    size=0;
    sizeA=32000;
    this->tabla=new MyLinkedList[this->sizeA];
}

void Bitacora::consultaOtraIP() {
    int opcion;
    cout << "¿Desea consultar otra IP? (1 para sí, 0 para no): ";
    cin>>opcion;
    if (opcion==1) {
        busqueda();
    }
}

void Bitacora::leer()
{
    ifstream archivo;
    string linea;
    int mes;
    string mesS;
    int dia;
    string hora;
    string IP;
    string razon;

    archivo.open("bitacora3.txt",ios::in);
    if(archivo.fail()){
        cout<<"El archivo no se pudo abrir";
        exit(1);
    }

    while (getline(archivo, linea)) {
        istringstream iss(linea);
        iss>>mesS>>dia>>hora>>IP;
        getline(iss, razon);

        Registro dato(mes,mesS,dia,hora);
        put(IP,dato);
    }

    archivo.close();
}

int Bitacora::getPos(string key) // Complejidad: O(1)
{
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%sizeA;
}

bool Bitacora::isEmpty() // Complejidad: O(1)
{
    return size==0;
}

void Bitacora::put(string key, Registro value) // Complejidad: O(1) si no hay colisiones.
{                                            // Si el factor de carga excede de 0.75 (se llama a rehashing()), la complejidad es O(n)
    int index;
    float factorCarga;

    //quitar puerto
    size_t pos = key.find(":"); // Encuentra la posici�n de ":"
    key=key.substr(0, pos);
    //

    index=getPos(key);
    tabla[index].insertFirst(key,value);
    size++;

    float f_size=size;
    float f_sizeA=sizeA;
    factorCarga=f_size/f_sizeA;
    if (factorCarga>0.75) {
        cout<<"entro a rehashing"<<endl;
        rehashing();
    }
}

void Bitacora::rehashing() // Complejidad: O(n)
{
    int prevSize=this->sizeA;
    this->sizeA=2*prevSize+1;

    MyLinkedList* prevTabla=tabla;
    this->tabla=new MyLinkedList[sizeA];
    this->size=0;

    MyNodoLL* current;

    for (int i=0;i<prevSize;i++) {
        MyLinkedList& currentList=prevTabla[i];
        if (!currentList.isEmpty()) {
            current=currentList.getHead();
            while (current!=nullptr) {
                for (int i=0;i<current->data.size();i++) { //! Solo ocupo reubicar las IPs, no cada registro asociado
                    put(current->key,current->data[i]);
                }
                current=current->next;
            }
        }
    }

    delete[] prevTabla;
}

Registro Bitacora::get(string key) // Complejidad: O(1)
{                                  // La complejidad aumenta mientras m�s colisiones haya, ya que se deben recorrer listas enlazadas m�s grandes.
    int index=getPos(key);         // En el peor caso, se recorre toda la lista.
    vector<Registro> vec;

    try{
        vec=this->tabla[index].getAt(key);
    } catch(const invalid_argument& e) {
        throw;
    }

    quickSort(vec);

    for(int i=0;i<vec.size();i++) {
        cout<<vec[i].getMesS()<<" "<<vec[i].getDia()<<" "<<vec[i].getHora()<<endl;
    }

    // Verificar si el vector no está vacío y devolver el primer elemento
    if(!vec.empty()){
        return vec[0];
    }else{
        // Si no hay resultados, lanzar una excepción o devolver un objeto vacío de tipo Registro
        throw invalid_argument("No se encontraron registros con la clave dada.");
    }
}

void Bitacora::remove(string key)  // Complejidad: O(1)
{                                  // Al igual que get(), la complejidad aumenta mientras m�s colisiones haya.
    int index=getPos(key);         // En el peor caso, se recorre toda la lista.

    try {
        if (!this->tabla[index].isEmpty()) {
            this->tabla[index].removeAt(key);
        } else {
            throw invalid_argument("No es posible eliminar elementos de una lista vacia.");
        }
    } catch (invalid_argument& e) {
        throw;
    }
}

void Bitacora::busqueda()
{
   string IPbusq;
    cout<<"Ingrese la IP que desea buscar: ";
    cin>>IPbusq;

    size_t pos=IPbusq.find(":");
    if(pos!=string::npos) {
        IPbusq=IPbusq.substr(0,pos);
    }

    try{
        get(IPbusq);
    }catch(const invalid_argument& e) {
        cout<<"La IP no se encontró en la tabla hash."<<endl;
    }
    
    consultaOtraIP();
}

void Bitacora::swapD(vector<Registro>& info, int i, int j)
{
    Registro aux=info[i];
    info[i]=info[j];
    info[j]=aux;
}

int Bitacora::particion(vector<Registro>& info, int ini, int fin)
{
    int pivote=ini;
    int i=ini+1;

    for(int j=i;j<=fin;j++) {
        if(info[j]<info[pivote]) {
            swapD(info,i,j);
            i+=1;
        }
    }

    swapD(info,ini,i-1);

    return i-1;
}

void Bitacora::quickSort(vector<Registro>& info)
{
    quickSort(info,0,info.size()-1);
}

void Bitacora::quickSort(vector<Registro>& info, int ini, int fin)
{
    if (ini<fin) {
        int posPivote=particion(info,ini,fin);
        quickSort(info,ini,posPivote-1);
        quickSort(info,posPivote+1,fin);
    }
}

Bitacora::~Bitacora() // Complejidad: O(n) (recorre todas las listas enlazadas del arreglo)
{

}
