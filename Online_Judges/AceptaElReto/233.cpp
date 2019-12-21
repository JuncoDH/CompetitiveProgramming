#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

typedef vector<int> vi;

#define show(x) cout<<":"<<x<<endl

#define MAX 1005



int main() {
	int n;
	string s;
	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		s="";
		while(n>9){
			s=s+"9";
			n-=9;
		}
		cout<<n<<s<<endl;


	}
	return 0;
}
