#include <stdio.h>
#include "equipement.h"

int main() {
    int choix = 0;
    
    while (choix != 5) {
        afficherMenu();
        scanf("%d", &choix);
        getchar(); // Pour vider le tampon d'entrée
        
        switch (choix) {
            case 1:
                ajouterEquipement();
                break;
            case 2:
                supprimerEquipement();
                break;
            case 3:
                modifierEquipement();
                break;
            case 4:
                afficherListeEquipements();
                break;
            case 5:
                sauvegarderEquipements();
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}
