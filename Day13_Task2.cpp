#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define DEF 300

using namespace std;

int M[DEF][DEF];

int di[] = {0, 0, -1, 0, 1};
int dj[] = {0, -1, 0, 1, 0};
int intersection[] = {0, 2, 3, 1};




class Cart {
public:
    int orientation;
    pair < int, int > pos;
    int curr_move;

    Cart (char chr, pair < int, int > _pos) {
        switch (chr) {
        case '<':
            orientation = 1;
            break;
        case '^':
            orientation = 2;
            break;
        case '>':
            orientation = 3;
            break;
        case 'v':
            orientation = 4;
            break;
        }

        curr_move = 1;
        pos = _pos;
    }

    bool operator== (const Cart b) {
        if (pos == b.pos and orientation == b.orientation and curr_move == b.curr_move)
            return true;
        return false;
    }

    bool operator< (Cart b) {
        return pos < b.pos;
    }

    int make_move (vector < Cart > Carts, vector < Cart > to_delete) {
        pair < int, int > new_pos = make_pair (pos.first + di[orientation], pos.second + dj[orientation]);

        switch (M[new_pos.first][new_pos.second]) {
        case '|':
            pos = new_pos;
            break;
        case '-':
            pos = new_pos;
            break;
        case '\\':
            make_turn ('\\');
            pos = new_pos;
            break;
        case '/':
            make_turn ('/');
            pos = new_pos;
            break;
        case '+':
            take_intersection();
            pos = new_pos;
            break;
        default:
            pos = new_pos;
        }

        for (int i = 0; i < Carts.size (); ++ i) {
            if ((* this) == Carts[i] and !contains (to_delete, Carts[i]))
                return i;
        }

        return -1;
    }

private:
    void make_turn (char chr) {
        if (chr == '\\') {
            switch (orientation) {
            case 1:
                orientation = 2;
                break;
            case 2:
                orientation = 1;
                break;
            case 3:
                orientation = 4;
                break;
            case 4:
                orientation = 3;
                break;
            }
        }
        if (chr == '/') {
           switch (orientation) {
            case 1:
                orientation = 4;
                break;
            case 2:
                orientation = 3;
                break;
            case 3:
                orientation = 2;
                break;
            case 4:
                orientation = 1;
                break;
           }
        }
    }

    bool contains (vector < Cart > v, Cart elem) {
        for (int i = 0; i < v.size (); ++ i) {
            if (v[i] == elem)
                return true;
        }
        return false;
    }

    void take_intersection () {
        if (curr_move == 1) {
            orientation -= 1;
            if (orientation == 0)
                orientation = 4;
            curr_move = intersection[curr_move];
            return;
        }
        if (curr_move == 3) {
            orientation += 1;
            if (orientation == 5)
                orientation = 1;
            curr_move = intersection[curr_move];
            return;
        }
        curr_move = intersection[curr_move];
    }
};

bool contains (vector < Cart > v, Cart elem) {
    for (int i = 0; i < v.size (); ++ i) {
        if (v[i] == elem)
            return true;
    }
    return false;

}

ifstream fin ("date.in");

int n, m;

vector < Cart > Carts;

int main () {

    char line[DEF];

    while (fin.getline (line, DEF)) {
        int _m = 0;
        for (int i = 0; line[i] != 0; ++ i, ++ _m) {
            M[n][_m] =
                (line[i] == ' ')
                ? 0
                : line[i];

            if (M[n][_m] == '<' or M[n][_m] == '>' or M[n][_m] == 'v' or M[n][_m] == '^') {
                Cart new_cart = Cart (M[n][_m], {n, _m});
                Carts.push_back (new_cart);
            }
        }
        m = max (m, _m);
        ++ n;
    }

    while (Carts.size () > 1) {
        vector < Cart > to_delete;

        sort (Carts.begin (), Carts.end ());

        for (int i = 0; i < Carts.size (); ++ i) {
            bool is_to_be_deleted = contains (to_delete, Carts[i]);

            if (is_to_be_deleted == false) {
                int result = Carts[i].make_move (Carts, to_delete);

                if (result != -1) {
                    cout << Carts[i].pos.first << " " << Carts[i].pos.second << " colides with" << Carts[i].pos.first << " " << Carts[i].pos.second;
                    to_delete.push_back (Carts[i]);
                    to_delete.push_back (Carts[result]);
                }
            }
        }

        for (int i = 0; i < to_delete.size (); ++ i) {
            for (int j = 0; j < Carts.size (); ++ j) {
                if (to_delete[i] == Carts[j])
                    Carts.erase (Carts.begin () + j);
            }
        }

         /*for (int i = 0; i < Carts.size (); ++ i) {
                cout << Carts[i].pos.first << " " << Carts[i].pos.second << "\n";
        }
        cout << "--------------------\n";*/
    }

    return 0;
}

