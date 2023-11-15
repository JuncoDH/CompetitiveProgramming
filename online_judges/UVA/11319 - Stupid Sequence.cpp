#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))
#define is_set(x, i) (((x)>>(i))&1)
#define set_bit(x, i) {(x) |= 1ll<<(i);}

#ifdef JUNCO_DEBUG
#define echoarr(x) {for(int _i=0,_n=min((size_t)15,sizeof(x)/sizeof(x[0]));_i<_n;_i++)\
 {cout << x[_i] << " ";} cout << endl;}
#define echo(...) {cout<<"->";ECHO(#__VA_ARGS__, __VA_ARGS__ );cout<<endl;}
#define echo2(x) {cout<<#x<<endl; for(auto el : x) {ECHO(el); cout << endl;}}
#else
#define echoarr(x)
#define echo(...) 
#define echo2(x) 
#endif

const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}//for s.size()
void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout<<_s;}
void ECHO(long double _s){cout<<_s;}
void ECHO(bitset<8> b) {cout << b;}//resize bitset
template<typename T> void ECHO(set<T> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(map<T1, T2> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(pair<T1, T2> _s) {
    cout << "("; ECHO(_s.fi); cout << ","; ECHO(_s.se); cout << ")";
}
template<typename T> void ECHO(vector<T> v) {
    for(auto el : v) {ECHO(el); cout << "_";}
}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    int _i, c = 0;
    for(_i = 0; _i < (int)_s.size(); _i++) {
        if(c==0 && _s[_i]==',') break;
        if(_s[_i] == '(') c++;
        if(_s[_i] == ')') c--;
    }
    cout << " (" << _s.substr(0, _i) << "): "; ECHO(x);
    while(_i < (int)_s.size() && (_s[_i] == ',' || _s[_i] == ' ')) _i++;
    ECHO(_s.substr(_i), args...);
}

template<typename T> // Input vector<T>.
istream& operator >> (istream& is, vector<T>& v) {
    for(T& el : v) is >> el;
    return is;
}

template<typename T> // Output vector<T>.
ostream& operator << (ostream& os, const vector<T>& v) {
    bool _first = false;
    for(T el : v) {
        if(_first) os << " ";
        _first = true;
        os << el;
    }
    return os;
}

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


// TODO Gaussian elimination.
// TODO Determinant.
// TODO Inverse Matrix.

const int MOD = 1e5; // MOD of the Matrix, remove this if MOD is not used.

template<typename T>
class Matrix {
    public:
    int nrow = 0;
    int ncol = 0;
    vector<vector<T>> v;
    Matrix() {}
    // Empty Matrix.
    Matrix(int _nrow, int _ncol) {
        nrow = _nrow;
        ncol = _ncol;
        v.assign(nrow, vector<T>(ncol, 0));
    }
    // Example: Matrix<ll> a({{1, 2}, {3, 4}}); // Can't use for one columnd vector.
    Matrix(vector<vector<T>> _v) {
        nrow = _v.size();
        ncol = _v[0].size();
        v = _v;
    }
    friend ostream& operator << (ostream &os, Matrix<T> m) {
        int i, j;
        for(i = 0; i < m.nrow; i++) {
            for(j = 0; j < m.ncol; j++) {
                if(j) cout << " ";
                cout << m.v[i][j]; // Becareful with "-0".
            }
            cout << "\n";
        }
        return os;
    }
    Matrix<T> operator + (const Matrix<T> other) {
        int i, j;
        for(i = 0; i < nrow; i++) {
            for(j = 0; j < ncol; j++) {
                v[i][j] += other[i][j];
                v[i][j] %= MOD;
            }
        }
        return *this;
    }
    // Use this for an empty square Matrix to create an identity Matrix.
    Matrix<T> convert_to_identity() {
        for(int i = 0; i < nrow; i++) v[i][i] = 1;
        return *this;
    }
    Matrix<T> operator * (const Matrix<T> other) {
        int i, j, k;
        Matrix<T> ans(nrow, other.ncol);
        for(i = 0; i < nrow; i++) {
            for(j = 0; j < other.ncol; j++) {
                for(k = 0; k < ncol; k++) {
                    ans.v[i][j] += v[i][k]*other.v[k][j];
                    ans.v[i][j] %= MOD;
                }
            }
        }
        return ans;
    }
    Matrix<T> operator ^ (int ex) {
        if(ex == 0) {
            Matrix<T> ans(nrow, ncol);
            return ans.convert_to_identity();
        }
        Matrix<T> half = (*this) ^ (ex/2);
        if(ex%2) return half * half * (*this);
        else return half * half;
    }
    bool is_null_matrix() {
        return ncol == 0 || nrow == 0;
    }
    // Change "-0" by "0".
    Matrix<T> delete_negative_cero() {
        int i, j;
        for(i = 0; i < nrow; i++) {
            for(j = 0; j < ncol; j++) {
                if(v[i][j] < eps) v[i][j] = 0;
            }
        }
        return *this;
    }
    static Matrix<T> gaussian_elimination(Matrix<T> mat, Matrix<T> dato) {
        int i, j, k, imx;
        T mx, val;
        for(i = 0; i < mat.ncol; i++) {
            mx = mat.v[i][i];
            imx = i;
            for(j = i+1; j < mat.nrow; j++) {
                if(mat.v[j][i] > mx) {
                    mx = mat.v[j][i];
                    imx = j;
                }
            }
            // If no pivot found, the matrix is not invertible.
            if(mat.v[imx][i] == 0) return Matrix<T>(0, 0);
            // Swap the line with the highest value.
            for(j = i; j < mat.ncol; j++) {
                swap(mat.v[i][j], mat.v[imx][j]);
            }
            for(j = 0; j < dato.ncol; j++) {
                swap(dato.v[i][j], dato.v[imx][j]);
            }
            for(j = i+1; j < mat.nrow; j++) {
                T factor = - mat.v[j][i] / mat.v[i][i]; // Change if using modulus.
                for(k = i; k < mat.ncol; k++) {
                    mat.v[j][k] += factor * mat.v[i][k];
                }
                for(k = 0; k < dato.ncol; k++) {
                    dato.v[j][k] += factor*dato.v[i][k];
                }
            }
        }
        // Solving Ux = dato.
        // For every column of dato.
        for(k = 0; k < dato.ncol; k++) {
            for(i = mat.nrow-1; i >= 0; i--) {
                val = dato.v[i][k];
                for(j = i+1; j < mat.ncol; j++) {
                    val -= mat.v[i][j] * dato.v[j][k];
                }
                dato.v[i][k] = val / mat.v[i][i];
            }
        }
        return dato.delete_negative_cero();
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll i, j;
    /*Matrix<ld> m1({{1, 2}, {3, 4}}), m2({{0, 3, 8}, {0, 7, 18}});
    cout << m1 << endl << m2 << endl;
    Matrix<ld> m3 = Matrix<ld>::gaussian_elimination(m1, m2);
    cout << m3 << endl;

    return 0;*/
    Matrix<ld> mat(7, 7), dato(7, 1), res(0, 0);
    for(i = 0; i < 7; i++) {
        mat.v[i][0] = 1;
        for(j = 1; j < 7; j++) mat.v[i][j] = mat.v[i][j-1]*(i+1);
    }
    //cout << mat << endl;
    //cout << dato << endl;
    //cout << Matrix<ld>::gaussian_elimination(mat, dato) << endl;
    ll tt;
    cin >> tt;
    while(tt--) {
        for(i = 0; i < 7; i++) {
            cin >> dato.v[i][0];
        }
        //cout << dato << endl;
        res = Matrix<ld>::gaussian_elimination(mat, dato);
        //cout << res << endl;
        ld ans, pas, num;
        bool ok = true;
        for(i = 8; i <= 1500; i++) {
            cin >> num;
            if(!ok) continue;
            ans = res.v[0][0];
            pas = 1;
            for(j = 1; j < 7; j++) {
                pas *= i;
                ans += pas*res.v[j][0];
            } 
            if(ans != num) {
                ok = false;
                //echo(i, ans, num);
            }
        }
        for(i = 0; i < 7; i++) {
            res.v[i][0] = round(res.v[i][0]);
            if(res.v[i][0] < 0 || res.v[i][0] > 1000) ok = false;
        }
        if(!ok) {
            cout << "This is a smart sequence!\n";
            continue;
        }
        for(i = 0; i < 7; i++) {
            if(i) cout << " ";
            cout << res.v[i][0];
        }
        cout << "\n";
    }



    return 0;
}
