#include "Generator.h"

int main() {
    std::ofstream databaseout("dataout.txt");
    int g;
    std::cout << "Введите чиселко:";
    std::cin >> g;
    DB::generator(g);
    DB::DB St;
    St.loadDB("outfile.txt");
    St.saveDB("save.txt");
    DB::fStudent* student = new DB::fStudent(St.getFreeID(), 52, std::string("Ivanov"), std::string("Andrey"),std::string("Ivanovich"),10111981,1999,std::string("Russian_Language"), std::string("Mathematics_pro"), std::string("Physics"), std::string("Mathematics_DVI"), 76, 83, 97, 100, (76+83+97+100)/4.0);
    St.add(student);
    student = new DB::fStudent(St.getFreeID(), 52, std::string("Ivanov"), std::string("Ivan"),std::string("Ivanovich"),10111981,1999,std::string("Russian_Language"), std::string("Mathematics_pro"), std::string("Physics"), std::string("Mathematics_DVI"), 76, 83, 97, 100, (76+83+97+100)/4.0);
    St.add(student);
    student = new DB::fStudent(St.getFreeID(), 52, std::string("Ivanov"), std::string("Ilya"),std::string("Alexeyevich"),10111981,1999,std::string("Russian_Language"), std::string("Mathematics_pro"), std::string("Physics"), std::string("Mathematics_DVI"), 76, 83, 97, 100, (76+83+97+100)/4.0);
    St.add(student);
    St.saveDB("save.txt");
    databaseout<<(St.select("Ivanov", "Ilya", "Alexeyevich", int(), int(), int(), std::string(), std::string(), std::string(), std::string(), int(), int(), int(), int(), double(), 4)->printDB());
    databaseout.close();
    delete student;
    return 0;
}