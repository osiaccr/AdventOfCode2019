#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin ("data.in");

int sum;

int back (int c, int m) {
    vector < long long > Vals;

    for (int i = 1; i <= c; ++ i) {
        int _c, _m;
        fin >> _c >> _m;
        Vals.push_back (back (_c, _m));
    }

    int _s = 0;
    if (c == 0) {
        for (int i = 1; i <= m; ++ i) {
            int x;
            fin >> x;
            _s += x;
        }
        return _s;
    }

    for (int i = 1; i <= m; ++ i) {
        int x;
        fin >> x;
        if (x <= Vals.size ())
            _s += Vals[x - 1];
    }

    return _s;
}

int main () {

    int children, metadata;
    fin >> children >> metadata;

    cout << back (children, metadata);


    return 0;
}
