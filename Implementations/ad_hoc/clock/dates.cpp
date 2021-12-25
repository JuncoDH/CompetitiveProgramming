int is_leap_year(int y) {
    if(y%4 || (y%100==0 && y%400)) return 0;
    return 1;
}
int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_month_accumulate[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

// d 1-index, m 1-index.
int date_to_num(int d, int m, int y) {
    m -= 2;
    int sum = d;
    if(m >= 1) sum += is_leap_year(y);
    y--;
    if(m >= 0) sum += days_month_accumulate[m];
    if(y >= 0) {
        sum += 365*y;
        sum += y/4 -y/100 + y/400;
    } 
    return sum;
}

int nd, nm, ny; // Tiny optimization, binary search the year, month and day.
void num_to_date(int num) {
    nd = 1; nm = 1; ny = 2020; // The date searched is >= this date.
    while(date_to_num(nd, nm, ny) <= num) ny++;
    ny--;
    while(nm < 12 && date_to_num(nd, nm, ny) <= num) nm++;
    nm--;
    while(date_to_num(nd, nm, ny) <= num) nd++;
    nd--;
}
