// Adam Raczkowski ID: 280951
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
const int size = 100; // rozmiar tablicy liczb pseudo losowych
const int random_range = 100; // zakrees liczb pseudo losowych od 0 do random_range
int t[size]; // tablica liczb pseudo losowych
int temp[random_range] = {0}; // tablica sluzaca zliczaniu liczby wystapien poszczegolnych wartosci w tablicy t[]
vector<int>mody; // kontener przechowujacy wszystkie mody tablicy t[]
void CreateRandomArray(int t[], const int size) // wypelnianie t[] liczbami pseudo losowymi
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        t[i] = rand() % random_range;
}
void printArray(int t[], const int size) // podawanie na strumien wyjsca wartosci tablicy t[]
{
    sort(t, t + size);
    for (int i = 0; i < size; i++)
        cout << t[i] << " ";
    cout << endl;
}
// t[] - tablica z losowymi wartosciami
// temp[] - tablica z liczba wystapien liczb w t[]
void moda(int t[], int *temp, const int size, const int random_range, vector<int>& mody)
{
    for (int i = 0; i < size; i++){
        temp[t[i]]++;
    }
//    cout << endl;
//    for (int i = 0; i < size; i++){ // blok kodu sluzacy testom
//        cout << temp[i] << " ";
//    } cout << endl;
    int maks_i = 0; // indeks z najwieksza wartoscia temp[]
    int maks = 0; // najwieksza wartosc w t[]
    for (int i = 0; i <= random_range; i++) { // szukam maksymalnej wartosci w tablicy temp[] odpowiadajacej liczbie wystapien liczby i w tablicy t[]
        maks_i = max(maks_i, temp[i]);
        maks = i;
    }
    for (int i = 0; i <= random_range; i++){
        if (temp[i] == maks_i)
            mody.push_back(i);
    }
    sort(mody.begin(), mody.end());
}
void printMody(vector<int>& mody) // wypisywanie zawartosci wektora przechowujacego mody tablicy t[]
{
    cout << "MODY: ";
    for (int i = 0; i < mody.size(); i++)
        cout << mody[i] << " ";
    cout << endl;
}
void removeDuplicates(vector<int>& mody, size_t i = 0) { // rekurencyjna funkcja do usuwania duplikatow z vectora
    if (i == mody.size() - 1) {
        return;
    }
    if (mody[i] == mody[i + 1]) {
        mody.erase(mody.begin() + i + 1);
    }
    else {
        i++;
        removeDuplicates(mody, i);
    }
}
double aritmAvg(int t[], const int size) // funkcja do obliczania sredniej arytmetycznej
{
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum+=t[i];
    return sum/size;
}
double median(int t[], const int size) // funkcja wyznacza mediane na tablicy t[]
{
    sort(mody.begin(), mody.end());
    if (size % 2 == 0)
        return (t[(size / 2) - 1] + t[((size / 2))])/2.0;
    else return t[(size / 2)];
}
int main ()
{
    sort(t, t + size); // sortuje tablice w celu zoptymalizowania dzialania pozostalych funkcji
    sort(mody.begin(), mody.end());

    CreateRandomArray(t, size);
    printArray(t, size); // funkcja testowa
//    cout << endl;
    moda(t, temp, size, random_range, mody);
//    removeDuplicates(mody); // ostatecznie chyba nie potrzebna funkcja do wywolania
    printMody(mody);
    cout << "SREDNIA ARYTMETYCZNA: " << aritmAvg(t, size) << endl << "MEDIANA: " << median(t, size) << endl;

    return 0;
}