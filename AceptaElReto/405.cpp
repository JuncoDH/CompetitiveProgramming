#include <iostream>

using namespace std;

int main() {
	int num, temp, flag;
	while (1) {
		cin >> num;
		temp = num;
		if (!num) {
			return 0;
		}
		cout << num;
		flag = 0;
		while (1) {
			cin >> num;
			if (!num) {
				if (flag) {
					cout << "-" << temp;
				}
				cout << endl;
				break;
			}
			if (num == temp + 1) {
				flag = 1;
				temp = num;
			} else if (flag) {
				cout << "-" << temp << "," << num;
				temp = num;
				flag = 0;
			} else {
				cout << "," << num;
				temp = num;
			}

		}
	}

	return 0;
}
