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

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

#define NUM 22364//95345
long long int triangulares[NUM];

int main() {
	ios_base::sync_with_stdio(false);
	int z,casos,i;
	string s, s1, s2;

	cin>>casos;
	for(z=casos;z;--z){
		cin>>s1>>s>>s2;
		for(i=0;i<s1.length();++i){
			s1[i]=tolower(s1[i]);
		}
		for(i=0;i<s2.length();++i){
					s2[i]=tolower(s2[i]);
				}
		if(s1==s2){
			cout<<"TAUTOLOGIA\n";
		}
		else{
			cout<<"NO TAUTOLOGIA\n";
		}
	}

	return 0;
}
