#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "invalid number of arguments." << endl;
		return 1;
	}

	int n = atoi(argv[1]);

	int** table = new int* [n];
	
	for (int i = 0; i < n; i++)
	{
		table[i] = new int[n];
	}

	for (int  i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j] = i + j;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << table[i][j] << "\t";
		}
		cout << "\n";
	}

	return 0;
}

