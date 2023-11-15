#include <cstdlib>
#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;


string n,mitad, bajo, alto,aux;
long long m,z,casos, i, flag;



int main(void) {

    cin>>casos;
    for(z=0;z<casos;++z){
        cin>>n;
        if(n=="9"){
            cout<<"2\n";
            continue;
        }
        if(n.length()==1){
            cout<<"1\n";
            continue;
        }
        for(flag=1,i=0;i<n.length();++i){
            if(n[i]!='9'){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<"2\n";
            continue;
        }
        if(n.length()%2==0){
            mitad=n.substr(0,n.length()/2);
            aux=mitad;
            reverse(aux.begin(), aux.end());
            bajo=mitad+aux;
            mitad=to_string(stoll(mitad)+1);
            aux=mitad;
            reverse(aux.begin(), aux.end());
            alto=mitad+aux;
        }else{
            mitad=n.substr(0,n.length()/2+1);
            aux=mitad;
            reverse(aux.begin(), aux.end());
            bajo=mitad+aux.substr(1, aux.length()-1);
            mitad=to_string(stoll(mitad)+1);
            aux=mitad;
            reverse(aux.begin(), aux.end());
            alto=mitad+aux.substr(1, aux.length()-1);

        }
        //<<bajo<<" "<<alto<<endl;
        if(stoll(bajo)>stoll(n) && bajo!=n)cout<<stoll(bajo)-stoll(n)<<"\n";
        else cout<<stoll(alto)-stoll(n)<<"\n";
        //cout<<bajo<<" "<<alto<<endl;
    }
    
    return 0;
}
