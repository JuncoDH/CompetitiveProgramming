/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: e399706
 *
 * Created on 21 de febrero de 2019, 18:03
 */

#include <iostream>
#include<cmath>

using namespace std;
typedef long long ll;
/*
 * 
 */
int main(int argc, char** argv) {
    ll suma,num;
    ll length;
    while(cin>>num&&num){
        length=log10(num);
        suma=0;
        while(num>0){
            suma+=num;
            num%= (ll)pow(10,length);
            length--;
        }
        cout<<suma<<"\n";
    }
    return 0;
}
