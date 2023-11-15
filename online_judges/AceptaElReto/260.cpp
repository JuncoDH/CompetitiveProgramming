#include <iostream>

using namespace std;

int v1[27],v2[27];
int main(int argc, char** argv) {
    int cas;
    cin>>cas;
    string s;
    bool equal;
    getline(cin,s);
    while(cas--){
        for(int i=0;i<27;++i){
            v1[i]=v2[i]=0;
        }
        getline(cin,s);
        for(char a:s){
            if(a==' '){
                
            }
            else if(a>='a'){
                v1[a-'a']++;
            }
            else{
                v1[a-'A']++;
            }
        }
        getline(cin,s);
        for(char a:s){
            if(a==' '){
                
            }
            else if(a>='a'){
                v2[a-'a']++;
            }
            else{
                v2[a-'A']++;
            }
        }
        equal=true;
        for(int i=0;i<27;++i){
            if(v1[i]!=v2[i]){
                equal=false;
                break;
            }
        }
        if(equal) cout<<"SI\n";
        else cout<<"NO\n";
        
        
    }
    return 0;
}

