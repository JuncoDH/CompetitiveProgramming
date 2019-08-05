#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

int main(void) {
    int cases, i, v[1000][2] = {0}, max, j;
    while (cin >> cases) {
        if (!cases) {
            return 0;
        }
        max = 0;
        for (i = 0; i < cases; i++) {
            cin >> v[i][0] >> v[i][1];
        }
        for (i = 0; i < cases; i++) {
            for (j = i; j < cases; j++) {
                if ((abs(v[i][0] - v[j][0]) + abs(v[i][1] - v[j][1])) > max) {
                    max = abs(v[i][0] - v[j][0]) + abs(v[i][1] - v[j][1]);
                }
            }
        }
        cout << max << endl;

    }

    return 0;
}

