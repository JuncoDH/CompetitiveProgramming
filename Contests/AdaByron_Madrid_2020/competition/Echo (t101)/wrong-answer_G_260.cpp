/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: desarrollador134
 *
 * Created on 29 de febrero de 2020, 9:31
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
int main(int argc, char** argv) {
    ll n, tt;
    string s;
    cin >> n;
    tt = n;
    while(tt--) {
        cin >> s;
    }
    
    if(s.length() >= 1 && s.back() == '#') {
        if(n%2 == 0) {
            cout << "0-1\n";
            return 0;
        } 
        cout << "1-0\n";
        return 0;
    }
    ll k = s.length();
    if(s.length() >= 2 && s[k-1] == '+' && s[k-2] == '+') {
        if(n%2 == 0) {
            cout << "0-1\n";
            return 0;
        } 
        cout << "1-0\n";
    }
    
    cout << "1/2-1/2\n";
    
    return 0;
}

