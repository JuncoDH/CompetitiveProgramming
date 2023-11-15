#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <cmath>
#include <map>

using namespace std;

int main() {
	int n, i, t, M, imax;

	while (1) {
		map<int, int> m;
		cin>>n;
		if (!n) {
			return 0;
		}
		M=0;
		for(i=0;i<n;++i){
			cin>>t;
			if(m.find(t)==m.end()){
				m[t]=0;
			}
			m[t]++;

			if(m[t]>M){
				M=m[t];
				imax=t;
			}
		}
		cout<<imax<<endl;

	}
	return 0;
}
