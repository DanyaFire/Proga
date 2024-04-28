#ifndef PROJECT_DB_H
#define PROJECT_DB_H
#include "fStudent.h"

namespace DB {
    class DB {
        std::set<fStudent*> fstudents;
    public:
        DB();
        DB(const DB& other_BD);
        bool loadDB(const std::string& filename);
        void printDB(const std::string& filename);
        bool saveDB();
        void add(fStudent* student);
        DB* select(const std::string& fnamer, const std::string& namer, const std::string& mnamer, const int& ren, const int& birthday, const int& finish, int mark1, int mark2, int mark3, int mark4, double middle_mark, int mask);
        bool add(const std::string& fnamer, const std::string& namer, const std::string& mnamer, const int& ren, const int& birthday, const int& finish, int& mark1, int& mark2, int& mark3, int& mark4, double middle_mark);
        int getFreeID();
        void sort();
        DB& operator=(const DB& other_DB);
        ~DB();
    };
}
#endif