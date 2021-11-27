#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;

//prototypes
void printFunc(int[]);
const int arrSize = 32 * 1024 * 1024;

int main()
{
	clock_t timer;
	int *array = new int[arrSize];
	timer = clock();

	ifstream myfile("example.txt");
	if (myfile.is_open())
	{
		for (int count = 0; count < arrSize; count++) {
			myfile >> array[count];
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	printFunc(array);
	timer = clock() - timer;
	cout << "Time Elapsed: " << ((float)timer)/CLOCKS_PER_SEC << " seconds.";

	return 0;
}

void printFunc(int array[])
{
	for (int i = 1; i < arrSize; i++)
	{
		cout << array[i] << '\n';
	}
}
