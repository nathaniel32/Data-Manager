#ifndef AUFGABE2_H
#define AUFGABE2_H
#define MAX_BEZEICHNUNG_LEN 50

typedef struct {
    int artikelnummer;
    char bezeichnung[MAX_BEZEICHNUNG_LEN];
    int lagerbestand;
} Material;

// Prototypen für Funktionen
void material_hinzufuegen(Material **liste, int *anzahl);
void material_zugang(Material *liste, int *anzahl);
void material_abgang(Material *liste, int *anzahl);
void material_anzeigen(Material *liste, int anzahl);
void material_loeschen(Material *liste, int *anzahl);
void material_speichern(Material *liste, int anzahl, const char *dateiname);
void material_laden(Material **liste, int *anzahl, const char *dateiname);

#endif