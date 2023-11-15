#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

long long n, m, M,cont;

int main(void) {

    while(1){
        cin>>n>>m>>M;
        
        if(!n&&!m&&!M)return 0;
        
        cont=0;
        cont+=2 * (n/M + (n%M != 0));
        cont+=2 * (m/M + (m%M != 0));

        
        cout<<cont<<"\n";
    
    }
    
    return 0;
}
