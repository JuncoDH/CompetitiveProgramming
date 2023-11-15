#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


string original[3], s[3];
vi nxtL[3][255];
int s_len;
char no0[3], ope, eq;
bool disponible[10];
bool flag;

void show(){
    cout << s[0] << endl << s[1] << endl << s[2] << endl << "-------" << endl;
}


void setL(char l, int num){
    int i, j;
    disponible[num] = false;
    for(i = 0; i <= 2; ++i){
        for(j = 0; j < nxtL[i][(int)l].size(); ++j){
            s[i][nxtL[i][(int)l][j]] = num + '0';
        }
    }
}

void unsetL(char l, int num){
    int i, j;
    disponible[num] = true;
    for(i = 0; i <= 2; ++i){
        for(j = 0; j < nxtL[i][(int)l].size(); ++j){
            s[i][nxtL[i][(int)l][j]] = original[i][nxtL[i][(int)l][j]];
        }
    }
}

bool valid(char letra, int num){
    if(num == 0 && (letra == no0[0] || letra == no0[1] || letra == no0[2])) return false;
    return disponible[num];
}

bool check(int col){
    ll i, num[3], cifras = s_len - col;

    for(i = 0; i <= 2; ++i) 
        num[i] = stoll(s[i].substr(col));
    
    string ans;
    if(ope == '*') ans = to_string(num[0] * num[1]);
    else ans = to_string(num[0] + num[1]);


    if((int)ans.size() - cifras >= 0 ) ans = ans.substr(ans.size() - cifras);
    if(stoll(ans) == num[2]) return true;
    return false;
}

int nxt(int col){
    ll i, num[2], cifras = s_len - col;

    for(i = 0; i <= 1; ++i)
        num[i] = stoll(s[i].substr(col));
    
    string ans;
    if(ope == '*') ans = to_string(num[0] * num[1]);
    else ans = to_string(num[0] + num[1]);
    
    if((int)ans.size() - cifras < 0  ) return 0;
    
    ans = ans.substr(ans.size() - cifras);

    return ans[0] - '0';
}

void finalCheck(){
    ll num[3];
    
    for(int i = 0; i <= 2; ++i){
        num[i] = stoll(s[i]);
    }
    
    if(ope == '*' && num[0] * num[1] == num[2]) {
        cout << num[0] << " * " << num[1] << " = " << num[2] << "\n";
        flag = true;
    }
    if(ope == '+' && num[0] + num[1] == num[2]) {
        cout << num[0] << " + " << num[1] << " = " << num[2] << "\n";
        flag = true;
    }
    
}

void DFS(ll col){
    int i, dep;
    
    if(flag == true) return;
    
    if(col == -1){
        finalCheck();
        return;
    }
    
    //set numbers in s0 and s1
    for(dep = 0; dep <= 1; ++dep){
        if(isdigit(s[dep][col]) == false){
            for(i = 0; i < 10; ++i){
                if(valid(s[dep][col], i)){
                    setL(original[dep][col], i);
                    DFS(col);
                    unsetL(original[dep][col], i);
                }
            }
            return;
        }
    }

    dep = 2;
    
    //case s2 has the number set
    if(isdigit(s[dep][col])){
        if(check(col) == true) DFS(col - 1);

        return;
    }
    
    //nxt(col) is what s2[col] has to be
    i = nxt(col);
    
    if(valid(s[dep][col], i)){
        setL(original[dep][col], i);
        DFS(col - 1);
        unsetL(original[dep][col], i);
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    
    int i, j;
    bool cero;

    while(cin >> original[0]){
        cin >> ope >> original[1] >> eq >> original[2];
        
        for(auto &el : disponible) el = true;
        
        for(i = 0; i <= 2; ++i){
            for(j = (int)'a'; j <=(int)'z'; ++j){
                nxtL[i][j].clear();
            } 
        }
        flag = false;

        for(i = 0; i <= 2; ++i){
            no0[i] = original[i][0];
            if(original[i].length() == 1) no0[i] = '-';//case 0
            s[i] = original[i];
        }
        
        s_len = s[2].length();
        while(s[0].length() < s_len) {s[0] = "0" + s[0]; original[0] = "0" + original[0];}
        while(s[1].length() < s_len){ s[1] = "0" + s[1]; original[1] = "0" + original[1];}
        
        //nxtL[i][j] will have all the indexes of s[i] whose char is j
        for(i = 0; i <= 2; ++i){
            cero = false;
            for(j = 0;  j < s_len; ++j){
                cero |= s[i][j] != '0';
                if(cero == true) nxtL[i][(int)s[i][j]].pb(j);
            }
        }        
        
        DFS(s_len - 1);

    }

    return 0;
}