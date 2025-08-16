#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/aufgabe3.h"

int compareGerman(const void *a, const void *b) {
    const Woerterbuch *w1 = (const Woerterbuch*) a;
    const Woerterbuch *w2 = (const Woerterbuch*) b;
    return strcmp(w1->deutsch, w2->deutsch);
}

int compareEnglish(const void *a, const void *b) {
    const Woerterbuch *w1 = (const Woerterbuch*) a;
    const Woerterbuch *w2 = (const Woerterbuch*) b;
    return strcmp(w1->english, w2->english);
}

void wortschatz_hinzufuegen(Woerterbuch **liste, int *anzahl) {
    *liste = realloc(*liste, (*anzahl + 1) * sizeof(Woerterbuch));
    if (*liste == NULL) {
        printf("Speicher konnte nicht erweitert werden.\n");
        exit(1);
    }

    printf("Deutsch: ");
    fgets((*liste)[*anzahl].deutsch, MAX_WORT_LEN, stdin);
    strtok((*liste)[*anzahl].deutsch, "\n");

    printf("English: ");
    fgets((*liste)[*anzahl].english, MAX_WORT_LEN, stdin);
    strtok((*liste)[*anzahl].english, "\n");

    (*anzahl)++;
    printf("Wortschatz hinzugefuegt.\n");
}

void wortschatz_deutsch_sort_anzeigen(Woerterbuch *liste, int *anzahl) {
    if (*anzahl == 0) {
        printf("Das Woerterbuch ist leer.\n");
        return;
    }
    Woerterbuch *copy = malloc(sizeof(Woerterbuch) * (*anzahl));
    if (copy == NULL) {
        printf("Fehler beim Allozieren des Speichers.\n");
        return;
    }
    memcpy(copy, liste, sizeof(Woerterbuch) * (*anzahl));
    qsort(copy, *anzahl, sizeof(Woerterbuch), compareGerman);
    printf("\nWoerterbuch (Deutsch sortiert):\n");
    for (int i = 0; i < *anzahl; i++) {
        printf("%s - %s\n", copy[i].deutsch, copy[i].english);
    }
    free(copy);
}

void wortschatz_english_sort_anzeigen(Woerterbuch *liste, int *anzahl) {
    if (*anzahl == 0) {
        printf("Das Woerterbuch ist leer.\n");
        return;
    }
    Woerterbuch *copy = malloc(sizeof(Woerterbuch) * (*anzahl));
    if (copy == NULL) {
        printf("Fehler beim Allozieren des Speichers.\n");
        return;
    }
    memcpy(copy, liste, sizeof(Woerterbuch) * (*anzahl));
    qsort(copy, *anzahl, sizeof(Woerterbuch), compareEnglish);
    printf("\nWoerterbuch (Englisch sortiert):\n");
    for (int i = 0; i < *anzahl; i++) {
        printf("%s - %s\n", copy[i].deutsch, copy[i].english);
    }
    free(copy);
}

void wortschatz_loeschen(Woerterbuch **liste, int *anzahl) {
    int index;

    if (*anzahl == 0) {
        printf("Kein Wortschatz zum Loeschen vorhanden.\n");
        return;
    }

    for (int i = 0; i < *anzahl; i++) {
        printf("%d. %s - %s\n", i + 1, (*liste)[i].deutsch, (*liste)[i].english);
    }

    printf("Nummer des zu loeschenden Wortschatz: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > *anzahl) {
        printf("Ungueltige Nummer.\n");
        return;
    }

    for (int i = index - 1; i < *anzahl - 1; i++) {
        (*liste)[i] = (*liste)[i + 1];
    }

    (*anzahl)--;
    *liste = realloc(*liste, *anzahl * sizeof(Woerterbuch));
    printf("Wortschatz geloescht.\n");
}

void wortschatz_speichern(Woerterbuch *liste, int anzahl, const char *dateiname) {
    FILE *file = fopen(dateiname, "wb");
    if (file == NULL) {
        printf("Fehler beim oeffnen der Datei zum Speichern.\n");
        return;
    }

    fwrite(&anzahl, sizeof(int), 1, file);
    fwrite(liste, sizeof(Woerterbuch), anzahl, file);
    fclose(file);
}

void wortschatz_laden(Woerterbuch **liste, int *anzahl, const char *dateiname) {
    FILE *file = fopen(dateiname, "rb");
    if (file == NULL) {
        return; // Datei existiert noch nicht
    }

    fread(anzahl, sizeof(int), 1, file);
    *liste = malloc(*anzahl * sizeof(Woerterbuch));
    if (*liste == NULL) {
        printf("Fehler beim Laden der Daten.\n");
        exit(1);
    }

    fread(*liste, sizeof(Woerterbuch), *anzahl, file);
    fclose(file);
}