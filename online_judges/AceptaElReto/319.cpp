#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {

	int inicio, num, temp, temp2;

	while (cin >> inicio) {
		cin >> num;
		queue<pair<int, int>> q;
		vector<int> v(10001);
		q.push(make_pair(inicio, 0));
		while (1) {
			temp = q.front().first;
			temp %= 10000;
			temp2 = q.front().second;
			q.pop();
			if (temp == num) {
				cout << temp2 << endl;
				break;
			}

			if (!v[(temp + 1) % 10000]) {
				q.push(make_pair((temp + 1) % 10000, temp2 + 1));
				v[(temp + 1) % 10000] = 1;
			}

			if (temp == 0) {
				continue;
			}

			if (!v[(temp * 2) % 10000]) {
				q.push(make_pair((temp * 2) % 10000, temp2 + 1));
				v[(temp * 2) % 10000] = 1;
			}

			if (!v[(temp / 3) % 10000]) {
				q.push(make_pair((temp / 3) % 10000, temp2 + 1));
				v[(temp / 3) % 10000] = 1;
			}

		}
	}

	return 0;
}

