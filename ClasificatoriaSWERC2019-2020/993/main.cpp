#include <bits/stdc++.h>
/*AC*/
#define echo(x) cout << #x << ":" << x << endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(void) {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll a;
    while(n--){
        cin>>a;
        if(a==0){
            cout<<"0\n";
                    continue;
        }
        if(a==1){
            cout<<"1\n";
                    continue;
        }
        vector<int> digits;
        for(int i=9;i>1;--i){
            while(a%i==0){
                a/=i;
                digits.push_back(i);
            }
        }
        sort(digits.begin(),digits.end());
        if(a==1){
            for(int a:digits){
            cout<<a;
        }
        }
        else cout<<"-1";
        cout<<"\n";
    }
    return 0;
}

