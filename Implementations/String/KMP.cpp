// Knuth-Morris-Pratt. Search the ocurrences of t (pattern to search) in s (the text).
// O(n). It increases j at most n times and decreases at most n times. 
void KMP(string &s, string &t) {
    int n = s.length(), m = t.length(), i, j, len = 0;
    // Longest proper prefix that is also suffix.
    // s[0..lps[i]-1] == s[i-lps[i]+1..i].
    vi lps(m, 0);
    for(i = 1; i < m; i++) {
        if(t[i] == t[len]) {
            len++;
            lps[i] = len;
        } else if(len > 0) {
            len = lps[len - 1];
            i--;
        }
    }
    for(i = 0, j = 0; i < n; i++) {
        if(s[i] == t[j]) {
            j++;
            if(j == m) {
                echo("Pattern found at:", i-j+1);
                // You will math at least lps[j-1] chars.
                j = lps[j - 1];
            }
        } else if(j > 0) {
            j = lps[j - 1];
            i--;
        }
    }
}

