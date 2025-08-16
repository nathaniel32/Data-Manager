#include "../include/utils.h"
#include <stdio.h>

#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

void make_dir(const char *folder) {
    #ifdef _WIN32
        if (_mkdir(folder) == 0) {
            printf("Ordner '%s' wurde erfolgreich erstellt.\n", folder);
        } else {
            perror("Ordner konnte nicht erstellt werden oder ist bereits vorhanden");
        }
    #else
        if (mkdir(folder, 0777) == 0) {
            printf("Ordner '%s' wurde erfolgreich erstellt.\n", folder);
        } else {
            perror("Ordner konnte nicht erstellt werden oder ist bereits vorhanden");
        }
    #endif
}

void int_wahl(int *nr){
    scanf("%d", nr);
    getchar(); // Eingabepuffer leeren
}