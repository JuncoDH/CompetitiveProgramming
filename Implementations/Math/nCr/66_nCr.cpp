const int MAX_C = 1+66; //66 is the for long long, C(66, x)
ll Comb[MAX_C][MAX_C];

void calc() {
    int i, j;
    for(i = 0; i < MAX_C; i++) {
        Comb[i][0] = 1;
        Comb[0][i] = 1;
    }
    for(i = 1; i < MAX_C; i++) {
        for(j = 1; j < MAX_C; j++) {
            if(i+j >= MAX_C) continue;
            Comb[i][j] = Comb[i-1][j] + Comb[i][j-1];
        }
    }
}

ll C(ll i, ll j) {
    return Comb[i-j][j];
}

void show() {
    int i, j;
    for(i = 0; i < MAX_C; i++) {
        for(j = 0; j < MAX_C; j++) {
            cout << Comb[i][j] << " ";
        }
        cout << endl;
    }
}
