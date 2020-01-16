//Find minimum in a discrete function that first decrease and then increase
//The minimum is check(x)

ll x = 0;
for(i = m; i > 0; i /= 2) {
       while(x + i + 1 < m && check(x + i) >= check(x + i + 1)) x += i;
}
if(check(x) >= check(x + 1)) ++x;
