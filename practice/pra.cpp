#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Friend
{
public:
    string name;
    int age;

    void print()
    {
        cout << name << " " << age << endl;
    }
};

int main()
{
    Friend myfriend{"Jack",10};
    myfriend.print();

    vector<Friend> myfriends;
    myfriends.resize(3);

    myfriends[0].print();
    myfriends[1].print();
    myfriends[2].print();

    return 0;
}