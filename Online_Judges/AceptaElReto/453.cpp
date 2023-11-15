#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int parents[10007];
int findParent(int i){
    if(i!=parents[i]){
        parents[i]=findParent(parents[i]);
    }
    return parents[i];
  
}
int main(void) {
    int nodes,edges;
    int a,b;
    int ip;
    bool all;
    while(cin>>nodes &&nodes){
        cin>>edges;
        for(int i=0;i<nodes;++i){
            parents[i]=i;
        }
        for(int i=0;i<edges;++i){
            cin>>a>>b;
            a--;
            b--;
            parents[b]=findParent(a);
        }
        ip=findParent(0);
        all=true;
        for(int i=1;i<nodes;++i){
            if(findParent(i)!=ip){
                all=false;
                break;
            }
        }
        if(all) cout<<"TODAS\n";
        else cout<<"FALTA ALGUNA\n";
    }
    return 0;
}
