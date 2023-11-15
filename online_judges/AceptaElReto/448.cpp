#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int n,i,j,cont,iguales,temp;
    
    while(1){
        cin>>n;
        if(!n){
            return 0;
        }
        vector<int> v1(n);
        
        for(i=0;i<n;++i){
            cin>>v1[i];
        }
        sort(v1.begin(),v1.end());
        
        cont=0;
        iguales=0;
        for(i=0;i<n;++i){
            cin>>temp;
            
            vector<int>::iterator it=lower_bound(v1.begin(),v1.end(),temp);
            cont+=it-v1.begin();
            while(it!=v1.end()&&*it==temp){++iguales;++it;}

  
        }   
        
        if(n*n-iguales-cont>cont)cout<<"PRIMERO\n";
        else if(n*n-iguales-cont==cont)cout<<"NO HAY DIFERENCIA\n";
        else cout<<"SEGUNDO\n";
        
    }
    

    return 0;
}
