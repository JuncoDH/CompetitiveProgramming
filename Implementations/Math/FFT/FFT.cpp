// Fast Fourier Trasnform, to get DFT
// Discrete Fourier Transform, point evaluation of
// w_n^k (the kth root of unity).
typedef complex<double> cd; // NOT long double, TLE.
class FFT{
    static void convolution(vector<cd> &a) {
        int i = 0, n = a.size(); // n power of 2.
        if(n == 1) return;
        vector<cd> a_even, a_odd;
        for(i = 0; i < n; i++)
            i%2 ? a_odd.pb(a[i]) : a_even.pb(a[i]);
        convolution(a_even);
        convolution(a_odd);
        cd wn = polar((double)1.0, 2*(double)PI/n), w = 1.0;
        for(i = 0; i < n/2; i++) {
            //w = polar(1.0, i*2*(double)PI/n); // Avoids precission error, but slower.
            a[i] = a_even[i] + w*a_odd[i];
            a[i + n/2] = a_even[i] - w*a_odd[i];
            w = w*wn;
        }
    }
    static void deconvolution(vector<cd> &a) {
        for(auto &el : a) el = conj(el); 
        convolution(a);
        for(auto &el : a) el /= (double)a.size();
    }
    public:
    // c[j] is Sum_{0, j} of a[i]*b[j - i].
    static vector<cd> multiply(vector<cd> a, vector<cd> b) {
        int i, n = max(a.size(), b.size());
        if(n == LSB(n)) n--;
        for(i = 30; i >= 0; i--) if(is_set(n, i)) break;
        i += 2; // Next power of two: 3 -> 8.
        n = 1<<i;
        while((int)a.size() < n) a.pb(0.0);
        while((int)b.size() < n) b.pb(0.0);
        convolution(a);
        convolution(b); // Don't need to call if a*a.
        vector<cd> ans(n);
        for(i = 0; i < n; i++) ans[i] = a[i]*b[i];
        deconvolution(ans);
        return ans;
    }
    static void show(vector<cd> &v) {
        int i, cont = 0; // Maximum 20 elements.
        for(i = 0; i < min((int)v.size(), 20); i++) {
            cout << " + " << (v[i].real() > eps ? v[i].real() : 0) << "x^" << cont++;
        } cout << endl;
    }
};

