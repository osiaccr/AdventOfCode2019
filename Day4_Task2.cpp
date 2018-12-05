#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#define DEF 1500

using namespace std;

ifstream fin ("data.in");

class Square {
public:
    int id;
    pair < int, int > position;
    pair < int, int > size;
};

vector < Square > Squares;

int M[DEF][DEF], isOverlaped[DEF];

int main () {

    Square newSquare;
    char dump;
    while (fin >> dump >> newSquare.id >> dump >> newSquare.position.first >> dump >> newSquare.position.second >> dump >> newSquare.size.first >> dump >> newSquare.size.second) {
        Squares.push_back (newSquare);

    }

    for (Square square : Squares) {
        for (int i = 0; i < square.size.first; ++ i) {
            for (int j = 0; j < square.size.second; ++ j) {
                int x = square.position.first + i;
                int y = square.position.second + j;
                if (M[x][y] == 0) {
                    M[x][y] = square.id;
                    continue;
                }
                if (M[x][y] != 0) {
                    isOverlaped[M[x][y]] = 1;
                    isOverlaped[square.id] = 1;
                }
            }
        }
    }

    for (Square square : Squares) {
        if (isOverlaped[square.id] == 0) {
            cout << square.id;
            break;
        }
    }

    return 0;
}
