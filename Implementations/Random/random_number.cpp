srand(time(0));
ll random_interval(ll l, ll r) { // r >= l. [l, r].
    return random()%(r-l+1) + l;
}
// Return random float in [0, 1].
ld rand_float() {
    return rand()/(ld)RAND_MAX;
}

