//DOS MANERAS, CON RECURSION Y CON PILAS
/*
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

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x)<<endl
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

#define MAX 10000
string cad;

int parentesis(int *i, char c, int flag) {
	(*i)++;
	if (flag) {
		return 1;
	}
	for (; (*i)<cad.length(); (*i)++) {
		if (cad[(*i)] != '(' && cad[(*i)] != '[' && cad[(*i)] != '{'&&cad[(*i)] != ')' &&cad[(*i)] != '}' &&cad[(*i)] != ']') {
			continue;
		}
		if (c == '(' && (cad[(*i)] == ']' || cad[(*i)] == '}')) {
			flag = 1;
			return 1;
		}
		if (c == '{' && (cad[(*i)] == ']' || cad[(*i)] == ')')) {
			flag = 1;
			return 1;
		}
		if (c == '[' && (cad[(*i)] == ')' || cad[(*i)] == '}')) {
			flag = 1;
			return 1;
		}
		if(c=='('&&cad[(*i)]==')'){
			return 0;
		}
		if(c=='{'&&cad[(*i)]=='}'){
					return 0;
				}
		if(c=='['&&cad[(*i)]==']'){
					return 0;
				}
		flag = parentesis(i, cad[(*i)], flag);
		if (flag) {
			return 1;
		}
	}

	return 1;
}

int main() {
	int i, flag;
	while (getline(cin, cad)) {
		
		flag = 0;
		for (i = 0; i < cad.length(); i++) {
			if (cad[i] != '(' && cad[i] != '[' && cad[i] != '{'&&cad[i] != ')' &&cad[i] != '}' &&cad[i] != ']') {
				continue;
			}
			if (cad[i] == ')' || cad[i] == ']' || cad[i] == '}') {
				flag = 1;
				break;
			}
			flag = parentesis(&i, cad[i], 0);
			if (flag) {
				break;
			}
		}
		if(flag){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}

	}
	return 0;
}
/*

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

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x)<<endl
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

#define MAX 10000
string cad;

int main() {
	int i, flag;

	while (getline(cin, cad)) {
		stack<char> q;
		//cad="{{()}}";
		flag = 0;
		for (i = 0; i < cad.length(); i++) {
			if (cad[i] != '(' && cad[i] != '[' && cad[i] != '{' && cad[i] != ')'
					&& cad[i] != '}' && cad[i] != ']') {
				continue;
			}
			if (cad[i] == '(' || cad[i] == '{' || cad[i] == '[') {
				q.push(cad[i]);
				continue;
			}
			if (q.empty()) {
				flag = 1;
				break;
			}
			if (cad[i] == ')' && q.top() == '(') {
				q.pop();
				continue;
			}
			if (cad[i] == '}' && q.top() == '{') {
				q.pop();
				continue;
			}
			if (cad[i] == ']' && q.top() == '[') {
				q.pop();
				continue;
			}

		}
		if (flag || q.empty()==0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}

	}
	return 0;
}

