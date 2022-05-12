typedef complex<double> cd;
typedef vector<cd> vcd;
void show(vcd &e) { //for debug
    int cont = 0; for(auto el : e) {cout << " +" << (el.real() > eps ? el.real() : 0) << "x^" << cont++;} cout << endl;
}
void convolution(vcd &a) { //insert a_i and get y_i = sum_j(a_j*w_i^j)
    int i, n = a.size(); //n power of 2
    if(n == 1) return;
    vcd a_even, a_odd;
    for(i = 0; i < n; i++) { //divide part of FFT
        if(i%2) a_odd.pb(a[i]);
        else a_even.pb(a[i]);
    }
    convolution(a_even); //recursive part
    convolution(a_odd);
    cd wn = polar(1.0, 2*(double)PI/n), w = 1.0; //wn^i are the n roots of n-unity
    //cd w;
    for(i = 0; i < n/2; i++) {
        //w = polar(1.0, i*2*(double)PI/n); //avoid precission error, but slower
        a[i] = a_even[i] + w*a_odd[i]; //A(wn^k) = Aeven(wn/2^k) + wn^k+Aodd(wn/2^k)
        a[i + n/2] = a_even[i] - w*a_odd[i]; //A(wn^k) = Aeven(wn/2^(k-n/2)) - wn^(k-n/2)+Aodd(wn/2^(k-n/2))
        w = w*wn;
    }
}
void deconvolution(vcd &a) { //insert y_i and get a_i = sum_j(y_j*w_i^-j)/n
    for(auto &el : a) el = conj(el); //you can conjugate wn and do a[i]/n o can conj(a[i])/n
    convolution(a); // The coefficients of the polynomial have to be are real
    for(auto &el : a) el /= (double)a.size();
}
// Calculate \sum_{i=0}^{n-1} a[i]*b[n-i].
vcd FFT(vcd &a, vcd &b) { //multiply polynomial a*b
    //vcd a = {1.0, 2.0}, b = {3.0}, c;// a and b examples of polynomials to multiply, real coefficients
    vcd c;
    if(a.size() < b.size()) swap(a, b);
    int i, n = a.size();
    while(n - LSB(n)) n++, a.pb(0.0); //add 0.0's to the next power of two of the next power of two, 3->8
    n++, a.pb(0.0);
    while(n - LSB(n)) n++, a.pb(0.0);
    while((int) b.size() < n) b.pb(0.0); //the grade of a and b equal.
    convolution(a);
    convolution(b); //if you want a*a then delete this 2º call
    for(i = 0; i < n; i++) c.pb(a[i]*b[i]);
    deconvolution(c);
    return c;
}

