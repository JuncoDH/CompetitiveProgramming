// Do vectorial product to a clockwise or anticlockwise SORTED points.
sum = 0;
for(i = 0; i < n; i++) {
    sum += v[i].fi*v[(i+1)%n].se - v[(i+1)%n].fi*v[i].se;
}
ans = abs(sum)/2.0;
