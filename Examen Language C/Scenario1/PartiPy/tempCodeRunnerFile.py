import csv

def afficher_liste_equipements():
    with open('equipements.csv', 'r') as fichier:
        lecteur_csv = csv.reader(fichier)
        
        # Affichage de l'en-tête
        print("Liste des équipements :")
        print("-----------------------")
        
        # Affichage des équipements un par un
        for equipement in lecteur_csv:
            print(f"Numéro de série : {equipement[0]}")
            print(f"Marque         : {equipement[1]}")
            print(f"Modèle         : {equipement[2]}")
            print(f"Année          : {equipement[3]}")
            print("-----------------------")

# Programme principal
print("Bienvenue dans l'application de gestion des équipements !")
print()

while True:
    print("Menu :")
    print("1. Afficher la liste des équipements")
    print("2. Quitter")
    
    choix = input("Votre choix : ")
    
    if choix == "1":
        print()
        afficher_liste_equipements()
        print()
    elif choix == "2":
        print("Merci d'avoir utilisé notre application. Au revoir !")
        break
    else:
        print("Choix invalide. Veuillez réessayer.")
        print()
