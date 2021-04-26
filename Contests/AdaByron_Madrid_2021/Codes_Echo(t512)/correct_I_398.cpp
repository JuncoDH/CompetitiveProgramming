#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define pb push_back
#define fi first
#define se second
using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;
int main() {
    int n,m;
    cin>>n>>m;
    vector<vi> table;
    table.reserve(n);
    vi maxims;
    int a;
    for(int i=0;i<n;++i){
        vi row;
        row.reserve(m);
        int ma=-1;
        for(int j=0;j<m;++j){
            cin>>a;
            row.pb(a);
            ma=max(ma,a);
        }
        table.pb(row);
        maxims.pb(ma);
    }
    int hab;
    while(cin>>hab && hab!= -1){
        int row=-1;
        int col=0;
        auto it =lower_bound(maxims.begin(),maxims.end(),hab);
        if(it==maxims.end()){
            row= n-1;
            col=m-1;
            cout<<"TU CITA ESTA EN LA HABITACION "<<row<<" "<<col<<"\n";
            continue;
        }
        row = it-maxims.begin();
        auto it2 = lower_bound(table[row].begin(), table[row].end(),hab);
        if(it2==table[row].end()){
            exit(-1);
        }
        col=it2-table[row].begin();
        cout<<"TU CITA ESTA EN LA HABITACION "<<row<<" "<<col<<"\n";
    }



    return 0;
}
