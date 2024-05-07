#include <iostream>
#include <string>

using namespace std;

const int Tam = 10;

class SolicitudIngreso {
private:
    string NombreAlumno;
    string Carrera;
    string PreparatoriaProcedente;
    float PromedioGeneral;

public:
    SolicitudIngreso() {
        PromedioGeneral = 0.0f;
    }

    SolicitudIngreso(const string& nombre, const string& carrera, const string& preparatoria, float promedio) {
        NombreAlumno = nombre;
        Carrera = carrera;
        PreparatoriaProcedente = preparatoria;
        PromedioGeneral = promedio;
    }

    string GetNombreAlumno() const {
        return NombreAlumno;
    }
    void SetNombreAlumno(const string& nombre) {
        NombreAlumno = nombre;
    }
    string GetCarrera() const {
        return Carrera;
    }
    void SetCarrera(const string& carrera) {
        Carrera = carrera;
    }
    string GetPreparatoriaProcedente() const {
        return PreparatoriaProcedente;
    }
    void SetPreparatoriaProcedente(const string& preparatoria) {
        PreparatoriaProcedente = preparatoria;
    }
    float GetPromedioGeneral() const {
        return PromedioGeneral;
    }
    void SetPromedioGeneral(float promedio) {
        PromedioGeneral = promedio;
    }

    friend istream& operator>>(istream& i, SolicitudIngreso& s) {
        cout << "Ingrese el nombre del alumno: ";
        getline(i, s.NombreAlumno);
        cout << "Ingrese la carrera a cursar: ";
        getline(i, s.Carrera);
        cout << "Ingrese el nombre de la preparatoria procedente: ";
        getline(i, s.PreparatoriaProcedente);
        cout << "Ingrese el promedio general obtenido: ";
        i >> s.PromedioGeneral;
        return i;
    }

    friend ostream& operator<<(ostream& o, const SolicitudIngreso& s) {
        o << "\tNombre del Alumno: " << s.GetNombreAlumno() << endl;
        o << "\tCarrera: " << s.GetCarrera() << endl;
        o << "\tPreparatoria Procedente: " << s.GetPreparatoriaProcedente() << endl;
        o << "\tPromedio General: " << s.GetPromedioGeneral() << endl;
        return o;
    }
};

class ListaSolicitudes {
private:
    SolicitudIngreso datos[Tam];
    int ult;

public:
    ListaSolicitudes() : ult(0) {}

    void altaSolicitud(const SolicitudIngreso& solicitud) {
        if (ult < Tam) {
            datos[ult] = solicitud;
            ult++;
            cout << "Solicitud de ingreso agregada exitosamente." << endl;
        } else {
            cout << "La lista de solicitudes esta llena. No se pudo agregar la solicitud." << endl;
        }
    }

    int buscarSolicitud(const string& nombreAlumno) const {
        for (int i = 0; i < ult; i++) {
            if (datos[i].GetNombreAlumno() == nombreAlumno) {
                return i; // Se encontro la solicitud
            }
        }
        return -1; // No se encontro la solicitud
    }

    void ordenarLista() {
    for (int i = 1; i < ult; i++) {
        SolicitudIngreso temp = datos[i];
        int j = i;
        while (j > 0 && datos[j - 1].GetPromedioGeneral() < temp.GetPromedioGeneral()) {
            datos[j] = datos[j - 1];
            j--;
        }
        datos[j] = temp;
    }
    cout << "Lista de solicitudes ordenada correctamente." << endl;
}
    void imprimirLista() const {
        if (ult == 0) {
            cout << "La lista de solicitudes esta vacia." << endl;
        } else {
            cout << "Solicitudes de ingreso en la lista:" << endl;
            for (int i = 0; i < ult; i++) {
                cout << "Posicion " << i << ":" << endl;
                cout << datos[i] << endl;
            }
        }
    }

    void mostrarSolicitudConLugar(int posicion) const {
        if (posicion >= 0 && posicion < ult) {
            int lugar = 1;
            float promedioActual = datos[posicion].GetPromedioGeneral();
            for (int i = 0; i < ult; i++) {
                if (datos[i].GetPromedioGeneral() > promedioActual) {
                    lugar++;
                }
            }
            cout << "La solicitud de ingreso se encuentra en la posicion " << posicion << " y ocupa el lugar " << lugar << " en la lista." << endl;
        } else {
            cout << "Error: La solicitud no se encuentra en la lista." << endl;
        }
    }
};

int main() {
    ListaSolicitudes listaSolicitudes;
    int opcion;
    SolicitudIngreso nuevaSolicitud;
    string nombreBuscar;

    do {
        cout << "----------------------------------------------" << endl;
        cout << "\t Menu\n" << endl;
        cout << "1. Agregar solicitud de ingreso" << endl;
        cout << "2. Buscar solicitud de ingreso" << endl;
        cout << "3. Ordenar lista de solicitudes de ingreso" << endl;
        cout << "4. Mostrar lista de solicitudes de ingreso" << endl;
        cout << "5. Salir\n" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Agregar nueva solicitud de ingreso" << endl;
                cin.ignore();
                cin >> nuevaSolicitud;
                listaSolicitudes.altaSolicitud(nuevaSolicitud);
                break;

            case 2:
                cout << "Ingrese el nombre del alumno de la solicitud a buscar: ";
                cin.ignore();
                getline(cin, nombreBuscar);
                int posicion;
                posicion = listaSolicitudes.buscarSolicitud(nombreBuscar);
                if (posicion != -1) {
                    cout << "Solicitud de ingreso encontrada:" << endl;
                    listaSolicitudes.mostrarSolicitudConLugar(posicion);
                } else {
                    cout << "Solicitud de ingreso no encontrada. Por favor, agregue una solicitud." << endl;
                }
                break;

            case 3:
                listaSolicitudes.ordenarLista();
                break;

            case 4:
                listaSolicitudes.imprimirLista();
                break;

            case 5:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}
