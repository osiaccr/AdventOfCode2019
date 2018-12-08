#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#define STDTIME 60
#define DEF 100
#define NRWORKERS 5+

using namespace std;

ifstream fin ("date.in");

vector < int > L[DEF];

int In[DEF], Viz[DEF], nr_nodes, totalTime;

set < int > Q;

vector < pair < int, int > > Workers; // {time, id}

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

    while (!Q.empty () or !Workers.empty ()) {
        if (Q.empty () or Workers.size () == NRWORKERS)  {// Means we have workes doing stuff and we have to wait for them
            int elasped_time = Workers.begin () -> first; // Or all workers ar busy and we have to wait for 'em
            totalTime += elasped_time;

            while (!Workers.empty () and Workers.begin () -> first == elasped_time) {\
                int index = Workers.begin () -> second;
                for (int i = 0; i < L[index].size (); ++ i) {
                    -- In[L[index][i]];
                    if (In[L[index][i]] == 0) {
                        Q.insert (L[index][i]);
                    }
                }

                Workers.erase (Workers.begin ());
            }

            for (vector < pair < int, int > >::iterator it = Workers.begin (); it != Workers.end (); ++ it) {
                it -> first -= elasped_time;
            }
        }

        while (!Q.empty () and Workers.size () < NRWORKERS) {
            int x = * Q.begin ();
            Workers.push_back ({* Q.begin () + STDTIME, * Q.begin ()});
            Q.erase (Q.begin ());
        }
        sort (Workers.begin (), Workers.end ());

    }

    cout << totalTime;


    return 0;
}
