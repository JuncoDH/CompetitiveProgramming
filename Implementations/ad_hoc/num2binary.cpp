// Converts num to binary with n digits.
string num2binary(ll const num, ll const digit) {
    string s = string(digit, '0');
    for(int i = 0; i < digit; i++) {
        if(is_set(num, i)) s[digit - i - 1] = '1';
    }
    return s;
}

