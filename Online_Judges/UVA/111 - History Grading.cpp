#include <bits/stdc++.h>

//#pragma GCC diagnostic ignored "-Wsign-compare"

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//O(nlogn) LIS
int LIS_len(vi &v) {
    int i, n = v.size(), it;
    vi LIS;
    LIS.pb(v[0]);

    for(i = 1; i < n; ++i) {
        if(binary_search(LIS.begin(), LIS.end(), v[i])) continue;
        else if(v[i] > LIS.back()) LIS.pb(v[i]);
        else {
            it = upper_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin();
            LIS[it] = v[i];
        }
    }
    return (int)LIS.size();
}

ll n;

//i should be in the pos v[i]
vi f(vi &v) {
    vi ans(n);
    int i;
    for(i = 0; i < n; ++i) {
        ans[v[i]] = i;
    }
    return ans;
}

string s;

//count number of numbers (if count() == 0 then there are 1 number, so it's a new test case)
int count(){
    int ans = 0;
    for(auto c : s) if(c == ' ') ans++;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    ll i, j;
    
    
    getline(cin, s);
//use stringstreams to manage differents test cases

    while(true) {
        //cin >> n;
        stringstream ss;
        ss << s;
        ss >> n;
        
        vi input(n), alumn(n);
        map<int, int> m;
        stringstream ss3;
        getline(cin, s);
        ss3 << s;
        for(i = 0; i < n; ++i) {
            ss3 >> input[i];
            --input[i];
        }

        input = f(input);

        for(i = 0; i < n; ++i) m[input[i]] = i;

        while(true){
            if(!getline(cin, s)) return 0;
            if(count() == 0) break;
            stringstream ss2;
            ss2 << s;
            for(j = 0; j < n; ++j){
                ss2 >> alumn[j];
                //cin >> alumn[j];
                --alumn[j];

            }

            alumn = f(alumn);
            for(j = 0; j < n; ++j) alumn[j] = m[alumn[j]];
            
            cout << LIS_len(alumn) << "\n";
            
        }
    
    }


    return 0;
}