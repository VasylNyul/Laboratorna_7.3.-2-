// Lab_7_3.cpp
// Нюл Василь
// Лабораторна робота No 7.3.
// Опрацювання динамічних багатовимірних масивів.
// Варіант ?

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a,  const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i=0; i<rowCount; i++)
        for (int j=0; j<colCount; j++)
             a[i][j] = Low + rand() % (High-Low+1);
}

void Print(int** a,  const int rowCount, const int colCount)
{
    cout << endl;
    for (int i=0; i<rowCount; i++)
    {
        for (int j=0; j<colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool Sum(int** a, const int rowCount, const int colCount, int& S)
{
    bool result = false;
    S = 0;
    int k_videm = 0;
    for (int i=0; i<rowCount; i++)
    {
        for (int j=0; j<colCount; j++)
        {
            if( a[i][j] < 0)
            {
                result = true;
                k_videm++;
                break;
            }
        }
        if( k_videm > 0)
        {
            for (int j=0; j<colCount; j++)
            {
                S += a[i][j];
            }
        }
        k_videm = 0;
    }
    return result;
}

int main()
{
    srand((unsigned) time(NULL));
    
    int Low = -3;
    int High = 10;
    
    int n;
    cout << "n = "; cin >> n;
    cout << endl;
    int rowCount = n;
    int colCount = n;
    
    int **a = new int*[n];
        for (int i=0; i<n; i++)
            a[i] = new int[n];
    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);
    
    int S = 0;
    if( Sum(a, rowCount, colCount, S ) )
        cout << "S = " << S << endl;
    else
        cout << "Тут не має від^ємних елементів" << endl;
        cout << endl;
    
    
    
    for (int i=0; i<rowCount; i++)
        delete [] a[i];
        delete [] a;
return 0;
    
}

