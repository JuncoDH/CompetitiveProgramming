// Convert hours and minutes to grades of the clock hand, mp(grade of large hour hand, small minute hand).
pair<ld, ld> get_grades(ll h, ll m) {
    return mp((ld)30*h + (ld)m/2, (ld)6*m);
}

// Convert hours and minutes to grades of the clock hand, mp(grade of large hour hand, small minute hand).
// Not tested.
pair<ld, pair<ld, ld>> get_grades(ll h, ll m, ll s) {
    return mp((ld)30*h + (ld)m/2 + (ld)s/120, mp((ld)6*m + (ld)s/10, (ld)6*s));
}

