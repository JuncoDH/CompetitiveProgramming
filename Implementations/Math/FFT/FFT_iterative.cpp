typedef complex<double> cd;
typedef vector<cd> vcd;
void show(vcd &e) { //for debug
    int cont = 0; for(auto el : e) {cout << " + " << (el.real() > eps ? el.real() : 0) << "x^" << cont++;} cout << endl;
}
int bitReverse(int num, int log2n) { //the reverse log2n bits of the num 0b011 -> 0b110
    int ans = 0;
    for(int i = 0; i < log2n; i++) {
        ans <<= 1;
        ans |= num&1;
        num >>= 1;
    }
    return ans;
}
vcd convolution(vcd &A) {
    int i, n = A.size(), log2n = -1, s, m, m2, j, k;
    cd t, u, w, wn;
    vcd a(n);
    while(n) log2n++, n>>=1; //calcule log2(n)
    for(i = 0, n = 1<<log2n; i < n; i++) { //change A to the order of the leaves in the recursive calls
        a[bitReverse(i, log2n)] = A[i]; 
    }
    for(s = 1; s <= log2n; s++) { //for every level of the recursion
        m = 1<<s; //recover n
        m2 = m>>1; //n/2
        wn = polar(1.0, 2*(double)PI/m);
        w = 1.0;
        for(j = 0; j < m2; j++) { //for every j element of the block of X
            for(k = j; k < n; k += m) { //for every block of X
                t = w * a[k + m2]; //twiddle
                u = a[k];
                a[k] = u + t;
                a[k + m2] = u - t;
            }
            w *= wn;
        }
    }
    return a;
}
void deconvolution(vcd &a) { //you can conjugate wn and do a[i]/n o can conj(a[i])/n
    for(auto &el : a) el = conj(el);
    a = convolution(a); // The coefficients of the polynomial have to be are real
    for(auto &el : a) el /= (double)a.size();
}
vcd FFT(vcd &a, vcd &b) { //multiply polynomial a*b
    //vcd a = {1.0, 2.0}, b = {3.0}, c;// a and b examples of polynomials to multiply, real coefficients
    vcd c;
    if(a.size() < b.size()) swap(a, b);
    int i, n = a.size();
    while(n - LSB(n)) n++, a.pb(0.0); //add 0.0's to the next power of two of the next power of two, 3->8
    n++, a.pb(0.0);
    while(n - LSB(n)) n++, a.pb(0.0);
    while((int) b.size() < n) b.pb(0.0); //the grade of a and b equal.
    a = convolution(a);
    b = convolution(b); //if you want a*a then delete this 2º call
    for(i = 0; i < n; i++) c.pb(a[i]*b[i]);
    deconvolution(c);
    return c;
}

