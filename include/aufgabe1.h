#ifndef AUFGABE1_H
#define AUFGABE1_H
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15

// Struktur für einen Datensatz im Telefonverzeichnis
typedef struct {
    char vorname[MAX_NAME_LEN];
    char nachname[MAX_NAME_LEN];
    char telefon[MAX_PHONE_LEN];
} Kontakt;

// Prototypen für Funktionen
void kontakt_hinzufuegen(Kontakt **liste, int *anzahl);
void kontakt_anzeigen(Kontakt *liste, int anzahl);
void kontakt_suchen(Kontakt *liste, int anzahl);
void kontakt_loeschen(Kontakt **liste, int *anzahl);
void kontakt_speichern(Kontakt *liste, int anzahl, const char *dateiname);
void kontakt_laden(Kontakt **liste, int *anzahl, const char *dateiname);

#endif