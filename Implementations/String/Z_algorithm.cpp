// Search the ocurrences of t (pattern to search) in s (the text).
// O(n + m). It increases R at most 2n times and decreases at most n times. 
// z[i] is the longest string s[i..i + z[i] - 1] that is a prefix = s[0..z[i] - 1].
void z_algorithm(string s, string const& t) {
    s = t + "$" + s; // "$" is a char not present in s nor t.
    int n = s.length(), m = t.length(), L = 0, R = 0;
    vi z(n, 0);
    // s[L..R] = s[0..R - L], [L, R] is the current window.
    for(int i = 1; i < n; i++) {
        if(i > R) { // Old window, recalculate.
            L = R = i;
            while(R < n && s[R] == s[R - L]) R++;
            R--;
            z[i] = R - L + 1;
        } else {
            if(z[i - L] < R - i) z[i] = z[i - L]; // z[i] will fall in the window.
            else { // z[i] can fall outside the window, try to increase the window.
                L = i;
                while(R < n && s[R] == s[R - L]) R++;
                R--;
                z[i] = R - L + 1;
            }
        }
        if(z[i] == m) { // Match found.
            //echo("Pattern found at: ", i - m - 1);
        }
    }
}

/* // Reduced code.
void z_array(string s){
    int i, L = 0,R = 0, n = s.length();
    vi z(n, 0);
    //the box is [L, R]
    for(i = 1; i < n; ++i){
        z[i] = max(0, min(z[i - L], R - i));
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            L = i; R = i + z[i]; ++z[i];
        }
    }
} */

