#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream fin ("date.in");

string s;

char to_Upper (char x) {
    if (x >= 'a' and x <= 'z') {
        x += 'A' - 'a';
    }
    return x;
}

bool is_Upper (char x) {
    return !(x >= 'a' and x <= 'z');
}

int main () {
    fin >> s;

    bool ok = true;
    while (ok) {
        ok = false;
        for (int i = 1; i < s.size (); ++ i) {
            if (to_Upper(s[i]) == to_Upper(s[i - 1])
            and
            (( is_Upper (s[i]) and !is_Upper (s[i - 1]) )
             or ( !is_Upper (s[i]) and is_Upper(s[i - 1]) )
             ) ) {
                s.erase (s.begin () + (i - 1), s.begin () + (i + 1));
                ok = true;
                break;
            }
        }
    }

    cout << s.size ();

    return 0;
}
