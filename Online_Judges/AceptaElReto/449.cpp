#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define MAX 82
string s;
int DP[MAX][MAX];

int f(int i, int j){
    int x, y,temp1,temp2;
    
    if(i==j)return 1;
    if(i>j)return 0;
    
    if(DP[i][j]){
        return DP[i][j];
    }
    
    x=i+1;
    y=j;
    while(x<s.length()&&s[x]==s[i])++x;//izq
    while(y>=0&&s[y]==s[i])--y;
    temp1=f(x,y);
    
    x=i;
    y=j-1;
    while(x<s.length()&&s[x]==s[j])++x;//der
    while(y>=0&&s[y]==s[j])--y;
    temp2=f(x,y);
    
            
            
    return DP[i][j]=min(temp1, temp2)+1;
}

int main(void) {
    int i, j;
    
    while(cin>>s){
        
        for(i=0;i<s.length();++i){
            for(j=i;j<s.length();++j){
                DP[i][j]=0;
            }
        }
        
        cout<<f(0,s.length()-1)<<"\n";
    }
    
    return 0;
}
