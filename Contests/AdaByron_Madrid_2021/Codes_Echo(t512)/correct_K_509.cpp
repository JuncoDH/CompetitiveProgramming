#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <climits>

#define pb push_back
#define fi first
#define se second
using namespace std;

using vi = vector<int>;
using ll = unsigned long long;
using pii = pair<int,int>;
int main() {
    int n;
    cin>>n;
    vector<queue<int>> vec;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int a,b;
    int targ = INT_MAX;
    for(int i=0;i<n;++i){
        cin>>a;
        queue<int> q;
        for(int j=0;j<a;++j){
            cin>>b;
            q.push(b);
            targ=min(targ,b);
        }
        vec.pb(q);
        pq.push({q.front(),i});
    }
    int extracted=0;
    while(!pq.empty()){
        pii t = pq.top();
        pq.pop();
        //cout<<t.fi<<endl;
        extracted++;
        if(t.fi==targ){
            break;
        }
        vec[t.se].pop();
        if(!vec[t.se].empty()){
            pq.push({vec[t.se].front(),t.se});

        }
    }
    cout<<extracted<<"\n";


    return 0;
}