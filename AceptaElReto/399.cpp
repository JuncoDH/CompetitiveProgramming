#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int i, j, flag;
	long long int temp;

	while (cin >> temp) {
		vector<long long int> v;
		if (!temp) {
			return 0;
		}
		v.push_back(temp);
		for (i = 1; ; i++) {
			cin >> temp;
			if (!temp) {
				break;
			}
			v.push_back(temp);
		}
		i--;
		j=i;
		flag = 0;
		if (i == 0) {
			cout << v[0] << endl;
			continue;
		}
		if (i % 2) {
			cout << "NO\n";
			continue;
		}

		sort(v.begin(), v.end());
		for (i--; i >= 0; i -= 2) {
			if (v[i] != v[i - 1]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << "NO\n";
			continue;
		}
		for(i=0;i<=j;i+=2){
			cout<<v[i]<<" ";
		}
		for(i=j-1;i>=2;i-=2){
			cout<<v[i]<<" ";
		}

		cout<<v[0]<<endl;

	}

	return 0;
}

