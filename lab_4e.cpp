// Adam Raczkowski ID: 280951
// zdecydowalem sie na nazwy zmiennych i tablic w j. angielskim w celu zwiekszenia uniwersalnosci kodu

#include<iostream>
#include <iomanip>

using namespace std;

const int rows = 10;
const int cols = 10;

void printArray(int t[rows][cols])
{
    cout << "|";
    for (int i = 0; i <= cols; i++)
        cout << setw(4) << i << " |";
    cout << endl;
    for (int row = 0; row < rows; row++) {
        cout << "|" << setw(4) << row + 1<< " |";
        for (int col = 0; col < cols; col++) {
            cout << setw(4) << t[row][col] << " |";
        }
        cout << endl;
    }
}

void createArray(int t[rows][cols])
{
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            t[row][col] = (row + 1) + (col + 1);
}

int main()
{
    int tab[rows][cols];
    createArray(tab);
    printArray(tab);
    return 0;
}
