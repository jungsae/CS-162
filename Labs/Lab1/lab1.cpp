#include <iostream>
#include <stdlib.h>
using namespace std;

struct mult_div_values
{
    int mult;
    float div;
};

bool is_valid_dimension(char *n)
{
    if (n == 0)
    {
        "Please enter an integer greater than 0 for a matrix: ";
        cin >> *n;
    }

    return &n;
}

mult_div_values **create_table(int n)
{
    mult_div_values **table = new mult_div_values *[n];

    for (int i = 1; i <= n; i++)
    {
        table[i] = new mult_div_values[n];
    }

    return table;
}

void set_mult_values(mult_div_values **table, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            table[i][j].mult = i * j;
        }
    };
}

void set_div_values(mult_div_values **table, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            table[i][j].div = (double)i / (double)j;
        }
    }
};

void delete_table(mult_div_values **table, int n)
{
    for (int i = 1; i <= n; i++)
    {
        delete[] table[i];
    }
    delete[] table;
};

int main(int argc, char **argv)
{
    if (argc != 2)
        {
            cout << "You did not input a valid size." << endl;
            return 1;
        }
    int n = atoi(argv[1]);
    int yOrN;        
    mult_div_values **multDivTable = create_table(n);

    do
    {
        set_mult_values(multDivTable,n);
        set_div_values(multDivTable,n);


        cout << "Would you like to see a different size matrix (0-no, 1-yes)?" << endl;
        cin >> yOrN;
    } while (yOrN == 1);

    delete_table(multDivTable, n);
    return 0;
}