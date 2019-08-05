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
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x)<<endl

int arr[500050]; //RESIZE

int main() {
	ios_base::sync_with_stdio(false);
	long long int n,k,viejo, nuevo, i, sum, M;

	while(cin>>n){
		cin>>k;
		--k;
		cin>>viejo;
		for(i=1;i<n;++i){
			cin>>nuevo;
			arr[i-1]=nuevo-viejo;
			viejo=nuevo;
		}
		sum=0;
		for(i=0;i<k;++i){
			sum+=arr[i];
		}
		M=sum;
		for(;i<n-1;++i){
			sum+=arr[i];
			sum-=arr[i-k];
			M=max(M, sum);
		}

		for(i=0;i<n-1;++i){
			arr[i]=-arr[i];
		}

		sum=0;
		for(i=0;i<k;++i){
			sum+=arr[i];
		}
		M=max(M, sum);
		for(;i<n-1;++i){
			sum+=arr[i];
			sum-=arr[i-k];
			M=max(M, sum);
		}



		cout<<M<<"\n";

	}

	return 0;
}