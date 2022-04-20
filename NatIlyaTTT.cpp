#include <iostream>
#include "TTT_lib.h"
using std::cout;

int main()
{
    init();

    while (!is_game_over()) {
        print();
        make_next_move();
    }
    print();
}
