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

#define show(x) cout<<":"<<x<<endl

#define MAX 1005
#define D 0
#define A 1
#define M 2
#define I 3
#define C 4

int main() {
	int i, imax, rep;
	double money, maximo;
	char c;
	string palabra[5] =
			{ "DESAYUNOS", "COMIDAS", "MERIENDAS", "CENAS", "COPAS" };
	double mon[5] = { 0 };
	int cantidad[5] = { 0 };
	while (cin >> c) {


		cin >> money;
		if (c == 'D') {
			mon[D] += money;
			cantidad[D]++;
			continue;
		} else if (c == 'A') {
			mon[A] += money;
			cantidad[A]++;
			continue;
		} else if (c == 'M') {
			mon[M] += money;
			cantidad[M]++;
			continue;
		} else if (c == 'I') {
			mon[I] += money;
			cantidad[I]++;
			continue;
		} else if (c == 'C') {
			mon[C] += money;
			cantidad[C]++;
			continue;
		}

		maximo = mon[0];
		imax = 0;
		for (i = 1; i < 5; i++) {
			if (mon[i] > maximo) {
				maximo = mon[i];
				imax = i;
			}
		}

		rep = 0;
		for (i = 0; i < 5; i++) {
			if (mon[i] == maximo) {
				rep++;
			}
		}
		if (rep > 1) {
			cout << "EMPATE#";
		} else {
			cout << palabra[imax] << "#";
		}
		//ahora es el minimo
		maximo = mon[0];
		imax = 0;
		for (i = 1; i < 5; i++) {
			if (mon[i] < maximo) {
				maximo = mon[i];
				imax = i;
			}
		}
		rep = 0;
		for (i = 0; i < 5; i++) {
			if (mon[i] == maximo) {
				rep++;
			}
		}
		if (rep > 1) {
			cout << "EMPATE#";
		} else {
			cout << palabra[imax] << "#";
		}

		if (cantidad[A] == 0) {
			cout<<"NO\n";
			mon[D]=0;mon[A]=0;mon[M]=0;mon[I]=0;mon[C]=0;
			cantidad[D]=0;cantidad[A]=0;cantidad[M]=0;cantidad[I]=0;cantidad[C]=0;
			continue;
		}

		if (mon[A] / cantidad[A]
				> (mon[D]+mon[A]+mon[M]+mon[I]+mon[C])/(cantidad[D]+cantidad[A]+cantidad[M]+cantidad[I]+cantidad[C]) ) {
			cout<<"SI\n";
		}
		else{
			cout<<"NO\n";
		}
		mon[D]=0;mon[A]=0;mon[M]=0;mon[I]=0;mon[C]=0;
		cantidad[D]=0;cantidad[A]=0;cantidad[M]=0;cantidad[I]=0;cantidad[C]=0;
	}

	return 0;
}
