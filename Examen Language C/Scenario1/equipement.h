#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

typedef struct {
    char numeroSerie[20];
    char marque[50];
    char modele[50];
    int annee;
} Equipement;

void afficherMenu();
void ajouterEquipement();
void supprimerEquipement();
void modifierEquipement();
void afficherListeEquipements();

#endif
