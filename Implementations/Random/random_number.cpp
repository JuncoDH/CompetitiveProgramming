srand(time(nullptr));
ll random_interval(ll const l, ll const r) { // r >= l. [l, r].
    return random() % (r - l + 1) + l;
}
// Return random float in [0, 1].
ld rand_float() {
    return rand() / (ld)RAND_MAX;
}

