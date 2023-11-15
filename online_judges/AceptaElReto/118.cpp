#include <bits/stdc++.h>

using namespace std;


inline double dist(int n1, double n2){
    return abs(n1 - n2);
}

int main(){
    ios::sync_with_stdio(false);

    int pedro, j, k, possum, misum, ans;
    double media, pastmedia, media_ans;
    bool valid, siempre;
    

    while(1){
    
        //INPUT: X Y PEDRO, X <= Y

       
       cin >> j >> k >> pedro;
       if(j < 0 || k < 0  || pedro < 0) return 0;
       
       if(k < j) swap(k, j);
       
       if(j == pedro && k == pedro) {cout << "0\n"; continue;}
       if(j < pedro && pedro < k) {cout << "0\n"; continue;}
        
        //-----------------------------------------------------------------
        media_ans = (pedro + j + k)/3.0;
        ans = -1;
        pastmedia = 9999; //INFINITO
        siempre = true;

        for(misum = 0; misum <= 64; ++misum){
            valid = true;
            for(possum = 0; possum <= 64 + 64; ++possum){
                media = (misum + possum) / 3.0;
                if(dist(pedro, media) >= dist(j, media) && dist(pedro, media) >= dist(k, media)) {valid = false; break;} //no valido
            }//comprobar el =.

            if(valid == false) {siempre = false; continue; }
            
            if(dist(misum, media_ans) < pastmedia){
                pastmedia = dist(misum, media_ans);
                ans = misum;
            }
        }
        
        if(siempre == true) cout << "0\n";
        else if(ans == -1) cout << "I\n";
        else cout << ans << "\n";
        
    }


    return 0;
}