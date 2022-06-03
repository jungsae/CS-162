#include <iostream>
#include <string>

using namespace std;

#ifndef CARD_H
#define CARD_H

class Cards
{
private:
    string suit;
    int rank;

public:
    Cards();
    
    // getters
    string getSuit() 
    { return this->suit; }
    int getRank() 
    { return this->rank; }
    
    // setters
    void setSuit(string s) 
    { this->suit = s; }
    void setRank(int i) 
    { this->rank = i; }
};

#endif