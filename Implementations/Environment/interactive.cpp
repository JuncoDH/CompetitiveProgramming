ll query(ll a, ll b) {
    ll num;
    cout << "? " << a + 1 << " " << b + 1 << endl;
    cin >> num;
    if(num == -1) exit(-1);
    return num;
}

void show(ll a) {
    cout << "! " << a + 1 << endl;
}

