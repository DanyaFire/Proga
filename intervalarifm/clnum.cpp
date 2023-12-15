#include "clnum.h"

interval combination(interval u, interval v){
    interval OUV;
    if((u.First(u) < v.First(v) && abs(u.Second(u) - v.Second(v)) < eps) || (v.Second(v) < u.Second(u) && u.First(u) < v.First(v)) || (abs(u.First(u) - v.First(v)) < eps && abs(u.Second(u) - v.Second(v)) < eps) || (v.Second(v) < u.Second(u) && abs(u.First(u) - v.First(v)) < eps)) OUV = u;
    else if((u.First(u) > v.First(v) && abs(u.Second(u) - v.Second(v)) < eps) || (u.Second(u) < v.Second(v) && abs(u.First(u) - v.First(v)) < eps) || (u.Second(u) < v.Second(v) && v.First(v) < u.First(u))) OUV = v;
    else if(u.First(u) < v.First(v) && v.First(v) < u.Second(u) && u.Second(u) < v.Second(v)) {
        interval t(u.First(u),v.Second(v));
        OUV = t;
    } else if(v.First(v) < u.First(u) && u.First(u) < v.Second(v) && v.Second(v) < u.Second(u)) {
        interval t(v.First(v),u.Second(u));
        OUV = t;
    } else {
        Point a(0), b(0);
        interval OUV(a,b);
        return OUV;
    }
    return OUV;
}

interval intersection(interval u, interval v) {
    interval OinterU;
    if((u.First(u) < v.First(v) && abs(u.Second(u) - v.Second(v)) < eps) || (v.Second(v) < u.Second(u) && abs(u.First(u) - v.First(v)) < eps) || (u.First(u) < v.First(v) && v.First(v) < v.Second(v) && v.Second(v) < u.Second(u))) OinterU = v;
    else if((u.Second(u) < v.Second(v) && abs(u.First(u) - v.First(v)) < eps) || (v.First(v) < u.First(u) && abs(u.Second(u) - v.Second(v)) < eps) || (v.First(v) < u.First(u) && u.First(u) < u.Second(u) && u.Second(u) < v.Second(v))) OinterU = u;
    else if(u.First(u) < v.First(v) && v.First(v) < u.Second(u) && u.Second(u) < v.Second(v)) { 
        interval t(v.First(v),u.Second(u));
        OinterU = t;
    } else if(v.First(v) < u.First(u) && u.First(u) < v.Second(v) && v.Second(v) < u.Second(u)) {
        interval t(u.First(u),v.Second(v));
        OinterU = t;
    } else {
        Point r(0), l(0);
        interval OinterU(r,l);
    }
    return OinterU; 
}

interval difference(interval u, interval v) {
    interval OdifU;
    if((u.First(u) < u.Second(u) && u.Second(u) <= v.First(v) && v.First(v) < v.Second(v)) || (abs(u.First(u) - v.First(v)) < eps && abs(u.Second(u) - v.Second(v)) < eps)) {
        interval t(u.First(u),u.Second(u));
        OdifU = t;
    } else if((u.First(u) < v.First(v) && v.First(v) < u.Second(u) && u.Second(u) < v.Second(v)) || (v.First(v) < u.First(u) && u.First(u) < v.Second(v) && v.Second(v) < u.Second(u))) {
        interval t(u.First(u),v.First(v));
        OdifU = t;
    } else if(v.First(v) < v.Second(v) && v.Second(v) <= u.First(u) && u.First(u) < u.Second(u)) {
        interval t(v.First(v),v.Second(v));
        OdifU = t;
    } else if(abs(u.First(u) - v.First(v)) < eps && (u.Second(u) < v.Second(v) || v.Second(v) < u.Second(u))) {
        interval t(u.Second(u),v.Second(v));
        OdifU = t;
    } else if((u.First(u) < v.First(v) || v.First(v) < u.First(u)) && abs(u.Second(u) - v.Second(v)) < eps) {
        interval t(u.First(u),v.First(v));
        OdifU = t;
    } else if((u.First(u) < v.First(v) && v.First(v) < v.Second(v) && v.Second(v) < u.Second(u))||(v.First(v) < u.First(u) && u.First(u) < u.Second(u) && u.Second(u) < v.Second(v))) {
        Point a(0), b(0);
        interval OdifU(a,b);
    }
    return OdifU;
}

void sym_difference(interval u, interval v) {
    if((u.First(u) < u.Second(u) && u.Second(u) <= v.First(v) && v.First(v) < v.Second(v))||(v.First(v) < v.Second(v) && v.Second(v) <= u.First(u) && u.First(u) < u.Second(u))) {
        interval t(u.First(u),u.Second(u));
        t.print_int(t);
        cout<<"U";
        interval p(v.First(v),v.Second(v));
        p.print_int(p);
    } else if((u.First(u) < v.First(v) && v.First(v) < u.Second(u) && u.Second(u) < v.Second(v)) || (v.First(v) < u.First(u) && u.First(u) < v.Second(v) && v.Second(v) < u.Second(u))) {
        interval t(u.First(u),v.First(v));
        t.print_int(t);
        cout<<"U";
        interval p(u.Second(u),v.Second(v));
        p.print_int(p);
    } else if(abs(u.First(u) - v.First(v)) < eps && (u.Second(u) < v.Second(v) || u.Second(u) > v.Second(v))) {
        interval t(u.Second(u),v.Second(v));
        t.print_int(t);
    } else if((u.First(u) < v.First(v) || v.First(v) < u.First(u)) && abs(u.Second(u) - v.Second(v)) < eps) {
        interval t(u.First(u),v.First(v));
        t.print_int(t);
    } else if(abs(u.First(u) - v.First(v)) < eps && abs(u.Second(u) - v.Second(v)) < eps) {
        cout<<"0";
    } else if((u.First(u) < v.First(v) && v.First(v) < v.Second(v) && v.Second(v) < u.Second(u))||(v.First(v) < u.First(u) && u.First(u) < u.Second(u) && u.Second(u) < v.Second(v))) {
        interval t(u.First(u),v.First(v));
        t.print_int(t);
        cout<<"U";
        interval p(u.Second(u),v.Second(v));
        p.print_int(p);
    }
}