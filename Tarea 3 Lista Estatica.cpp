#include <iostream>
#include <string>

using namespace std;
const int Tam=10;

class Empleado {
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;

public:
    Empleado() {
        ClaveEmpleado = 0;
        Sueldo = 0.0f;
    }

    Empleado(int ClaveEmpleado,string Nombre,string Domicilio,float Sueldo, string ReportaA){
        this->ClaveEmpleado=ClaveEmpleado;
         this->Nombre=Nombre;
         this->Domicilio=Domicilio;
         this->Sueldo=Sueldo;
         this->ReportaA=ReportaA;
    }


    int GetClaveEmpleado() const {
        return ClaveEmpleado;}
    void SetClaveEmpleado(int clv) {
        ClaveEmpleado = clv;}
    string GetNombre() const {
        return Nombre;}
    void SetNombre(const string& nom) {
        Nombre = nom;}
    string GetDomicilio() const {
        return Domicilio;}
    void SetDomicilio(const string& dom) {
        Domicilio = dom;}
    float GetSueldo() const {
        return Sueldo;}
    void SetSueldo(float sue) {
        Sueldo = sue;}
    string GetReporta() const {
        return ReportaA;}
    void SetReporta(const string& rep) {
        ReportaA = rep;}
    friend istream& operator>>(istream& i, Empleado& e) {
        cout << "Ingrese la clave del empleado: ";
        i >> e.ClaveEmpleado;
        i.ignore();
        cout << "Ingrese el nombre del empleado: ";
        getline(i, e.Nombre);
        cout << "Ingrese el domicilio del empleado: ";
        //i.ignore();
        getline(i, e.Domicilio);
        cout << "Ingrese el sueldo del empleado: ";
        i >> e.Sueldo;
        cout << "Ingrese a quien reporta el empleado: ";
        i.ignore();
        getline(i, e.ReportaA);
        return i;}
    friend ostream& operator<<(ostream& o, const Empleado& e) {
    o << "Clave del Empleado: " << e.GetClaveEmpleado() << endl;
    o << "Nombre: " << e.GetNombre() << endl;
    o << "Domicilio: " << e.GetDomicilio() << endl;
    o << "Sueldo: " << e.GetSueldo() << endl;
    o << "Reporta a: " << e.GetReporta() << endl;
    return o;}
};

class Lista{
private:
    Empleado datos[Tam];
    int ult;
public:
    Lista():ult(0){}

    //Metodo Inserta
    void Inserta(const Empleado& empleado, int posicion) {
        if (ult == Tam) {
            cout << "La lista esta llena. No se pudo insertar el empleado." << endl;
        }

        if (posicion < 0 || posicion > ult) {
            cout << "La posicion para insertar el empleado es invalida." << endl;
        }
        for (int i = ult; i > posicion; i--) {
            datos[i] = datos[i - 1];
        }
        datos[posicion] = empleado;
        ult++;
        cout << "Empleado insertado exitosamente en la posicion " << posicion << "." << endl;

    }
    //Metodo Agrega

    int Agrega(const Empleado& empleado){
          if (ult < Tam) {
            datos[ult] = empleado;
            ult++;
            return 1;
        } else {
            cout << "La lista esta llena. No se pudo agregar el empleado." << endl;
            return 0;
        }
    }
    //Metodo Busca
    int Busca(int clave)const{
        for(int i=0; i<= ult; i++){
            if(datos[i].GetClaveEmpleado() == clave)
                cout << "Empleado encontrado en la posicion " << i << ":" << endl;
                cout << datos[i] << endl;
                return i;//La posicion donde se encuentra el empleado
        }
        return -1;//No se encontro el empleado
    }

