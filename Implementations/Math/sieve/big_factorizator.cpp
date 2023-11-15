add srand(time(nullptr)); // ADD srand(time(0));
// USE THIS ONLY WHEN NO OTHER OPTION LEFT ...
namespace Factorizator {
    vll primes; // Add primes manually.
    constexpr vll fixed_primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 }; // 47, 53, 59.
    // a^{p - 1} = 1 mod p => p divides some factor of (a^{d2^s} + 1) * (a^{d2^{s - 1}} + 1) * ... * (a^d + 1) * (a^d - 1).
    // Return true if the number is composite, false if it is not sure.
    bool check_composite(ll num, ll a, ll d, int const s) {
        ll x = elevate(a, d, num);
        if(x == 1 || x == num - 1) return false;
        for(int i = 0; i < s; ++i) {
            x = mult(x, x, num);
            if(x == num - 1) return false;
        }
        return true;
    }
    // Miller_Rabin DETERMINISTIC Version for num up to 1e18 (all LL).
    bool isPrime(ll const num) { // num - 1 == d * 2^s.
        bool flag = true;
        ll d = num - 1, s = 0;
        if(num <= 1) return false;
        for(auto const& p : fixed_primes) {
            if(p == num) return true;
            if(p % num == 0) return false; // Optimization.
        }
        while(d % 2 == 0) {
            d /= 2;
            ++s;
        }
        for(auto& p : fixed_primes) flag &= !check_composite(num, p, d, s);
        return flag;
    }
    // A polynomial function modulo mod, it will contain a cycle.
    ll f_pollard_rho(ll x, ll c, ll const mod) {
        return (mult(x, x, mod) + c) % mod;
    }
    // Found a factor (maybe not prime) of num. x0 and c are random, change them if the return is num.
    ll pollard_rho(ll const num, ll x0, ll c) {
        ll x1 = x0, x2 = x0;
        ll g = 1;
        if(num == 1) return 1;
        if(num % 2 == 0) return 2;
        x0 %= num;
        c %= num;
        while(g == 1) { // Floyd cycle detection.
            x1 = f_pollard_rho(x1, c, num);
            x2 = f_pollard_rho(x2, c, num);
            x2 = f_pollard_rho(x2, c, num);
            g = __gcd(abs(x1 - x2), num);
        }
        return g;
    }
    vector<pll> factors; // .fi is the prime, .se is the exponent.
    vector<pll> factorize(ll num) {
        factors.clear();
        ll y = num;
        while(num > 1) {
            if(isPrime(num)) y = num;
            else {
                y = pollard_rho(num, rand(), rand());
                while(isPrime(y) == false) y = pollard_rho(y, rand(), rand());
            }
            ll cont = 0;
            while(num % y == 0) {
                num /= y; ++cont;
            }
            factors.pb({ y, cont });
        }
        sort(factors.begin(), factors.end());
        return factors;
    }
    vll divisors; // Will save all the divisors.
    void dfs_div(ll const x, ll const i) {
        if(i == (int)factors.size()) { divisors.pb(x); return; }
        dfs_div(x, i + 1);
        for(int j = 0; j < factors[i].se; ++j) { x *= factors[i].fi; dfs_div(x, i + 1); }
    }
    // NOT TESTED.
    vector<ll> get_divisors(ll const num) { // 1 and num inclusive.
        if(factors.empty()) factorize(num);
        divisors.clear();
        dfs_div(1, 0);
        sort(divisors.begin(), divisors.end());
        return divisors;
    }
    // Factorize knowing that its primes are in primes vector.
    vector<pll> factorize_using_primes(ll num) {
        vector<pll> ans;
        for(int i = 0; i < (int)primes.size() && primes[i] <= num / primes[i]; ++i) {
            if(num % primes[i] == 0) {
                ll cont = 0;
                while(num % primes[i] == 0) {
                    num /= primes[i];
                    ++cont;
                }
                ans.pb({ primes[i], cont });
            }
        }
        if(num > 1) ans.pb({ num, 1 });
        return ans;
    }
    // empty if gcd = 1.
    vector<pll> gcd(vector<pll> const& va, vector<pll> const& vb) {
        vector<pll> ans;
        int l = 0, r = 0, va_sz = (int)va.size(), vb_sz = (int)vb.size();
        while(l < va_sz && r < vb_sz) {
            if(va[l].fi == vb[r].fi) { ans.pb({ va[l].fi, min(va[l].se, vb[r].se) }); ++l; ++r; }
            else if(va[l].fi < vb[r].fi) ++l;
            else ++r;
        }
        return ans;
    }
}

