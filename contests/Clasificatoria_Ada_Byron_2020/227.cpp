#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back


typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

char board[5][5];
int ipos,jpos;

bool move(char c){
    switch(c){

        case 'A':{
            if(ipos==0)return false;
            swap(board[ipos][jpos],board[ipos-1][jpos]);
            ipos--;
            break;
        }
        case 'B':{
            if(ipos==4)return false;
            swap(board[ipos][jpos],board[ipos+1][jpos]);
            ipos++;
            break;
        }
        case 'L':{
            if(jpos==0)return false;
            swap(board[ipos][jpos],board[ipos][jpos-1]);
            jpos--;
            break;
        }
        case 'R':{
            if(jpos==4)return false;
            swap(board[ipos][jpos],board[ipos][jpos+1]);
            jpos++;
            break;
        }


    }
    return true;
}

int main(){
    int pnum=1;
    while(true){
        for(int i=0;i<5;++i){
            string ss;
            getline(cin,ss);
            //cout<<ss<<" "<<ss.length()<<"\n";
            if(ss.length()==1&&ss[0]=='Z')return 0;
            for(int j=0;j<5;++j){
                board[i][j]=ss[j];
                if(ss[j]==' '){
                    ipos=i;
                    jpos=j;
                }
            }

        }
        bool managed=true;
        string s;
        while(true){
            getline(cin,s);
            bool f=true;
            for(char c:s){
                if(c=='0'){
                    f=false;
                    break;
                }
                managed=managed && move(c);
            }
            if(!f)break;
            
        }
        if(pnum!=1)cout<<"\n";
        cout<<"Puzzle #"<<pnum<<":\n";
        pnum++;
        if(!managed){
            cout<<"This puzzle has no final configuration.\n";
        }
        else{
            for(int i=0;i<5;++i){
                for(int j=0;j<5;++j){
                    if(j)cout<<" ";
                    cout<<board[i][j];
                }
                cout<<"\n";
            }
        }




    }


    return 0;
}