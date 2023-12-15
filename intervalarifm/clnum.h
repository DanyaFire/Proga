#pragma once

#include <iostream>
#include <cmath>
#include <fstream>

#define eps 1.e-10

using namespace std;

class Point;
class interval;

interval combination(interval u, interval v);
interval intersection(interval u, interval v);
interval difference(interval u, interval v);
void sym_difference(interval u, interval v);

class Point {
private:
    double x;
    bool def;
    double DistanceTo(const Point &a) const {
        return a.x - x;
    }
public:
    Point() : def(false){};
    Point(double _x): x(_x), def(true){};
    Point(const Point& a) : x(a.x), def(a.def){};
    double get_coord() {
        return x;
    }
    friend class interval;
};

class interval {
private:
    Point a, b;
    bool def;
    double Length() const {
        return a.DistanceTo(b);
    }
public:
    interval() : def(false) {}
    interval(const Point &a1, const Point &a2) : a(a1), b(a2), def(a1.def && a2.def) {
        if(b.get_coord() < a.get_coord()) {
            Point t(a);
            a = b;
            b = t;
        }
    }
    interval(const interval &s) : a(s.a), b(s.b), def(s.def) {}
    bool IsDef() const { 
        return def; 
    }
    const interval & operator=(const interval &s) { 
        a = s.a; 
        b = s.b; 
        def = s.def; 
        return *this; 
    }
    bool operator==(const interval &s) const { 
        return fabs(Length() - s.Length()) < eps; 
    }
    bool IsTrivial() const { 
        return def && Length(); 
    }
    double First(interval &u) {
        a = u.a;
        return a.get_coord();
    }
    double Second(interval &u) {
        b = u.b;
        return b.get_coord();
    }
    void print_int(interval &u) {
        double x, y;
        a = u.a;
        b = u.b;
        cout<<"("<<a.get_coord()<<","<<b.get_coord()<<")";
    }
    friend class Point;
};