#include "ASCII.h"


#include <iostream>

int main() {
    char sequence[] = {0, 1, 2, 3, 4};
    ASCII test(sequence, 5);
    std::cout << test.getLength() << std::endl;
}