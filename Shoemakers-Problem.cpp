#include <iostream>
#include <algorithm>

using namespace std;

struct work {
    int fine;
    int time;
    int index;
};

bool cmp(work a, work b) {
    if (a.time * b.fine != b.time * a.fine) {
        return a.time * b.fine < b.time * a.fine;
    }
    return a.index < b.index;
}

int main() {
    int cnt, n;
    work D[1001];

    cin >> cnt;
    while (cnt--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> D[i].time >> D[i].fine;
            D[i].index = i + 1;
        }

        sort(D, D + n, cmp);
        for (int i = 0; i < n; i++) {
            if (i) {
                cout << ' ';
            }
            cout << D[i].index;
        }
        cout << endl;
        if (cnt) {
            cout << endl;
        }
    }
    return 0;
}
