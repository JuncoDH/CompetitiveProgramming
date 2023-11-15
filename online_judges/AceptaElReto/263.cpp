/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: e399706
 *
 * Created on 21 de febrero de 2019, 18:16
 */

#include <iostream>

using namespace std;

char cube [52][52];
int dim;
void shift_right(int row){
    char prev=cube[row][0];
    char buff=cube[row][0];
    for(int i=1;i<dim;++i){
        buff=cube[row][i];
        cube[row][i]=prev;
        prev=buff;
    }
    cube[row][0]=buff;
}

void shift_left(int row){
    char prev=cube[row][dim-1];
    char buff=cube[row][dim-1];
    for(int i=dim-1;i>=0;--i){
        buff=cube[row][i];
        cube[row][i]=prev;
        prev=buff;
    }
    cube[row][dim-1]=buff;
}

void shift_up(int col){
    char prev=cube[dim-1][col];
    char buff=cube[dim-1][col];
    for(int i=dim-1;i>=0;--i){
        buff=cube[i][col];
        cube[i][col]=prev;
        prev=buff;
    }
    cube[dim-1][col]=buff;
}
void shift_down(int col){
    char prev=cube[0][col];
    char buff=cube[0][col];
    for(int i=0;i<dim;++i){
        buff=cube[i][col];
        cube[i][col]=prev;
        prev=buff;
    }
    cube[0][col]=buff;
}

int main(int argc, char** argv) {
    int i,j;
    char c;
    int n;
    while(cin>>dim&&dim){
        for(i=0;i<dim;++i){
            for(j=0;j<dim;++j){
                cin>>cube[i][j];
            }
        }
        while(cin>>c&&c!='x'){
            cin>>n;
            if(c=='c'){
                if(n>0) shift_down(n-1);
                else if(n<0) shift_up(-n-1);
            }
            else{
                if(n>0) shift_right(n-1);
                else if(n<0) shift_left(-n-1);
            }
        }
        
        for(i=0;i<dim;++i){
            cout<<cube[i][0];
            for(j=1;j<dim;++j){
                cout<<cube[i][j];
            }
            cout<<"\n";
        }
        cout<<"---\n";
        
    }
    
    return 0;
}
