// Get maximum, minimum, second maximum and second minimum.
pair<pll, pll> get_mnmx(vll const& v) {
    ll n = v.size(), mx, mx2, mn, mn2;
    mx = mn = v[0];
    mx2 = -inf;
    mn2 = inf;
    for(int i = 1; i < n; ++i) {
        if(v[i] >= mx) {
            mx2 = mx;
            mx = v[i];
        } else if(v[i] >= mx2) {
            mx2 = v[i];
        }
        if(v[i] <= mn) {
            mn2 = mn;
            mn = v[i];
        } else if(v[i] <= mn2) {
            mn2 = v[i];
        }
    }
    return { { mn, mn2 }, { mx, mx2 } };
}

