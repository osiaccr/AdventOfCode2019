#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#define DEF 100

using namespace std;

ifstream fin ("date.in");

set < int > L[DEF];

int In[DEF], Viz[DEF], nr_nodes;

vector < int > Sol, FSol;

void dfs (int nod) {
    Viz[nod] = 1;

    for (set < int >::reverse_iterator it = L[nod].rbegin (); it != L[nod].rend (); ++ it) {
        int curr_nod = * it;
        if (Viz[curr_nod] == 1)
            continue;
        dfs (curr_nod);
    }

    Sol.push_back (nod);
}

int main () {

    char x, y;
    string dump;
    while (fin >> dump >> x >> dump >> dump >> dump >> dump >> dump >> y >> dump >> dump) {
        x -= 'A' - 1;
        y -= 'A' - 1;
        L[x].insert (y);
        ++ In[y];
        nr_nodes = max (nr_nodes, max (int(x), int(y)));
    }

    for (int i = nr_nodes; i >= 1; -- i) {
        if (In[i] == 0 and Viz[i] == 0) {
            dfs (i);

            vector < int > Temp;

            for (int i = Sol.size () - 1; i >= 0; -- i) {
                Temp.push_back (Sol[i]);
            }

            Sol = Temp;
            Temp.clear ();

            int i = 0, j = 0;
            while (i < Sol.size () and j < FSol.size ()) {
                if (Sol[i] < FSol[j]) {
                    Temp.push_back (Sol[i]);
                    ++ i;
                }
                else {
                    Temp.push_back (FSol[j]);
                    ++ j;
                }
            }

            while (i < Sol.size ()) {
                Temp.push_back (Sol[i]);
                ++ i;
            }

            while (j < FSol.size ()) {
                Temp.push_back (FSol[j]);
                ++ j;
            }

            FSol = Temp;
            Sol.clear ();
        }
    }

    for (int i = 0; i < FSol.size (); ++ i) {
        cout << char(FSol[i] + 'A' - 1);
    }

    return 0;
}
