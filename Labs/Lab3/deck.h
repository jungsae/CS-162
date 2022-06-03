#include "card.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef DECK_H
#define DECK_H

class Deck
{
private:
    Cards card[52];
    
public:
    Deck();
    ~Deck();
    
    
};

#endif