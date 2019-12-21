#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
long long int papel, edificio;
int cont=0;
while(cin>>papel){
	cin>>edificio;
	cout<<ceil(log2(edificio*pow(10, 6))-log2(papel))<<endl;

}

	return 0;
}