ll f(ll last) {
    return ;
}

void floyd_detection() {
    ll pslow = f(F_0), pfast = f(f(F_0)), iteration = 0;
    while(pslow != pfast) pslow = f(pslow), pfast = f(f(pfast));
    pslow = F_0;
    while(pslow != pfast) pslow = f(pslow), pfast = f(pfast), iteration++;
    cout << "In " << iteration << " coincide with value: " << pslow << endl;
    pfast = f(pfast), iteration++;
    while(pslow != pfast) pfast = f(pfast), iteration++;
    cout << "In " << iteration << " coincide with value: " << pfast << endl;
}
