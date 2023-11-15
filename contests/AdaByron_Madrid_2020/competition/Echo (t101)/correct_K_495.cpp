#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second


int main(int argc, char** argv) {
    int tt;
    int n, c, i;
    
    cin >> tt;
    while(tt--) {
        cin >> n >> c;
        //vector<int> mal(c);
        set<int> smal;
        vector<pii> q(c);
        for(i = 0; i < c; i++) {
            cin >> q[i].se >> q[i].fi;
            //mal[i] = q[i].se;
            smal.insert(q[i].se);
        }
        sort(q.begin(), q.end());

        
        //cout << (*smal.begin()) << " " << (*(smal.rbegin())) << endl;
        int l = 0, r = c-1, a=1, b=n;
        bool nos = false;

        while(l <= r && a < b) {
            /*cout << "estoy en " << a << " " << b << endl;
            cout << "q\n";
            for(int kk = l; kk <= r; kk++) {
                cout << q[kk].fi << " " << q[kk].se << "....";
            }cout << endl;
            cout << "smal\n";
            for(auto el : smal) cout << el << "...";
            cout << endl;*/
            

            
            while(l <= r && a >= q[l].fi) {
                smal.erase(q[l].se);
                l++;
            }
            
            while(l <= r && b <= q[r].fi) {
                smal.erase(q[r].se);
                r--;
            }
            if(l > r) break;
            
            if(a == (*smal.begin())-1 && b == (*smal.rbegin())+1) {nos = true; break;}
            if(a != (*smal.begin())-1) {
                a = (*smal.begin())-1;
                continue;
            }
            //if(b == (*smal.rbegin())+1) {
                
              //  continue;
            //}
            b = max(q[r].fi, (*smal.rbegin())+1);
        }
        
        if(nos == true) {
            cout << "Encerrados para siempre.\n";
        } else cout << b << "\n";
        
    }
    return 0;
}

