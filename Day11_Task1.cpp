#include <fstream>
#include <iostream>
#define DEF 310
#define SIZE 300

using namespace std;

ifstream fin ("date.in");

int M[DEF][DEF], max_fuel, serial_number, sol_size;

pair < int, int > sol_position;

int find_fuel_cell (int x, int y) {
    int rack_ID = x + 10;
    int power_level = rack_ID * y;
    power_level += serial_number;
    power_level *= rack_ID;
    power_level = power_level % 1000 - power_level % 100;
    power_level -= 5;
    return power_level;
}

int find_fuel_square (int x, int y, int size) {
    int fuel = 0;
    /*for (int i = x; i <= x + size - 1; ++ i) {
        for (int j = y; j <= y + size - 1; ++ j) {
            fuel += M[i][j];
        }
    }*/
    fuel = M[x][y] - M[x + size][y] - M[x][y + size] - M[x + size][y + size];
    return fuel;
}

int main () {
    fin >> serial_number;

    for (int i = 1; i <= SIZE ; ++ i) {
        for (int j = 1; j <= SIZE; ++ j) {
            M[i][j] = find_fuel_cell (i, j) + M[i + 1][j] + M[i][j + 1] - M[i + 1][j + 1];
        }
    }

    /*for (int i = SIZE; i >= 1; -- i) {
        for (int j = SIZE; j >= 1; -- j) {
            M[i][j] = find_fuel_cell (i, j) + M[i + 1][j] + M[i][j + 1] - M[i + 1][j + 1];
        }
    }*/

    for (int size = 1; size <= 300; ++ size ) {
        cout << size << "\n";
        for (int i = 1; i <= SIZE - (3 - 1); ++ i) {
            for (int j = 1; j <= SIZE - (3 - 1); ++ j) {
                int fuel = find_fuel_square (i, j, 3);
                if (fuel > max_fuel) {
                    max_fuel = fuel;
                    sol_position = {i, j};
                    sol_size = size;
                }
            }
        }
    }

    cout << sol_position.first << ' ' << sol_position.second << " " << sol_size;

    return 0;
}
