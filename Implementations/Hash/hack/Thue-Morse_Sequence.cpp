string Thue_Morse = "01101001100101101001011001101001";
int count_ones(int num) {
    int ans = 0;
    while(num) {
        ans += num & 1;
        num >>= 1;
    }
    return ans;
}
ll get_hash(string s) {
    ll  i, ans = s[0] - '0', b = 7, base = 1, n = s.length();
    for(i = 1; i < n; ++i) {
        base *= b;
        ans += (s[i] - '0') * base;
    }
    return ans;
}
//Hash(S[0..2^k-1]) == Hash(S[2^k..2^(k-1)-1]), k >= 10, 14 is fine for int, ll, ull
//It not depend on the base of the Rolling-Hash
void collision() {
    string S = "", T = "";
    ll i = 0, X = 1 << 14;//2 ^ 14 = 16384 < 1e5 / 2   
    for(i = 0; i < X; ++i) {
        S += to_string(count_ones(i) & 1); //S[0..2^k]
        T += to_string(1 - (count_ones(i) & 1)); //S[2^k..2^(k-1)-1]
    }
    cout << get_hash(S) << " " << get_hash(T) << endl;
    //cout << "2\n";
    //cout << S << " " << T << endl;
}

