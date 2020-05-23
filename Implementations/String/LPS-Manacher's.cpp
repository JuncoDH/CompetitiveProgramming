//Manacher's algorithm, Longest Palindromic(s) Substring in O(n)
string LPS(string s){
    string str = "#", ans = "";
    ll i, c = 0, r = 0, imirror, n = s.length(), M = -1;
    
    for(i = 0; i < n; ++i){
        str+=s[i];
        str+="#";
    }
    n = str.size();
    vector<ll> P(n); P[0] = 0;

    for(i = 1; i < n; ++i){
        
        imirror = c - (i - c);
        
        if(i < r){
            P[i] = min(r - i, P[imirror]); 
        }
        else{
            P[i] = 0;
        }
        
        while(i + 1 + P[i] < n && i - 1 - P[i] >= 0 && str[i + 1 + P[i]] == str[i - 1 - P[i]]) ++P[i];
        
        if(i + P[i] > r){
            c = i;
            r = i + P[i];
        }
        
        
    }
    
    for(i = 0; i < n; ++i){
        if(P[i] > M){
            M = P[i];
            c = i;
        }
    }

    for(i = c - P[c]; i <= c + P[c]; ++i){
        if(str[i] != '#'){
            ans += str[i];
        }
    }
    //echo(str, M, c, ans, P);
    return ans;
}