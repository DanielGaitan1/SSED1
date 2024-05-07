#include <iostream>
#include <limits>

using namespace std;

template <class T>
class Nodo {
public:
    T data;//Data almacena el valor del nodo
    Nodo<T>* izq;//Puntero que apunta hacia el nodo izquierdo del arbol hijo
    Nodo<T>* der;//Lo mismo que el anterior pero hacia el lado derecho

    Nodo(T value) : data(value), izq(nullptr), der(nullptr) {}

    Nodo<T>* obtenerIzq() const {
        return izq;
    }

    Nodo<T>* obtenerDer() const {
        return der;
    }
};

template <class T>
class Arbol {
private:
    Nodo<T>* raiz;

    void inserta(Nodo<T>*& nodo, T valor) {
        if (nodo == nullptr) {
            nodo = new Nodo<T>(valor);
        } else {
            if (valor < nodo->data) {
                inserta(nodo->izq, valor);
            } else {
                inserta(nodo->der, valor);
            }
        }
    }

    bool esVacio(Nodo<T>* nodo) {
        return nodo == nullptr;
    }

    bool esHoja(Nodo<T>* nodo) {
        return nodo != nullptr && nodo->izq == nullptr && nodo->der == nullptr;
    }

    Nodo<T>* Mayor(Nodo<T>* nodo) {
        if (nodo->der == nullptr) {
            return nodo;
        }
        return Mayor(nodo->der);
    }

    Nodo<T>* Menor(Nodo<T>* nodo) {
        if (nodo->izq == nullptr) {
            return nodo;
        }
        return Menor(nodo->izq);
    }

    void eliminarNodo(Nodo<T>*& nodo) {
        if (nodo == nullptr) {
            return;
        }
        if (esHoja(nodo)) {
            delete nodo;
            nodo = nullptr;
        } else if (nodo->izq != nullptr) {
            Nodo<T>* maxIzq = Mayor(nodo->izq);
            nodo->data = maxIzq->data;
            eliminarNodo(maxIzq);
        } else {
            Nodo<T>* minDer = Menor(nodo->der);
            nodo->data = minDer->data;
            eliminarNodo(minDer);
        }
    }

    void elimina(Nodo<T>*& nodo, int pos, int& contador) {
        if (nodo == nullptr || contador > pos) {
            return;
        }
        elimina(nodo->izq, pos, contador);
        if (++contador == pos) {
            eliminarNodo(nodo);
            return;
        }
        elimina(nodo->der, pos, contador);
    }

    void anularArbol(Nodo<T>*& nodo) {
    if (nodo != nullptr) {

        anularArbol(nodo->izq);
        anularArbol(nodo->der);


        delete nodo;
        nodo = nullptr;
    }
}

public:
    Arbol() : raiz(nullptr) {}

    void inserta(T valor) {
        inserta(raiz, valor);
    }

    void vacio() {
        if (esVacio(raiz)) {
            cout << "El arbol esta vacio." << endl;
        } else {
            cout << "El arbol no esta vacio." << endl;
        }
    }
    void recorrido_inorder(Nodo<T>* node) {
        if (node != nullptr) {
            recorrido_inorder(node->izq);
            cout << node->data << " ";
            recorrido_inorder(node->der);
        }
    }

    void recorrido_inorder() {
        recorrido_inorder(raiz);
    }

   void recorrido_posorder(Nodo<T>* node) {
    if (node != nullptr) {
        recorrido_posorder(node->izq);
        recorrido_posorder(node->der);
        cout << node->data << " ";
    }
}

    void recorrido_posorder() {
        recorrido_posorder(raiz);
    }

    void recorrido_preorder(Nodo<T>* node) {
    if (node != nullptr) {
        cout << node->data << " "; // Visita la raíz, es esto correcto en este recorrido? visitar primero la raiz??
        recorrido_preorder(node->izq); // Recorre el subárbol izquierdo
        recorrido_preorder(node->der); // Recorre el subárbol derecho
    }
}

    void recorrido_preorder() {
        recorrido_preorder(raiz); // Comienza el recorrido desde la raíz
    }

    T recupera(int pos) {
        int cont = 0;
        Nodo<T>* node = Recupera(raiz, cont, pos);
        if (node == nullptr) {
            cout << "Elemento no encontrado en el arbol" << endl;
            return T();
        }
        return node->data;
    }

