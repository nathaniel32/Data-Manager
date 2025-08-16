#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/aufgabe1.h"

void kontakt_hinzufuegen(Kontakt **liste, int *anzahl) {
    *liste = realloc(*liste, (*anzahl + 1) * sizeof(Kontakt));
    if (*liste == NULL) {
        printf("Speicher konnte nicht erweitert werden.\n");
        exit(1);
    }

    printf("Vorname: ");
    fgets((*liste)[*anzahl].vorname, MAX_NAME_LEN, stdin);
    strtok((*liste)[*anzahl].vorname, "\n");

    printf("Nachname: ");
    fgets((*liste)[*anzahl].nachname, MAX_NAME_LEN, stdin);
    strtok((*liste)[*anzahl].nachname, "\n");

    printf("Telefonnummer: ");
    fgets((*liste)[*anzahl].telefon, MAX_PHONE_LEN, stdin);
    strtok((*liste)[*anzahl].telefon, "\n");

    (*anzahl)++;
    printf("Kontakt hinzugefuegt.\n");
}

void kontakt_anzeigen(Kontakt *liste, int anzahl) {
    if (anzahl == 0) {
        printf("Keine Kontakte vorhanden.\n");
        return;
    }

    for (int i = 0; i < anzahl; i++) {
        printf("%d. %s %s\nTelefon: %s\n\n", i + 1, liste[i].vorname, liste[i].nachname, liste[i].telefon);
    }
}

void kontakt_suchen(Kontakt *liste, int anzahl) {
    char suchbegriff[MAX_PHONE_LEN];

    printf("Telefonnummer suchen: ");
    fgets(suchbegriff, MAX_PHONE_LEN, stdin);
    strtok(suchbegriff, "\n");

    for (int i = 0; i < anzahl; i++) {
        if (strcmp(liste[i].telefon, suchbegriff) == 0) {
            printf("Gefunden: %s %s\nTelefon: %s\n\n", liste[i].vorname, liste[i].nachname, liste[i].telefon);
            return;
        }
    }
    printf("Kein Kontakt mit dieser Telefonnummer gefunden.\n");
}

void kontakt_loeschen(Kontakt **liste, int *anzahl) {
    int index;

    if (*anzahl == 0) {
        printf("Keine Kontakte zum Loeschen vorhanden.\n");
        return;
    }

    kontakt_anzeigen(*liste, *anzahl);
    printf("Nummer des zu loeschenden Kontakts: ");
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
    *liste = realloc(*liste, *anzahl * sizeof(Kontakt));
    printf("Kontakt geloescht.\n");
}

void kontakt_speichern(Kontakt *liste, int anzahl, const char *dateiname) {
    FILE *file = fopen(dateiname, "wb");
    if (file == NULL) {
        printf("Fehler beim oeffnen der Datei zum Speichern.\n");
        return;
    }

    fwrite(&anzahl, sizeof(int), 1, file);
    fwrite(liste, sizeof(Kontakt), anzahl, file);
    fclose(file);
}

void kontakt_laden(Kontakt **liste, int *anzahl, const char *dateiname) {
    FILE *file = fopen(dateiname, "rb");
    if (file == NULL) {
        return; // Datei existiert noch nicht
    }

    fread(anzahl, sizeof(int), 1, file);
    *liste = malloc(*anzahl * sizeof(Kontakt));
    if (*liste == NULL) {
        printf("Fehler beim Laden der Daten.\n");
        exit(1);
    }

    fread(*liste, sizeof(Kontakt), *anzahl, file);
    fclose(file);
}

// ----------------------------------------------------------------------
/* 
void int_wahl(int *nr){
    scanf("%d", nr);
    getchar(); // Eingabepuffer leeren
}

int main() {
    int wahl;
    Kontakt *telefonbuch = NULL;
    int anzahl_kontakte = 0;
    const char *dateiname = "data/telefonbuch.dat";
    kontakt_laden(&telefonbuch, &anzahl_kontakte, dateiname);
    do {
        printf("\nElektronisches Telefonverzeichnis\n");
        printf("1. Kontakt hinzufuegen\n");
        printf("2. Kontakte anzeigen\n");
        printf("3. Kontakt suchen\n");
        printf("4. Kontakt loeschen\n");
        printf("5. Kontakt speichern und zueruck\n");
        printf("Ihre Wahl: ");
        int_wahl(&wahl);
        switch (wahl) {
            case 1:
                kontakt_hinzufuegen(&telefonbuch, &anzahl_kontakte);
                break;
            case 2:
                kontakt_anzeigen(telefonbuch, anzahl_kontakte);
                break;
            case 3:
                kontakt_suchen(telefonbuch, anzahl_kontakte);
                break;
            case 4:
                kontakt_loeschen(&telefonbuch, &anzahl_kontakte);
                break;
            case 5:
                kontakt_speichern(telefonbuch, anzahl_kontakte, dateiname);
                printf("Daten gespeichert.\n");
                break;
            default:
                printf("Ungueltige Wahl. Bitte erneut versuchen.\n");
        }
    } while (wahl != 5);
    free(telefonbuch);
    return 0;
} 
*/