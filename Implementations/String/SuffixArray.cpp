class SuffixArray {
    string s;
    int n;
    vi sa;
    vi c; // Equivalence class. When built, c[sa[i]] = i, is also the inverse.
    // LCP(i, j) longest common prefix of suffix i and j. 
    // LCP(i, j) = min(lcp[pos[i] ... pos[j]-1]), create a SegmentTree with lcp array.
    vi lcp; //lcp[i] = LCP(sa[i], sa[i]+1). 

    // To make sort O(n). (a, b) sort first by b and then by a.
    void radix_sort(vector<pair<pii, int>> &a) {
        int i;
        vi cont(n);
        for(auto el : a) cont[el.fi.se]++; // by b.
        vector<pair<pii, int>> a2(n);
        vi psum(n);
        for(i = 1; i < n; i++) psum[i] = psum[i-1] + cont[i-1];
        for(auto el : a) {
            a2[psum[el.fi.se]] = el;
            psum[el.fi.se]++;
        }
        fill(cont.begin(), cont.end(), 0);
        for(auto el : a) cont[el.fi.fi]++; // by a.
        psum[0] = 0;
        for(i = 1; i < n; i++) psum[i] = psum[i-1] + cont[i-1];
        for(auto el : a2) {
            a[psum[el.fi.fi]] = el;
            psum[el.fi.fi]++;
        }
    }

    // cmp s with s2, return -1 if s < s2, 1 if s > s2, 0 otherwise.
    int cmpSubstr(int idx, string &s2) { 
        int i, n2 = min(n, idx + (int)s2.size());
        for(i = idx; i < n2; i++) {
            if(s[i] < s2[i - idx]) return -1;
            if(s[i] > s2[i - idx]) return 1;
        }
        return 0;
    }

    public:
    // O(n log n) construction of SA.
    SuffixArray(string &_s) {
        _s += '$'; // $ is the char lesser than all chars of _s (and not equal).
        s = _s;
        n = s.length();
        sa = vi(n);
        c = vi(n);
        int i, k = 1;
        vector<pair<char, int>> a0(n); // for the first iteration.
        vector<pair<pii, int>> a(n); // for the next iterations ((c of the first 2^k, c of the second 2^k), i).
        for(i = 0; i < n; i++) a0[i] = {s[i], i};
        sort(a0.begin(), a0.end());
        for(i = 0; i < n; i++) sa[i] = a0[i].se;
        c[sa[0]] = 0;
        for(i = 1; i < n; i++) {
            c[sa[i]] = c[sa[i-1]];
            c[sa[i]] += a0[i].fi != a0[i-1].fi;
        }
        while(c[sa[n-1]] != n-1) { // at most ceil(log2(n)) iterations (because of $)
            for(i = 0; i < n; i++) {
                a[i] = {{c[i], c[(i+(1ll<<(k-1))) % n]}, i};
            }
            radix_sort(a);
            for(i = 0; i < n; i++) sa[i] = a[i].se;
            c[sa[0]] = 0;
            for(i = 1; i < n; i++) {
                c[sa[i]] = c[sa[i-1]];
                c[sa[i]] += a[i].fi != a[i-1].fi;
            }
            k++;
        }
    }
    // Debugging SA.
    void showSA() {
        for(int i = 0; i < n; i++) cout << sa[i] << " " << s.substr(sa[i], n - sa[i]) << endl;
    }
    vi getSA() {return sa;}
    // Count the number of ocurrences of string s2 as a substring in s.
    int cntSubstr(string &s2) {
        int res, res2, l, r, bl, br, bmid;

        res = cmpSubstr(sa[0], s2);
        res2 = cmpSubstr(sa[n-1], s2);
        if(res > 0 || res2 < 0) return 0; // all 1's or all -1's.
        if(res == 0) l = 0; // l is the position of the first 0. 
        else {
            bl = 0; br = n-1;
            while(bl + 1 < br) {
                bmid = (bl + br) >> 1;
                res = cmpSubstr(sa[bmid], s2);
                if(res >= 0) br = bmid;
                else bl = bmid;
            }
            l = br;
        }
        if(res2 == 0) r = n-1; // r is the position of the last 0.
        else {
            bl = 0; br = n-1;
            while(bl + 1 < br) {
                bmid = (bl + br) >> 1;
                res = cmpSubstr(sa[bmid], s2);
                if(res <= 0) bl = bmid;
                else br = bmid;
            }
            r = bl;
        }

        return r - l + 1;
    }
    // Preprocess for creating lcp array.
    void preprocessLCP() {
        int i, k = 0;
        lcp = vi(n-1);
        for(i = 0; i < n-1; i++) { // Iterate over the suffix in decreasing order of length.
            // At most 2*n k++ and n k--;
            while(k+i < n && k+sa[c[i]-1] < n && s[k+i] == s[k+sa[c[i]-1]]) k++;
            lcp[c[i] - 1] = k;
            k = max(0, k-1); // The next suffix will have at least k-1 equal chars.
        }
    }
    vi getlcp() {return lcp;}
    // need the call of preprocessLCP(). Return the number of distinct nonempty substring of s. Use ll.
    ll numSubstr() {
        ll i, cont = 0;
        // ans = length of the i sorted suffix - the common part with the previous sorted suffix.
        for(i = 1; i < n; i++) cont += n - sa[i] -1 - lcp[i-1];
        return cont;
    }
};

void LCS(string &s, string &t) {
    string stotal = s + "@" + t;
    SuffixArray SA(stotal);
    SA.preprocessLCP();
    vi sa = SA.getSA(), lcp = SA.getlcp();
    int i, mn = -1, imn, n = s.length(); // mn = size of the LCS, imn index of the starting LCS.
    for(i = 0; i < (int)stotal.length() - 1; i++) {
        if((sa[i] < n && sa[i+1] >= n) || (sa[i] >= n && sa[i+1] < n)) {
            if(lcp[i] > mn) {
                mn = lcp[i];
                imn = sa[i];
            }
        }
    }
    // Use mn for the ans length or this to get the longest common substring.
    cout << stotal.substr(imn, mn) << "\n";
}
