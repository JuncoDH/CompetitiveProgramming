#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int gente, caso, z, salida, entrada;
	while (1) {
		cin>>gente>>caso;
		if(!gente && !caso){break;}
		if (caso >= gente || gente - caso == 1) {
			cout << "SI\n";
			for (z = 0; z < caso; z++) {
				cin >> salida >> entrada;

			}
			continue;
		}
		if (gente - caso > 2) {
			cout << "NO\n";
			for (z = 0; z < caso; z++) {
				cin >> salida >> entrada;

			}
			continue;
		}
		vector<int> vS(50);
		vector<int> vE(50);
		for (z = 0; z < caso; z++) {
			cin >> salida >> entrada;
			vS[salida-1]++;
			vE[entrada-1]++;
		}
		for(z=0;z<gente;z++){
			if(vS[z]==0 && vE[z]==0){
				cout<<"SI\n";break;
			}
		}
		if(z==gente){cout<<"NO\n";}

	}

	return 0;
}