#include <stdio.h>
#include "equipement.h"
#include <string.h>
#define MAX_EQUIPEMENTS 100

Equipement listeEquipements[MAX_EQUIPEMENTS];
int nombreEquipements = 0;

void afficherMenu() {
    printf("----- Gestion des équipements -----\n");
    printf("1. Ajouter un équipement\n");
    printf("2. Supprimer un équipement\n");
    printf("3. Modifier un équipement\n");
    printf("4. Afficher la liste des équipements\n");
    printf("5. Quitter\n");
    printf("Choix : ");
}

void ajouterEquipement() {
    if (nombreEquipements == MAX_EQUIPEMENTS) {
        printf("La liste des équipements est pleine.\n");
        return;
    }
    
    Equipement nouvelEquipement;
    printf("Numéro de série : ");
    scanf("%s", nouvelEquipement.numeroSerie);
    printf("Marque : ");
    scanf("%s", nouvelEquipement.marque);
    printf("Modèle : ");
    scanf("%s", nouvelEquipement.modele);
    printf("Année : ");
    scanf("%d", &nouvelEquipement.annee);
    
    listeEquipements[nombreEquipements++] = nouvelEquipement;
    
    printf("Equipement ajouté avec succès.\n");
}

void supprimerEquipement() {
    char numeroSerie[20];
    printf("Entrez le numéro de série de l'équipement à supprimer : ");
    scanf("%s", numeroSerie);
    
    int i;
    for (i = 0; i < nombreEquipements; i++) {
        if (strcmp(listeEquipements[i].numeroSerie, numeroSerie) == 0) {
            int j;
            for (j = i; j < nombreEquipements - 1; j++) {
                listeEquipements[j] = listeEquipements[j + 1];
            }
            nombreEquipements--;
            printf("Equipement supprimé avec succès.\n");
            return;
        }
    }
    
    printf("Equipement introuvable.\n");
}

void modifierEquipement() {
    char numeroSerie[20];
    printf("Entrez le numéro de série de l'équipement à modifier : ");
    scanf("%s", numeroSerie);
    // Demande à l'utilisateur d'entrer le numéro de série de l'équipement à modifier et le stocke dans la variable 'numeroSerie'
    
    int i;
    for (i = 0; i < nombreEquipements; i++) {
        // Parcours de chaque équipement dans la liste
        
        if (strcmp(listeEquipements[i].numeroSerie, numeroSerie) == 0) {
            // Vérifie si le numéro de série de l'équipement courant correspond à celui saisi par l'utilisateur
            
            printf("Numéro de série : ");
            scanf("%s", listeEquipements[i].numeroSerie);
            // Demande à l'utilisateur de saisir le nouveau numéro de série de l'équipement et le met à jour dans la liste
            
            printf("Marque : ");
            scanf("%s", listeEquipements[i].marque);
            // Demande à l'utilisateur de saisir la nouvelle marque de l'équipement et la met à jour dans la liste
            
            printf("Modèle : ");
            scanf("%s", listeEquipements[i].modele);
            // Demande à l'utilisateur de saisir le nouveau modèle de l'équipement et le met à jour dans la liste
            
            printf("Année : ");
            scanf("%d", &listeEquipements[i].annee);
            // Demande à l'utilisateur de saisir la nouvelle année de l'équipement et la met à jour dans la liste
            
            printf("Equipement modifié avec succès.\n");
            // Affiche un message de confirmation de la modification
            
            return;
        }
    }
    
    printf("Equipement introuvable.\n");
    // Si aucun équipement correspondant au numéro de série saisi n'est trouvé, affiche un message d'erreur
}

void afficherListeEquipements() {
    int i;
    printf("Liste des équipements :\n");
    for (i = 0; i < nombreEquipements; i++) {
        printf("Numéro de série : %s\n", listeEquipements[i].numeroSerie);
        printf("Marque : %s\n", listeEquipements[i].marque);
        printf("Modèle : %s\n", listeEquipements[i].modele);
        printf("Année : %d\n\n", listeEquipements[i].annee);
    }
}

// Sauvegarde les équipements dans un fichier CSV
void sauvegarderEquipements() {
    FILE *fichier = fopen("equipements.csv", "r");
    // Tentative d'ouverture du fichier "equipements.csv" en mode lecture
    
    if (fichier == NULL) {
        // Le fichier n'existe pas, on le crée en mode écriture
        fichier = fopen("equipements.csv", "w");
        if (fichier == NULL) {
            printf("Erreur lors de la création du fichier.\n");
            return;
        }
        
        // Écriture de l'en-tête du fichier CSV
        fprintf(fichier, "Numéro de série,Marque,Modèle,Année\n");
        
        // Fermeture du fichier
        fclose(fichier);
    } else {
        // Le fichier existe déjà, on le réouvre en mode écriture en le vidant
        fclose(fichier);
        fichier = fopen("equipements.csv", "w");
        if (fichier == NULL) {
            printf("Erreur lors de l'ouverture du fichier.\n");
            return;
        }
        
        // Écriture de l'en-tête du fichier CSV
        fprintf(fichier, "Numéro de série,Marque,Modèle,Année\n");
        
        // Fermeture du fichier
        fclose(fichier);
    }
    
    // Ouvrir le fichier en mode append (ajout) pour écrire les équipements
    fichier = fopen("equipements.csv", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    
    // Écriture des équipements dans le fichier CSV
    for (int i = 0; i < nombreEquipements; i++) {
        fprintf(fichier, "%s,%s,%s,%d\n", listeEquipements[i].numeroSerie, listeEquipements[i].marque, listeEquipements[i].modele, listeEquipements[i].annee);
    }
    
    // Fermeture du fichier
    fclose(fichier);
    
    printf("Equipements sauvegardés avec succès dans le fichier equipements.csv.\n");
}