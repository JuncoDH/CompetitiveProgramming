#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


int main(void) {
    int c, cases, flag = 0;
    string name, prov;
    
    cin >> c;
    while(c--) {
        flag = 0;
        cin >> name;
        
        cin >> cases;
        
        if(cases == 1) {
            cin >> prov;
            cout << "FALSA\n";
        } 
        else {
            for (int i = 0; i < cases; i++) {
                cin >> prov;
                if (prov == name && i != cases - 1) {
                    flag = 1;
                }
            }
            if (flag == 1) {

                cout << "FALSA\n";
            } else if (prov == name) {
                cout << "VERDADERA\n";
            } else cout << "FALSA\n";
        }
        
    }
    
    
    
    return 0;
}
