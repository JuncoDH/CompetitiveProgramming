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
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
string s,r;
int i,j,arr[1002][1002];

int main() {
	ios_base::sync_with_stdio(false);

	while(getline(cin,s)){
	getline(cin,r);

	for(i=0;i<=r.length();++i){
		for(j=0;j<=s.length();++j){
			arr[i][j]=0;
		}
	}

	for(i=1;i<=r.length();++i){
		for(j=1;j<=s.length();++j){

			if(r[i-1]==s[j-1]){
				arr[i][j]=min(arr[i-1][j]+1,arr[i][j-1]+1);
			}
			else{
				arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
			}
		}
	}
	cout<<arr[r.length()][s.length()]<<"\n";
	}


	return 0;
}
