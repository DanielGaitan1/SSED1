#include <iostream>

/* Programa con los objetos declarados
Jefe planta empleado 1  y Jefe personal empleado 2 a los cuales se les aplican las funciones del menu*/

using namespace std;

class Empleado {

private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;

public:
    //constructor
    Empleado (int ClaveEmpleado, string Nombre, string Domicilio, float Sueldo,string ReportaA){
        this->ClaveEmpleado = ClaveEmpleado;
        this-> Nombre = Nombre;
        this-> Domicilio = Domicilio;
        this-> Sueldo = Sueldo;
        this-> ReportaA = ReportaA;
    }
     void CambiaDomic(string Domicilionuevo){
        this->Domicilio=Domicilionuevo;
    }
     void ActualSueldo(float Sueldonuevo){
        this->Sueldo=Sueldonuevo;
    }
    void CambiaReportaAA(string ReportaAnuevo){
        this->ReportaA=ReportaAnuevo;
    }
    void Imprime() const {
        cout<<"Clave del Empleado: "<<ClaveEmpleado<<endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: " << Sueldo << endl;
        cout << "ReportaA a: " << ReportaA << endl;
    }

};



int main (){

    //Declarando los objetos de tipo empleado
    Empleado empleado1(12345,"jefeplanta","amadonervo123",1000,"gerente");
    Empleado empleado2 (54321,"jefepersonal","Revolucion321",1000,"supervisor");

    int opcion;
do{
    string resp = "";
    float respSueldo=0;

    cout<<"\t Menu\n"<<endl;
    cout<<"1.Cambiar Domicilio de un empleado"<<endl;
    cout<<"2.Actualizar Sueldo de un empleado"<<endl;
    cout<<"3.Imprimir los datos de un empleado"<<endl;
    cout<<"4.Cambiar el Nombre de la persona a quien ReportaA el empleado"<<endl;

    cout<<"5.Salir\n"<<endl;
    cin>>opcion;


switch (opcion) {

    case 1:
        cout<<"Cambiar Domicilio del empleado"<<endl;
        cout<<"1.Jefe planta"<<endl;
        cout<<"2.Jefe personal"<<endl;
        cout<<"Que opcion quieres elegir(escoger numero)"<<endl;
        cin>>opcion;


        switch(opcion){

            case 1:

                cout<<"Cual es el nuevo Domicilio"<<endl;
                cin>>resp;

                empleado1.CambiaDomic(resp);
                cout<<"dato guardado"<<endl;

                break;


            case 2:
                cout<<"Cual es el nuevo Domicilio"<<endl;
                cin>>resp;

                empleado2.CambiaDomic(resp);
                cout<<"dato guardado"<<endl;
                break;

            default:
                cout<<"No se encontro empleado"<<endl;
        }
        break;

    case 2:
        cout<<"entrando a la funcion 2"<<endl;
        cout<<"entrando a la funcion 1 Cambiar Domicilio del empleado"<<endl;

        cout<<"1.Jefe planta"<<endl;
        cout<<"2.Jefe personal"<<endl;
        cout<<"Que opcion quieres elegir(escoger numero)"<<endl;
        cin>>opcion;

        switch(opcion){

            case 1:

                cout<<"Cual es el nuevo Sueldo"<<endl;
                cin>>respSueldo;

                empleado1.ActualSueldo(respSueldo);
                cout<<"dato guardado"<<endl;

                break;

            case 2:

                cout<<"Cual es el nuevo Sueldo"<<endl;
                cin>>respSueldo;

                empleado2.ActualSueldo(respSueldo);
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
                empleado1.Imprime();
                break;
            case 2:
                empleado2.Imprime();
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
                cout<<"Cual es la nueva persona a quien ReportaA"<<endl;
                cin>>resp;

                empleado1.CambiaReportaAA(resp);
                cout<<"dato guardado"<<endl;
                break;
            case 2:
                cout<<"Cual es la nueva persona a quien ReportaA"<<endl;
                cin>>resp;

                empleado2.CambiaReportaAA(resp);
                cout<<"dato guardado"<<endl;

                break;
        }

}//del switch
    } //del do
    while (opcion != 5);

return  0;
}









