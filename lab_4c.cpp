#include <stdio.h>

const int size = 10;

void swap(double *x, double *y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(double tab[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (tab[j] > tab[j + 1])
                swap(&tab[j], &tab[j + 1]);
}

void show_tab(double tab[], int sizee)
{
    for (int i = 0; i < sizee; i++)
        printf("%.2lf ", tab[i]);
    printf("\n");
}

int main() {
    double tab[size] = {64.0, 34.0, 25.0, 12.0, 22.0, 11.0, 90.0, 88.0, 45.0, 77.0};

    printf("Tablica przed sortowaniem:\n");
    show_tab(tab, size);

    bubbleSort(tab, size);

    printf("Tablica po sortowaniu:\n");
    show_tab(tab, size);

    return 0;
}
