#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int jour;
    int mois;
    int annee;
} dateTaches;

typedef struct {
    char nomTach[50];
    char desTach[50];
    dateTaches date;
} taches;

int taille = 0;
taches tache1[1000];

void ajouterTache() {
    if (taille < 1000) {
        printf("ENTREZ LE NOM DE VOTRE TACHE : ");

        getchar();
        fgets(tache1[taille].nomTach,sizeof(tache1[taille].nomTach),stdin);

        printf("ENTREZ LA DESCRIPTION DE VOTRE TACHE : ");
        getchar();
        fgets(tache1[taille].desTach, sizeof(tache1[taille].desTach), stdin);


        printf("ENTREZ LE JOUR DE VOTRE TACHE : ");
        scanf("%d", &tache1[taille].date.jour);

        printf("ENTREZ LE MOIS DE VOTRE TACHE : ");
        scanf("%d", &tache1[taille].date.mois); 

        printf("ENTREZ L'ANNEE DE VOTRE TACHE : ");
        scanf("%d", &tache1[taille].date.annee);

        taille++;
        printf("Tache ajoutee avec succes!\n");
    } else {
        printf("La liste des taches est pleine. Impossible d'ajouter plus de taches.\n");
    }
}


void menu() {
    int choice;
    do {
        printf("\n \n \n ");
        printf("Hello, Welcome to My TasksNote 👍\n\n");
        printf(" - 1 Ajouter une Tache : \n");
        printf(" - 2 Afficher la Liste des Taches :  \n");
        printf(" - 3 Modifier une Tache :  \n");
        printf(" - 4 Supprimer une Tache :  \n");
        printf(" - 5 Ordonner les Taches:  \n");
        printf(" - 6 Filtrer les Taches : \n");
        printf(" - 0 Quitter\n");
        printf("\n\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            ajouterTache();
            break;
        case 2:
            /* afficherTache(); */
            break;
        case 3:
            /* modifierTache(); */
            break;
        case 4:
            /* supprimerTache(); */
            break;
        case 5:
            /* ordonnerTache(); */
            break;
        case 6:
            /* filtrerTache(); */
            break;
        default:
            printf("Choix invalide. Veuillez entrer un nombre entre 0 et 6.\n");
        }
    } while (choice != 0);
}



/* void checkUser() {
    char name[7];
    int password;
    printf("\n");
    printf("For testing this project, enter your name and password!\n");
    printf("USERNAME :");
    scanf("%s", name);

    printf("PASSWORD: ");
    scanf("%d", &password);

    if (strcmp(name, "oussama") != 0 || password != 971414) {
        printf("Invalid username or password. Please try again.\n");
        checkUser();
    } else {
        menu();
    }
} */


int main() {
    menu();
    /* checkUser(); */
    return 0;
}
