#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int i, n, escalador, ngrupos, tammin, tammax, tamtemp, vlento, flag;

	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		tammin = 1;
		tammax = 1;
		ngrupos = 1;
		tamtemp = 1;
		flag = 0;
		cin >> vlento;
		for (i = 1; i < n; i++) {
			cin >> escalador;
			if (escalador >= vlento) {
				tamtemp++;
			} else if (escalador < vlento || i == n - 1) {
				if (!flag) {
					tammin = tamtemp;
					flag = 1;
				} else {
					tammin = min(tammin, tamtemp);
				}
				tammax = max(tammax, tamtemp);
				ngrupos++;
				tamtemp = 1;
				vlento = escalador;
			}
		}
		if (!flag) {
							tammin = tamtemp;
		}else{
		tammin = min(tammin, tamtemp);}
		tammax = max(tammax, tamtemp);
		cout << ngrupos << " " << tammin << " " << tammax << endl;
	}
	return 0;
}
