#include "Ucenik.h"
#include <stdio.h>
#include <string.h>

int dodajUcenika(Ucenik ucenici[], int *brojUcenika) {
    if (*brojUcenika == DIM) {
        printf("nema vise mesta da bi dodali novog ucenika!\n");
        return 0;
    }

    printf("unesite podatke o novom uceniku:\n");
    printf("uneti sifru ucenika: ");
    scanf("%d", &ucenici[*brojUcenika].Sifra);
    printf("uneti ime ucenika: ");
    scanf(" %s", ucenici[*brojUcenika].Ime);
    printf("uneti prezime ucenika: ");
    scanf(" %s", ucenici[*brojUcenika].Prezime);
    printf("uneti broj zavrsenih razreda: ");
    scanf("%d", &ucenici[*brojUcenika].zavrseniRazredi);
    printf("uneti prosecnu ocena: ");
    scanf("%f", &ucenici[*brojUcenika].prosecnaOcena);

    (*brojUcenika)++;
    return 1;
}

void ispisiVrloDobre(Ucenik ucenici[], int brojUcenika) {
    int p=0;
    printf("broj vrlo dobrih ucenika:\n");
    for (int i = 0; i < brojUcenika; i++) {
        if (ucenici[i].prosecnaOcena < 4.5) {
            printf("  - %d %s %s (%.2f)\n", ucenici[i].Sifra, ucenici[i].Ime, ucenici[i].Prezime, ucenici[i].prosecnaOcena);
            p = 1;
        }
    }
    if (!p) {
        printf("  nema vrlo dobrih ucenika.\n");
    }
}

void zavrsiRazred(Ucenik ucenici[], int brojUcenika) {
    int sifra,razred,p=0;
    float novaOcena;

    printf("Unesite sifru ucenika: ");
    scanf("%d", &sifra);

    for (int i=0;i<brojUcenika;i++){
        if (ucenici[i].Sifra == sifra){
            printf("uneti razred koji ucenik zavrsava: ");
            scanf("%d", &razred);
            printf("uneti prosecnu ocenu za taj razred: ");
            scanf("%f", &novaOcena);

            ucenici[i].zavrseniRazredi++;
            ucenici[i].prosecnaOcena = (ucenici[i].zavrseniRazredi * ucenici[i].prosecnaOcena + novaOcena) / ucenici[i].zavrseniRazredi;
            printf("razred i prosecna ocena ucenika su azurirani.\n");
            p=1;
            break;
        }
    }

    if (!p) {
        printf("ucenik sa unetom sifrom nije pronadjen.\n");
    }
}

void ispisiSveUcenike(Ucenik ucenici[], int brojUcenika) {
    printf("lista svih ucenika:\n");
    for (int i = 0; i < brojUcenika; i++) {
        printf("%d %s %s %d %.2f\n", ucenici[i].Sifra, ucenici[i].Ime, ucenici[i].Prezime, ucenici[i].zavrseniRazredi, ucenici[i].prosecnaOcena);
    }
}

void ispisiNajduzeImePrezime(Ucenik ucenici[], int brojUcenika) {
    int max_duzina=0;
    for (int i=0;i<brojUcenika;i++){
        int duzina=strlen(ucenici[i].Ime) + strlen(ucenici[i].Prezime);
        if (duzina>max_duzina){
            max_duzina=duzina;
        }
    }

    printf("ucenici sa najduzim imenom i prezimenom:\n");
    for (int i = 0; i < brojUcenika; i++) {
        int duzina = strlen(ucenici[i].Ime) + strlen(ucenici[i].Prezime);
        if (duzina == max_duzina) {
            printf("%d %s %s %d %.2f\n", ucenici[i].Sifra, ucenici[i].Ime, ucenici[i].Prezime, ucenici[i].zavrseniRazredi, ucenici[i].prosecnaOcena);
        }
    }
}
