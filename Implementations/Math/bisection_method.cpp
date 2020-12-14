// Find the root of ld f(ld x){} in the interval [l..r] with precission of eps.
ld bisection_method(ld l, ld r) {
    ld fl = f(l), fr = f(r), mid, fmid;
    if(fl == 0) return l;
    if(fr == 0) return r;
    bool sgn1 = fl > 0, sgn2 = fr > 0;
    if(sgn1 == sgn2) {echo("ERROR", sgn1); exit(-1);}
    while(r-l > eps) {
        mid = (l+r)/2;
        fmid = f(mid);
        if(fmid == 0) return mid;
        if(fmid > 0) {
            if(sgn1) l = mid;
            else r = mid;
        } else {
            if(sgn1) r = mid;
            else l = mid;
        }
    }
    return (l+r)/2;
}