    //Metodo vacia
    bool vacia()const{
        if(ult==-1)
            return true;
        return false;
    }
    //Metodo llena
    bool llena()const{
        if(ult==Tam-1)
            return true;
        return false;
    }
    //Metodo Elimina
    void eliminar(int pos){
        if(vacia() || pos<0 || pos>ult){
            std::cout<<"error de eliminacion\n";
        }
        else{
            int i=pos;
            while(i<ult){
               datos[i]=datos[i+1];
               i++;
            }
            ult--;
            cout<<"eliminado con exito"<<endl;

        }
    }
    //Ultimo
    int ultimo()const{
        return ult;
    }
    //Recupera
    Empleado recupera(int pos){
        if(vacia() ||pos<0 || pos>ult){
            cout<<"\n Insuficiencia datos";
        }
        else{
            return datos[pos];
        }
    }
    void imprime() {
        if (ult == 0) {
        cout << "La lista esta vacia." << endl;
        } else {
            cout << "Empleados en la lista:" << endl;
            for (int i = 0; i < ult; i++) {
                cout << "Posicion " << i << ":" << endl;
                cout << datos[i] << endl;
            }
        }
    }
};

int main()
{
    Lista MiLista;
    int opcion ;
    int clave=1;
    string nombre="1";
    string domicilio="1";
    float sueldo=1;
    string reportaA="1";

    Empleado nuevoEmpleado;

    do{
    string resp = "";
    //float respSueldo=0;

    cout<<"\t Menu\n"<<endl;
    cout<<"1.Agregar empleado"<<endl;
    cout<<"2.Buscar empleado"<<endl;
    cout<<"3.Eliminar empleado"<<endl;
    cout<<"4.Insertar empleado"<<endl;
    cout<<"5.Mostrar lista de empleados registrados"<<endl;
    cout<<"6.Salir\n"<<endl;
    cin>>opcion;

switch (opcion) {
    case 1:
        // Código para la opción 1
        cout<<"\tAgregar nuevo empleado"<<endl;

        cout<<"Ingrese la clave del empleado:"<<endl;
        cin>> clave;
        cout<<"Ingrese el nombre del empleado:"<<endl;
        cin>> nombre;
        cout<<"Ingrese el domicilio del empleado:"<<endl;
        cin>> domicilio;
        cout<<"Ingrese el sueldo del empleado:"<<endl;
        cin>> sueldo;
        cout<<"Ingrese el nombre de a quien reporta el empleado:"<<endl;
        cin>> reportaA;


        nuevoEmpleado = Empleado(clave,nombre,domicilio,sueldo,reportaA);
        if(MiLista.Agrega(nuevoEmpleado))
            cout<<"Empleado agregado correctamente"<<endl;
        else
            cout<<"No se pudo agregar el empleado"<<endl;

        cout<<"dato guardado\n"<<endl;
        cout<<"-----------------"<<endl;
            break;

    case 2:
        int claveBus;
        cout<<"\nCual es la clave del empleado a buscar?"<<endl;
        cin>>claveBus;

        MiLista.Busca(claveBus);
        break;
    case 3:
        int posEli;
        cout<<"\nCual es la posicion que se eliminara?"<<endl;
        cin>>posEli;
        MiLista.eliminar(posEli);

        break;

    case 4:

        int nuevoIns;
        cout<<"\tInsertar nuevo empleado en posicion"<<endl;

        cout<<"En que posicion se insertara el empleado nuevo"<<endl;
        cin>>nuevoIns;

        cout<<"Ingrese la clave del empleado:"<<endl;
        cin>> clave;
        cout<<"Ingrese el nombre del empleado:"<<endl;
        cin>> nombre;
        cout<<"Ingrese el domicilio del empleado:"<<endl;
        cin>> domicilio;
        cout<<"Ingrese el sueldo del empleado:"<<endl;
        cin>> sueldo;
        cout<<"Ingrese el nombre de a quien reporta el empleado:"<<endl;
        cin>> reportaA;

        nuevoEmpleado = Empleado(clave,nombre,domicilio,sueldo,reportaA);

        MiLista.Inserta(nuevoEmpleado,nuevoIns);

        break;
    case 5:
        MiLista.imprime();
        break;
    case 6:
        // Código para la opción 6
        break;
    default:
        // Código para manejar opciones no válidas
        break;
    }//del switch
} //del do
    while (opcion != 6);

    return 0;
}
