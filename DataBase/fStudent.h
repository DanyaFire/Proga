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
        std::string fam_name, name, mid_name, obj1, obj2, obj3, obj4;
        int data, region, finish_school, mark1, mark2, mark3, mark4;
        double mid_mark;

        fStudent(): id(0), region(0), fam_name(std::string ()), name(std::string ()), mid_name(std::string ()), data(0), finish_school(0), obj1(std::string ()), obj2(std::string ()), obj3(std::string ()), obj4(std::string ()), mark1(0), mark2(0), mark3(0), mark4(0), mid_mark(0) {}

        fStudent(int i, int reg, std::string fn, std::string n, std::string mn, int dt, int year, std::string o1, std::string o2, std::string o3, std::string o4, int m1, int m2, int m3, int m4, double srb): 
        id(i), region(reg), fam_name(fn), name(n), mid_name(mn), data(dt), finish_school(year), obj1(o1), obj2(o2), obj3(o3), obj4(o4), mark1(m1), mark2(m2), mark3(m3), mark4(m4), mid_mark(srb) {}
        
        std::string print_to_gen() const {
            std::ostringstream str; //высокоуровневый вывод потока строк
            str << std::setfill('0') << std::setw(5) << id << "|" << region << "|" << fam_name  << "|" << name << "|" << mid_name << "|" << data << "|" << finish_school << "|" << obj1 << "|" << obj2 << "|" << obj3 << "|" << obj4 << "|" << mark1 << "|" << mark2 << "|" << mark3 << "|" << mark4 << "|" << mid_mark; 
            return str.str(); // конвертировали всё в строку
        }

        std::string print() const {
            std::ostringstream str; //высокоуровневый вывод потока строк
            str << std::setfill('0') << std::setw(5) << id << " | " << region << " | " << fam_name << " | " << name << " | " << mid_name << " | " << std::setfill('0') << std::setw(2) << data / 1000000 << "." << std::setfill('0') << std::setw(2) << (data / 10000) % 100 << "." << data % 10000 << " | " << finish_school << " | " << obj1 << " | " << obj2 << " | " << obj3 << " | " << obj4 << " | " << mark1 << " | " << mark2 << " | " << mark3 << " | " << mark4 << " | " << mid_mark; 
            return str.str(); // конвертировали всё в строку
        }

        std::string getCSVRepr () const { // Просто всё представили в виде: "1; Джон; Doe; 2; 101; 1; Нью-Йорк" 
            return std::to_string(id) + " | " + std::to_string(region) + " | " + fam_name + " | " + name + " | " + mid_name + " | " + std::to_string(data / 1000000) + "." + std::to_string((data / 10000) % 100) + "." + std::to_string(data % 10000) + " | " + std::to_string(finish_school) + " | " + obj1 + " | " + obj2 + " | " + obj3 + " | " + obj4 + " | " + std::to_string(mark1) + " | " + std::to_string(mark2) + " | " + std::to_string(mark3) + " | " + std::to_string(mark4) + " | " + std::to_string(mid_mark);
        }

        fStudent& operator=(const fStudent& otherStud) {
            if (this != &otherStud) {
                this->id = otherStud.id;
                this->fam_name = otherStud.fam_name;
                this->name = otherStud.name;
                this->mid_name = otherStud.mid_name;
                this->obj1 = otherStud.obj1;
                this->obj2 = otherStud.obj2;
                this->obj3 = otherStud.obj3;
                this->obj4 = otherStud.obj4;
                this->data = otherStud.data;
                this->region = otherStud.region;
                this->finish_school = otherStud.finish_school;
                this->mark1 = otherStud.mark1;
                this->mark2 = otherStud.mark2;
                this->mark3 = otherStud.mark3;
                this->mark4 = otherStud.mark4;
                this->mid_mark = otherStud.mid_mark;
            }
        return *this;
        }
    };
} 
#endif