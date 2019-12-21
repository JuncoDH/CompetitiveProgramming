#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main() {
	int n, cont, i, z;
	string s;
	cin>>n;
	for(z=0;z<n;z++){
		cin>>s;
		cont=0;
		for(i=0;i<s.length();i++){
			if(s[i]=='.'){
				cont++;
				i+=2;
			}
		}
		cout<<cont<<endl;
	}
	return 0;
}
