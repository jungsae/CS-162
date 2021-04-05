#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct mult_div_values
{
    int mult;
    float div;
};

mult_div_values **create_table(int n)
{
    mult_div_values **table = new mult_div_values *[n];

    for (int i = 0; i < n; i++)
    {
        table[i] = new mult_div_values[n];
    }

    return table;
}

bool is_valid_dimension(char *n)
{
    while (*n < '1' || *n > '9')
    {
        cout << "You did not input a valid size." << endl;
        cout << "Please enter an integer greater than 0 for a matrix: ";
        cin >> n;
    }
}

void set_mult_values(mult_div_values **table, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            table[i][j].mult = (i + 1) * (j + 1);
        }
    };
}

void set_div_values(mult_div_values **table, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            table[i][j].div = (float)(i + 1) / (j + 1);
        }
    }
};

void print_mult_div_table(mult_div_values **table, int n)
{
    cout << "Multiplication Table:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << table[i][j].mult << "\t";
        }
        cout << endl;
    }

    cout << "Division Table:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << fixed;
            cout.precision(2);
            cout << table[i][j].div << "\t";
        }
        cout << endl;
    }
}

void delete_table(mult_div_values **table, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] table[i];
    }
    delete[] table;
};

void prompt_ask(int &y_n)
{
    int input;
    cout << "Would you like to see a different size matrix (0-no, 1-yes)?" << endl;
    cin >> input;
    if (input == 1)
    {
        y_n = input;
    }
    else if (input == 0)
    {
        y_n = 0;
    }
}

int main(int argc, char **argv)
{   
    int input;
    do{
    is_valid_dimension(argv[1]);
    int n = atoi(argv[1]);
    mult_div_values **multDivTable = create_table(n);
    set_mult_values(multDivTable, n);
    set_div_values(multDivTable, n);
    print_mult_div_table(multDivTable, n);
    delete_table(multDivTable, n);
    prompt_ask(input);
    }while(input == 1);
    
    return 0;
}