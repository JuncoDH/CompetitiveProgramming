#include <iostream>
#include <string>

using namespace std;

bool vill[100][100];
int width, height;
string s;

int find_right(int x, int y) {
    int count = 0;
    for (; y < width; ++y) {
        if (vill[x][y]) {
            return count;
        } else count++;
    }
    return -1;
}

int find_left(int x, int y) {
    int count = 0;
    for (; y >= 0; --y) {
        if (vill[x][y]) {
            return count;
        } else count++;
    }
    return -1;
}

int find_down(int x, int y) {
    int count = 0;
    for (; x < height; ++x) {
        if (vill[x][y]) {
            return count;
        } else count++;
    }
    return -1;
}

int find_up(int x, int y) {
    int count = 0;
    for (; x >= 0; --x) {
        if (vill[x][y]) {
            return count;
        } else count++;
    }
    return -1;
}

int main(int argc, char** argv) {
    char c;
    int cas, x, y;
    while (cin >> height >> width && width) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cin>>c;
                if (c == 'X') vill[i][j] = true;
                else vill[i][j] = false;
            }
        }
        cin>>cas;
        int res;
        while (cas--) {
            cin >> x>>y;
            cin>>s;
            x--;y--;
            if (s == "ARRIBA") {
                res = find_up(x, y);
                if (res == -1) cout << "NINGUNO\n";
                else cout << res << "\n";

            } else if (s == "DERECHA") {
                res = find_right(x, y);
                if (res == -1) cout << "NINGUNO\n";
                else cout << res << "\n";

            } else if (s == "ABAJO") {
                res = find_down(x, y);
                if (res == -1) cout << "NINGUNO\n";
                else cout << res << "\n";

            } else if (s == "IZQUIERDA") {
                res = find_left(x, y);
                if (res == -1) cout << "NINGUNO\n";
                else cout << res << "\n";

            }

        }
        cout << "---\n";



    }
    return 0;
}
