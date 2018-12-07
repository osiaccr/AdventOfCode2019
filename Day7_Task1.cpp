#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <deque>
#include <vector>
#define DEF 100

using namespace std;

ifstream fin ("date.in");

vector < int > L[DEF];

int In[DEF], Viz[DEF], nr_nodes;

set < int > Q;

int main () {

    char x, y;
    string dump;
    while (fin >> dump >> x >> dump >> dump >> dump >> dump >> dump >> y >> dump >> dump) {
        x -= 'A' - 1;
        y -= 'A' - 1;
        L[x].push_back (y);
        ++ In[y];
        nr_nodes = max (nr_nodes, max (int(x), int(y)));
    }

    for (int i = 1; i <= nr_nodes; ++ i) {
        if (In[i] == 0) {
            Q.insert (i);
        }
    }

    while (!Q.empty ()) {
        int nod = * Q.begin ();
        Q.erase (Q.begin ());
        cout << char(nod + 'A' - 1);

        for (int i = 0; i < L[nod].size (); ++ i) {
            -- In[L[nod][i]];
            if (In[L[nod][i]] == 0) {
                Q.insert (L[nod][i]);
            }
        }
    }


    return 0;
}
