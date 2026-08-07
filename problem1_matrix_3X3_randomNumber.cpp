#include <iostream>
#include <cstdlib>
using namespace std;
int ReadRandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}
void GetRandomElement(int arr[3][3])
{

	for (int row = 0;row < 3;row++)
	{


		for (int colom = 0;colom < 3;colom++)

		{

			arr[row][colom] = ReadRandomNumber(0, 100);

		}


	}

}
void PrintArr(int arr[3][3])
{

	for (int row = 0;row < 3;row++)
	{


		for (int colom = 0;colom < 3;colom++)

		{

			cout << arr[row][colom];
			cout << "\t";

		}
		cout << endl;

	}

}
int main()
{

	

	
	srand((unsigned)time(NULL));
	int arr[3][3];
	cout << "The Following is s 3X3 random Matrix :" << endl;
	GetRandomElement(arr);
	PrintArr(arr);
}