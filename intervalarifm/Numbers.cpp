#include "clnum.h"


int main() {
    int n = 0;
    double v, f, g, h;
    cout<<"Choose the approach, which will use for enter of tests:\n1) From file;\n2)From keyboard\n";
    cin>>n;
    if(n == 1) {
        ifstream test("test.txt");
        if(!test.is_open()) {
            cout<<"Error! File have not opened!";
            return 1;
        }
        while(test.peek() != EOF) {
            cout<<"TEST "<<n<<": "<<endl;
            test>>v>>f>>g>>h;
            Point a(v), b(f), c(g), d(h);
            interval ab(a,b);
            interval cd(c,d);
            if(ab.IsTrivial() != 1 || cd.IsTrivial() != 1) {
                cout<<"One of the intervals is trivial!\n\n";
                n++;
                continue;
            }
            cout<<"combination: ";
            interval V = combination(ab,cd); 
            if(V.IsTrivial() != 1) {
                ab.print_int(ab);
                cout<<"U";
                cd.print_int(cd);
            } else { 
                V.print_int(V);
            }
            cout<<"\nintersection: ";
            V = intersection(ab,cd);
            if(V.IsTrivial() != 1) cout<<"0";
            else V.print_int(V);
            cout<<endl;
            cout<<"difference: ";
            V = difference(ab,cd);
            if(V.IsTrivial() != 1) {
               interval ac(ab.First(ab),cd.First(cd));
               ac.print_int(ac);
               cout<<"U";
               interval bd(ab.Second(ab),cd.Second(cd));
               bd.print_int(bd);
            } else V.print_int(V);
            cout<<"\nsym_difference: ";
            sym_difference(ab,cd);
            cout<<"\n"<<endl;
            n++;
        }
    } else if(n == 2) {
        cout<<"Enter start and finish of intervals, there are 2 of them, so the coordinates are 4:";
        cin>>v>>f>>g>>h;
        Point a(v), b(f), c(g), d(h);
        interval ab(a,b);
        interval cd(c,d);
        interval V;
        if(ab.IsTrivial() != 1 || cd.IsTrivial() != 1) {
            cout<<"One of the intervals is trivial!";
            return 1;
        }
        cout<<"Choose the operation with intervals:\n 1) Combining\n 2) Intersection\n 3) Difference\n 4) Symmetric difference\n";
        cin>>n;
        switch(n){
            case 1: V = combination(ab,cd); if(V.IsTrivial() != 1) {ab.print_int(ab);cout<<"U";cd.print_int(cd);} else {V.print_int(V);} break;
            case 2: V = intersection(ab,cd); if(V.IsTrivial() != 1) cout<<"0"; else V.print_int(V); break;
            case 3: V = difference(ab,cd); if(V.IsTrivial() != 1) {interval ac(ab.First(ab),cd.First(cd)); ac.print_int(ac);cout<<"U";interval bd(ab.Second(ab),cd.Second(cd));bd.print_int(bd);} else V.print_int(V); break;
            case 4: sym_difference(ab,cd); break;
        }
    } else {
        cout<<"Enter the integer number from 1 to 2, please!";
    }
    return 0;
}        