#include <iostream>
using namespace std;
int readPositiveNumber(string message)
{
    int Number = 0;
    do
    {
        cout << message << endl;
        cin >> Number;
    } while (Number < 0);

    return Number;
}
void printFibonacciSeries(short Number,short previes1,short previes2)
{

    if(Number>0)
    {

        int sum=previes1+previes2;
        previes2=previes1;
        previes1=sum;
        cout<<sum<<"  ";
        printFibonacciSeries(Number-1, previes1, previes2);

    }
}
int main()
{
     int number=readPositiveNumber("please enter positive Number");
     printFibonacciSeries(number,0,1);
}