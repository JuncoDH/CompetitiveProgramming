// Change here and date_to_num.
ll is_leap_year(ll const y) {
    // if(y % 4 || (y % 100 == 0 && y % 400)) return 0; // Complete leap year. // Gregorian Calendar.
    if(y % 4 != 0) return 0; // Restricted leap year. // Julian Calendar.
    return 1;
}
constexpr ll days_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
constexpr ll days_month_accumulate[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
// d 1-index, m 1-index.
ll date_to_num(ll const d, ll m, ll y) {
    ll sum = d;
    m -= 2;
    if(m >= 1) sum += is_leap_year(y);
    --y;
    if(m >= 0) sum += days_month_accumulate[m];
    if(y >= 0) {
        sum += 365 * y;
        // sum += y / 4 - y / 100 + y / 400; // Complete leap year.
        sum += y / 4; // Restricted leap year.
    }
    return sum;
}
// Tiny optimization, binary search the year, month and day.
void num_to_date(ll const num, ll d, ll m, ll y) {
    d = 1; m = 1; y = 0; // The date searched is >= this date.
    while(date_to_num(d, m, y) <= num) ++y;
    --y;
    while(date_to_num(d, m, y) <= num) ++m;
    --m;
    while(date_to_num(d, m, y) <= num) ++d;
    --d;
}
void cin_date(ll& d, ll& m, ll& y) {
    char c;
    cin >> d >> c >> m >> c >> y;
}
void cout_date(ll const d, ll const m, ll const y) {
    cout.fill('0');
    cout << setw(2) << d << "/";
    cout << setw(2) << m << "/";
    cout << setw(4) << y;
}

