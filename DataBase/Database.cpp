#include "DataBase.h"
#include <cstdlib>

DB::DB::DB() : fstudents() {}

DB::DB::DB(const DB& other_BD) {
    this->fstudents = other_BD.fstudents;
}

bool DB::DB::loadDB(const std::string& filename) {
    std::ifstream file(filename);
    for (auto student: fstudents) {
        delete student;
    }
    fstudents.clear();

    std::string line;
    std::string param;
    std::vector<std::string> data;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        data.clear();
        while (std::getline(lineStream, param, '|')) {
            data.push_back(param);
        }
        auto* student = new fStudent(std::atoi(data[0].c_str()), std::atoi(data[1].c_str()), data[2], data[3], data[4], std::atoi(data[5].c_str()), std::atoi(data[6].c_str()), data[7], data[8], data[9], data[10], std::atoi(data[11].c_str()), std::atoi(data[12].c_str()), std::atoi(data[13].c_str()),std::atoi(data[14].c_str()), std::stod(data[15]));
        fstudents.insert(student);
    }
    data.clear();
    file.close();
    return true;
}

void DB::DB::printDB(const std::string& filename) {
    std::string str;
    std::fstream out(filename);
    for(auto student: fstudents) {
        str += student->print();
        str += "\n";
    }
    out << str;
}

bool DB::DB::saveDB() {
    std::ofstream save("save.txt");
    save << "id, Region, Surname, Name, Middle Name, Birthday, Finish Of School, Objects, Marks, Middle Mark" <<std::endl;
    for (auto student: fstudents) {
        save << student->getCSVRepr() << std::endl;
    }
    save.close();
    return true;
}

void DB::DB::add(fStudent* student) {
    fstudents.insert(student);
}

bool DB::DB::add(const std::string& fnamer, const std::string& namer, const std::string& mnamer, const int& ren, const int& birthday, const int& finish, int& mark1, int& mark2, int& mark3, int& mark4, double middle_mark) {
    if (fnamer.empty() & namer.empty() & mnamer.empty() & (ren < 0 || ren > 89) & (mark1 < 70 || mark1 > 100) & (mark2 < 70 || mark2 > 100) & (mark3 < 70 || mark3 > 100) & (mark4 < 70 || mark4 > 100) & (middle_mark < 0) & (birthday < 0 || (birthday%10000 - finish) < 16 || (birthday%10000 - finish) > 20)) {
        std::cout << "Data entered incorrectly!";
        return -1;
    }
    std::string obj1 = "Russian_Language", obj2 = "Mathematics_pro", obj3 = "Physics", obj4 = "Mathematics_DVI";
    fStudent* stud = new fStudent(this->getFreeID(), ren, fnamer, namer, mnamer, birthday, finish, obj1, obj2, obj3, obj4, mark1, mark2, mark3, mark4, middle_mark);
    this->add(stud);
    return true;
}

int DB::DB::getFreeID() {
    std::vector<int> ids;
    for (auto student: fstudents) {
        ids.push_back(student->id);
    }
    auto it = *std::max_element(std::begin(ids), std::end(ids));
    ids.clear();
    return it+1;
}

DB::DB* DB::DB::select(const std::string& fnamer, const std::string& namer, const std::string& mnamer, const int& ren, const int& birthday, const int& finish, int mark1, int mark2, int mark3, int mark4, double middle_mark, int mask) {
    std::string obj1 = "Russian_Language", obj2 = "Mathematics_pro", obj3 = "Physics", obj4 = "Mathematics_DVI";
    DB* selectDB = new DB();
    bool isRight;
    for (auto student: fstudents) {
        isRight = true;
        if((mask % 2 != 0) && (student->fam_name != fnamer)) { // 1 для выборки только по фамилии
            isRight = false;
        }
        if((mask / 2 % 2 != 0) && (student->name != namer)) { // 2 для выборки только по имени 
            isRight = false; // 3 для выборки только по фамилии и имени
        }
        if((mask / 4 % 2 != 0) && (student->mid_name != mnamer)) { // 4 для выборки только по отчеству 
            isRight = false;    // 5 для выборки по имени и отчеству
        }                       // 6 для выборки по фамилии и отчеству и 7 для выборки по фамилии, имени и отчеству
        if((mask / 8 % 2 != 0) && (student->region != ren)) { // 8 для выборки только по региону, 9 для выборки по фамилии и региону
            isRight = false;                                  // 10 для выборки по имени и региону, 11 для выборки по фамилии, имени и региону и т.д.) Просто смотрим на деление) 
        }
        if((mask / 16 % 2 != 0) && (abs(student->mid_mark - middle_mark) > 0.001)) { // 16 для выборки только по среднему баллу
            isRight = false; 
        }
        if((mask / 32 % 2 != 0) && (student->data != birthday)) { // 32 для выборки только по дате рождения 
            isRight = false;
        }
        if((mask / 64 % 2 != 0) && (student->finish_school != finish)) { // 64 для выборки только по дате окончания школы
            isRight = false;
        }
        if(isRight) {
            selectDB->add(student);
        }
    }
    return selectDB;
}

DB::DB& DB::DB::operator=(const DB& other_DB) {
    this->fstudents = other_DB.fstudents;
    return *this;
}

DB::DB::~DB() {
     for (auto student: fstudents) {
        delete student;
    }
    fstudents.clear();
}