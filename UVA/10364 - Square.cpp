#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))


typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


vi square, v(30);
vector<bool> used(30);
bool flag;
ll sum, n;
/* //This function is correct but TLE. It select one of the four position for every element in the array
void back(int id, int last_pos) {
    if(id == -1) {
        if(square[0] == sum && square[0] == square[1] && square[2] == square[3] && square[0] == square[2]) flag = true;
    }
    if(flag == true || id < 0) return;
    int i = 0;
    if(v[id] == v[id + 1]) i = last_pos;
    for(; i < 4; ++i) {
        if(square[i] + v[id] <= sum && (i == 0 || square[i] != square[i - 1])) {
            square[i] += v[id];
            back(id - 1, i);
            square[i] -= v[id];
        }
    }
}*/

//This function AC, first complete the first side of the square, next the second one etc.
void back2(int id, int pos) {
    //cout << id << " " << pos << " "<< square;

    if(flag) return;
    
    if(pos == 4) {
        if(square[0] == sum && square[0] == square[1] && square[2] == square[3] && square[0] == square[2]) flag = true;
    }
    
    if(square[pos] == sum) {back2(n - 1, pos + 1); return;}
    if(id < 0) return;
    
    int i;
    for(i = id; i >= 0; --i) {
        if(used[i] == false && square[pos] + v[i] <= sum) {
            used[i] = true;
            square[pos] += v[i];
            back2(i - 1, pos);
            used[i] = false;
            square[pos] -= v[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    ll i, t = 1;
    
    cin >> t;
    while(t--){
        cin >> n;
        for(i = 0; i < n; ++i) {cin >> v[i]; used[i] = false;}
        
        square.assign(4, 0);
        flag = false;
        sort(v.begin(), v.begin() + n);

        sum = 0;
        
        for(i = 0; i < n; ++i) sum += v[i];
        if(sum % 4 == 0) {
            sum /= 4;
            used[n - 1] = true;
            square[0] = v[n - 1];
            back2(n - 2, 0);
        }
        if(flag) cout << "yes\n";
        else cout << "no\n";
    }


    return 0;
}


