#include <iostream>


int main(){
	int n;
	while(std::cin>>n){
		if(!n){break;}
		n%2?std::cout<<"IZQUIERDA"<<std::endl:std::cout<<"DERECHA"<<std::endl;
	}
	return 0;
}