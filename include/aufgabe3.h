#ifndef AUFGABE3_H
#define AUFGABE3_H

#define MAX_WORT_LEN 100

typedef struct {
    char deutsch[MAX_WORT_LEN];
    char english[MAX_WORT_LEN];
} Woerterbuch;

void wortschatz_hinzufuegen(Woerterbuch **liste, int *anzahl);
void wortschatz_deutsch_sort_anzeigen(Woerterbuch *liste, int *anzahl);
void wortschatz_english_sort_anzeigen(Woerterbuch *liste, int *anzahl);
void wortschatz_loeschen(Woerterbuch **liste, int *anzahl);
void wortschatz_speichern(Woerterbuch *liste, int anzahl, const char *dateiname);
void wortschatz_laden(Woerterbuch **liste, int *anzahl, const char *dateiname);

#endif