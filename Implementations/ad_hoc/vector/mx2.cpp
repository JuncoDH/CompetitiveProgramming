// Get the second maximum element and its index.
void get_mx2(vll &v, ll &mx2, ll &mxi2) {
    ll mx, mxi, i, n = v.size();
    if(v[0] < v[1]) {mx = v[1]; mxi = 1; mx2 = v[0]; mxi2 = 0;}
    else {mx = v[0]; mxi = 0; mx2 = v[1]; mxi2 = 1;}
    for(i = 2; i < n; i++) {
        if(v[i] >= mx) {
            mx2 = mx;
            mxi2 = mxi;
            mx = v[i];
            mxi = i;
        } else if(v[i] >= mx2) {
            mx2 = v[i];
            mxi2 = i;
        }
    }
}

