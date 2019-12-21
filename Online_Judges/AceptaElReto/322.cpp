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
#include <time.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;

#define MAX 1003
string s,final;
int arr[MAX][MAX];

void lector(int i,int j){
	if(i>j){
		return;
	}
	if(arr[i][j]==1){
		final+=s[j];
		return;
	}
	if(s[i]==s[j]){
		final+=s[i];
		lector(i+1,j-1);
		return;
	}
	if(arr[i][j]==arr[i+1][j]){
		lector(i+1,j);
		return;
	}
	if(arr[i][j]==arr[i][j-1]){
		lector(i,j-1);
		return;
	}
	if(arr[i][j-1]>arr[i+1][j]){
		lector(i,j-1);
		return;
	}
	else{
		lector(i+1,j);
	}

}

int pal(int i, int j){
	if(i>j){
		return 0;
	}
	if(arr[i][j]){
		return arr[i][j];
	}
	if(i==j){
		return arr[i][j]=1;
	}
	if(s[i]==s[j]){
		return arr[i][j]= pal(i+1, j-1)+2;
	}
	return arr[i][j] = max(pal(i+1,j),pal(i,j-1));
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int i,j;

	while(cin>>s){

	for(i=0;i<=s.length();++i){
		for(j=0;j<=s.length();++j){
			arr[i][j]=0;
		}
	}


	pal(0,s.length()-1);
	//MOSTRAR TABLA DP
	/*for(i=0;i<s.length();++i){
		cout<<s[i]<<" ";
	}cout<<endl;
	for(i=0;i<s.length();++i){
		for(j=0;j<s.length();++j){
			cout<<arr[i][j]<<" ";
		}cout<<endl;
	}

*/
	final="";
	lector(0,s.length()-1);
	if(2*final.length()==arr[0][s.length()-1]){
		cout<<final;
		reverse(final.begin(), final.end());
		cout<<final<<"\n";
	}
	else{
		cout<<final;
		reverse(final.begin(), final.end()-1);
		cout<<final.substr(0,final.length()-1)<<"\n";
	}
	}
	return 0;
}

