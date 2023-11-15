/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: desarrollador134
 *
 * Created on 29 de febrero de 2020, 10:20
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

double arr[1048600];
double presum[1048600];
double ddd;

int main(int argc, char** argv) {
    int t;
    cin>>t;
    while(t--){
        ll n;
        double d;
        cin>>n>>d;
        double tm;
        presum[0]=0;
        double ma=50000;
        double sum=0;
        for(int i=0;i<n;++i){
            cin>>arr[i];
            sum+=arr[i];
            ma=min(ma,arr[i]);
        }
        printf("%.2lf\n",(sum-ma)*(1-d/100)+ma);
        continue;
        
    }
    
    return 0;
}

