// Prints the hour. printf("%02d:%02d:%02d", h, m, s);
void print_hour(ll h, ll m, ll s) {
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
// Read the hour. scanf("%d:%d:%d", &h, &m, &s);
void read_hour(ll &h, ll &m, ll &s) {
    char c; // Dummy for read ':'.
    cin >> h >> c >> m >> c >> s;
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

