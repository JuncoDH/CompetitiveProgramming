#include <bits/stdc++.h>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;



struct semaforo{
    int ta, tc;
    double m;
};

int fa, fc;
double fm;
bool par = false;
double siguienteV(int& anterior){
    if(par == false){
        par = true;
        anterior += fc; 
    } else {
        par = false;
        anterior += fa;
    }
    
    return fm / anterior;
}

int main(){
    ios::sync_with_stdio(false);
    int i, t = 0, n, maxv;
    double vel, s;
    bool flag;

    while(1) {
        par = false;
        cin >> n >> maxv;
        
        if(n == 0 && maxv == 0) return 0;
        
        //if(n == 0) {cout << maxv << "\n"; continue; }
        
        vector<semaforo> v(n);
        flag = false;
        
        for(i = 0; i < n; ++i){
            cin>>v[i].m >> v[i].tc >> v[i].ta;
            if(i > 0) v[i].m += v[i-1].m;
            
            if(v[i].ta == 0) flag = true;
        }
        
        if(flag == true) {cout << "IMPOSIBLE\n"; continue; }
        
        fm = v[n - 1].m;
        fa = v[n - 1].ta;
        fc = v[n - 1].tc;

        t = 0;
        vel = siguienteV(t);
        

        while(vel > maxv && vel >= 0.1) vel = siguienteV(t);

        for(i = 0; i < n - 1; ++i) {
            if(vel < 0.1) break;
            
            s = double(v[i].m * t) / (double)fm;
            
            int cociente = s / (v[i].ta + v[i].tc);

            if(s - cociente*(v[i].ta + v[i].tc) < v[i].tc - 0.01 && s - cociente*(v[i].ta + v[i].tc) > 0.01){
                vel = siguienteV(t);
                i = -1;
                continue;
            }
            
            
        }
        
        if(vel > maxv || vel < 0.1) cout << "IMPOSIBLE\n";
        else cout << fm / vel << "\n";
        
    }

    return 0;
}