#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/aufgabe1.h"
#include "../include/aufgabe2.h"
#include "../include/aufgabe3.h"

void int_wahl(int *nr){
    scanf("%d", nr);
    getchar(); // Eingabepuffer leeren
}

int main() {
    int wahl;

    do {
        printf("\nMenu\n");
        printf("1. Aufgabe1\n");
        printf("2. Aufgabe2\n");
        printf("3. Aufgabe3\n");
        printf("4. Beenden\n");
        printf("Ihre Wahl: ");
        int_wahl(&wahl);
        switch (wahl) {
            case 1:
                Kontakt *telefonbuch = NULL;
                int anzahl_kontakte = 0;
                const char *kontakt_dateiname = "data/telefonbuch.dat";
                kontakt_laden(&telefonbuch, &anzahl_kontakte, kontakt_dateiname);
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
                            kontakt_speichern(telefonbuch, anzahl_kontakte, kontakt_dateiname);
                            printf("Daten gespeichert.\n");
                            break;
                        default:
                            printf("Ungueltige Wahl. Bitte erneut versuchen.\n");
                    }
                } while (wahl != 5);
                free(telefonbuch);
                break;
            case 2:
                Material *materialien = NULL;
                int anzahl_material = 0;
                const char *material_dateiname = "data/materialverwaltung.dat";
                material_laden(&materialien, &anzahl_material, material_dateiname);
                do {
                    printf("\nMaterialverwaltung\n");
                    printf("1. Material hinzufuegen\n");
                    printf("2. Lagerbestand Zugang\n");
                    printf("3. Lagerbestand Abgang\n");
                    printf("4. Materialien anzeigen\n");
                    printf("5. Material loeschen\n");
                    printf("6. Material speichern und zueruck\n");
                    printf("Ihre Wahl: ");
                    int_wahl(&wahl);
                    switch (wahl) {
                        case 1:
                            material_hinzufuegen(&materialien, &anzahl_material);
                            break;
                        case 2:
                            material_zugang(materialien, &anzahl_material);
                            break;
                        case 3:
                            material_abgang(materialien, &anzahl_material);
                            break;
                        case 4:
                            material_anzeigen(materialien, anzahl_material);
                            break;
                        case 5:
                            material_loeschen(materialien, &anzahl_material);
                            break;
                        case 6:
                            material_speichern(materialien, anzahl_material, material_dateiname);
                            printf("Daten gespeichert.\n");
                            break;
                        default:
                            printf("Ungueltige Wahl. Bitte erneut versuchen.\n");
                    }
                } while (wahl != 6);
                free(materialien);
                break;
            case 3:
                Woerterbuch *wortschatz = NULL;
                int anzahl_wortschatz = 0;
                const char *woerterbuch_dateiname = "data/woerterbuch.dat";
                wortschatz_laden(&wortschatz, &anzahl_wortschatz, woerterbuch_dateiname);
                do {
                    printf("\nWoerterbuch\n");
                    printf("1. Wortschatz hinzufuegen\n");
                    printf("2. Liste auf Deutsch sortiert anzeigen\n");
                    printf("3. Liste auf Englisch sortiert anzeigen\n");
                    printf("4. Wortschatz loeschen\n");
                    printf("5. Wortschatz speichern und zueruck\n");
                    printf("Ihre Wahl: ");
                    int_wahl(&wahl);
                    switch (wahl) {
                        case 1:
                            wortschatz_hinzufuegen(&wortschatz, &anzahl_wortschatz);
                            break;
                        case 2:
                            wortschatz_deutsch_sort_anzeigen(wortschatz, &anzahl_wortschatz);
                            break;
                        case 3:
                            wortschatz_english_sort_anzeigen(wortschatz, &anzahl_wortschatz);
                            break;
                        case 4:
                            wortschatz_loeschen(&wortschatz, &anzahl_wortschatz);
                            break;
                        case 5:
                            wortschatz_speichern(wortschatz, anzahl_wortschatz, woerterbuch_dateiname);
                            printf("Daten gespeichert.\n");
                            break;
                        default:
                            printf("Ungueltige Wahl. Bitte erneut versuchen.\n");
                    }
                } while (wahl != 5);
                free(wortschatz);
                break;
            case 4:
                break;
            default:
                printf("Ungueltige Wahl. Bitte erneut versuchen.\n");
        }
    } while (wahl != 4);
    return 0;
}