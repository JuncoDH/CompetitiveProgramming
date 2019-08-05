#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>

using namespace std;

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define echo(x) cout<<":"<<(x)<<endl;
#define first fi
#define second se


typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define MAX_N 2002
#define MAX_DIF 4000005

int i,j,N,M,temp, vn[MAX_N],pos,MM, Mvalor, tempValor;
vi dif(MAX_DIF);


int main(){
    ios::sync_with_stdio(false);

    while(cin>>N){
    	cin>>M;

    	for(i=0;i<N;++i){
    		cin>>vn[i];
    	}

    	pos=0;

    	for(i=0;i<M;++i){
    		cin>>temp;
    		for(j=0;j<N;++j){
    			if(vn[j]>temp)break;
    			dif[pos]=temp-vn[j];
    			++pos;
    		}
    	}

    	if(pos==0){
    		cout<<"0\n";
    		continue;
    	}

    	sort(dif.begin(), dif.begin()+pos);

    	MM=temp=1;
    	Mvalor=tempValor=dif[0];



    	for(i=1;i<pos;++i){
    		if(dif[i]==tempValor){
    			++temp;
    		}else{
    			if(temp>MM){
    				Mvalor=tempValor;
    				MM=temp;
    			}
    			tempValor=dif[i];
    			temp=1;
    		}
    	}
    	if(temp>MM&&i-1>=0){
    		Mvalor=dif[i-1];
    	}
    	cout<<Mvalor<<"\n";

    }


    return 0;
}
