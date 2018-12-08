#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin ("data.in");

int sum;

void back (int c, int m) {
    for (int i = 1; i <= c; ++ i) {
        int _c, _m;
        fin >> _c >> _m;
        back (_c, _m);
    }

    for (int i = 1; i <= m; ++ i) {
        int x;
        fin >> x;
        sum += x;
    }
}

int main () {

    int children, metadata;
    fin >> children >> metadata;

    back (children, metadata);

    cout << sum;

    return 0;
}
