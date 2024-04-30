#include <iostream>
#include <string>

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
    void CambiaReportaA(string ReportaAnuevo){
        this->ReportaA=ReportaAnuevo;
    }
    void Imprime() const {
        cout<<"Clave del Empleado: "<<ClaveEmpleado<<endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: " << Sueldo << endl;
        cout << "ReportaA a: " << ReportaA << endl;
    }
    bool operator ==(const Empleado& otra)const{
        return this->ClaveEmpleado == otra.ClaveEmpleado &&
               this->Nombre == otra.Nombre &&
               this->Domicilio ==otra.Domicilio &&
               this->Sueldo == otra.Sueldo &&
               this->ReportaA == otra.ReportaA;
    }

    bool operator!=(const Empleado& otra)const{
        return !(*this == otra);
    }

    friend ostream& operator<<(ostream& os, const Empleado& empleado){
        os << "Clave del Empleado: " << empleado.ClaveEmpleado
        << "Nombre: " <<empleado.Nombre
        << "Domicilio: "<<empleado.Domicilio
        << "Sueldo: "<<empleado.Sueldo
        <<"Reporta a: "<<empleado.ReportaA;
        return os;
    }
    friend istream& operator>>(istream& is, Empleado& empleado){
        cout<<"Ingrese la clave";
        is >> empleado.ClaveEmpleado;
        cout<<"Ingrese el nombre";
        is >> empleado.Nombre;
        cout<<"Ingrese el domicilio";
        is >> empleado.Domicilio;
        cout<<"Ingrese el sueldo";
        is >> empleado.Sueldo;
        cout<<"Ingrese el nombre de quien reporta";
        is >> empleado.ReportaA;
        return is;
    }

    Empleado operator+(const Empleado& otra)const{
        Empleado nuevoEmpleado(*this);
        nuevoEmpleado.ClaveEmpleado += otra.ClaveEmpleado; //esta sumando las cantidades, no las esta mostrando como cadenas
        nuevoEmpleado.Nombre += " y " + otra.Nombre;
        nuevoEmpleado.Domicilio += " y " + otra.Domicilio;
        nuevoEmpleado.Sueldo += otra.Sueldo;//esta sumando las cantidades, no las esta mostrando como cadenas
        nuevoEmpleado.ReportaA += " y " + otra.ReportaA;
        return nuevoEmpleado;
    }

    bool operator<(const Empleado& otra)const{
        return this->ClaveEmpleado < otra.ClaveEmpleado;
    }

    bool operator>(const Empleado& otra)const{
        return this-> ClaveEmpleado > otra.ClaveEmpleado;
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
    cout<<"4.Cambiar el Nombre de la persona a quien reporta el empleado"<<endl;
    cout<<"5.=="<<endl;
    cout<<"6.!="<<endl;
    cout<<"7.<"<<endl;
    cout<<"8.>"<<endl;
    cout<<"9. +"<<endl;
    cout<<"10.Salir\n"<<endl;
    cin>>opcion;

switch (opcion) {

    case 1:
        cout<<"\tCambiar Domicilio del empleado"<<endl;
        cout<<"1.Jefe planta"<<endl;
        cout<<"2.Jefe personal"<<endl;
        cout<<"Que empleado quieres modificar(escoger numero)"<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Cual es el nuevo Domicilio"<<endl;
                cin>>resp;

                empleado1.CambiaDomic(resp);
                cout<<"dato guardado\n"<<endl;
                cout<<"-----------------"<<endl;
                break;

            case 2:
                cout<<"Cual es el nuevo Domicilio"<<endl;
                cin>>resp;

                empleado2.CambiaDomic(resp);
                cout<<"dato guardado"<<endl;
                cout<<"-----------------"<<endl;
                break;

            default:
                cout<<"No se encontro empleado"<<endl;
        }
        break;

    case 2:

        cout<<"\tCambiar Domicilio del empleado\n"<<endl;

        cout<<"1.Jefe planta"<<endl;
        cout<<"2.Jefe personal"<<endl;
        cout<<"Que empleado quieres modificar(escoger numero)"<<endl;
        cin>>opcion;

        switch(opcion){

            case 1:
                cout<<"Cual es el nuevo Sueldo"<<endl;
                cin>>respSueldo;

                empleado1.ActualSueldo(respSueldo);
                cout<<"dato guardado"<<endl;
                cout<<"-----------------"<<endl;
                break;

            case 2:
                cout<<"Cual es el nuevo Sueldo"<<endl;
                cin>>respSueldo;

                empleado2.ActualSueldo(respSueldo);
                cout<<"dato guardado"<<endl;
                cout<<"-----------------"<<endl;
                break;

            default:
                cout<<"No se encontro empleado"<<endl;
        }
        break;

    case 3:
        cout<<"\t Mostrar empleados registrados \n"<<endl;

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
        cout<<"\tCambiar persona a quien reporta"<<endl;

        cout<<"1.Jefe planta"<<endl;
        cout<<"2.Jefe personal"<<endl;
        cout<<"Que empleado quieres modificar?(escoger numero)"<<endl;
        cin>>opcion;

        switch (opcion){
            case 1:
                cout<<"Cual es el nombre de la nueva persona a quien Reporta"<<endl;
                cin>>resp;

                empleado1.CambiaReportaA(resp);
                cout<<"dato guardado"<<endl;
                cout<<"-----------------"<<endl;
                break;
            case 2:
                cout<<"Cual es la nueva persona a quien ReportaA"<<endl;
                cin>>resp;

                empleado2.CambiaReportaA(resp);
                cout<<"dato guardado"<<endl;
                cout<<"-----------------"<<endl;
                break;}
    case 5:{
        if(empleado1 == empleado2){
            cout<<"Los empleados son iguales"<<endl;
        }else{
            cout<<"Los empleados son diferentes"<<endl;
        }
    }
    break;

    case 6:{
        if(empleado1 != empleado2){
            cout<<"Los empleados son diferentes"<<endl;
            }else{
                cout<<"Los empleados son iguales"<<endl;
            }
        }
    break;
    case 7:
        if (empleado1 < empleado2){
            cout<<"El empleado 1 tiene una clave menor que el empleado 2"<<endl;
        }else{
            cout<<"El empleado 1 no tiene una clave menor que el empleado 2"<<endl;
        }
    break;
    case 8:
        if(empleado1 > empleado2){
            cout<<"El empleado 1 tiene una clave mayor que El empleado 1"<<endl;
        }else{
            cout<<"El empleado 1 no tiene una clave mayor que El empleado 2"<<endl;
        }
    break;
    case 9:{
        Empleado empleadoConcatenado = empleado1 + empleado2;

        cout<<"Empleado Concatenado: "<<endl;
        empleadoConcatenado.Imprime();}
    break;
    case 10:
        break;
    default:
        cout<<"Opcion no valida"<<endl;
        break;
}//del switch
    } //del do
    while (opcion != 10);

return  0;
}









