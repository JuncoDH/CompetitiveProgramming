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
	int i, j, n, cont;

	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		vi v(n+1);
		for(i=2;i<=n;i++){
			cont=0;
			for(j=1;j<=n;j++){
				if(v[j]==0){
					cont++;
				}
				if(cont>=i){
					break;
				}
			}
			if(cont<i){
				break;
			}
			cont=0;
			for(j=1;j<=n;j++){
				if(v[j]==0){
					if(cont%i==0){
						v[j]=1;
					}
					cont++;
				}
			}
		}

		cout<<n<<":";
		for(i=n;i>=1;i--){
			if(v[i]==0){
				cout<<" "<<i;
			}
		}
		cout<<endl;

	}

	return 0;
}
