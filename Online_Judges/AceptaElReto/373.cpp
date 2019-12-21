#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	long long int n, z, cubo;

	cin >> n;
	for (z = 0; z < n; z++) {
		cin>>cubo;

		cout<<(cubo*cubo*2+(cubo-2)*cubo*2+(cubo-2)*(cubo-2)*2)<<endl;
	}
	return 0;
}

