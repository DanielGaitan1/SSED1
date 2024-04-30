#include <iostream>

using namespace std;

/*Incluya en la clase anteriores
la sobrecarga de los siguientes operadores: ==, !=, >>, <<, +, < y >, de tal manera que
dos objetos se puedan comparar (==, !=, <,>) o unir (+) usando los operadores indicados.*/

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

        // Sobrecarga de operadores
    bool operator==(const Materia& otra) const {
        return this->Clave == otra.Clave && this->Nombre == otra.Nombre &&
               this->ProfesorTit == otra.ProfesorTit && this->LibroTexto == otra.LibroTexto;
    }

    bool operator!=(const Materia& otra) const {
        return !(*this == otra);
    }

    friend ostream& operator<<(ostream& os, const Materia& materia) {
        os << "Clave: " << materia.Clave << ", Nombre: " << materia.Nombre
           << ", Profesor Titular: " << materia.ProfesorTit << ", Libro de Texto: " << materia.LibroTexto;
        return os;
    }

    friend istream& operator>>(istream& is, Materia& materia) {
        cout << "Ingrese la clave: ";
        is >> materia.Clave;
        cout << "Ingrese el nombre: ";
        is >> materia.Nombre;
        cout << "Ingrese el nombre del profesor titular: ";
        is >> materia.ProfesorTit;
        cout << "Ingrese el nombre del libro de texto: ";
        is >> materia.LibroTexto;
        return is;
    }

    Materia operator+(const Materia& otra) const {
        Materia nuevaMateria(*this);
        nuevaMateria.Nombre += " y " + otra.Nombre;
        nuevaMateria.ProfesorTit += " y " + otra.ProfesorTit;
        nuevaMateria.LibroTexto += " y " + otra.LibroTexto;
        return nuevaMateria;
    }

    bool operator<(const Materia& otra) const {
        return this->Clave < otra.Clave;
    }

    bool operator>(const Materia& otra) const {
        return this->Clave > otra.Clave;
    }


};


int main()
{
    //Declarando los objetos de tipo Materia
    Materia materia1(1234,"programacion","Profesor Rodriguez","El arte de programar");
    //Materia materia2(1234,"programacion","Profesor Rodriguez","El arte de programar"); Comentado para hacer prueba de igualdad
    Materia materia2 (5678,"basesDatos","Profesor Ruvalcaba","Principios basicos de estructuras de datos");

    int opcion;
do{
    int resp;
    string resp2 = "";

    cout<<"\t Menu\n"<<endl;
    cout<<"1.Cambiar clave de la materia Programacion"<<endl;
    cout<<"2.Cambiar el nombre del maestro que imparte Bases Datos"<<endl;
    cout<<"3.Imprimir los datos de la materia bases de datos"<<endl;
    cout<<"4.=="<<endl;
    cout<<"5.!="<<endl;
    cout<<"6.<"<<endl;
    cout<<"7.>"<<endl;
    cout<<"8. +"<<endl;
    cout<<"9.Salir\n"<<endl;
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

    case 4:
        if (materia1 == materia2) {
        cout << "Las materias son iguales" << endl;
    } else {
        cout << "Las materias son diferentes" << endl;
    }
        break;

    case 5:
        if (materia1 != materia2) {
        cout << "Las materias son diferentes" << endl;
    } else {
        cout << "Las materias son iguales" << endl;
    }
        break;

    case 6:
        if (materia1 < materia2) {
        cout << "La materia 1 tiene una clave menor que la materia 2" << endl;
    } else {
        cout << "La materia 1 no tiene una clave menor que la materia 2" << endl;
    }
        break;
    case 7:
        if (materia1 > materia2) {
        cout << "La materia 1 tiene una clave mayor que la materia 2" << endl;
    } else {
        cout << "La materia 1 no tiene una clave mayor que la materia 2" << endl;
    }
        break;

    case 8:
        Materia materiaConcatenada = materia1 + materia2;

        cout << "Materia concatenada: " << endl;
        materiaConcatenada.Imprime();




}//del switch
    } //del do
    while (opcion != 9);

    return 0;
}
