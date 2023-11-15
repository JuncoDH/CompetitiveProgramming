#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>


#define pb push_back
#define mp make_pair
#define se second
#define fi first

using namespace std;


typedef long long ll;
typedef vector<ll> vll;


int main() {
    ll J, P, D, M, F, i, num;
    string s1, s2;

    cin >> J >> P >> D >> M >> F;
    ll SUM = P+D+M+F;
    vll v(SUM);
    for(i = 0; i < SUM; i++) {
        cin >> v[i];
    }
    map<ll, pair<string, string>> ma;
    for(i = 0; i < J; i++) {
        cin >> num >> s1 >> s2;
        ma[num] = {s1, s2};
    }
    ll np = 0, nd = 0, nm = 0, nf= 0;
    vector<string> vp, vd, vm, vf;
    for(i = 0; i < SUM; i++) {
        pair<string, string> p = ma[v[i]];
        if(p.second == "P") {
            vp.pb(p.fi);
            np++;
        }
        else if(p.se == "DF") {
            vd.pb(p.fi);
            nd++;
        }
        else if(p.se == "MC") {
            vm.pb(p.fi);
            nm++;
        }
        else if(p.se == "DL") {
            vf.pb(p.fi);
            nf++;
        }
    }
    if(np < P || nd < D || nm < M || nf < F) {
        cout << "Error en la alineacion\n";
        return 0;
    }
    for(i = 0; i < P; i++) {
        if(i > 0) cout << " ";
        cout << vp[i];
    }
    cout << "\n";
    for(i = 0; i < D; i++) {
        if(i > 0) cout << " ";
        cout << vd[i];
    }
    cout << "\n";
    for(i = 0; i < M; i++) {
        if(i > 0) cout << " ";
        cout << vm[i];
    }
    cout << "\n";
    for(i = 0; i < F; i++) {
        if(i > 0) cout << " ";
        cout << vf[i];
    }
    cout << "\n";



    return 0;
}
