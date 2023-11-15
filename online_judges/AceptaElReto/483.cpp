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
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;


int main() {
	//ios_base::sync_with_stdio(false);
	int casos, z, h1, m1, s1, h2, m2, s2, sec1, sec2, campanadas, uva, dif;
																			//ES EL D
	scanf("%d", &casos);
	for(z=0;z<casos;++z){
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		scanf("%d %d", &campanadas, &uva);
		sec1=s1+m1*60+h1*60*60;
		sec2=s2+m2*60+h2*60*60;
		if(sec1>sec2){
			sec2+=24*60*60;
		}
		dif=sec2-sec1;
		dif/=(campanadas-1);
		dif*=(uva-1);
		dif+=sec1;
		s1=dif%60;
		dif/=60;
		m1=dif%60;
		dif/=60;
		h1=dif%24;
		printf("%02d:%02d:%02d\n", h1, m1, s1);


	}

	return 0;
}