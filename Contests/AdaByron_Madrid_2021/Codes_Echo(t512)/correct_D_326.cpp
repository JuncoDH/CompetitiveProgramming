#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;
int main() {
    int n;
    int a;
    string s;
    cin>>n;
    unordered_set<int> opts;
    bool fail=false;
    for(int i=0;i<n;++i){
        cin>>a>>s;
        if(opts.count(a)){
            fail=true;
        }
        opts.insert(a);
    }
    if(fail){
        cout<<"ERROR\n";
    }
    else{
        cout<<"OK\n";
    }
    return 0;
}
