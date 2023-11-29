#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
int binarySearch_asc(int tab[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (tab[mid] == x) // sprawdzam czy od razu nie trafilem na wartosc szukana
            return mid;

        if (tab[mid] > x)
            return binarySearch_asc(tab, l, mid - 1, x); // poczatek nowego zakresu sie nie zmienia, ale koniec nowego zakresu jest teraz starym srodkiem

        return binarySearch_asc(tab, mid + 1, r, x);
    }

    return -1;
}
int binarySearch_desc(int tab[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (tab[mid] == x)
            return mid;

        if (tab[mid] > x)
            return binarySearch_desc(tab, mid + 1, r, x);

        return binarySearch_desc(tab, l, mid - 1, x);
    }

    return -1;
}
void asc(int tab[], const int &size)
{
    sort(tab, tab + size); // sortowanie rosnace
}
void desc(int tab[], const int &size)
{
    sort(tab, tab + size, greater<int>()); // sortowanie malejace
}
void choose_sort(int tab[], const int &size)
{
    int sortowanie = 0;
    cout << "Jakie sortowanie wybierasz?\n1. Rosnace\n2. Malejace\n";
    cin >> sortowanie;
    if (sortowanie == 1)
        asc(tab, size);
    else desc(tab, size);
}
void what_you_look_for(int &szukana, const int &random_range)
{
    printf("Podaj liczbe ktorej szukasz. Musi byc w zakresie 0 - %d\n", random_range-1);
    cin >> szukana;
    if (szukana > random_range)
    {
        cout << "Podano liczbe nie mieszczaca sie w zakresie. Podaj inna lliczbe:\n";
        what_you_look_for(szukana, random_range);
    }
}
int main (){
    const int size = 100;
    int tab[size];
    int szukana;
    int szukana_index;
    const int random_range = 100;
    random_device rd; // ustalenie ziarna
    mt19937 gen(rd()); // zastosowanie bardziej nowoczesnego generatora liczb losowych
    uniform_int_distribution<int> distrib(0, random_range); // po wywolaniu distrib() generuje sie liczba losowa z zakrezu <0, ranodom_range)

    for (int i = 0; i < size; i++) // wypelniam tablice losowymi wartosciami
        tab[i] = distrib(gen);

    choose_sort(tab, size);
    what_you_look_for(szukana, random_range);
    
    for (int i = 0; i < size; i++)
        cout << tab[i] << " ";
    cout << endl;
    if (tab[0] <= tab[size-1]) // w zaleznosci od tego czy sortowalem malejaco czy rosnoco wybieram odpowiedni wariant funkcji
        szukana_index = binarySearch_asc(tab, 0, size-1, szukana);
    else
        szukana_index = binarySearch_desc(tab, 0, size-1, szukana);
    if (szukana_index != -1)
        cout << "Szukana liczba znajduje sie pod indeksem: " << szukana_index;
    else
        cout << "Nie znaleziono liczby :(";
    return 0;
}