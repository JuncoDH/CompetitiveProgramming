//1-Binary Search 2-Priority Queue 


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

using namespace std;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int arr[100002], partituras, musicos, ciclos; //Resize

int busbin(int m, int M) {
	int i, suma = 0, nueva = (m + M) / 2;
	for (i = 0; i < musicos; ++i) {
		suma += ceil(arr[i] / (double) nueva);
	}

	ciclos++;
	if (ciclos > 25) {
		if (suma <= partituras) {
			return nueva;
		}
		return nueva + 1;
	}
	if (suma > partituras) {
		return busbin(nueva, M);
	}
	return busbin(m, nueva);
}

int main() {
	ios_base::sync_with_stdio(false);
	int i, M, suma;
	while (cin >> partituras) {
		cin >> musicos;
		M = 0;
		suma = 0;
		for (i = 0; i < musicos; ++i) {
			cin >> arr[i];
			M = max(M, arr[i]);
			suma += arr[i];
		}
		if (partituras >= suma) {
			cout << "1\n";
			continue;
		}
		if (partituras == musicos) {
			cout << M << "\n";
			continue;
		}
		ciclos = 0;
		cout << busbin(0, M + 1) << "\n";

	}

	return 0;
}





/*#include <iostream>
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
/*
 typedef vector<int> vi;

 #define show(x) cout<<":"<<x<<endl

 #define MAX 1005*/

int main() {
	int n, partituras, i, temp;
	while (cin >> partituras) {
		priority_queue<pair<double, pair<int, double>>> q;
		pair<double, pair<int, double>> element;

		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> temp;
			q.push(make_pair(temp, make_pair(temp, 1.0)));
		}
		for (i = partituras - n; i > 0; i--) {
			element = q.top();
			q.pop();
			q.push(
					make_pair(
							element.second.first / (element.second.second + 1),
							make_pair(element.second.first,
									element.second.second + 1)));
		}
		cout << ceil(q.top().first) << endl;

	}

	return 0;
}
*/