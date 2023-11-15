/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: desarrollador104
 *
 * Created on 28 de febrero de 2020, 19:04
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int s;
    cin>>s;
    map<string,int> m;
    for(int i=0;i<s;++i){
        int n;
        cin>>n;
        for(int j=0;j<n;++j){
            string s;
            int a;
            cin>>s>>a;
            m[s]=a;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        if(m.count(s)){
            cout<<m[s]+1<<"\n";
        }
        else cout<<"?\n";
    }
    return 0;
}

