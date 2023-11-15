#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back

string w;
int w_len, cont;
vector<string> ans;

struct node {
    struct node* l[27];
    bool end;
};

struct node* new_node() {
    struct node* n = new node;
    int i;
    for(i = 0; i < 27; i++) {
        n->l[i] = NULL;
    }
    n->end = false;
    return n;
}

void f(struct node*n, int i, bool abri) {
    if(n->end == true) {
        abri = true;
        cont++;
        ans.pb(w);
    }
    if(i == w_len) {
        if(abri == false) {
            cont++;
            ans.pb(w);
        }
        n->end = true;
        return;
    }
    if(n->l[w[i]-'a'] != NULL) {
        f(n->l[w[i] - 'a'], i+1, abri);
        return;
    }
    n->l[w[i]-'a'] = new_node();
    f(n->l[w[i] - 'a'], i+1, true);
}

int main(int argc, char** argv) {
    int tt, n, i;
    
    cout << ('z' - 'a') << endl;
    cin >> tt;
    while(tt--) {
        cin >> n;
        cont = 0;
        ans.clear();
        struct node*root = new_node();
        
        for(i = 0; i < n; i++)  {
            cin >> w;
            w_len = w.length();
            f(root, 0, false);
        }
        cout << cont << "\n";
        for(i = 0; i < cont; i++) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}

