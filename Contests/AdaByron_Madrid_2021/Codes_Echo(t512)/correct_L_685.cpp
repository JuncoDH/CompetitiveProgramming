#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define pb push_back
#define fi first
#define se second
using namespace std;

using vi = vector<int>;
using ll = unsigned long long;
using pi = pair<int,int>;

vector<vi> adyList;
vi num, low;
int cnt;
int root, rchild;
vi artic;

void dfs(int nparent, int nnode){
    num[nnode]=low[nnode]=cnt++;
    rchild += (nparent == root);

    for(auto a: adyList[nnode]){
        if(num[a]==-1) {
            dfs(nnode, a);
            low[nnode] = min(low[nnode], low[a]);
            if (low[a] >= num[nnode]) {
                artic[nnode] = true;
            }
            if (low[a] > num[nnode]) {

            }
        }else if(a !=nparent){
                low[nnode] =min(low[nnode],num[a]);

        }
    }
}
int ccc;
void findArticulations(int n){
    cnt = 0;
    low=num=vi(n,-1);
    artic = vi(n,0);

    for(int i=0;i<n;++i){
        if(num[i]!= -1){
            continue;
        }
        ccc++;
        root = i;
        rchild = 0;
        dfs(-1,i);
        artic[root]=rchild>1;
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    adyList = vector<vi>(n,vi());
    int a,b;
    ccc=0;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        adyList[a].pb(b);
        adyList[b].pb(a);

    }
    findArticulations(n);
    vi art;
    for(int i=0;i<n;++i){
        if(artic[i]){
            art.pb(i);
        }
    }
    cout<<ccc<<"\n";
    sort(art.begin(),art.end());
    for(auto a: art){
        cout<<a<<"\n";
    }
    return 0;
}