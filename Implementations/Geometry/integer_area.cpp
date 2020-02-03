//Do vectorial product to a clockwise or anticlockwise sorted points
cin >> n;
vector<pll> v(n);
for(i = 0; i < n; i++) {
    cin >> v[i].fi >> v[i].se;
    
}
s = 0;
for(i = 0; i < n; i++) {
    s += v[i].fi*v[(i+1)%n].se - v[(i+1)%n].fi*v[i].se;
}
ans = abs(s)/2.0;
