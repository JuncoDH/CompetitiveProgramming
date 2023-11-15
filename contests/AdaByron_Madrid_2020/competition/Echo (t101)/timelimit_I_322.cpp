/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: desarrollador134
 *
 * Created on 29 de febrero de 2020, 9:42
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

/*
 * 
 */
int main(int argc, char** argv) {
    int n,m;
    string ssss;
    getline(cin,ssss);
    stringstream sst(ssss);
    sst>>n>>m;
    set<string> se;
    map<string,int> ma;
    for(int i=0;i<n;++i){
        string s;
        getline(cin,s);
        se.insert(s);
        ma[s]=0;
    }
    
    for(int i=0;i<m;++i){
        string s;
        getline(cin,s);
        ma[s]++;
    }
    bool all=true;
    bool rep=false;

    for(auto d:ma){
        if(d.second<1){
            all=false;
            break;
        }
        if(d.second>1)rep=true;
        
    }
    if(!all){
        cout<<"PONTE A TRABAJAR\n";
    }
    else{
        if(rep){
            cout<<"TRABAJAS DEMASIADO\n";
        }
        else{
            cout<<"PUEDES DESCANSAR\n";
        }
    }
    return 0;
}

