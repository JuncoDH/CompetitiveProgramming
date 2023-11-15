#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back


typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

ll diez[10];
ll n;

bool valid(ll num) {

    ll a = num % diez[n/2];
    ll b = num / diez[n/2];
    //cout << a << " " << b << endl;
    if((a+b)*(a+b) == num) return true;


    return false;
}

int main(){
    ll i;

    diez[0] = 1;
    for(i = 1; i < 10; i++) diez[i] = diez[i-1]*10;
   /* n = 8;


    for(i = 0; i < diez[n]; i++) {
        if(valid(i)) {
            cout << i << endl;
        }
    }*/

    vll ans2 = {0, 1, 81};
    vll ans4 = {0, 1, 2025, 3025, 9801};
    vll ans6 = {0, 1, 88209, 494209, 998001};
    vll ans8 = {0, 1, 4941729, 7441984, 24502500, 25502500, 52881984, 60481729, 99980001};

    //printf("%")
    while(cin >> n) {
        ll zn;
        if(n == 2) {
            zn = ans2.size();
            for(i = 0; i < zn; i++) {
                printf("%02lld\n", ans2[i]);
            }
        } else if(n == 4) {
            zn = ans4.size();
            for(i = 0; i < zn; i++) {
                printf("%04lld\n", ans4[i]);
            }
        } else if(n == 6) {
            zn = ans6.size();
            for(i = 0; i < zn; i++) {
                printf("%06lld\n", ans6[i]);
            }
        } else if(n == 8) {
            zn = ans8.size();
            for(i = 0; i < zn; i++) {
                printf("%08lld\n", ans8[i]);
            }
        } else {
            return -1;
        }
    }


    return 0;
}