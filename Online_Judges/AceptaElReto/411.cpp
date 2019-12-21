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

int main() {
	ios_base::sync_with_stdio(false);

	long int tela, cont, elefante, suma, final;
	while (1) {
		cin >> tela;
		if (!tela) {
			return 0;
		}
		cont = 0;
		suma = 0;
		final = -1;
		while (1) {
			cin >> elefante;
			if (!elefante) {
				break;
			}
			suma += elefante;
			if (suma > tela && final == -1) {
				//echo(final);
				final = cont;
			}
			cont++;
		}
		if (final == -1) {
			cout << cont << "\n";
		} else {
			cout << final << "\n";
		}

	}

	return 0;
}
