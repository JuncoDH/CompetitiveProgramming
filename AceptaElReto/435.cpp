#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
string s;
int i, flag;
while(cin>>s){
	vector<int> v(10);

	for(i=0;s[i]!=0;i++){
		v[s[i]-'0']++;
	}
	flag=0;
	for(i=1;i<10;i++){
		if(v[i]!=v[i-1]){
			cout<<"no subnormal\n";
			flag=1;
			break;
		}

	}
	if(!flag){
		cout<<"subnormal\n";
	}


}
	return 0;
}