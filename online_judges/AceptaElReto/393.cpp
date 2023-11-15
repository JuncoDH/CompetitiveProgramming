#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <utility>
#include <string.h>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

//Primero inserto las palabras en el Trie y luego desde cada posicion hago BFS actualizando el numero coincidencias en las palabras

#define MAX 305
char arr[MAX][MAX];
int x, y;
enum {N,NE,E,SE,S,SO,O,NO};//8 direcciones

struct node{
	struct node *izq;
	struct node *der;
	int cont;
	bool word;
}*root;

struct node *getnode(){
	struct node *nuevo=new struct node;//o sin el struct
	nuevo->izq=NULL;
	nuevo->der=NULL;
	nuevo->cont=0;
	nuevo->word=false;
	return nuevo;
}


void insert(string s){
	//cout<<"Meto: "<<s<<endl;
	struct node *p=root;
	int i;

	for(i=0;i<(int)s.length();++i){
		if(s[i]=='0'){
			if(p->izq==NULL){
				p->izq=getnode();
			}
			p=p->izq;
		}
		else{
			if(p->der==NULL){
				p->der=getnode();
			}
			p=p->der;
		}
	}
	p->word=true;
}

void Nueva(int *i, int *j, int direccion){
	switch (direccion){
	case N:
		--(*i);
		break;
	case NE:
		++(*j);
		--(*i);
		break;
	case E:
		++(*j);
		break;
	case SE:
		++(*j);
		++(*i);
		break;
	case S:
		++(*i);
		break;
	case SO:
		--(*j);
		++(*i);
		break;
	case O:
		--(*j);
		break;
	case NO:
		--(*j);
		--(*i);
		break;
	}

}

void BFS(int i, int j, struct node *p,int direccion){
	//cout<<"BFS: "<<i<<" "<<j<<" "<<direccion<<endl;
	if(i<0||j<0||i>=x||j>=y||p==NULL){
		return;
	}
	if(arr[i][j]=='0'){
		p=p->izq;
	}
	else{
		p=p->der;
	}
	if(p==NULL){
		return;
	}

	if(p->word){
		p->cont+=1;
	}
	Nueva(&i,&j,direccion);

	BFS(i,j,p,direccion);
}



void output(string s, struct node *p){
	//cout<<"estoy con: "<<s<<" "<<p->word<<" "<<p->cont<<endl;
	if(p->word&&p->cont){
		cout<<s<<" "<<p->cont<<"\n";
	}

	if(p->izq!=NULL){
		output(s+"0",p->izq);
	}

	if(p->der!=NULL){
		output(s+"1",p->der);
	}

}



int main() {
	ios_base::sync_with_stdio(false);
	int i,j,query;
	string s;

	while(cin>>y){
		cin>>x;

		root=getnode();

		for(i=0;i<x;++i){
			for(j=0;j<y;++j){
				cin>>arr[i][j];
			}
		}

		cin>>query;
		for(i=0;i<query;++i){
			cin>>s;
			if((int)s.length()>max(x,y)){
				continue;
			}
			insert(s);
		}

		for(i=0;i<x;++i){
			for(j=0;j<y;++j){
				//cout<<i<<" "<<j<<endl;

				if(arr[i][j]=='0'){
					if(root->izq==NULL){
						continue;
					}
					if(root->izq->word){
						root->izq->cont+=1;
					}
					BFS(i-1,j,root->izq,N);
					BFS(i-1,j+1,root->izq,NE);
					BFS(i,j+1,root->izq,E);
					BFS(i+1,j+1,root->izq,SE);
					BFS(i+1,j,root->izq,S);
					BFS(i+1,j-1,root->izq,SO);
					BFS(i,j-1,root->izq,O);
					BFS(i-1,j-1,root->izq,NO);

				}
				else{
					if(root->der==NULL){
						continue;
					}
					if(root->der->word){
						root->der->cont+=1;
					}
					BFS(i-1,j,root->der,N);
					BFS(i-1,j+1,root->der,NE);
					BFS(i,j+1,root->der,E);
					BFS(i+1,j+1,root->der,SE);
					BFS(i+1,j,root->der,S);
					BFS(i+1,j-1,root->der,SO);
					BFS(i,j-1,root->der,O);
					BFS(i-1,j-1,root->der,NO);

				}
			}
		}





	output("",root);
	cout<<"---\n";


	}
	return 0;
}
