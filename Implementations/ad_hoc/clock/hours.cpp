// Read the hour. scanf("%d:%d:%d", &h, &m, &s);
void cin_hour(ll &h, ll &m, ll &s) {
    char c; // Dummy for read ':'.
    cin >> h >> c >> m >> c >> s;
}

// Prints the hour. printf("%02d:%02d:%02d", h, m, s);
void cout_hour(ll h, ll m, ll s) {
    h %= 24; h += 24; h %= 24;
    m %= 60; m += 60; m %= 60;
    s %= 60; s += 60; s %= 60;
    if(h < 10) cout << "0";
    cout << h << ":";
    if(m < 10) cout << "0";
    cout << m << ":";
    if(s < 10) cout << "0";
    cout << s; 
}

// One day has 60*60*24 = 86400 seconds.
// Converts the hour to number of seconds since 00:00:00.
ll hours_to_seconds(ll h, ll m, ll s) {
    return 60*60*h + 60*m + s;
}

// From sec seconds, get the hour. Just's for one day.
void seconds_to_hours(ll &h, ll &m, ll &s, ll sec) {
    sec %= 86400; sec += 86400; sec %= 86400;
    h = sec / (60*60);
    sec %= 60*60;
    m = sec / 60;
    sec %= 60;
    s = sec;
}

// Convert grades of the clock hand to hours and minutes. gh is grades of hours and gm grades of minutes.
// return mp(-1, -1) if no solution exists.
pair<ll, ll> grades_to_hour(ld gh, ld gm) {
    ll h = gh/30, m = gm/6;
    if((ld)30*h + (ld)m/2 != gh || (ld)6*m != gm) return mp(-1, -1);
    return mp(h, m);
}

// Convert hours and minutes to grades of the clock hand, mp(grade of large hour hand, small minute hand).
pair<ld, ld> hour_to_grades(ll h, ll m) {
    return mp((ld)30*h + (ld)m/2, (ld)6*m);
}

// Convert hours and minutes to grades of the clock hand, mp(grade of large hour hand, small minute hand).
// Not tested.
pair<ld, pair<ld, ld>> hour_to_grades(ll h, ll m, ll s) {
    return mp((ld)30*h + (ld)m/2 + (ld)s/120, mp((ld)6*m + (ld)s/10, (ld)6*s));
}

