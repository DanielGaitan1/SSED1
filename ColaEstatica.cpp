#include <iostream>
#include "Cola.h"

int main()
{
    Cola MiCola;
    persona x;
    for(int i=1;i<=2; i++){
        std::cin>>x;
        MiCola.enqueue(x);
    }
    for(int i=1;i<=2; i++)
        std::cout<<MiCola.dequeue();

    return 0;
}

