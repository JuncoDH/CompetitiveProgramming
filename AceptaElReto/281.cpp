#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <utility>
#include <string.h>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

#define MAX 202
long int ady[MAX][MAX];



int main() {
	ios_base::sync_with_stdio(false);
	int i,j,k,n;



	while(cin>>n){
		for(i=0;i<n;++i){
			for(j=i+1;j<n;++j){
				cin>>ady[i][j];
			}
		}

		for(k=0;k<n;++k){
			for(i=0;i<k;++i){
				for(j=k+1;j<n;++j){
					ady[i][j]=min(ady[i][j],ady[min(k,j)][max(k,j)]+ady[min(i,k)][max(i,k)]);

				}
			}

		}

		//mostrar
		for(i=0;i<n;++i){
				if(i+1<n){
					cout<<ady[i][i+1];
				}
				for(j=i+2;j<n;++j){
					cout<<" "<<ady[i][j];
				}
				if(i!=n-1){
					cout<<"\n";
				}
			}

	}

	return 0;
}
