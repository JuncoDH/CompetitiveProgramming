#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back


typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


int main(){

    int t;
    cin>>t;
    for(int w=0;w<t;++w){
        int n;
        cin>>n;
        vector<pii> dat;
        string ssss;
        getline(cin,ssss);
        for(int i=0;i<n;++i){
            string s;
            
            getline(cin,s);
            stringstream ss(s);
            int cnt=0;
            int aux=0;
            while(ss>>aux)cnt++;
            dat.pb({cnt,i});
        }
        /*for(auto a:dat){
            cout<<a.fi<<" "<<a.se<<"\n";
        }*/
        sort(dat.begin(),dat.end());

        vi res;
        for(int i=0;i<(int)dat.size();++i){
            if(dat[i].fi>dat[0].fi)break;
            res.pb(dat[i].se);
        }
        for(int i=0;i<(int)res.size();++i){
            if(i)cout<<" ";
            cout<<res[i]+1;
        }
        cout<<"\n";
        

    }



    return 0;
}