#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long int n, k, tengo, como;
	while (1) {
		cin >> n >> k >> tengo;
		if (!n && !k && !tengo) {
			return 0;
		}
		como = tengo;
		if (k >= n && n <= tengo) {
			cout << "RUINA" << endl;
		} else if (!k) {
			cout << tengo << " " << tengo << endl;
		} else if (k >= n && n > tengo) {

			cout << tengo << " " << tengo << endl;
		} else {
			while (tengo >= n) {
				como += (tengo / n) * k;

				tengo = (tengo / n) * k + tengo % n;
			}
			cout << como << " " << tengo << endl;
		}
	}

	return 0;
}
