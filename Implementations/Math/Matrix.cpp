// Determinant: https://cp-algorithms.com/linear_algebra/determinant-gauss.html

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
    // Example: Matrix<ll> a({{1, 2}, {3, 4}}); // Can't use for one column vector.
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
        Matrix<T> ans(nrow, ncol);
        for(i = 0; i < nrow; i++) {
            for(j = 0; j < ncol; j++) {
                ans.v[i][j] = v[i][j] + other.v[i][j];
            }
        }
        return ans.delete_negative_cero();
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
                }
            }
        }
        return ans.delete_negative_cero();
    }
    Matrix<T> operator ^ (ll ex) {
        if(ex == 0) {
            Matrix<T> ans(nrow, ncol);
            return ans.convert_to_identity();
        }
        Matrix<T> half = (*this) ^ (ex/2);
        if(ex%2) return half * half * (*this);
        else return half * half;
    }
    bool operator == (const Matrix<T> other) {
        int i, j;
        if(nrow != other.nrow || ncol != other.ncol) return false;
        for(i = 0; i < nrow; i++) {
            for(j = 0; j < ncol; j++) {
                if(abs(v[i][j] - other.v[i][j]) > eps) return false;
            }
        }
        return true;
    }
    bool is_null_matrix() {
        return ncol == 0 || nrow == 0;
    }
    // Change "-0" by "0".
    Matrix<T> delete_negative_cero() {
        int i, j;
        for(i = 0; i < nrow; i++) {
            for(j = 0; j < ncol; j++) {
                if(abs(v[i][j]) < eps) v[i][j] = 0;
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
            // If no pivot found, the matrix is not invertible. Its determinant is 0.
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
    // If you are going to *, it loses a lot of precission.
    static Matrix<T> inverse(Matrix<T> mat) {
        Matrix<T> id(mat.nrow, mat.ncol);
        id.convert_to_identity();
        return gaussian_elimination(mat, id);
    }
};
