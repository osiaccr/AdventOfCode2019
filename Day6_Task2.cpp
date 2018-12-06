#include <fstream>
#include <iostream>
#include <vector>
#define INF 1 << 29
#define DEF 1100
#define NR_INDEX 60
#define COMP 10000

using namespace std;

ifstream fin ("date.in");

vector < pair < int, int > > Points;

vector < pair < int, int > > SafePoints;

vector < pair < int, int > > IndexPoints[NR_INDEX];

int Map[100];

int abs (int x) {
    if (x < 0)
        x = -x;
    return x;
}

int get_dist_to_all (int x, int y) {
    int dist = 0;

    for (int i = 1; i < Points.size (); ++ i) {
        dist += abs (x - Points[i].first) + abs (y - Points[i].second);
    }

    return dist;
}

int find_closest (int x, int y) {
    int Min = INF;
    int index_Min;
    int duplicate = false;
    for (int i = 1; i < Points.size (); ++ i) {
        int new_dist = abs(x - Points[i].first) + abs (y - Points[i].second);
        if (Min == new_dist) {
            duplicate = true;
        }
        if (Min > new_dist) {
            Min = new_dist;
            index_Min = i;
            duplicate = false;
        }
    }

    if (duplicate)
        return -1;

    return index_Min;
}

int main () {
    Points.push_back ({0, 0});

    int x, y;
    char dump;
    while (fin >> x >> dump >> y) {
        swap (x, y);
        Points.push_back ({x, y});
    }

    int sol = 0;
    for (int i = 0; i <= DEF; ++ i) {
        for (int j = 0; j <= DEF; ++ j) {
            if (get_dist_to_all (i, j) < COMP) {
                ++ sol;
            }
        }
    }

    cout << sol;

    return 0;
}
