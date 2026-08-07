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
void printFibonacciSeries(int Number)
{
    int previes1=1,previes2=0;
    cout<<"1  ";
    for (int i=2;i<=Number;i++)
    {
       int sum=previes1+previes2;
        cout<<sum<<"   ";
        previes2=previes1;
        previes1=sum;
        //sum=previes1+previes2;
    }
}
int main()
{
     int number=readPositiveNumber("please enter positive Number");
     printFibonacciSeries(number);
}