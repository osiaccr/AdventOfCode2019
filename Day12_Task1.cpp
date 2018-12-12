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
#define DEF 100
#define START 30
#define NR_GENERATIONS 20

using namespace std;

vector < string > sequences;

char pots[DEF];

int nr_flowers;

ifstream fin ("date.in");

bool check_generation (int pos) {
    for (int i = 0; i < sequences.size (); ++ i) {
        for (int j = pos - 2; j <= pos + 2; ++ j) {
            if (pots[i] != sequences[i][j - (pos - 2)]) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    char line[100];
    
    fin.getline (line, 100);
    
    nr_flowers = strlen (line) - 16;
    
    string sequance, dump, result;
    while (fin >> sequance >> dump >> result) {
        if (result[0] == '#') {
            sequences.push_back (sequance);
        }
    }
    
    for (int i = 15; line[i] != 0; ++ i) {
        pots[START + i - 15] = line[i];
    }
    
    for (int generation = 1; generation <= NR_GENERATIONS; ++ generation) {
        char new_pots[DEF];
        for (int j = 0; j <= START + nr_flowers; ++ j) {
            new_pots[j] = '.';
        }
        for (int i = 0; i <= START + nr_flowers; ++ i) {
            if (check_generation(i)) {
                new_pots[i] = '#';
            }
            else {
                new_pots[i] = '.';
            }
        }
        for (int j = 0; j <= START + nr_flowers; ++ j) {
            pots[j] = new_pots[j];
        }
    }
    
    for (int j = 0; j <= START + nr_flowers; ++ j) {
        cout << pots[j] << " ";
    }
    
    return 0;
}
