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

struct birthday {
    int day;
    int month;
    int byear;
};

namespace DB {
    struct fStudent {
        int id;
        std::string fam_name;
        std::string name;
        std::string mid_name;
        birthday data;
        int region;
        int finish_school;
        std::vector<std::string> obj;
        std::vector<int> marks;
        double mid_mark;

        fStudent(int i, std::string fn, std::string n, std::string mn, int reg, birthday dt, int year, std::vector<std::string> o, std::vector<int> m, double srb): 
        id(i), fam_name(fn), name(n), mid_name(mn), region(reg), data(dt), finish_school(year), obj(o), marks(m), mid_mark(srb) {}
        
        std::string print() const {
            std::ostringstream str; //высокоуровневый вывод потока строк
            str << std::setfill('0') << std::setw(1) << id << " | " << region << " | " << fam_name << " | " << name << " | " << mid_name << " | " << data.day << "." << data.month << "." << data.byear << " | " << finish_school << " | " << obj[0] << " | " << obj[1] << " | " << obj[2] << " | " << obj[3] << " | " << marks[0] << " | " << marks[1] << " | " << marks[2] << " | " << marks[3] << " | " << mid_mark; 
            return str.str(); // конвертировали всё в строку
        }

        std::string getCSVRepr () const { // Просто всё представили в виде: "1, Джон, Doe, 2,101, 1, Нью-Йорк" 
            return std::to_string(id) + "," + fam_name + "," + name + "," + mid_name + "," + std::to_string(region) + ",";
        }
    };
} 
#endif