#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <utility>
#include <set>

using namespace std;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;


int main() {
	ios_base::sync_with_stdio(false);
	int s, d, n1, n2, temp1, temp2, dias, flag;
	while (cin>>d) {
		cin  >> s;
		temp1 = 0;
		temp2 = 0;
		dias = 1;
		flag = 0;
		while (1) {
			cin >>n1>> n2;

			if (!n1 && !n2) {
				break;
			}
			if (flag) {
				continue;
			}
			temp1 += abs(n1);
			if (n2 >= 0) {
				temp2 += n2;
			}
			if (n1 > d || n2 > s) {
				flag = 1;
			}
			if (temp1 > d || temp2 > s) {
				temp1 = n1;
				temp2 = max(0,n2);
				dias++;
			}
		}
		if (flag) {
			cout << "DESTITUIDO\n";
			continue;
		}
		cout << dias << endl;
	}
	return 0;
}
