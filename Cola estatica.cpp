#include "Cola.h"

persona::persona(){
    nombre="juanito";
    carrera= "Computacion";
    materias=6;
    promedio=9.5;
}

persona::persona(string n,string c,int m,float p): nombre(n),carrera(c), materias(m), promedio(p) {}
void persona::operator=(persona& x)
{
    nombre=x.nombre;
    carrera=x.carrera;
    materias=x.materias;
    promedio=x.promedio;

}

std::ostream& operator<<( std::ostream& o, persona& p)
{
    o<<"nombre: "<<p.nombre<<"\t carrera: "<<p.carrera<<"\t materias: "<<p.materias<<"\t promedio: "<<p.promedio<<endl;
    return o;
}
std::istream& operator>>( std::istream& o, persona& p)
{
    std::cout<<"\n inserta nombre: ";
    o>>p.nombre;
    std::cout<<"\n inserta carrera: ";
    std::cin.ignore();
    o>>p.carrera;
    std::cout<<"\n inserta materias que se aprobaron: ";
    std::cin.ignore();
    o>>p.materias;
    std::cout<<"\n inserta promedio: ";
    std::cin.ignore();
    o>>p.promedio;
    std::cout<<"\n ----------------------------------- "<<endl;
    return o;
}

bool Cola::vacia()const
{
    if(ult==-1)
        return true;
    return false;
}
bool Cola::llena()const
{
    if(ult==TAM-1)
        return true;
    return false;
}

int Cola::ultimo()const
{
    return ult;
}

std::ostream& operator<<(std::ostream & o, Cola& L)
{
    int i=0;
    std::cout<<"\n";
    while(i<=L.ultimo())
    {
        ;
        o<<L.datos[i];
        i++;
    }
    return o;
}

void Cola::enqueue(persona& elem)
{
    inserta(elem,0);
}

persona& Cola::dequeue()
{
    if(vacia()){
        std::cout<<"\n La cola esta vacia"<<std::endl;
    }
    else{
        ult--;
        return datos[ult+1];
    }
}

bool Cola::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        std::cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return false;
}
int Cola::inserta(persona& elem, int pos)
{
    if(llena()|| pos<0 || pos>ult+1)
    {
        std::cout<<"\n Error de insercion";
        return 0;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}
