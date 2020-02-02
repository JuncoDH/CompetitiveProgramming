//Using a 26 prefix sums with 'a' to 'z' chars
string s;
const int MAX_LEN = 2*1e5+4;
int cnt[26][MAX_LEN];
void pre_cont_letters() {
    int i, j, n = s.length();
    for(i = 0; i < n; i++) {
        for(j = 0; j < 26; j++) {
            cnt[j][i+1] = cnt[j][i];
        }
        cnt[s[i]-'a'][i+1]++;
    }
}
//returns the number of distinct letters in the substring [l..r] of the string s
int cont_letters(int l, int r) {
    int i, sum=0;
    for(i = 0; i < 26; i++) {
        if(cnt[i][r + 1] - cnt[i][l] > 0) sum++;
    }

    return sum;
}
