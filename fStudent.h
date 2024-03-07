#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H
#include <iostream>
#include <string>
#include <utility> //для работы с парами
#include <iomanip> //для работы с манипуляторами
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace DB {
    struct fStudent {
        int id;
        std::string fam_name;
        std::string name;
        std::string mid_name;
        int region;
        std::vector<std::string> objects;

        fStudent(int i, std::string fn, std::string n, std::string mn, int reg): 
        id(i), fam_name(fn), name(n), mid_name(mn), region(reg) {}
        
        std::string print() const {
            std::ostringstream str; //высокоуровневый вывод потока строк
            str << std::setfill('0') << std::setw(1) << id << " | " << region << " | " << fam_name << " | " << name << " | " << mid_name << " | ";
            return str.str(); // конвертировали всё в строку
        }

        std::string getCSVRepr () const { // Просто всё представили в виде: "1, Джон, Doe, 2,101, 1, Нью-Йорк" 
            return std::to_string(id) + "," + fam_name + "," + name + "," + mid_name + "," + std::to_string(region) + ",";
        }
    };
} 
#endif