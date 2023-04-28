//
// Created by harb2 on 4/17/2023.
//

#ifndef CPPLABS_ASCII_H
#define CPPLABS_ASCII_H
#include <memory>
#include <iostream>
#include <cstring>

class ASCII {
private:
    int SequenceLength;

public:
    char* SymbolsSequence;
    ASCII(char* SymbolsSequence, int SequenceLength);


    [[nodiscard]] int getLength() const;

    void append(ASCII &other);

    void whitespacePartition() const;

    ASCII(const ASCII&);

    char& operator[](int i) const;

    ASCII& operator=(ASCII&);

    virtual ~ASCII();



};


#endif //CPPLABS_ASCII_H
