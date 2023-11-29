#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int size = 100;
int tab[size];

void fill_tab() {
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        tab[i] = rand() % 100;
}

void show_tab() {
    for (int i = 0; i < size; i++)
        printf("%d %d\n", i, tab[i]);
}

int find_tab(int *n) {
    for (int i = 0; i < size; i++) {
        if (tab[i] == *n)
            return i;
    }
    return -1;
}
int input()
{
    int n;
    printf("Podaj szukana liczbe: ");
    scanf("%d", &n);
    return n;
}
int main() {
    fill_tab();
    show_tab();
    int n = input();
    int index = find_tab(&n);

    if (index != -1)
        printf("Element %d znaleziony pod indeksem %d\n",n, index);
     else
        printf("Elementu %d nie znaleziono w tablicy.\n", n);

    return 0;
}
