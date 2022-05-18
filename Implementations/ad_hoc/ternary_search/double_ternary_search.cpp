Point<ld> q1, q2, q3;
ld f(ld mid1, ld mid) {
    Point<ld> p(mid1, mid);
    pair<Point<ld>, ld> ret1 = get_fermat_point(p, q1, q2);
    pair<Point<ld>, ld> ret2 = get_fermat_point(p, q2, q3);
    pair<Point<ld>, ld> ret3 = get_fermat_point(p, q1, q3);
    return max(ret1.se, max(ret2.se, ret3.se));
}
ld ternary_serch(ld mid1) {
    ld l = -1e5, r = 1e5, mid, mi_eps = 1e-6;
    int i;
    for(i = 0; i < 200; i++) {
        mid = (l+r)/2;
        if(f(mid1, mid) > f(mid1, mid+mi_eps)) l = mid;
        else r = mid; 
    }
    return f(mid1, l);
}
// Convex function, return minimum of g, and
// g = max(f1, f2, f3). Binary search each one of its coordinates.
ld double_ternary_search() {
    ld l = -1e5, r = 1e5, mid, mi_eps = 1e-6;
    int i;
    for(i = 0; i < 200; i++) {
        mid = (l+r)/2;
        if(ternary_serch(mid) > ternary_serch(mid+mi_eps)) l = mid;
        else r = mid;
    }
    return ternary_serch(l);
}

