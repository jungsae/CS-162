#include <iostream>
using namespace std;

struct animal
{
    int num_teeth;
    int num_legs;
    string species;
};


int main(/*int argc, char **argv[]*/)
{
    animal dog;
    dog.num_teeth=32;
    
    animal *dog_ptr = &dog;
    cout << " The dog has" << dog_ptr->num_teeth << " teeth\n";

    return 0;
}