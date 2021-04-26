#include <iostream>
#include <vector>
#include <algorithm>

#define push_back pb
#define make_pair mp

using namespace std;


typedef long long ll;
typedef vector<ll> vll;

struct node {
    node* p[26];
    int end;
};

node* get_node() {
    int i;
    node* pn = new node();
    for(i = 0; i < 26; i++) pn->p[i] = NULL;
    pn->end = 0;
}

node* root = NULL;

void add(string &s) {
    node* pn = root;
    for(auto c : s) {
        int ch = c-'a';
        if(pn->p[ch] == NULL) pn->p[ch] = get_node();
        pn = pn->p[ch];
    }
    pn->end++;
}
bool muestra;

void show2(node* pn, string &s) {
    int i;
    for(i = 0; i < pn->end; i++) {
        cout << s << "\n";
        muestra = true;
    }
    for(i = 0; i < 26; i++) {
        if(pn->p[i] != NULL) {
            char c = i+'a';
            s += c;
            node* pn2 = pn->p[i];
            show2(pn2, s);
            s.pop_back();
        }
    }
}

void show(string &s) {
    node* pn = root;
    string res = "";
    for(auto c : s) {
        int ch = c-'a';
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

    cin  >> n;
    for(i = 0; i < n; i++) {
        cin >> s;
        add(s);
    }
    cin >> q;
    for(i = 1; i <= q; i++) {
        cout << "Caso #" << i << ":\n";
        cin >> s;
        muestra = false;
        show(s);
        if(!muestra) {
            cout << "Sin combinacion.\n";
        }
    }

    return 0;
}
