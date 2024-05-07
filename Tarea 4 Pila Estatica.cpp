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
    friend ostream& operator<<(ostream& o, const Empleado& e) {//Esta línea de código sobrecarga el operador de inserción << para la clase Empleado, lo que permite imprimir objetos de la clase Empleado en flujos de salida estándar, como cout.
    o << "\tClave del Empleado: " << e.GetClaveEmpleado() << endl;
    o << "\tNombre: " << e.GetNombre() << endl;
    o << "\tDomicilio: " << e.GetDomicilio() << endl;
    o << "\tSueldo: " << e.GetSueldo() << endl;
    o << "\tReporta a: " << e.GetReporta() << endl;
    return o;}
};

class Pila{
private:
    Empleado datos[Tam];
    int indice;
public:
    Pila():indice(-1){}

    // Método push
    void push(const Empleado& empleado) {
        if (indice == Tam - 1) {
            cout << "\tLa pila esta llena. No se puede agregar el empleado." << endl;
            return;
        }
        indice++;
        datos[indice] = empleado;
        cout << "\t\n\nEmpleado agregado correctamente." << endl;
    }

    // Método pop
    void pop() {
        if (indice == -1) {
            cout << "\tLa pila esta vacia. No se puede eliminar ningun empleado." << endl;
            return;
        }
        cout << "\n\n\tEmpleado eliminado correctamente." << endl;
        indice--;
    }

    // Método top
    Empleado top() const {
        if (indice == -1) {
            cout << "La pila esta vacia. No hay ningun empleado en la cima." << endl;
            return Empleado();
        }
        return datos[indice];
    }

    // Método llena
    bool llena() const {
        return indice == Tam - 1;
    }

    // Método vacia
    bool vacia() const {
        return indice == -1;
    }
};

int main() {
    Pila miPila;
    int opcion;
    int clave=1;
    string nombre="1";
    string domicilio="1";
    float sueldo=1;
    string reportaA="1";

    Empleado empleado1(5346,"Fernando Avila","Calle Revolucion #154",36000,"Supervisor Hernandez");
    Empleado empleado2(1454,"Mariana Sol"," Avenida Principal #36",40000,"Supervisor Lopez");
    Empleado empleado3(53,"Joaquin Garcia","Olmo #44",22000,"Supervisor Diaz");

    miPila.push(empleado1);
    miPila.push(empleado2);
    miPila.push(empleado3);

    do {
        cout << "----------------------------------------------" << endl;
        cout << "\t Menu\n" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Salir\n" << endl;

        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\tAgregar nuevo empleado" << endl;

                cout << "Ingrese la clave del empleado:" << endl;
                cin >> clave;
                cout << "Ingrese el nombre del empleado:" << endl;
                cin >> nombre;
                cout << "Ingrese el domicilio del empleado:" << endl;
                cin >> domicilio;
                cout << "Ingrese el sueldo del empleado:" << endl;
                cin >> sueldo;
                cout << "Ingrese el nombre de a quien reporta el empleado:" << endl;
                cin >> reportaA;

                miPila.push(Empleado(clave, nombre, domicilio, sueldo, reportaA));
                break;

            case 2:
                miPila.pop();
                break;

            case 3:
                cout << "\n\nEmpleado en la cima de la pila:" << endl;
                cout << miPila.top() << endl;
                break;

            case 4:
                // Código para la opción 4 (Salir)
                break;

            default:
                cout << "Opcion no valida. Por favor, elija una opción valida." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
