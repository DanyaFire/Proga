#include "polyg.h"

Polygon::Polygon(int _n, int _p) : n(_n), p(_p), def(true) {
    ofstream file("poly.txt");
        Point* a = new Point[n]; // на new
        double angle = 2*M_PI/n;
        for(int i = 0; i < n; i++) {
            a[i].x = R*cos(angle);
            a[i].y = R*sin(angle);
            angle += ((2*M_PI)/n);
        }
        for(int i = 0; i < n; i++) {
            file<<a[i].x<<" "<<a[i].y<<endl;
            if(i == n-1) {
                file<<a[0].x<<" "<<a[0].y<<endl<<endl;
            }
        }
    Craftp(a,file);
    delete[] a;
    file.close();
}

void Polygon :: Craftp(Point* a, ofstream &file) {
    unsigned int max_pow = 1<<n, i, j;
        int s, dx = 0, c = 0;
        for (i = 0; i < max_pow; i++) {
            j = i;
            for (c = 0; j != 0; j >>= 1) {
                c += j & 1;
            }
            if (c == p) {
                dx++;
                j = i;
                int r = __builtin_ctz(j & (-j));
                while (j != 0) {
                    s = __builtin_ctz(j & (-j));
                    file<<a[s].x + 2*dx<<" "<<a[s].y + 2*dx<<endl;
                    j = j & (j - 1);
                }
            file<<a[r].x + 2*dx<<" "<<a[r].y + 2*dx<<endl<<endl;
            }
        }
}