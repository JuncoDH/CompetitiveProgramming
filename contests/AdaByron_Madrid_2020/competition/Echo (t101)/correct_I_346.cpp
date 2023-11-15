
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;


int main(int argc, char** argv) {
    /*int n,m;
    string ssss;
    getline(cin,ssss);
    stringstream sst(ssss);
    sst>>n>>m;
    set<string> se;
    map<string,int> ma;
    for(int i=0;i<n;++i){
        string s;
        getline(cin,s);
        se.insert(s);
        ma[s]=0;
    }
    
    for(int i=0;i<m;++i){
        string s;
        getline(cin,s);
        ma[s]++;
    }
    bool all=true;
    bool rep=false;

    for(auto d:ma){
        if(d.second<1){
            all=false;
            break;
        }
        if(d.second>1)rep=true;
        
    }
    if(!all){
        cout<<"PONTE A TRABAJAR\n";
    }
    else{
        if(rep){
            cout<<"TRABAJAS DEMASIADO\n";
        }
        else{
            cout<<"PUEDES DESCANSAR\n";
        }
    }*/
    int n, m, i;
    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;
    ss >> n >> m;
    vector<string> v(n), a(m);
    //vector<int> respuesta(n, 0);
    for(i = 0; i < n; i++) {
        getline(cin, v[i]);
    }
    for(i = 0; i < m; i++) {
        getline(cin, a[i]);
    }
    sort(v.begin(), v.end());
    sort(a.begin(), a.end());
    int l = 0, r = 0;
    while(l < n && r < m) {
        if(v[l] == a[r]) {l++; r++;}
        else r++;
    }
    /*if(v == a) {cout << "PUEDES DESCANSAR\n";}
    else if(n < m) */
    if(l == n && r == m) cout << "PUEDES DESCANSAR\n";
    else if(l == n) cout << "TRABAJAS DEMASIADO\n";
    else cout << "PONTE A TRABAJAR\n";
    
    return 0;
}

