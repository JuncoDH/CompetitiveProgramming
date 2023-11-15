#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int clave[12],v[250005];

int main() {
    int r,n,i,j,iaux,posclave,flag,m;
    
    while(cin>>r){
        cin>>n;
        for(i=0;i<r;++i){
            cin>>clave[i];
        }
        for(i=0;i<n;++i){
            cin>>v[i];
        }
        
        m=INT_MAX;
        
        for(iaux=0;iaux<n;++iaux){
            if(v[iaux]!=clave[0])continue;
            posclave=1;
            flag=0;
            for(j=iaux+1;j<n;++j){
                if(posclave==1&&v[j]==clave[0]){iaux=j-1;flag=1;break;}
                
                if(v[j]==clave[posclave]){++posclave;if(posclave==r){m=min(m,j-iaux+1);flag=1;}}
                
            }
            
            if(!flag)break;
            
        }
        
        cout<<m<<"\n";
        
        
        
        
        
    }
    
    
    
    
    return 0;
}
