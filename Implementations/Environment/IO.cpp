// Never mix cin with scanf.
// Fast IO.
ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


stringstream ss;
ss << "Hello world";
ss.str("Hello world");
while(ss >> s) cout << s << endl;
ss.clear();


cout << setprecision(9) << num << '\n';
cout.precision(20);
cout << fixed << ans;

// Add leading zeros in cout:
cout.fill('*'); // The character to be appended.
cout << -12345 << endl; 
cout << setw(10) << -12345 << endl; 
cout << setw(10) << left << -12345 << endl; 
cout << setw(10) << right << -12345 << endl;
cout << setw(10) << internal << -12345 << endl;

// Output.
-12345
****-12345
-12345****
****-12345
-****12345
