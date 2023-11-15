/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: desarrollador104
 *
 * Created on 28 de febrero de 2020, 19:16
 */

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ll tt, sum1, sum2, d1, m1, m2, a1, a2, d2, i;
    vector<ll> mes = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, m(12), a(5005);
    
    a[0] = 365;
    for(i = 1; i < 5005; i++) {
        a[i] = a[i-1] + 365;
        if(i% 4 == 0 && (i%100 != 0 || i%400 == 0)) a[i]++;
    }
    
    m[0] = mes[0];
    for(i = 1; i < 12; i++) {
        m[i] = m[i-1] + mes[i];
    }
    cin >> tt;
    while(tt--) {
        cin >> d1 >> m1 >> a1 >> d2 >> m2 >> a2;
        --m1; --m2;
        --m1; --m2;
        a1--; a2--;
        sum1 = d1;
        if(m1 >= 0) sum1 += m[m1];
        if(a1 >= 0) sum1 += a[a1];

        sum2 = d2;
        if(m2 >= 0) sum2 += m[m2];
        if(a2 >= 0) sum2 += a[a2];
        

        a1++; a2++;
        if(m1 >= 1 && a1% 4 == 0 && (a1%100 != 0 || a1%400 == 0)) {sum1++;}
        if(m2 >= 1 && a2% 4 == 0 && (a2%100 != 0 || a2%400 == 0)) {sum2++;}
        //cout << m[m1] << " " << m[m2] << " " << m1 << " " << m2 << " " << a2 << " " << m2>=1 << " " << a2%4 << ".. " << a2%100 << " " << a2%400 <<   endl;
        cout << sum2 - sum1 << "\n";
        
        
    }
    return 0;
}

