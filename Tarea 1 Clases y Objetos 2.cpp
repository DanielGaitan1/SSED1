#include <iostream>

using namespace std;

/*Defina la clase Materia, declare los objetos Programacion y bases de datos

1.Cambiar la clave de la materia programacion
2.Cambiar el nombre del maestro que imparte la materia de basesdedatos
3.Imprimir todos los datos de la materia bases de de datos

*/

class Materia {
    private:
        int Clave;
        string Nombre;
        string ProfesorTit;
        string LibroTexto;
    public:
        //constructor
        Materia(int Clave, string Nombre, string ProfesorTit, string LibroTexto){
            this -> Clave = Clave;
            this -> Nombre = Nombre;
            this -> ProfesorTit = ProfesorTit;
            this -> LibroTexto = LibroTexto;
        }


        void Imprime()const{
            cout<<"----------"<<endl;
            cout<<"Clave:"<<Clave<<endl;
            cout<<"Nombre:"<<Nombre<<endl;
            cout<<"Profesor Titular:"<<ProfesorTit<<endl;
            cout<<"Libro de Texto:"<<LibroTexto<<endl;
            cout<<"---------------------"<<endl;
        }

        void CambiaClave(int claveNueva){
            this -> Clave=claveNueva;
        }

        void CambiaProfe(string ProfeNuevo){
            this ->ProfesorTit = ProfeNuevo;

        }

};


int main()
{
    //Declarando los objetos de tipo Materia
    Materia materia1(1234,"programacion","Profesor Rodriguez","El arte de programar");
    Materia materia2 (5678,"basesDatos","Profesor Ruvalcaba","Principios basicos de estructuras de datos");

    int opcion;
do{
    int resp;
    string resp2 = "";

    cout<<"\t Menu\n"<<endl;
    cout<<"1.Cambiar clave de la materia Programacion"<<endl;
    cout<<"2.Cambiar el nombre del maestro que imparte Bases Datos"<<endl;
    cout<<"3.Imprimir los datos de la materia bases de datos"<<endl;
    cout<<"4.Salir\n"<<endl;
    cin>>opcion;

switch (opcion) {

    case 1:
        cout<<"\tCambiar clave de la materia Programacion"<<endl;
        cout<<"Cual es el nuevo numero clave de la materia Programacion"<<endl;
        cin>>resp;

        materia1.CambiaClave(resp);
        cout<<"\nDato guardado\n"<<endl;
        break;

    case 2:
        cout<<"\t Cambiar el nombre del profesor"<<endl;
        cout<<"Cual es el nombre del nuevo profesor que impartira la materia?"<<endl;
        cin>>resp2;

        materia2.CambiaProfe(resp2);
        cout<<"\nDato guardado\n"<<endl;
        break;

    case 3:
        cout<<"\n\t*************************************************"<<endl;
        cout<<"Imprimiendo los datos de las materias "<<endl;
        materia2.Imprime();
        materia1.Imprime();
        break;

}//del switch
    } //del do
    while (opcion != 4);

    return 0;
}
