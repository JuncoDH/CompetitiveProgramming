class BaseConverter {
    int base;
    int n;
    vi v; // v is stored reversed, v[i] is the coefficient of b^i.
    static int get_letter_value(char const c) {
        if('0' <= c && c <= '9') return c - '0';
        if('A' <= c && c <= 'Z') return c - 'A' + 10;
        if('a' <= c && c <= 'z') return c - 'a' + 10;
        return c; // Error.
    }
    static char get_letter(int const c) {
        if(c <= 9) return '0' + c;
        return 'A' + c - 10;
    }
    public:
    BaseConverter(string const& s, int const _base) {
        n = s.size();
        v.assign(n, 0);
        for(int i = 0; i < n; i++) {
            v[n - i - 1] = get_letter_value(s[i]);
        }
        base = _base;
    }
    void change_base(int const new_base) {
        ll b = 1, rest = 0;
        vi new_v;
        for(int i = 0; i < n; i++) {
            rest += v[i] * b;
            b *= base;
        }
        while(rest) {
            ll temp = rest % new_base;
            new_v.pb(temp);
            rest /= new_base;
        }
        v = new_v;
        n = v.size();
        base = new_base;
    }
    string get_number() const {
        string s = "";
        for(int i = n - 1; i >= 0; i--) s += get_letter(v[i]);
        return s;
    }
};

