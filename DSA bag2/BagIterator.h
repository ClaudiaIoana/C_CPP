//
// Created by dell on 07.04.2022.
//

#ifndef DSA_BAG2_BAGITERATOR_H
#define DSA_BAG2_BAGITERATOR_H

#endif //DSA_BAG2_BAGITERATOR_H
#include "Bag.h"

class BagIterator
{
    //DO NOT CHANGE THIS PART
    friend class Bag;

private:
    const Bag& bag;
    Node* current;
    TElem occ;
    //BagIterator(const Bag& bag);
    BagIterator(const Bag& c);

public:
    void first();
    void next();
    TElem getCurrent() const;
    bool valid() const;
    void jumpForward(int k);
};
