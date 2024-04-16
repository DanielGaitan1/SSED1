#include <iostream>
#include <string>
using namespace std;

template<class T>
class LSLSE;

//Clase Socio Club
template<class T>
class SocioClub{
    public:
        int NumeroSocio;
        string NombreSocio;
        string Domicilio;
        int AnoIngreso;
};

//Clase para nodo
template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class LSLSE<T>;

    //Metodos funciones getters para devolver los valores de los atributos de la clase nodo privados de Data
    int obtenerNumeroSocio() const {
        return data.NumeroSocio;
    }
    string obtenerNombreSocio() const { //const para no modificar el valor solo para consulta
        return data.NombreSocio;
    }
    string obtenerDomicilio() const { //Son funciones que regresan el valor que se esta solicitando
        return data.Domicilio;
    }
    int obtenerAnoIngreso() const {
        return data.AnoIngreso;
    }
    node<T>* obtenersig()const{
    return sig;
    }
};

//Clase Lista Simple Ligada
template<class T>
class LSLSE{
private:
    node<T>* lista;
    int contador;
public:
    LSLSE():lista(nullptr),contador(0){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    int contarElementos() const { return contador; }
    node<T>* buscarPorDomicilio(const string& domicilio) const;
    node<T>* buscarPorNombre(const string& nombre) const;
};

template<class T>
void LSLSE<T>::imprimir() const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        cout <<"Numero de Socio: " << aux->data.NumeroSocio <<endl;
        cout<<"Nombre del socio: "<< aux->data.NombreSocio<<endl;
        cout<<"Domicilio: "<< aux->data.Domicilio<<endl;
        cout<<"Año ingreso: "<< aux->data.AnoIngreso<<endl;
        cout<<"-------------------------------"<<endl;
        aux = aux->sig;
    }
}


template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    contador--;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
    contador++;
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

template<class T>
node<T>* LSLSE<T>::buscarPorDomicilio(const string& domicilio) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        if (aux->obtenerDomicilio() == domicilio) {
            return aux;
        }
        aux = aux->obtenersig();
    }
    return nullptr; // Si no se encuentra ningún socio con el domicilio especificado
}

template<class T>
node<T>* LSLSE<T>::buscarPorNombre(const string& nombre) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        if (aux->obtenerNombreSocio() == nombre) {
            return aux;
        }
        aux = aux->obtenersig();
    }
    return nullptr; // Si no se encuentra ningún socio con el domicilio especificado
}

int main()
{
    LSLSE<SocioClub<float>> milista; //Se dejo el <float> para no mover tanto el codigo,
    SocioClub<float> socio;
     int opcion;
    do {
        cout <<endl;
        cout << "Menu:" << endl;
        cout << "1. Registrar Socio" << endl;
        cout << "2. Dar de Baja" << endl;
        cout << "3. Generar Reporte" << endl;
        cout << "4. Buscar por Nombre" << endl;
        cout << "5. Buscar por Domicilio" << endl;
        cout << "6. Calcular e Imprimir Socios" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Dame el numero del Socio" << endl;
                cin>>socio.NumeroSocio;
                cout << "Dame el nombre del socio" << endl;
                cin>>socio.NombreSocio;
                cout << "Dame el domicilio" << endl;
                cin>>socio.Domicilio;
                cout << "Dame el anio de ingreso" << endl;
                cin>>socio.AnoIngreso;

                milista.insertar(milista.ultimo(), socio);

                break;
            case 2:{
                int numSocio;

                cout << "Ingrese el número de socio a dar de baja: ";
                cin >> numSocio;


                node<SocioClub<float>>* aux = milista.primero();
                while (aux != nullptr) {
                    if (aux->obtenerNumeroSocio() == numSocio) {
                        milista.eliminar(aux);
                        cout << "Socio eliminado exitosamente." << endl;
                        break;
                    }
                    aux = aux->obtenersig();
                }
                if (aux == nullptr) {
                    cout << "No se encontró un socio con ese número." << endl;
                }
            }
                break;
            case 3:
                milista.imprimir();
                break;
            case 4:
                {
                string nombre;
                cout << "Ingrese el nombre a buscar: ";
                cin >> nombre;
                node<SocioClub<float>>* resultado = milista.buscarPorNombre(nombre);
                if (resultado != nullptr) {
                    cout << "Se encontró un socio con el nombre especificado:" << endl;
                    cout <<"Numero de Socio: " << resultado->obtenerNumeroSocio() <<endl;
                    cout<<"Nombre del socio: "<< resultado->obtenerNombreSocio()<<endl;
                    cout<<"Domicilio: "<< resultado->obtenerDomicilio()<<endl;
                    cout<<"Año ingreso: "<< resultado->obtenerAnoIngreso()<<endl;
                } else {
                    cout << "No se encontró ningún socio con ese nombre." << endl;
                }
            }

                break;
            case 5:{
                string domicilio;
                cout << "Ingrese el domicilio a buscar: ";
                cin >> domicilio;
                node<SocioClub<float>>* resultado = milista.buscarPorDomicilio(domicilio);
                if (resultado != nullptr) {
                    cout << "Se encontró un socio con el domicilio especificado:" << endl;
                    cout <<"Numero de Socio: " << resultado->obtenerNumeroSocio() <<endl;
                    cout<<"Nombre del socio: "<< resultado->obtenerNombreSocio()<<endl;
                    cout<<"Domicilio: "<< resultado->obtenerDomicilio()<<endl;
                    cout<<"Año ingreso: "<< resultado->obtenerAnoIngreso()<<endl;
                } else {
                    cout << "No se encontró ningún socio con ese domicilio." << endl;
                }
            }

                break;
            case 6:
                cout << "Número total de elementos en la lista: " << milista.contarElementos() << endl;
                break;
            case 7:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Inténtelo de nuevo." << std::endl;
                break;
        }
    } while (opcion != 7);

    return 0;
}

