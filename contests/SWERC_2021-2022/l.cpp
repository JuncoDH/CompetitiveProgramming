#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef long double ld;
typedef vector<lli> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<lli, lli> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
int filled[21][365];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vi> lines(21);
        for(int i=0;i<21;++i){
            for(int j=0;j<365;++j){
                filled[i][j]=0;
            }
        }
        for(int i=0;i<n;++i){
            char c;
            cin>>c;
            if(c=='C'){
                int c1,c2,r;
                cin>>r>>c1>>c2;
                if(c1<c2){
                    for(int j=c1;j<c2;++j){
                        filled[r][j]=true;
                    }
                }
                else{
                    for(int j=c1;j<360;++j){
                        filled[r][j]=true;
                    }
                    for(int j=0;j<c2;++j){
                        filled[r][j]=true;
                    }
                }
            }
            else{
                int r1, r2, c;
                cin>>r1>>r2>>c;
                for(int j=r1;j<r2;++j){
                    lines[j].pb(c);
                }
            }
            for(int z=0;z<21;++z){
                sort(lines[z].begin(), lines[z].end());
                
            }
            
        }
        
        vector<vector<pii>> gates(21);

        for(int z = 1;z<=20;++z){
            int prev= 0;
            for (int tt=0;tt<360;++tt){
                if(filled[z][tt]){
                    if(prev != -1 && prev<tt){
                        gates[z].pb({prev,tt-1});
                    }
                    prev = -1;
                }
                else{
                    if(prev==-1) prev=tt;
                }
            }
            if(prev !=-1)
            gates[z].pb({prev,359});
        }

        set<pii> current_entry;
        set<pii> next_entry;
        current_entry.insert({0,359});
        for(int zz=20;zz>0;--zz){
            if(lines[zz-1].size()==0){
                for(auto gate2: gates[zz]){
                    next_entry.insert(gate2);
                }
                cout<<"hii"<<zz<<endl;
                continue;
            }   
            for(int i=0;i<lines[zz-1].size();++i){
                for(auto gate:current_entry){
                    for(auto gate2:gates[zz]){
                        int ll = 0;
                        if(i != 0) ll= lines[zz-1][i-1];
                        int rr = lines[zz-1][i];

                        if(max(ll,gate.fi)<=min(rr,gate.se)){
                            int mm= max(ll,gate2.fi);
                            int mm2=min(rr,gate2.se);
                            if(mm<=mm2){
                                next_entry.insert(gate2);
                            }
                        }
                    }
                }
            }
            for(auto gate:current_entry){
                for(auto gate2:gates[zz]){
                    int ll = lines[zz-1].back();
                    int rr = 359;
                    if(max(ll,gate.fi)<=min(rr,gate.se)){
                        int mm= max(ll,gate2.fi);
                        int mm2=min(rr,gate2.se);
                        if(mm<=mm2){
                            next_entry.insert(gate2);
                        }
                    }
                }
            }
            current_entry = next_entry;
            cout<<zz<<"-> ";
            for(auto a: current_entry){
                cout<<a.fi<<","<<a.se<<" ";
            }
            next_entry.clear();
            cout<<endl;
        }


        for(int z=0;z<=20;++z){
            cout<<z<<": ";
            for(auto a:lines[z]){
                cout<<a<<" ";
            }
            cout<<":: ";
            for(auto a:gates[z]){
                cout<<a.fi<<","<<a.se<<endl;
            }
            cout<<endl;
        }

    }

    return 0;
}