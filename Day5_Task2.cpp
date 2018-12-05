#include <fstream>
#include <iostream>
#include <string>
#define INF 1 << 29

using namespace std;

ifstream fin ("date.in");

string s;

int Min = INF;

char to_Upper (char x) {
    if (x >= 'a' and x <= 'z') {
        x += 'A' - 'a';
    }
    return x;
}

bool is_Upper (char x) {
    return !(x >= 'a' and x <= 'z');
}

int reduce (string _s) {
    bool ok = true;

    while (ok) {
        ok = false;
        for (int i = 1; i < _s.size (); ++ i) {
            if (to_Upper(_s[i]) == to_Upper(_s[i - 1])
            and
            (( is_Upper (_s[i]) and !is_Upper (_s[i - 1]) )
             or ( !is_Upper (_s[i]) and is_Upper(_s[i - 1]) )
             ) ) {
                _s.erase (_s.begin () + (i - 1), _s.begin () + (i + 1));
                ok = true;
                break;
            }
        }
    }

    return _s.size ();
}

int main () {
    fin >> s;

    for (char letter = 'A'; letter <= 'Z'; ++ letter) {
        cout << letter << '\n';
        string new_string = s;
        for (int i = 0; i < new_string.size (); ++ i) {
            if (to_Upper(new_string[i]) == letter) {
                new_string.erase (new_string.begin () + i, new_string.begin () + (i + 1));
                -- i;
            }
        }
        int new_size = reduce (new_string);
        Min = min (Min, new_size);
    }

    cout << Min;

    return 0;
}
