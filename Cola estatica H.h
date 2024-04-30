#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <string>

using namespace std;


const int TAM=100;

//***************************Definicion de la clase persona*************************
//**********************************************************************************
class persona
{
private:
    string nombre;
    string carrera;
    int materias;
    float promedio;

public:
    persona();
    void operator=(persona& x);
    persona(std::string n, string c,int e, float p);
    friend std::ostream& operator<<( std::ostream&, persona&);
    friend std::istream& operator>>( std::istream&, persona&);
};
//***************************************************************************************



//****************************Definicion de la clase Pila****************************
//***********************************************************************************
class Cola
{
private:
    persona datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(persona& elem, int pos);
public:
    Cola():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    int ultimo()const;
    friend std::ostream& operator<<(std::ostream & o, Cola& L);
    void enqueue(persona& elem);
    persona& dequeue();

};
//*************************************************************************************

#endif // COLA_H
