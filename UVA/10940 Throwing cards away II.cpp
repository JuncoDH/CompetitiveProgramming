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

queue<int> prueba;
ll n, i,z;
ll dos[20];

void mostrarPatron(){
	for(n=1;n<200;++n){

	    	prueba=queue<int>();
	    	for(i=1;i<=n;++i){
	    		prueba.push(i);
	    	}

	    	while(prueba.size()!=1){
	    		prueba.pop();
	    		prueba.push(prueba.front());
	    		prueba.pop();
	    	}

	    	cout<<n<<": "<<prueba.front()<<endl;

	    }
}

void rellena(){
	ll temp=1;
	dos[0]=1;
	for(i=1;i<19;++i){
		temp*=2;
		dos[i]=temp;
	}
}

int main(){
    ios::sync_with_stdio(false);
    rellena();


    //mostrarPatron();

    while(1){
    	cin>>n;
    	if(!n)return 0;
    	if(dos[(ll)floor(log2(n))]==n)cout<<n<<"\n";
    	else cout<<(n-dos[(ll)floor(log2(n))])*2<<"\n";
    }


    return 0;
}
