// Return s1 < s2.
// lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
bool less_than(string const& s1, string const& s2) {
    if(s1.size() != s2.size())
        return s1.size() < s2.size();
    for(int i = 0; i < (int)s1.size(); i++) {
        if(s1[i] != s2[i]) return s1[i] < s2[i];
    }
    return false;
}
// s1 + s2. s1[0] is the Most Significative digit.
string add(string const& s1, string const& s2) {
    int i = (int)s1.size()-1, j = (int)s2.size()-1, a, b, carry = 0;
    string ans;
    while(i >= 0 || j >= 0) {
        if(i >= 0) a = s1[i] - '0';
        else a = 0;
        if(j >= 0) b = s2[j] - '0';
        else b = 0;
        ans.pb((a + b + carry) % 10 + '0');
        carry = (a + b + carry) > 9;
        i--; j--;
    }
    if(carry) ans.pb('1');
    while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}
// Return s1 - s2. s1 has to be >= s2;
string substract(string const& s1, string const& s2) {
    string ans;
    int i = (int)s1.size()-1, j = (int)s2.size()-1, a, b, carry = 0;
    while(i >= 0) {
        a = s1[i] - '0';
        if(j >= 0) b = s2[j] - '0' + carry;
        else b = carry;
        if(a < b) a += 10;
        ans.pb(a - b + '0');
        carry = a > 9;
        i--; j--;
    }
    while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

