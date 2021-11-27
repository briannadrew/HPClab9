#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;

//prototypes
void printFunc(int[]);
void fillFunc(int[]);
const int arrSize = 32 * 1024 * 1024;

int main()
{
	clock_t timer;
	int *array = new int[arrSize];
	srand((unsigned)time(NULL));
	timer = clock();
	fillFunc(array);
	printFunc(array);


	ofstream myfile("example.txt");
	if (myfile.is_open())
	{
		for (int count = 0; count < arrSize; count++) {
			myfile << array[count] << " "; // or "\n" or endl
		}
		myfile.close();
	}
	else cout << "Unable to open file";
	timer = clock() - timer;
	cout << "Time Elapsed: " << ((float)timer)/CLOCKS_PER_SEC << " seconds.";

	return 0;
}

void fillFunc(int array[])
{
	for (int i = 1; i < arrSize; i++)
	{
		array[i] = 1 + rand() % 10;
	}

}

void printFunc(int array[])
{
	for (int i = 1; i < arrSize; i++)
	{
		cout << array[i] << '\n';
	}
}
