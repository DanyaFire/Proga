#include "polyg.h"

int main() { 
    ifstream input("polytest.txt");
    if(!input.is_open()) {
        cout<<"File have not opened!";
        return 1;
    }
    int n, p, test, n_test;
    input>>test;
    cout<<"Enter number of test:"<<endl;
    cin>>n_test;
    for(int i = 0; i < test; i++) {
        input>>n>>p;
        if(n < p) {
            cout<<"n<p in the test "<<i+1<<endl;
        }
        Polygon Q(n,p);
        if(i == n_test) {
            break;
        }
    }
    input.close();
    return 0;
}