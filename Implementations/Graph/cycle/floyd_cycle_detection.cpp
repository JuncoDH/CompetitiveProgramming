ll f(ll const x) {
    return (x + 1) % 4; // Example.
}
// mu is the first index of the node in the cycle.
// lambda is the length of the cycle.
pll floyd_cycle_detection(ll const x0) {
    ll tortoise = f(x0), hare = f(f(x0)), mu = 0, lambda = 1;
    while(tortoise != hare) tortoise = f(tortoise), hare = f(f(hare));
    tortoise = x0;
    while(tortoise != hare) tortoise = f(tortoise), hare = f(hare), ++mu;
    hare = f(hare);
    while(tortoise != hare) hare = f(hare), ++lambda;
    return { mu, lambda };
}

