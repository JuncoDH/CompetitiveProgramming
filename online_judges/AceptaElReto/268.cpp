#include <cstdlib>
#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX 30
int p, c, i, j;
double coronas[MAX], platos[MAX];
string s,resultado;
priority_queue<pair<double, string>> pq;

int main(void) {

    while(1){
        cin>>p>>c;
        pq=priority_queue<pair<double, string>> ();
        if(!p&&!c)return 0;
        
        for(i=0;i<p;++i){
            cin>>platos[i];
        }
        
        for(i=0;i<c;++i){
            cin>>coronas[i];
        }
        
        for(i=0;i<p;++i){
            for(j=0;j<c;++j){
                s=to_string((int)platos[i])+"-"+to_string((int)coronas[j]);
                pq.push(make_pair(-platos[i]/coronas[j],s));
            }
        }
        
        
        resultado="";
        while(!pq.empty()){
            resultado+=pq.top().second + " ";
            pq.pop();
        }
        cout<<resultado.substr(0,resultado.length()-1)<<"\n";
    }
    
    return 0;
}
