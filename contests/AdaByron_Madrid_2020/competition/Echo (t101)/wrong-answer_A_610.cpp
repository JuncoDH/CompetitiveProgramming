#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

typedef vector<vector<long double>> mat;
int n;

const long double eps = 1e-6;

void show(mat m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }cout << endl;
    }
    cout << "..--------" << endl;
}

mat mul(mat &a, mat &b) {
    mat c(n, vector<long double> (n));
    int i, j, k;
    long double sum;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            sum = 0.0;
            for(k = 0; k < n; k++) {
                sum += a[i][k]*b[k][j];
            }
            c[i][j] = sum;
        }
    }
    return c;
}

mat id(ll num) {
    mat c(n, vector<long double> (n, 0));
    int i;
    for(i = 0; i < n; i++) c[i][i] = 1;
    return c;
}

mat elevate(mat a, ll b) {
    mat ans = id(n);
    while(b) {
        if(b&1) ans = mul(ans, a);
        b>>=1;
        a = mul(a, a);
    }
    return ans;
}

int main(int argc, char** argv) {
    int i, j, tt, M, k;
    
    cin >> tt;
    //scanf("%d", &tt);
    
    while(tt--) {
        cin >> n >> M >> k;
        //scanf("%d %d %d", &n, &M, &k);
        mat m(n, vector<long double> (n));
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cin >> m[i][j];
                //scanf("%lf", &m[i][j]);
                m[i][j] /= 100;
            }
        }
        //show(m);
        /*show(m);
        show(mul(m, m));
        show(id(n));*/
        //show(elevate(m, k));
        m = elevate(m, k);
        vector<int> v(M);
        for(i = 0; i < M; i++) {
            cin >> v[i];
            //scanf("%d", &v[i]);
        }
        sort(v.begin(), v.end());
        bool mal = true;
        for(i = 0; i< M; i++) {
            if(m[v[i]-1][n-1] > eps) {mal = false; break ;}
        }
        if(mal) {
            cout << "Hasta la vista, chaval!\n";
            //printf("Hasta la vista, chaval!\n");
            continue;
        }
        for(i = 0; i < M; i++) {
            cout.precision(15);
            cout << v[i] << " " << fixed << m[v[i]-1][n-1] << "\n";
            //printf("%d %.15llf\n", v[i], m[v[i]-1][n-1]);
        }
        
    }
    

    return 0;
}

