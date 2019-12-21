#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define show(x) cout<<":"<<x<<endl

int main() {
	int i, n;

	while (1) {
		cin >> n;
		if(!n){
			return 0;
		}
		vi v(n);
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		if(n%2==0){
			cout<<v[n/2]+v[n/2 - 1]<<endl;
		}
		else{
			cout<<2*v[n/2]<<endl;
		}
	}

	return 0;
}
