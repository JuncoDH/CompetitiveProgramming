// Using a 26 prefix sums with 'a' to 'z' chars.
string s;
constexpr int MAX_LEN = 2 * 1e5 + 4;
constexpr int ALPHABET = 26;
int cnt[ALPHABET][MAX_LEN];
void pre_cont_letters() {
    int n = s.length();
    for(int i = 0; i < ALPHABET; i++) {
        for(int j = 0; j < n; j++) {
            cnt[i][j + 1] = cnt[i][j];
            if(s[j] - 'a' == i) cnt[i][j + 1]++;
        }
    }
}
// Returns the number of distinct letters in the substring [l..r] of the string s.
int cont_letters(int const l, int const r) {
    int sum=0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i][r + 1] - cnt[i][l] > 0) sum++;
    }
    return sum;
}

