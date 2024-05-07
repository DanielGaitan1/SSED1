#include <iostream>
#include <string>

using namespace std;

const int TAM = 100;

class persona {
private:
    string nombre;
    string carrera;
    int materias;
    float promedio;

public:
    persona();
    persona(string n, string c, int m, float p);

    void operator=(persona& x);
    string obtenerNombre()const{
        return nombre;
    };
    friend ostream& operator<<(ostream&, persona&);
    friend istream& operator>>(istream&, persona&);
};

persona::persona() {
    nombre = "juanito";
    carrera = "Computacion";
    materias = 6;
    promedio = 9.5;
}

persona::persona(string n, string c, int m, float p): nombre(n), carrera(c), materias(m), promedio(p) {}

void persona::operator=(persona& x) {
    nombre = x.nombre;
    carrera = x.carrera;
    materias = x.materias;
    promedio = x.promedio;
}

ostream& operator<<(ostream& o, persona& p) {
    o << "nombre: " << p.nombre << "\t carrera: " << p.carrera << "\t materias: " << p.materias << "\t promedio: " << p.promedio << endl;
    return o;
}

istream& operator>>(istream& o, persona& p) {
    cout << "\n inserta nombre: ";
    o >> p.nombre;
    cout << "\n inserta carrera: ";
    o >> p.carrera;
    cout << "\n inserta materias que se aprobaron: ";
    o >> p.materias;
    cout << "\n inserta promedio: ";
    o >> p.promedio;
    cout << "\n ----------------------------------- " << endl;
    return o;
}

class Cola {
private:
    persona datos[TAM];
    int ult;

    bool elimina(int pos);
    int inserta(persona& elem, int pos);

public:
    Cola(): ult(-1) {}

    bool vacia() const;
    bool llena() const;
    int ultimo() const;

    friend ostream& operator<<(ostream & o, Cola& L);

    void enqueue(persona& elem);
    persona& dequeue();
    int buscar(string nombre);
    void altaSolicitud();
    void elaborarConstancia();
    void buscarSolicitud();
};

bool Cola::vacia() const {
    return ult == -1;
}

bool Cola::llena() const {
    return ult == TAM - 1;
}

int Cola::ultimo() const {
    return ult;
}

ostream& operator<<(ostream & o, Cola& L) {
    int i = 0;
    while (i <= L.ultimo()) {
        o << L.datos[i];
        i++;
    }
    return o;
}

void Cola::enqueue(persona& elem) {
    if (llena()) {
        cout << "\n Error de insercion: la cola esta llena." << endl;
        return;
    }
    inserta(elem, ult+1);
}

persona& Cola::dequeue() {
    if (vacia()) {
        cout << "\n La cola está vacía. No hay ningún elemento para eliminar." << endl;
        static persona empty;
        return empty;
    } else {
        persona& eliminado = datos[0];
        for (int i = 0; i < ult; ++i) {
            datos[i] = datos[i +1];
        }
        ult-1; // No funciona esta parte del programa si lo dejo asi en -1 repetira el ultimo aunque ya no haya constancias, si lo pongo
        //si lo pongo como ult-- dara incorrecta la forma en la que salen las constancias
        return eliminado;
    }
}

bool Cola::elimina(int pos) {
    if (vacia() || pos < 0 || pos > ult) {
        cout << "\n error de eliminacion";
        return true;
    }
    int i = pos;
    while (i < ult) {
        datos[i] = datos[i + 1];
        i++;
    }
    ult--;
    return false;
}

int Cola::inserta(persona& elem, int pos) {
    if (llena() || pos < 0 || pos > ult + 1) {
        cout << "\n Error de insercion";
        return 0;
    }
    int i = ult + 1;
    while (i > pos) {
        datos[i] = datos[i - 1];
        i--;
    }
    datos[pos] = elem;
    ult++;
    return 1;
}

int Cola::buscar(string nombreBuscado) {
    for (int i = 0; i <= ult; ++i) {
        if (datos[i].obtenerNombre() == nombreBuscado) {
            return i;
        }
    }
    return -1;
}

void Cola::altaSolicitud() {
    persona nuevaSolicitud;
    cin >> nuevaSolicitud;
    enqueue(nuevaSolicitud);
}

void Cola::elaborarConstancia() {
    if (vacia()) {
        cout << "\n No hay solicitudes en espera." << endl;
        return;
    }
    persona solicitudActual = dequeue();
    cout << "\n Constancia elaborada para: " << solicitudActual;
}

void Cola::buscarSolicitud() {
    string nombre;
    cout << "\n Ingrese el nombre del alumno para buscar la solicitud: ";
    cin >> nombre;
    int posicion = buscar(nombre);
    if (posicion != -1) {
        cout << "\n La solicitud se encuentra en la posicion " << posicion + 1 << " de la cola." << endl;
        cout << "Cantidad de constancias a elaborar antes de esta solicitud: " << posicion << endl;
    } else {
        cout << "\n La solicitud de " << nombre << " no se encuentra en la cola. Debe dar de alta una solicitud." << endl;
    }
}

int main() {
    Cola MiCola;
    int opcion;

    do {
        cout << "\n--------------------------------------" << endl;
        cout << "\t\tMenu" << endl;
        cout << "1. Dar de alta la solicitud de un alumno." << endl;
        cout << "2. Elaborar una constancia." << endl;
        cout << "3. Buscar una solicitud." << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                MiCola.altaSolicitud();
                break;
            case 2:
                MiCola.elaborarConstancia();
                break;
            case 3:
                MiCola.buscarSolicitud();
                break;
            case 4:
                cout << "\nSaliendo del programa." << endl;
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
