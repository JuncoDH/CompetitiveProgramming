#include <iostream>
#include <string.h>


using namespace std;


int main() {
	int casos, v[3], z;
	unsigned i;
	string cad;
	cin>>casos;

	for(z=0;z<casos;z++){
		cin>>v[0]>>v[1]>>v[2]>>cad;
		for(i=0;i<cad.length();i++){
			if(v[0]<0||v[1]<0||v[2]<0){
				break;
			}
			switch(cad[i]){
			case 'M':
				v[0]--;
				break;
			case 'A':
				v[1]--;
				break;
			case 'C':
				v[2]--;
				break;
			case 'R':
				v[0]--;
				v[1]--;
				break;
			case 'N':
				v[0]--;
				v[1]--;
				v[2]--;
				break;
			case 'V':
				v[2]--;
				v[1]--;
				break;
			case 'L':
				v[0]--;
				v[2]--;
				break;

			}
		}
		if(v[0]<0||v[1]<0||v[2]<0){
			cout<<"NO\n";
			continue;
		}
		cout<<"SI "<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	}

	return 0;
}


