#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ifstream fin ("date.in");

string s;

int Max;

char to_Upper (char x) {
    if (x >= 'a' and x <= 'z') {
        x += 'A' - 'a';
    }
    return x;
}

bool is_Upper (char x) {
    return !(x >= 'a' and x <= 'z');
}

int reduce (string s) {
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

    return s.size ();
}

int main () {
    fin >> s;

    for (int letter = 'A'; letter <= 'Z'; ++ letter) {
        string new_string = s;
        for (int i = 0; i < new_string.size (); ++ i) {
            if (to_Upper(new_string[i]) == letter) {
                new_string.erase (new_string.begin () + i, new_string.begin () + (i + 1));
            }
        }
        int new_size = reduce (new_string);
        Max = max (Max, new_size);
    }

    cout << Max;

    return 0;
}
