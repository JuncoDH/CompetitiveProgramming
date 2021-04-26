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
int main() {
    ll n,b;
    cin>>n>>b;
    ll x,y,z;


    for(int i=0;i<n;++i){
        cin>>x>>y>>z;
        if(b>63){
            cout<<"PUKECARTAS\n";
        }
        else{
            ll na= (1ull<<b);
            if(na > x && na > y && na > z){
                cout<<"PUKECARTAS\n";
            }
            else{
                cout<<"SIN BATERIA\n";
            }

        }
    }

    return 0;
}