#include <bits/stdc++.h>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool flag = false;
vi r(5);
set<pii> sdos;
set<pair<int, pii> > stres;
set<pair<pii, pii> > scuatro;
int l;


void dos(int num1, int num2){
    if(flag == true) return;
    if(num1 == l || num2 == l) {flag = true; return;}
    
    if(sdos.find(mp(num1, num2)) != sdos.end()) return;
    sdos.insert(mp(num1, num2));
    
    dos(0, num2);
    dos(num1, 0);
    
    dos(r[0], num2);
    dos(num1, r[1]);
    
    if(num1 > 0){
        if(num1 + num2 >= r[1]) dos(num1 - (r[1] - num2), r[1]);
        else dos(0, num1 + num2);
    }
    if(num2 > 0){
        if(num2 + num1 >= r[0]) dos(r[0], num2 - (r[0] - num1));
        else dos(num1 + num2, 0);
    }
}

void tres(int num1, int num2, int num3){
    if(flag == true) return;
    if(num1 == l || num2 == l || num3 == l) {flag = true; return;}
    
    if(stres.find(mp(num1, mp(num2, num3))) != stres.end()) return;
    stres.insert(mp(num1, mp(num2, num3)));
    
    tres(0, num2, num3);
    tres(num1, 0, num3);
    tres(num1, num2, 0);
    
    tres(r[0], num2, num3);
    tres(num1, r[1], num3);
    tres(num1, num2, r[2]);
    
    if(num1 > 0){
        if(num1 + num2 >= r[1]) tres(num1 - (r[1] - num2), r[1], num3);
        else tres(0, num1 + num2, num3);
        
        if(num1 + num3 >= r[2]) tres(num1 - (r[2] - num3), num2, r[2]);
        else tres(0, num2, num1 + num3);
    }
    
    if(num2 > 0){
        if(num2 + num1 >= r[0]) tres(r[0], num2 - (r[0] - num1), num3);
        else tres(num1 + num2, 0, num3);
        
        if(num2 + num3 >= r[2]) tres(num1, num2 - (r[2] - num3), r[2]);
        else tres(num1, 0, num2 + num3);
    }
    
    if(num3 > 0){
        if(num3 + num1 >= r[0]) tres(r[0], num2, num3 - (r[0] - num1));
        else tres(num1 + num3, num2, 0);
        
        if(num3 + num2 >= r[1]) tres(num1, r[1], num3 - (r[1] - num2));
        else tres(num1, num2 + num3, 0);
    }
    
}

void cuatro(int num1, int num2, int num3, int num4){
    if(flag == true) return;
    if(num1 == l || num2 == l || num3 == l || num4 == l) {flag = true; return;}
    
    if(scuatro.find(mp(mp(num1, num2), mp(num3, num4))) != scuatro.end()) return;
    scuatro.insert(mp(mp(num1, num2), mp(num3, num4)));
    
    cuatro(0, num2, num3, num4);
    cuatro(num1, 0, num3, num4);
    cuatro(num1, num2, 0, num4);
    cuatro(num1, num2, num3, 0);
    
    cuatro(r[0], num2, num3, num4);
    cuatro(num1, r[1], num3, num4);
    cuatro(num1, num2, r[2], num4);
    cuatro(num1, num2, num3, r[3]);
    
    if(num1 > 0){
        if(num1 + num2 >= r[1]) cuatro(num1 - (r[1] - num2), r[1], num3, num4);
        else cuatro(0, num1 + num2, num3, num4);
        
        if(num1 + num3 >= r[2]) cuatro(num1 - (r[2] - num3), num2, r[2], num4);
        else cuatro(0, num2, num1 + num3, num4);
        
        if(num1 + num4 >= r[3]) cuatro(num1 - (r[3] - num4), num2, num3, r[3]);
        else cuatro(0, num2, num3, num1 + num4);
    }
    
    if(num2 > 0){
        if(num2 + num1 >= r[0]) cuatro(r[0], num2 - (r[0] - num1), num3, num4);
        else  cuatro(num1 + num2, 0, num3, num4);
        
        if(num2 + num3 >= r[2]) cuatro(num1, num2 - (r[2] - num3), r[2], num4);
        else cuatro(num1, 0, num2 + num3, num4);
        
        if(num2 + num4 >= r[3]) cuatro(num1, num2 - (r[3] - num4), num3, r[3]);
        else cuatro(num1, 0, num3, num2 + num4);
    }
    
    if(num3 > 0){
        if(num3 + num1 >= r[0]) cuatro(r[0], num2, num3 - (r[0] - num1), num4);
        else cuatro(num1 + num3, num2, 0, num4);
        
        if(num3 + num2 >= r[1]) cuatro(num1, r[1], num3 - (r[1] - num2), num4);
        else cuatro(num1, num2 + num3, 0, num4);
        
        if(num3 + num4 >= r[3]) cuatro(num1, num2, num3 - (r[3] - num4), r[3]);
        else cuatro(num1, num2, 0, num3 + num4);
    }
    
    if(num4 > 0){ 
        if(num4 + num1 >= r[0]) cuatro(r[0], num2, num3, num4 - (r[0] - num1));
        else cuatro(num1 + num4, num2, num3, 0);
        
        if(num4 + num2 >= r[1]) cuatro(num1, r[1], num3, num4 - (r[1] - num2));
        else cuatro(num1, num2 + num4, num3, 0);
        
        if(num4 + num3 >= r[2]) cuatro(num1, num2, r[2], num4 - (r[2] - num3));
        else cuatro(num1, num2, num3 + num4, 0);
        
    }
    
}


int main(){
    ios::sync_with_stdio(false);
   int n, i;
   
   l = 2;
   r[0]=4;r[1]=5;

   
   while(1){
       cin >> l;
       if(l == 0) return 0;
       cin >> n;
       for(i = 0; i < n; ++i) cin >> r[i];
       
       flag = false;
       
       if(n == 1){
         if(r[0] == l ) flag = true;  
        }
       else if(n == 2){
           sdos = set<pii>();
           dos(0, 0);
       }
       else if(n == 3){
           stres = set<pair<int, pii> > ();
           tres(0, 0, 0);
       } else{
           scuatro = set<pair<pii, pii> > ();
           cuatro(0, 0, 0, 0);
       }

       
       if(flag == true) cout << "SI\n";
       else cout << "NO\n";
       
   }
   
    return 0;
}