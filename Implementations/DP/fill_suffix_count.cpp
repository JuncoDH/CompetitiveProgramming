string t;
int cont2[MAX_LENGTH+1][MAX_ALPHABET]; //cont[i][j] = number of ocurrences of char i in suf[j..n-1]
void fill_suffix_count2() {
    int i, j, n = t.size();
    for(i = n-1; i >= 0; i--) {
        for(j = 0; j < MAX_ALPHABET; j++) {
            cont2[i][j] = cont2[i+1][j];
        }
        cont2[i][t[i]-'a']++;
    }
}
