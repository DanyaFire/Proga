#pragma once

#include <iostream>
#include <cmath>
#include <fstream>

#define eps 1.e-10

using namespace std;

class Point;
class Polygon;

class Point {
private:
    double x, y;
    bool def;
public:
    Point() : def(false) {};
    Point(double _x, double _y) : x(_x), y(_y), def(true) {};
    Point(const Point& a) : x(a.x), def(a.def){};
    friend class Polygon;
};

class Polygon {
private:
    Point* a; 
    int n, p;
    double R = 1;
    bool def;
public:
    Polygon() : def(false) {};
    Polygon(int _n, int _p);
    void Craftp(Point* a, ofstream &file);
};