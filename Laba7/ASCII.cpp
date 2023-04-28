//
// Created by harb2 on 4/17/2023.
//
#include <memory>
#include <iostream>
#include <cstring>

#include "ASCII.h"

ASCII::ASCII(char *SymbolsSequence, int SequenceLength)
        : SequenceLength(SequenceLength), SymbolsSequence(SymbolsSequence) {}


ASCII::ASCII(const ASCII &Other)
        : SequenceLength(Other.getLength()) {
    std::memcpy(SymbolsSequence, Other.SymbolsSequence, Other.getLength());
}


int ASCII::getLength() const { return SequenceLength; }

void ASCII::append(ASCII &other) {
    char* tmp = new char[SequenceLength + other.getLength()];

    std::memcpy(tmp, SymbolsSequence, SequenceLength);
    std::memcpy(tmp + (SequenceLength * sizeof(char)), other.SymbolsSequence, other.getLength());
    char* toDelete = this->SymbolsSequence;
    this->SymbolsSequence = tmp;

    free(toDelete);
    this->SequenceLength = SequenceLength + other.getLength();
}

char& ASCII::operator[](int i) const {
    return SymbolsSequence[i];
}

void ASCII::whitespacePartition() const {
    char* tmp = new char[SequenceLength] {0};
    int k = 0;
    for (int i = 0; i < SequenceLength; i++) {

        if (SymbolsSequence[i] == 32) {
            for (int j = 0; j < k; j++) {
                std::cout << tmp[j];
            }
            std::cout << std::endl;
            tmp = new char[SequenceLength];
            k = 0;
        }
        else {
            tmp[k] = SymbolsSequence[i];
        }
        k++;
    }
}

ASCII::~ASCII() = default;



int main() {
    char* sequence = new char[5] {3,1,2,3,32};
    ASCII test(sequence, 5);
    ASCII test1(sequence, 5);
    ASCII test3 = test;

    std::cout << test[1] << std::endl;
    test[1] = 34;
    std::cout << test[1] << std::endl;
    test.append(test1);
    std::cout << test3[2] << std::endl;

    test3[2] = 10;

    std::cout << test3[2] << std::endl;
    std::cout << test.getLength() << std::endl;
    std::cout << test.getLength() << std::endl;
    std::cout << test[5] << std::endl;
    std::cout << test3[2] << std::endl;

    test.whitespacePartition();

}