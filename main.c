#include <stdio.h>
#include "Ucenik.h"

void istampajMeni() {
    printf("++++ MENI ++++\n");
    printf("1. dodaj novog ucenika\n");
    printf("2. ispisi sve vrlo dobre ucenike\n");
    printf("3. zavrsi razred za ucenika\n");
    printf("4. ispisi sve ucenike\n");
    printf("5. ispisi ucenike sa najduzim imenom i prezimenom\n");
    printf("0. izlaz\n");
    printf("Izaberite opciju: ");
}

int main() {
    Ucenik ucenici[DIM];
    int brojUcenika = 0;
    int izbor;

    do{
        istampajMeni();
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                dodajUcenika(ucenici, &brojUcenika);
                break;
            case 2:
                ispisiVrloDobre(ucenici, brojUcenika);
                break;
            case 3:
                zavrsiRazred(ucenici, brojUcenika);
                break;
            case 4:
                ispisiSveUcenike(ucenici, brojUcenika);
                break;
            case 5:
                ispisiNajduzeImePrezime(ucenici, brojUcenika);
                break;
            case 0:
                printf("izlaz iz programa.\n");
                break;
            default:
                printf("odabrali ste nepostojecu opciju, molim Vas pokusajte ponovo.\n");
        }
    }while (izbor!=0);

    return 0;
}
