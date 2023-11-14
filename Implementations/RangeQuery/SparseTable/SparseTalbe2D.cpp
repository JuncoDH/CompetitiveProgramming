// BE CAREFUL, PROBABLY MLE.
// Preprocess O(nlogn * mlogm), query in O(1).
// table[ir][jr][ic][jr] = f of colum ic to ic + 2^jc - 1 of rows ir to ir + 2^jr - 1.
constexpr ll MAX = 100; // LESS THAN 1500 ELEMENTS MLE, NO COMPILE.
ll table[MAX][(ll)(log2(MAX)) + 1][MAX][(ll)(log2(MAX)) + 1], nr, nc;
vector<vll> v;
ll f(ll const a, ll const b) { return min(a, b); }
void preprocess() {
    ll ir, jr, ic, jc;
    // table[ir][0][ic][jc] is sparse table of row ir.
    for(ir = 0; ir < nr; ++ir){
        for(ic = 0; ic < nc; ++ic) table[ir][0][ic][0] = v[ir][ic];
        for(jc = 1; jc <= (ll)log2(nc); ++jc){
            for(ic = 0; ic < nc; ++ic){
                if((ic + (1ll << jc) - 1) >= nc) break;
                table[ir][0][ic][jc] = f(table[ir][0][ic][jc - 1], table[ir][0][ic + (1ll << (jc - 1))][jc - 1]);
            }
        }
    }
    for(jr = 1; jr <= (ll)log2(nr); ++jr){
        for(ir = 0; ir < nr; ++ir){
            for(jc = 0; jc <= (ll)log2(nc); ++jc){
                for(ic = 0; ic < nc; ++ic){
                    if((ir + (1ll << jr) - 1) >= nr) break;
                    table[ir][jr][ic][jc] = f(table[ir][jr - 1][ic][jc], table[ir + (1ll << (jr - 1))][jr - 1][ic][jc]);
                }
            }
        }
    }
}
// [(x1, y1), (x2, y2)].
ll query(ll const x1, ll const y1, ll const x2, ll const y2){
    ll kx = floor(log2(x2 - x1 + 1));
    ll ky = floor(log2(y2 - y1 + 1));
    ll rg1 = f(table[x1][kx][y1][ky], table[x2 - (1ll << kx) + 1][kx][y1][ky]);
    ll rg2 = f(table[x1][kx][y2 - (1ll << ky) + 1][ky], table[x2 - (1ll << kx) + 1][kx][y2 - (1ll << ky) + 1][ky]);
    return f(rg1, rg2);
}

