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
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

#define MAX 20
char arr[MAX][MAX];
long DP[MAX][MAX][MAX][MAX];
int N,M;

void clean(){
	int i,j,k,l;
	for(i=0;i<N;++i){
		for(j=0;j<M;++j){
			for(k=0;k<N;++k){
				for(l=0;l<M;++l){
					DP[i][j][k][l]=0;
				}
			}
		}
	}
}

long crop(int i, int j, int x, int y){
	if(DP[i][j][x][y]){
		return DP[i][j][x][y];
	}
	int i2,j2,flag=1;
	long m=LONG_MAX;

	char car=arr[i][j];
	for(i2=i;i2<=x;++i2){
		for(j2=j;j2<=y;++j2){
			if(arr[i2][j2]!=car){
				flag=0;
				i2=x+1;//salir
				break;
			}
		}
	}
	if(flag){
		return DP[i][j][x][y]=0;//no necesita cortes el bloque
	}

	for(i2=i;i2<x;++i2){
		m=min(m,crop(i,j,i2,y)+crop(i2+1,j,x,y)+1);
	}
	for(j2=j;j2<y;++j2){
		m=min(m,crop(i,j,x,j2)+crop(i,j2+1,x,y)+1);
	}

	return DP[i][j][x][y]=m;

}

int main() {
	ios_base::sync_with_stdio(false);
	int i,j;

	while(cin>>N){
		cin>>M;
		clean();

		for(i=0;i<N;++i){
			for(j=0;j<M;++j){
				cin>>arr[i][j];

			}
		}
		cout<<crop(0,0,N-1,M-1)<<"\n";

	}

	return 0;
}
