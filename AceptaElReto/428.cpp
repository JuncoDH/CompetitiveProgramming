#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<x<<endl
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

//Convierte de string s con base base a int base 10
int to10(string s, int base) {
	int coef = 1, num, i, suma = 0;
	for (i = s.length() - 1; i >= 0; i--) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			num = s[i] - 'a' + 10;
		} else {
			num = s[i] - '0';
		}
		suma += num * coef;
		coef *= base;
	}

	return suma;
}

//Convierte de entero base 10 a string de la base B
string toB(int num, int B) {
	string s = "", abc[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
			"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W",
			"X", "Y", "Z" };
	int n;
	if(!num){
		return "0";
	}
	while (num) {
		n = num % B;
		if (n < 10) {
			s = to_string(n) + s;
		} else {

			s = abc[n - 10] + s;
		}
		num /= B;
	}
	return s;
}

int main() {
	int n, z, num,cont, j;
	string s;
	cin>>n;
	for(z=0;z<n;z++){
		cin>>num;
		s=toB(num,5);
		cont=0;
		for(j=0;j<s.length();j++){
			if(s[j]=='4'){
				cont++;
			}
			if(cont==2){
				break;
			}
		}
		if(cont>=2){
			cout<<"SI\n";
		}
		else{
			cout<<"NO\n";
		}

	}
	return 0;
}

