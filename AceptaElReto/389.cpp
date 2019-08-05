#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <utility>
#include <time.h>
#include <set>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

bool salida;
string original1, original2, original3,signo;
char no01,no02,no03;//que no sea 0 el primer elemento, mejor que un set

int ALLOWED(char c){//devuelve 1 si c puede ser "0"
	if(c==no01||c==no02||c==no03)return 0;
	return 1;
}

bool isNumber(char c){//devuelve 1 si c es un número
	if(c>='0'&&c<='9'){
		return true;
	}
	return false;
}

void mostrar(string s1, string s2, string s3){//Debuggear
	cout<<s1<<endl<<s2<<endl<<s3<<endl<<"------------"<<endl;
}

void mostrarfinalproducto(string s1, string s2, string s3){//muestra el resultado siempre que sea correcto
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	reverse(s3.begin(),s3.end());
	if(signo=="+"&&stoll(s1)+stoll(s2)!=stoll(s3))return;
	if(signo=="*"&&stoll(s1)*stoll(s2)!=stoll(s3))return;
	cout<<s1<<" "<<signo<<" "<<s2<<" = "<<s3<<"\n";
	salida=true;
}

string ParcialRes(string s1, string s2, int col){//es el resultado parcial, dado la vuelta
	s1=s1.substr(0,min(col+1,(int)s1.length()));
	s2=s2.substr(0,min(col+1,(int)s2.length()));
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	lli exponente=1;
	for(int i=0;i<col+1;++i)exponente*=10;//evita problemas de precision del pow(10,col+1)

	if(signo=="*"){
		s1=to_string((stoll(s1)*stoll(s2))%exponente);
	}else{
		s1=to_string((stoll(s1)+stoll(s2))%exponente);
	}

	reverse(s1.begin(),s1.end());
	while(s1.length()<col+1){
		s1+="0";
	}
	return s1;
}

void DFS(string s1, string s2, string s3, bool disponible[10],int col){
	int i,x;

	if(salida){//se ha mostrado el resultado ya
		return;
	}

	if(col==s3.length()){
		mostrarfinalproducto(s1,s2,s3);
		//exit(0);
		return;
	}

	//fila 1, columna col
	if(col<s1.length()&&!isNumber(s1[col])){
		for(i=0;i<=9;++i){
			if(!disponible[i]||(i==0&&!ALLOWED(s1[col]))){
				continue;
			}
			for(x=0;x<s1.length();++x)if(original1[x]==original1[col])s1[x]=i+'0';//SET
			for(x=0;x<s2.length();++x)if(original2[x]==original1[col])s2[x]=i+'0';
			for(x=0;x<s3.length();++x)if(original3[x]==original1[col])s3[x]=i+'0';
			disponible[i]=false;
			DFS(s1,s2,s3,disponible,col);
			for(x=0;x<s1.length();++x)if(original1[x]==original1[col])s1[x]=original1[col];//UNSET
			for(x=0;x<s2.length();++x)if(original2[x]==original1[col])s2[x]=original1[col];
			for(x=0;x<s3.length();++x)if(original3[x]==original1[col])s3[x]=original1[col];
			disponible[i]=true;
		}
		return;//desechar
	}

	//fila 2, columna col
	if(col<s2.length()&&!isNumber(s2[col])){
		for(i=0;i<=9;++i){
			if(!disponible[i]||(i==0&&!ALLOWED(s2[col]))){
				continue;
			}
			for(x=0;x<s1.length();++x)if(original1[x]==original2[col])s1[x]=i+'0';//SET
			for(x=0;x<s2.length();++x)if(original2[x]==original2[col])s2[x]=i+'0';
			for(x=0;x<s3.length();++x)if(original3[x]==original2[col])s3[x]=i+'0';
			disponible[i]=false;
			DFS(s1,s2,s3,disponible,col);
			for(x=0;x<s1.length();++x)if(original1[x]==original2[col])s1[x]=original2[col];//UNSET
			for(x=0;x<s2.length();++x)if(original2[x]==original2[col])s2[x]=original2[col];
			for(x=0;x<s3.length();++x)if(original3[x]==original2[col])s3[x]=original2[col];
			disponible[i]=true;
		}
		return;//desechar
	}

	string numero=ParcialRes(s1,s2,col);//coge el resultado que deberia salir, si es un numero lo comprueba y si no lo pone a SET
	if(isNumber(s3[col])){
		if(numero[col]!=s3[col]){
			return;
		}
		DFS(s1,s2,s3,disponible,col+1);
	}else{
		if(!disponible[numero[col]-'0']||(numero[col]-'0'==0&&!ALLOWED(s3[col]))){
			return;
		}
		for(x=0;x<s1.length();++x)if(original1[x]==original3[col])s1[x]=numero[col];//SET
		for(x=0;x<s2.length();++x)if(original2[x]==original3[col])s2[x]=numero[col];
		for(x=0;x<s3.length();++x)if(original3[x]==original3[col])s3[x]=numero[col];
		disponible[numero[col]-'0']=false;
		DFS(s1,s2,s3,disponible,col+1);//avanza 1 col
		for(x=0;x<s1.length();++x)if(original1[x]==original3[col])s1[x]=original3[col];//UNSET
		for(x=0;x<s2.length();++x)if(original2[x]==original3[col])s2[x]=original3[col];
		for(x=0;x<s3.length();++x)if(original3[x]==original3[col])s3[x]=original3[col];
		disponible[numero[col]-'0']=true;
		return;//desechar
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	bool disponiblep[10];
	string igual;
	int i;


	while(cin>>original1){
		cin>>signo>>original2>>igual>>original3;

		for(i=0;i<=9;++i)disponiblep[i]=true;//inicializacion
		no01=no02=no03='-';
		salida=false;

		if(original1.length()>1)no01=original1[0];//si solo hay una letra no puede tener 0's superfluos a la izq
		if(original2.length()>1)no02=original2[0];
		if(original3.length()>1)no03=original3[0];

		reverse(original1.begin(),original1.end());//normalizamos los indices
		reverse(original2.begin(),original2.end());
		reverse(original3.begin(),original3.end());

		DFS(original1,original2,original3,disponiblep,0);
	}

	return 0;
}
