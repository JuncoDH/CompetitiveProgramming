#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

long int arr[1001][1001];

long int kto1(int n, int k){
	if(n==k){return 1;}
	if(k<0||n<k){return 0;}
	if(n==1){
		if(k==0){
			return 1;
		}
		return 0;
	}
	if(!arr[n][k]){arr[n][k]=kto1(n-1,k)%1000000007+kto1(n-1,k-1)%1000000007;}


	return arr[n][k];

}


int main(){
	int n, k;
	while(1){
		cin>>n>>k;
		if(!n&&!k){return 0;}
		if(!n||n<0||k<0){cout<<"0\n";continue;}
		cout<<kto1(n,k)%1000000007<<endl;

	}


	return 0;
}
