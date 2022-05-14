srand(time(0));
ll random_interval(ll l, ll r) { // r >= l.
    return random()%(r-l+1) + l;
}

