ll f(ll const x) {
    return (x + 1) % 4; // Example.
}
// mu is the first index of the node in the cycle.
// lambda is the length of the cycle.
// Faster than Floyd.
pll brent_cycle_detection(ll const x0) {
    ll power2 = 1, lambda = 1, mu = 0;
    ll tortoise = x0; // starts at node x0.
    ll hare = f(tortoise);
    while(hare != tortoise) { // Find lambda.
        if(power2 == lambda) {
            power2 *= 2;
            lambda = 0;
            tortoise = hare;
        }
        hare = f(hare);
        ++lambda;
    }
    tortoise = hare = x0; // Find mu.
    for(ll i = 0; i < lambda; ++i) hare = f(hare);
    while(tortoise != hare) tortoise = f(tortoise), hare = f(hare), ++mu;
    return { mu, lambda };
}

