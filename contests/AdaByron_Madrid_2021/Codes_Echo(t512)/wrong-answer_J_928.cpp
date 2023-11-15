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

const int ABC = 256;
struct node {
    node* p[ABC];
    int end;
};

node* get_node() {
    int i;
    node* pn = new node();
    for(i = 0; i < ABC; i++) pn->p[i] = NULL;
    pn->end = 0;

    return pn;
}

node* root = NULL;

void add(string &s) {
    node* pn = root;
    for(auto c : s) {
        int ch = (int)c;//c-'a';
        if(pn->p[ch] == NULL) pn->p[ch] = get_node();
        pn = pn->p[ch];
    }
    pn->end++;
}
bool muestra;

void show2(const node* pn, string &s) {
    int i;

    if(pn->end > 0) {
        //for(i = 0; i < pn->end; i++) {
        cout << s << "\n";
        muestra = true;
    }
    for(i = 0; i < ABC; i++) {
        if(pn->p[i] != NULL) {
            char c = (char)i;//i+'a';
            s += c;
            node* pn2 = pn->p[i];
            show2(pn2, s);
            s.pop_back();
        }
    }
}

void show(string &s) {
    const node* pn = root;
    string res = "";
    for(auto c : s) {
        int ch = (int)c;//c-'a';
        if(pn->p[ch] == NULL) return;
        res += c;
        pn = pn->p[ch];
    }
    show2(pn, res);
}

int main() {
    ll n, i, q;
    string s;
    root = get_node();

    getline(cin, s);
    n = stoll(s);
    // cin  >> n;
    for(i = 0; i < n; i++) {
        getline(cin, s);
        //cin >> s;
        add(s);
    }

    getline(cin, s);
    q  = stoll(s);
    // cin >> q;
    for(i = 1; i <= q; i++) {
        cout << "Caso #" << i << ":\n";
        getline(cin, s);
        //cin >> s;
        muestra = false;
        show(s);
        if(!muestra) {
            cout << "Sin combinacion.\n";
        }
    }

    return 0;
}
