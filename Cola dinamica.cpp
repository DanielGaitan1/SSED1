#include <iostream>
#include <string>
using namespace std;

template<class T>
class LSLSE;

//Clase alumno Club
template<class T>
class Alumno{
    public:
        string nombre;
        string Carrera;
        float Promedio;
        int Materias;
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
    string obtenernombre() const {
        return data.nombre;
    }
    string obtenerCarrera() const { //const para no modificar el valor solo para consulta
        return data.Carrera;
    }
    float obtenerPromedio() const { //Son funciones que regresan el valor que se esta solicitando
        return data.Promedio;
    }
    int obtenerMaterias() const {
        return data.Materias;
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
    node<T>* buscarPorPromedio(const float& Promedio) const;
    node<T>* buscarPorNombre(const string& nombre) const;
};

template<class T>
void LSLSE<T>::imprimir() const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        cout <<"Nombre de alumno: " << aux->data.nombre <<endl;
        cout<<"Carrera que cursa: "<< aux->data.Carrera<<endl;
        cout<<"Promedio: "<< aux->data.Promedio<<endl;
        cout<<"Materias aprobadas: "<< aux->data.Materias<<endl;
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
node<T>* LSLSE<T>::buscarPorPromedio(const float& Promedio) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        if (aux->obtenerPromedio() == Promedio) {
            return aux;
        }
        aux = aux->obtenersig();
    }
    return nullptr; // Si no se encuentra ningún alumno con el Promedio especificado
}

template<class T>
node<T>* LSLSE<T>::buscarPorNombre(const string& nombre) const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        if (aux->obtenerCarrera() == nombre) {
            return aux;
        }
        aux = aux->obtenersig();
    }
    return nullptr; // Si no se encuentra ningún alumno con el Promedio especificado
}

int main()
{
    LSLSE<Alumno<float>> milista; //Se dejo el <float> para no mover tanto el codigo,
    Alumno<float> alumno;
     int opcion;
    do {
        cout <<endl;
        cout << "Menu:" << endl;
        cout << "1. Dar de alta solicitud de alumno" << endl;
        cout << "2. Elaborar constancia de alumno" << endl;
        cout << "3. Imprimir cola" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Dame el nombre del alumno" << endl;
                cin>>alumno.nombre;
                cout << "Dame la carrera que cursa" << endl;
                cin>>alumno.Carrera;
                cout << "Dame el Promedio" << endl;
                cin>>alumno.Promedio;
                cout << "Dame la cantidad de materias aprobadas" << endl;
                cin>>alumno.Materias;

                milista.insertar(milista.ultimo(), alumno);

                break;
            case 2:{

                node<Alumno<float>>* aux = milista.primero();

                if (aux == nullptr) {
                    cout << "La cola se encuentra vacia" << endl;
                    break;
                }
                cout<<"Nombre del alumno:"<<aux->obtenernombre()<<endl;
                cout<<"Carrera:"<<aux->obtenerCarrera()<<endl;
                cout<<"Promedio:"<<aux->obtenerPromedio()<<endl;
                cout<<"Cantidad de materias aprobadas:"<<aux->obtenerMaterias()<<endl;

                while (aux != nullptr) {
                    milista.eliminar(aux);
                    cout << "Alumno desencolado." << endl;
                    break;
                }
            }
                break;
            case 3:
                milista.imprimir();
                break;

            case 4:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Inténtelo de nuevo." << std::endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}

