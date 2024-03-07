#include "Generator.h"

int main() {
    int g;
    std::cout<<"Введите чиселко:";
    std::cin>>g;
    DB::generator(g);
    return 0;
}