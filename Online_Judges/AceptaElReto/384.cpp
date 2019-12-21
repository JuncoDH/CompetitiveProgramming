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
#include <time.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

#define MAX 500002*2
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	int i, j, iarr, n, temp, final; //final=flag
	while (scanf("%d", &n) == 1) { //cin>>n){

		final = 0;
		//cin>>temp;
		scanf("%d", &temp);
		arr[0] = temp;
		arr[1] = temp;
		iarr = 1;
		for (j = n - 1; j > 0; --j) {
			//cin>>temp;
			scanf("%d", &temp);
			for (i = iarr; i > 0 && arr[i - 1] < temp; i -= 2) {
				if (arr[i - 1] < temp && arr[i] > temp) {
					final = 1;
					break;
				}
			}
			if (final) {
				break;
			}

			if (arr[iarr - 1] < temp) {
				arr[iarr] = temp;
			} else if (arr[iarr - 1] == arr[iarr]) {
				arr[iarr - 1] = temp;
				arr[iarr] = temp;

				//break;
			} else {
				iarr += 2;
				arr[iarr - 1] = temp;
				arr[iarr] = temp;
			}
		}
		for (--j; j > 0; --j) {
			//cin>>temp;
			scanf("%d", &temp);
		}

		if (final) {
			//cout<<"ELEGIR OTRA\n";
			printf("ELEGIR OTRA\n");
		} else {
			//cout<<"SIEMPRE PREMIO\n";
			printf("SIEMPRE PREMIO\n");
		}

	}

	return 0;
}

