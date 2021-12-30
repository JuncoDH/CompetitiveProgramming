// for a pair<ll, ll> dont need to use random, can numerate all pairs and use a map.
//return a hash for a pair a, b. To avoid symmetry hash(a, b) = hash(b, a) use f1 and f2
#define prev vvvla
#define hash valks
ll prev = 1e5;
//get random primes: https://primes.utm.edu/nthprime/
//ll mod = 179'424'673;

ll mod = 373'587'883;
ll f1(ll a) {
    ll mask = 0b11001001011001101;
    return (a^mask)%mod;
}
ll f2(ll b) {
    ll mask = 0b011001010011100111;
    return (b^mask)%mod;
}
ll hash(ll a, ll b) {
    ll ans = (f1(a)*f2(b))%mod;
    //if the hash can not be less than prev
    if(ans < prev) ans += prev;
    return ans;
}
