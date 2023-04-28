#include "Graph.h"
#include <iostream>

int main() {
    Graph<10, true> test;
    Graph<10, false> test1;

    std::cout << test.add_edge(1, 2) << std::endl;
    std::cout << test.are_adjacent(1,2) << std::endl;

    std::cout << test.add_edge(2, 1) << std::endl;
    std::cout << test.add_edge(2, 3) << std::endl;
    std::cout << test.add_edge(1, 3) << std::endl;

    std::cout << test1.add_edge(1, 2) << std::endl;
    std::cout << test1.add_edge(2, 1) << std::endl;

    std::cout << test1.add_edge(2, 1) << std::endl;

    std::cout << test1.are_adjacent(1,2) << std::endl;
    std::cout << test1.are_adjacent(2,1) << std::endl;
}