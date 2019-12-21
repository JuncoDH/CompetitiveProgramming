#include <iostream>

using namespace std;


int main(){
	int i, j, arr[40][10]={0}, caso, n, x;

	for(i=30;i>0;i--){
		if(arr[i+2][2]==0&&arr[i+3][3]==0&&arr[i+4][4]==0&&arr[i+7][7]==0){
			arr[i][1]=1;
		}
		if(arr[i+1][1]==0&&arr[i+3][3]==0&&arr[i+5][5]==0&&arr[i+8][8]==0){
			arr[i][2]=1;
		}
		if(arr[i+2][2]==0&&arr[i+1][1]==0&&arr[i+6][6]==0&&arr[i+9][9]==0){
			arr[i][3]=1;
		}
		if(arr[i+1][1]==0&&arr[i+5][5]==0&&arr[i+6][6]==0&&arr[i+7][7]==0){
			arr[i][4]=1;
		}
		if(arr[i+2][2]==0&&arr[i+4][4]==0&&arr[i+6][6]==0&&arr[i+8][8]==0){
			arr[i][5]=1;
		}
		if(arr[i+5][5]==0&&arr[i+3][3]==0&&arr[i+4][4]==0&&arr[i+9][9]==0){
			arr[i][6]=1;
		}
		if(arr[i+1][1]==0&&arr[i+4][4]==0&&arr[i+8][8]==0&&arr[i+9][9]==0){
			arr[i][7]=1;
		}
		if(arr[i+2][2]==0&&arr[i+5][5]==0&&arr[i+9][9]==0&&arr[i+7][7]==0){
			arr[i][8]=1;
		}
		if(arr[i+7][7]==0&&arr[i+8][8]==0&&arr[i+6][6]==0&&arr[i+3][3]==0){
			arr[i][9]=1;
		}

	}
	/*
	for(i=0;i<32;i++){
		cout<<i<<":";
		for(j=1;j<10;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	 */
	cin>>caso;
	for(i=0;i<caso;i++){
		cin>>n>>x;
		if(arr[n][x]){cout<<"PIERDE\n";}
		else{cout<<"GANA\n";}

	}

return 0;
}
