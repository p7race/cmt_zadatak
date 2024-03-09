#ifndef UCENIK_H_INCLUDED
#define UCENIK_H_INCLUDED

#define DIM 100

typedef struct {
    int Sifra;
    char Ime[50];
    char Prezime[50];
    int zavrseniRazredi;
    float prosecnaOcena;
} Ucenik;

int dodajUcenika(Ucenik ucenici[], int *brojUcenika);
void ispisiVrloDobre(Ucenik ucenici[], int brojUcenika);
void zavrsiRazred(Ucenik ucenici[], int brojUcenika);
void ispisiSveUcenike(Ucenik ucenici[], int brojUcenika);
void ispisiNajduzeImePrezime(Ucenik ucenici[], int brojUcenika);

#endif /* UCENIK_H */
