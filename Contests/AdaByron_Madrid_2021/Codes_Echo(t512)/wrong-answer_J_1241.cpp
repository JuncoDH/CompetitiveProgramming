#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#include <set>

#define pb push_back
#define fi first
#define se second
using namespace std;

using vi = vector<int>;
using ll = unsigned long long;
using pi = pair<int,int>;
const int lim = 257;
struct node{
    char letter;
    node* next[lim];
    bool isEnding;
};

node * new_node(){
    node* n = new node();
    n->letter = 0;
    n->isEnding = false;
    for(int i=0;i<lim;++i){
        n->next[i]=nullptr;
    }
    return n;
}
node * root=new_node();
void add(string s){
    node * n = root;
    for(auto c:s){
        if(!n->next[c]){
            n->next[c]=new_node();
            n->next[c]->letter=c;
        }
        n=n->next[c];
    }
    n->isEnding=true;
}

set<string> values;
void getall(const string prefix, node * point){
    if(point->isEnding){
        values.insert(prefix+point->letter);
    }
    for(int i=0;i<lim;++i){
        if(point->next[i]){
            getall(prefix+point->letter,point->next[i]);
        }
    }

}
bool fetch(string prefix){
    node * n= root;
    for(auto c:prefix){
        if(!n->next[c]){
            return false;
        }
        n=n->next[c];
    }
    prefix.pop_back();
    getall(prefix,n);
    return true;
}
int main() {
    int n;
    cin>>n;
    string s;
    root = new_node();
    for(int i=0;i<n;++i){
        cin>>s;
        add(s);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        cin>>s;
        values.clear();
        fetch(s);
        cout<<"Caso #"<<i+1<<":\n";
        if(values.size()==0){
            cout<<"Sin combinacion\n";
        }
        else{
            for(auto s:values){
                cout<<s<<"\n";
            }
        }
    }

    return 0;
}