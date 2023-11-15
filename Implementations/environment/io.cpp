// setxkbmap es, change keyboard layout to esp.
// Fast IO. Never mix cin with scanf.
ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// Read multiple tokens until End Of Line
stringstream ss;
ss << "Hello world";
while(ss >> s) cout << s << endl;
ss.clear();
ss.str("Hello world");

// Precission for doubles.
cout.precision(20);
cout << setprecision(9) << num << '\n';
// Adds extra zeros to the right 0.5000.
cout << fixed;

// Add leading zeros in cout:
cout.fill('*'); // The character to be appended.
cout << -12345 << endl;
// setw only works for the next element.
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

