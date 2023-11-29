#include <stdio.h>
#include <stdlib.h>

int ile[127];

int main() {
    char *napis;
    int max_dlugosc = 255;

    printf("Podaj napis: ");
    napis = (char *)malloc(max_dlugosc * sizeof(char));

    if (napis != NULL) {
        scanf("%s", napis);

        for (int i = 0; napis[i] != '\0'; i++) {
            ile[(int)napis[i]]++;
        }

        free(napis);
    }

    for (int i = 32; i <= 126; i++) {
        if (ile[i] != 0) {
            printf("%c - %d\n", i, ile[i]);
        }
    }

    return 0;
}