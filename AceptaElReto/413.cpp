#include <iostream>

using namespace std;

int main(){
  int i, casos, a, b;
  cin>>casos;
  for(i=0;i<casos;i++){
    cin>>a>>b;
    if(a*b%2){cout<<(a*b)/2+1<<" "<<(a*b)/2<<endl;}
    else{cout<<(a*b)/2<<" "<<(a*b)/2<<endl;}
  }
  
  return 0;
}