    void elimina(int pos) {
        if (raiz == nullptr || pos <= 0) {
            cout << "Error: Arbol o posición invalida." << endl;
            return;
        }
        int contador = 0;
        elimina(raiz, pos, contador);
    }

    Nodo<T>* Recupera(Nodo<T>* node, int& cont, int pos) {
        if (node == nullptr) {
            return nullptr;
        }
        Nodo<T>* izq = Recupera(node->izq, cont, pos);
        if (izq != nullptr) {
            return izq;
        }
        if (++cont == pos) {
            return node;
        }
        return Recupera(node->der, cont, pos);
    }
    void anularArbol() {
    anularArbol(raiz); // Comienza la anulación desde la raíz
}

    void insertarDesdeTeclado() {
    T valor;
    cout << "Ingrese los elementos del arbol (ingrese un valor no valido para terminar):" << endl;
    while (cin >> valor) {
        inserta(valor);
        cout << "Ingrese el valor del siguiente nodo (o un valor no valido para finalizar): ";
    }
    // Limpiar el buffer de entrada
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');// es una plantilla de clase que proporciona información sobre los límites de los tipos de datos. streamsize es un tipo de datos que representa el tamaño de los flujos. numeric_limits<streamsize>::max() devuelve el valor máximo posible para el tipo streamsize, lo que significa que se ignorarán todos los caracteres en el búfer de entrada hasta alcanzar este límite.
}//Sin esa linea el programa se queda ciclando infinitamente despues de dar los valores al arbol
};

int main() {
    Arbol<int> arbol;
    int opcion1=0;
    int opcion2=0;


    cout<<"\n\t Arboles "<<endl;
    cout<<"\n Quieres insertar elementos en el arbol o usar los ya predeterminados? (10,5,15,3,7) "<<endl;
    cout<<"\n\ 1) Insertar elementos "<<endl;
    cout<<"\n\ 2) Usar los predeterminados "<<endl;
    cin>>opcion1;

    switch (opcion1){
        case 1:
        cout<<"\n\n\n\t Insertar elementos "<<endl;
        arbol.insertarDesdeTeclado();
        break;

        case 2:
        cout<<"\n\t Los valores asignados predeterminados son (10,5,15,3,7)  "<<endl;
            arbol.inserta(10);
            arbol.inserta(5);
            arbol.inserta(15);
            arbol.inserta(3);
            arbol.inserta(7);
        break;
    default:
        cout << "Opcion inválida. Por favor, seleccione una opcion válida." << endl;
                break;
    }


while (opcion2!=8) {
        cout << "\n\n--- Menu ---" << endl;
        cout << "1. Mostrar recorrido preorden" << endl;
        cout << "2. Mostrar recorrido inorden" << endl;
        cout << "3. Mostrar recorrido postorden" << endl;
        cout << "4. Verificar si el arbol esta vacio" << endl;
        cout << "5. Recuperar elemento por posicion" << endl;
        cout << "6. Anular el arbol" << endl;
        cout << "7. Ingresar nuevos valores al arbol"<<endl;
        cout << "8. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion2;

        switch (opcion2) {
            case 1:
                cout << "Recorrido preorden: ";
                arbol.recorrido_preorder();
                cout << endl;
                break;
            case 2:
                cout << "Recorrido inorden: ";
                arbol.recorrido_inorder();
                cout << endl;
                break;
            case 3:
                cout << "Recorrido postorden: ";
                arbol.recorrido_posorder();
                cout << endl;
                break;
            case 4:
                arbol.vacio();
                break;
            case 5:
                /*Recupera da el valor asignado por teclado en la posicion, en los ya dados usara las posiciones al estilo
                de un arreglo, y cuando se le den numeros los tomara como fureon entrando*/


                int pos;
                cout << "Ingrese la posicion del elemento a recuperar: ";
                cin >> pos;
                cout << "El elemento recuperado es: " << arbol.recupera(pos) << endl;
                break;
            case 6:
                arbol.anularArbol();
                cout << "El arbol ha sido anulado." << endl;
                break;

            case 7:
                arbol.insertarDesdeTeclado();
                cout<<""<<endl;
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opción inválida. Por favor, seleccione una opcion válida." << endl;
                break;
        }
    }
    return 0;
}

/*Faltan las funciones de hijo derecho, hijo izquierdo y localiza, reparar eliminar y ver como funciona
el motivo es porque no entiendo cuando el pseudocodigo propone que se de un arbol y una posicion, esa logica no he logrado
comprenderla*/


