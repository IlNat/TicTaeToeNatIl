#include <iostream>
#include "TTT_lib.h"
using std::cout;
void print(const char board[3][3]);

int main()
{
    init();

    while (!is_game_over()) {
        print();
        get_coords();
    }
    print();
}
