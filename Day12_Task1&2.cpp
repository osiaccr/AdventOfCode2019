//
//  main.cpp
//  Cristi Aoc
//
//  Created by Bogdan Circeanu on 12/12/2018.
//  Copyright © 2018 Bogdan Circeanu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#define DEF 1000
#define START 20
#define SIZE 230
#define NR_GENERATIONS 150

using namespace std;

vector < string > sequences;

char pots[DEF];

int nr_flowers;

ifstream fin ("date.in");

bool check_generation (int pos) {
    for (int i = 0; i < sequences.size (); ++ i) {
        string curr = sequences[i];
        bool ok = true;
        for (int j = pos - 2; j <= pos + 2; ++ j) {
            if (pots[j] != sequences[i][j - (pos - 2)]) {
                ok = false;
                break;
            }
        }
        if (ok)
            return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {

    char line[100];

    fin >> line;

    nr_flowers = strlen (line);

    string sequance, dump, result;

    while (fin >> sequance >> dump >> result) {
        if (result[0] == '#') {
            sequences.push_back (sequance);
        }
    }

    for (int i = 0; i <= SIZE; ++ i) {
        pots[i] =
            (i >= START and i <= START + nr_flowers - 1)
                ? line[i - START]
                : '.';
    }

    cout << "0:\n" << pots << "\n";

    for (int generation = 1; generation <= NR_GENERATIONS; ++ generation) {
        char new_pots[DEF];
        for (int j = 0; j <= SIZE; ++ j) {
            new_pots[j] = '.';
        }
        for (int i = 0; i <= SIZE; ++ i) {
            new_pots[i] =
                (check_generation(i))
                    ? '#'
                    : '.';
        }
        for (int j = 0; j <= SIZE; ++ j) {
            pots[j] = new_pots[j];
        }

        int sol = 0;
        for (int i = 0; i <= SIZE; ++ i) {
            sol +=
                (pots[i] == '#')
                    ? (i - START)
                    : 0;
        }

        cout << generation << ": " << sol << "\n" << pots << "\n";
    }


    return 0;
}
