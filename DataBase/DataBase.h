#ifndef PROJECT_DB_H
#define PROJECT_DB_H
#include "fStudent.h"

namespace DB {
    class DB {
        std::set<fStudent*> fstudents;
    public:
        DB();
        DB(const DB& other_BD);
        void loadDB(const std::string& filename);
        std::string printDB();
        void saveDB(const std::string& filename);
        void add(fStudent* student);
        DB* select(const std::string& fnamer, const std::string& namer, const std::string& mnamer, const int& ren, const int& birthday, const int& finish, const std::string& obj1, const std::string& obj2, const std::string& obj3, const std::string& obj4, int mark1, int mark2, int mark3, int mark4, double middle_mark, int mask);
        int add(const std::string& fnamer, const std::string& namer, const std::string& mnamer, const int& ren, const int& birthday, const int& finish, const std::string& obj1, const std::string& obj2, const std::string& obj3, const std::string& obj4, int& mark1, int& mark2, int& mark3, int& mark4, double middle_mark);
        int getFreeID();
        DB& operator=(const DB& other_DB);
        ~DB();
        //конструктор копирования и оператор присваивания
    };
}
#endif