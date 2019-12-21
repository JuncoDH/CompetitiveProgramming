#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int casos, z, i, n, temp, cont;
	cin>>casos;
	for(z=0;z<casos;z++){
		cin>>n;
		cont=0;
		for(i=0;i<n;i++){
			cin>>temp;

			if(!(temp%2)){
				cont++;
			}
		}
		cout<<cont<<endl;
	}

	return 0;
}
