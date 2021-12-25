// Convert grades of the clock hand to hours and minutes. gh is grades of hours and gm grades of minutes.
// return mp(-1, -1) if no solution exists.
pair<ll, ll> get_hand(ld gh, ld gm) {
    ll h = gh/30, m = gm/6;
    if((ld)30*h + (ld)m/2 != gh || (ld)6*m != gm) return mp(-1, -1);
    return mp(h, m);
}
