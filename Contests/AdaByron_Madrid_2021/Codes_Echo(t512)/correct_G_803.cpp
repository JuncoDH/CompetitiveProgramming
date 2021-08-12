#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <sstream>


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
    string s;

    //cin >> J >> P >> D >> M >> F;
    getline(cin, s);
    stringstream ss;
    ss << s;
    ss >> s;
    J = stoll(s);
    ss >> s;
    P = stoll(s);
    ss >> s;
    D = stoll(s);
    ss >> s;
    M = stoll(s);
    ss >> s;
    F = stoll(s);


    ll SUM = P+D+M+F;
    vll v(SUM);
    getline(cin, s);
    ss.clear();
    ss << s;
    i = 0;
    while(ss >> s) {
        v[i] = stoll(s);
        i++;
    }
    //for(i = 0; i < SUM; i++) {
     //   cin >> v[i];
    //}
    map<ll, pair<int, pair<string, string>>> ma;
    int tot = 0;
    for(i = 0; i < J; i++) {
        //cin >> num >> s1 >> s2;
        getline(cin, s);
        num = stoll(s);
        getline(cin, s1);
        getline(cin, s2);
        ma[num] = {tot, {s1, s2}};
        tot++;
    }
    ll np = 0, nd = 0, nm = 0, nf= 0;
    vector<pair<int, string>> vp, vd, vm, vf;
    for(i = 0; i < SUM; i++) {
        pair<int, pair<string, string>> p = ma[v[i]];
        //cout << v[i] << " " << p.second.fi << " " << p.se.se << endl;
        if(p.second.se == "P") {
            vp.pb({p.fi, p.se.fi});
            np++;
        }
        else if(p.se.se == "DF") {
            vd.pb({p.fi, p.se.fi});
            nd++;
        }
        else if(p.se.se == "MC") {
            vm.pb({p.fi, p.se.fi});
            nm++;
        }
        else if(p.se.se == "DL") {
            vf.pb({p.fi, p.se.fi});
            nf++;
        }
    }
    //cout << np << " " << nd << " " << nm << " " << nf << endl;
    if(np != P || nd != D || nm != M || nf != F) {
        cout << "Error en la alineacion\n";
        return 0;
    }
    sort(vp.begin(), vp.end());
    sort(vd.begin(), vd.end());
    sort(vm.begin(), vm.end());
    sort(vf.begin(), vf.end());
    for(i = 0; i < P; i++) {
        if(i > 0) cout << " ";
        cout << vp[i].se;
    }
    cout << "\n";
    for(i = 0; i < D; i++) {
        if(i > 0) cout << " ";
        cout << vd[i].se;
    }
    cout << "\n";
    for(i = 0; i < M; i++) {
        if(i > 0) cout << " ";
        cout << vm[i].se;
    }
    cout << "\n";
    for(i = 0; i < F; i++) {
        if(i > 0) cout << " ";
        cout << vf[i].se;
    }
    cout << "\n";



    return 0;
}