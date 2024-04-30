#include <iostream>

/* Programa con los objetos declarados
Jefe planta empleado 1  y Jefe personal empleado 2 a los cuales se les aplican las funciones del menu*/
//Tiene error en las variables hasta el final me di cuenta que la tarea especificaba ciertos nombres para variables

using namespace std;

class Empleado {

private:
    string nombre;
    string domicilio;
    float sueldo;
    string reporta;

public:
    //constructor
    Empleado (string nombre, string domicilio, float sueldo,string reporta){
        this-> nombre = nombre;
        this-> domicilio = domicilio;
        this-> sueldo = sueldo;
        this-> reporta = reporta;
    }
     void setDomicilio(string domicilionuevo){
        this->domicilio=domicilionuevo;
    }
     void setSueldo(float sueldonuevo){
        this->sueldo=sueldonuevo;
    }
    void setReporta(string reportanuevo){
        this->reporta=reportanuevo;
    }
    void imprimirEmpleado() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta a: " << reporta << endl;
    }

};



int main (){

    //Declarando los objetos de tipo empleado
    Empleado empleado1("jefeplanta","amadonervo123",1000,"gerente");
    Empleado empleado2 ("jefepersonal","Revolucion321",1000,"supervisor");

    int opcion;
do{
    string resp = "";
    float respsueldo=0;

    cout<<"\t Menu\n"<<endl;
    cout<<"1.Cambiar domicilio de un empleado"<<endl;
    cout<<"2.Actualizar sueldo de un empleado"<<endl;
    cout<<"3.Imprimir los datos de un empleado"<<endl;
    cout<<"4.Cambiar el nombre de la persona a quien reporta el empleado"<<endl;

    cout<<"5.Salir\n"<<endl;
    cin>>opcion;


switch (opcion) {

    case 1:
        cout<<"Cambiar domicilio del empleado"<<endl;
        cout<<"1.Jefe planta"<<endl;
        cout<<"2.Jefe personal"<<endl;
        cout<<"Que opcion quieres elegir(escoger numero)"<<endl;
        cin>>opcion;


        switch(opcion){

            case 1:

                cout<<"Cual es el nuevo domicilio"<<endl;
                cin>>resp;

                empleado1.setDomicilio(resp);
                cout<<"dato guardado"<<endl;

                break;


            case 2:
                cout<<"Cual es el nuevo domicilio"<<endl;
                cin>>resp;

                empleado2.setDomicilio(resp);
                cout<<"dato guardado"<<endl;
                break;

            default:
                cout<<"No se encontro empleado"<<endl;
        }
        break;

    case 2:
        cout<<"entrando a la funcion 2"<<endl;
        cout<<"entrando a la funcion 1 Cambiar domicilio del empleado"<<endl;

        cout<<"1.Jefe planta"<<endl;
        cout<<"2.Jefe personal"<<endl;
        cout<<"Que opcion quieres elegir(escoger numero)"<<endl;
        cin>>opcion;

        switch(opcion){

            case 1:

                cout<<"Cual es el nuevo sueldo"<<endl;
                cin>>respsueldo;

                empleado1.setSueldo(respsueldo);
                cout<<"dato guardado"<<endl;

                break;

            case 2:

                cout<<"Cual es el nuevo sueldo"<<endl;
                cin>>respsueldo;

                empleado2.setSueldo(respsueldo);
                cout<<"dato guardado"<<endl;

                break;
            default:
                cout<<"No se encontro empleado"<<endl;


        }
        break;

    case 3:
        cout<<"entrando a la funcion 3"<<endl;

        cout<<"1.Jefe planta"<<endl;
        cout<<"2.Jefe personal"<<endl;
        cout<<"Que opcion quieres elegir(escoger numero)"<<endl;
        cin>>opcion;

        switch (opcion){
            case 1:
                empleado1.imprimirEmpleado();
                break;
            case 2:
                empleado2.imprimirEmpleado();
                break;
        }
        break;

    case 4:
        cout<<"entrando a la funcion 4"<<endl;

        cout<<"1.Jefe planta"<<endl;
        cout<<"2.Jefe personal"<<endl;
        cout<<"Que opcion quieres elegir(escoger numero)"<<endl;
        cin>>opcion;

        switch (opcion){

            case 1:
                cout<<"Cual es la nueva persona a quien reporta"<<endl;
                cin>>resp;

                empleado1.setReporta(resp);
                cout<<"dato guardado"<<endl;
                break;
            case 2:
                cout<<"Cual es la nueva persona a quien reporta"<<endl;
                cin>>resp;

                empleado2.setReporta(resp);
                cout<<"dato guardado"<<endl;

                break;
        }

}//del switch
    } //del do
    while (opcion != 5);

return  0;
}









