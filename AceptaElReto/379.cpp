#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, i, flag;
	string s;
	while (cin >> n) {
		if (!n) {
			return 0;
		}
		int v[n];
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		for(i=n-1;i>0;i--){
			if(v[i]==v[i-1]){
				break;
			}
		}
		flag=i;
		v[i]++;

		for(i+=2;i<n;i++){
			v[i]=v[flag];
		}
		cout<<v[0];
		for(i=1;i<n;i++){
			cout<<" "<<v[i];
		}
		cout<<endl;

	}
	return 0;
}

