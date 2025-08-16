#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/aufgabe2.h"

void material_hinzufuegen(Material **liste, int *anzahl) {
    *liste = realloc(*liste, (*anzahl + 1) * sizeof(Material));
    if (*liste == NULL) {
        printf("Speicher konnte nicht erweitert werden.\n");
        exit(1);
    }

    printf("Artikelnummer: ");
    scanf("%d", &(*liste)[*anzahl].artikelnummer);
    getchar();

    printf("Artikelbezeichnung: ");
    fgets((*liste)[*anzahl].bezeichnung, MAX_BEZEICHNUNG_LEN, stdin);
    strtok((*liste)[*anzahl].bezeichnung, "\n");

    printf("Lagerbestand: ");
    scanf("%d", &(*liste)[*anzahl].lagerbestand);
    getchar();

    (*anzahl)++;
    printf("Material hinzugefuegt.\n");
}

void material_anzeigen(Material *liste, int anzahl) {
    if (anzahl == 0) {
        printf("Keine Material vorhanden.\n");
        return;
    }

    for (int i = 0; i < anzahl; i++) {
        printf("Artikelnummer\t\t: %d\nArtikelbezeichnung\t: %s\nLagerbestand\t\t: %d\n\n", liste[i].artikelnummer, liste[i].bezeichnung, liste[i].lagerbestand);
    }
}

void material_loeschen(Material *liste, int *anzahl) {
    int artikelnummer;

    if (*anzahl == 0) {
        printf("Keine Materialien zum Loeschen vorhanden.\n");
        return;
    }

    material_anzeigen(liste, *anzahl);
    printf("Nummer des zu loeschenden Materials: ");
    scanf("%d", &artikelnummer);
    getchar();

    for (int i = 0; i < *anzahl; i++) {
        if (liste[i].artikelnummer == artikelnummer) {
            printf("Artikelnummer\t\t: %d\nArtikelbezeichnung\t: %s\nLagerbestand\t\t: %d\n\n", liste[i].artikelnummer, liste[i].bezeichnung, liste[i].lagerbestand);

            for (int j = i; j < *anzahl - 1; j++) {
                liste[j] = liste[j + 1];
            }
            (*anzahl)--;
            printf("Material geloescht.\n");
            return;
        }
    }
    printf("Kein Material mit dieser Artikelnummer gefunden.\n");
}

void material_zugang(Material *liste, int *anzahl) {
    int artikelnummer, menge;

    if (*anzahl == 0) {
        printf("Keine Materialien vorhanden.\n");
        return;
    }

    material_anzeigen(liste, *anzahl);
    printf("Artikelnummer des Materials: ");
    scanf("%d", &artikelnummer);
    printf("Menge zum Hinzufuegen: ");
    scanf("%d", &menge);

    for (int i = 0; i < *anzahl; i++) {
        if (liste[i].artikelnummer == artikelnummer) {
            liste[i].lagerbestand += menge; // Lagerbestand erhöhen
            printf("Neuer Lagerbestand von '%s': %d\n", liste[i].bezeichnung, liste[i].lagerbestand);
            return;
        }
    }

    printf("Material mit Artikelnummer %d nicht gefunden.\n", artikelnummer);
}

void material_abgang(Material *liste, int *anzahl) {
    int artikelnummer, menge;

    if (*anzahl == 0) {
        printf("Keine Materialien vorhanden.\n");
        return;
    }

    material_anzeigen(liste, *anzahl);
    printf("Artikelnummer des Materials: ");
    scanf("%d", &artikelnummer);
    printf("Menge zum Entfernen: ");
    scanf("%d", &menge);

    for (int i = 0; i < *anzahl; i++) {
        if (liste[i].artikelnummer == artikelnummer) {
            if (liste[i].lagerbestand >= menge) {
                liste[i].lagerbestand -= menge; // Lagerbestand verringern
                printf("Neuer Lagerbestand von '%s': %d\n", liste[i].bezeichnung, liste[i].lagerbestand);
            } else {
                printf("Fehler: Nicht genug Lagerbestand von '%s' (Verfügbar: %d, Angeforderte Menge: %d).\n",
                       liste[i].bezeichnung, liste[i].lagerbestand, menge);
            }
            return;
        }
    }

    printf("Material mit Artikelnummer %d nicht gefunden.\n", artikelnummer);
}

void material_speichern(Material *liste, int anzahl, const char *dateiname) {
    FILE *file = fopen(dateiname, "wb");
    if (file == NULL) {
        printf("Fehler beim oeffnen der Datei zum Speichern.\n");
        return;
    }

    fwrite(&anzahl, sizeof(int), 1, file);
    fwrite(liste, sizeof(Material), anzahl, file);
    fclose(file);
}

void material_laden(Material **liste, int *anzahl, const char *dateiname) {
    FILE *file = fopen(dateiname, "rb");
    if (file == NULL) {
        return; // Datei existiert noch nicht
    }

    fread(anzahl, sizeof(int), 1, file);
    *liste = malloc(*anzahl * sizeof(Material));
    if (*liste == NULL) {
        printf("Fehler beim Laden der Daten.\n");
        exit(1);
    }

    fread(*liste, sizeof(Material), *anzahl, file);
    fclose(file);
}