#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll; 

bool g(ll num) {
    while(num % 2 == 0) num /= 2;
    while(num % 3 == 0) num /= 3;
    while(num % 5 == 0) num /= 5;
    return num == 1;    
}

void f() {
    ll cont = 0, i;
    for(i = 1; i < 1000000000; i++) {
        if(g(i)) cont++;
        if(cont == 1500) break;
    }
    cout << cont << endl;
    cout << i << endl;
}

int main(){

    // f();
    cout << "The 1500'th ugly number is 859963392.\n";

    return 0;
}