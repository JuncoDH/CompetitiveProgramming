#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define pb push_back
#define fi first
#define se second
using namespace std;

using vi = vector<int>;
using ll = unsigned long long;
using pi = pair<int,int>;

const int lim = 31;

int n,p,m;
int adyMat[lim][lim];
int iinf = INT_MAX/10;
int picked[5]={-1,-1,-1,-1,-1};
int minval= iinf;

void evaluate(){
    int ma=0;
    for(int i=0;i<n;++i){
        int mi=iinf;
        for(int j=0;j<p;++j){
            mi =min(mi,adyMat[i][picked[j]]);
        }
        ma=max(ma,mi);
    }
    minval=min(minval,ma);
}


void choose(int index, int alredpick){

    if(alredpick==p){
        evaluate();
        return;
    }
    if(index==n){
        return;
    }
    picked[alredpick]=index;
    choose(index+1,alredpick+1);
    picked[alredpick]=-1;
    choose(index+1, alredpick);
}
int main(){
    cin>>n>>p>>m;
    for(int i=0;i<lim;++i){
        for(int j=0;j<lim;++j){
            adyMat[i][j] = iinf;
            if(i==j){
                adyMat[i][j]=0;
            }
        }
    }
    int a,b,c;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        adyMat[a][b]= min(adyMat[a][b],c);
        adyMat[b][a] = min(adyMat[b][a],c);
    }
    for (int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                adyMat[i][j] = min(adyMat[i][j], adyMat[i][k] + adyMat[k][j]);
            }
        }
    }
    choose(0,0);
    cout<<minval<<"\n";


    return 0;
}