// Count digits in [1, num] without leading zeros.
ll count_digits(ll num) {
    ll ten = 1, len_dig = 1;
    if(num == 0) return 0;
    while(ten <= num) ten *= 10, len_dig++;
    ten /= 10, len_dig--;
    return (num-ten+1)*len_dig + count_digits(ten-1);
}

