#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char important_[20] = "IMPORTANT";
char pasImportant_[20] = "PAS IMPORTANT";

typedef struct {
    char priorite[20];
} important;

typedef struct {
    int jour;
    int mois;
    int annee;
} tache_date;

typedef struct {
    char tache_name[15];
    char tache_des[50];
    tache_date date;
    important pre;
} taches;

taches tache1[1000];
int taille = 0;


void ajoutee() {
    if (taille < 1000) {
        printf("ENTRER LE NOM DE VOTRE TACHE :");
        getchar();
        fgets(tache1[taille].tache_name, sizeof(tache1[taille].tache_name), stdin);
        printf("ENTER LA DESCRIPTOIN DE VOTRE TACHE :");
        fgets(tache1[taille].tache_des, sizeof(tache1[taille].tache_des), stdin);
        printf("ENTRER LE JOUR : ");
        scanf("%d", &tache1[taille].date.jour);
        printf("ENTRER LE MOIS : ");
        scanf("%d", &tache1[taille].date.mois);
        printf("ENTRER L'ANNEE : ");
        scanf("%d", &tache1[taille].date.annee);
        
            int choice;
        printf("-----EST-CE QUE CETTE TACHE EST IMPORTANTE OU PAS IMPORTANTE ?----- \n\n");
        printf("- 1 - CETTE TACHE EST IMPORTANTE ! :\n");
        printf("- 2 - CETTE TACHE N'EST PAS IMPORTANTE ! :\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(tache1[taille].pre.priorite, important_);
                break;
            case 2:
                strcpy(tache1[taille].pre.priorite, pasImportant_);
                break;
            default:
                printf("ENTREZ UN NOMBER ENTER 1 ET 2 !\n");
            }

        taille++;
        printf("LA TACHE AJOUTEE ------ > SECCUS!\n");
    } else {
        printf("LA LISTE DES TACHES EST PLANIEN !!");
    }
}

void afficher() {
    if (taille > 0) {
        for (int i = 0; i < taille; i++) {
            printf("\n---------------------\n");
            printf("\nTACHE NUMERO - %d  \n\n", i + 1);
            printf("CETTE TACHE EST ---> %s\n\n", tache1[i].pre.priorite);
            printf("LE NOME DE VOTRE TACHE EST : %s \n", tache1[i].tache_name);
            printf("LA DESCRIPTION DE VOTRE TACHE EST : %s \n", tache1[i].tache_des);
            printf("LA DATE DE VOTRE TACHE EST : JOUR %d / MOIS %d / ANNEE %d \n", tache1[i].date.jour, tache1[i].date.mois, tache1[i].date.annee);
            printf("\n---------------------\n");
        }
    } else {
        printf("\nLA LISTE DES TACHES EST VIDE !!\n");
    }
}

void supprimerTache() {
    if (taille > 0) {
        int index;
        printf("ENTREZ NOMBER ENTER 1 ET  %d: ", taille);
        scanf("%d", &index);

        if (index >= 1 && index <= taille) {
            for (int i = index - 1; i < taille - 1; i++) {
                tache1[i] = tache1[i + 1];
            }
            taille--;
            printf("LA TACHE SUPPRIMEE ------- >  SUCCES!\n");
        } else {
            printf("NUMERO DE TACHE INVALIDE !.\n");
        }
    } else {
        printf("AUCUNE TACHE. IMPOSSIBLE D'AJOUTEE\n");
    }
}

void modifierTache() {
    if (taille > 0) {
        int index;
        printf("ENTREZ UN NOMBER ENTER 1 ET %d POUR MODIFIER !: ", taille);
        scanf("%d", &index);

        if (index >= 1 && index <= taille) {
            printf("ENTREZ LE NOUVEAU NOM DE VOTRE TACHE : ");
            scanf("%s", tache1[index - 1].tache_name);

            printf("ENTREZ LA NOUVELLE DESCRIPTION DE VOTRE TACHE : ");
            scanf("%s", tache1[index - 1].tache_des);

            printf("ENTREZ LE NOUVEAU JOUR DE VOTRE TACHE : ");
            scanf("%d", &tache1[index - 1].date.jour);

            printf("ENTREZ LE NOUVEAU MOIS DE VOTRE TACHE : ");
            scanf("%d", &tache1[index - 1].date.mois);

            printf("ENTREZ LA NOUVELLE ANNEE DE VOTRE TACHE : ");
            scanf("%d", &tache1[index - 1].date.annee);

            int choice;
                printf("-----EST-CE QUE CETTE NOUVEAU TACHE EST IMPORTANTE OU PAS IMPORTANTE ?----- \n\n");
                printf("- 1 - CETTE TACHE EST IMPORTANTE ! :\n");
                printf("- 2 - CETTE TACHE N'EST PAS IMPORTANTE ! :\n");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        strcpy(tache1[index - 1].pre.priorite, important_);
                    break;
                    case 2:
                        strcpy(tache1[index - 1].pre.priorite, pasImportant_);
                    break;
                    default:
                    printf("ENTREZ UN NOMBER ENTER 1 ET 2 !\n");
            }

            printf("LA TACHE MODIFIEE ---------- > SUCCES!\n");
        } else {
            printf("NUMERO DE TACHE INVALIDE !!.\n");
        }
    } else {
        printf("AUCUNE TACHE. IMPOSSIBLE DE MODIFIER.\n");
    }
}

void ordonnerTache() {
    if (taille > 0) {
        
        for (int i = 0; i < taille - 1; i++) {

            for (int j = 0; j < taille - i - 1; j++) {
                
                if (tache1[j].date.annee > tache1[j + 1].date.annee ||
                    (tache1[j].date.annee == tache1[j + 1].date.annee
                    &&
                    tache1[j].date.mois > tache1[j + 1].date.mois) ||
                    (tache1[j].date.annee == tache1[j + 1].date.annee
                    &&
                     tache1[j].date.mois == tache1[j + 1].date.mois
                    &&
                     tache1[j].date.jour > tache1[j + 1].date.jour)) {
                    
                    taches temp = tache1[j];
                    tache1[j] = tache1[j + 1];
                    tache1[j + 1] = temp;
                }
            }
        }

        printf("LA TACHE ORDONNER --------- > SUCCES!\n");
    } else {
        printf(" IMPOSSIBLE D'ORDONNER.\n");
    }
};

void filtrer() {
    int choice;
    char filterChoice[20];
    int annee;
    int mois;
    printf("TU VOUDRAIS FILTRER PAR DATE OU PAR PRIORITE !\n\n");
    printf("---- > PAR PRIORITE ENTRER 1 ! :\n\n");
    printf("---- > PAR DATE ENTRER 2 ! :\n\n");
    printf("ENTER TON CHOIX ! :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("ENTREZ LE MOT FILTER (IMPORTANT ou PAS IMPORTANT) : ");
         scanf("%s", filterChoice);

         printf("TACHES FILTREES :\n");
            for (int i = 0; i < taille; i++) {
             if (strcmp(tache1[i].pre.priorite, filterChoice) == 0) {
            printf("\n---------------------\n");
            printf("TACHE NUMERO - %d  \n", i + 1);
            printf("CETTE TACHE EST ---> %s\n", tache1[i].pre.priorite);
            printf("LE NOME DE VOTRE TACHE EST : %s \n\n", tache1[i].tache_name);
            printf("LA DESCRIPTION DE VOTRE TACHE EST : %s \n\n", tache1[i].tache_des);
            printf("LA DATE DE VOTRE TACHE EST : JOUR %d / MOIS %d / ANNEE %d \n\n", tache1[i].date.jour, tache1[i].date.mois, tache1[i].date.annee);
            printf("\n---------------------\n");
        }
            }
        break;
    case 2:
            printf("ENTER L'ANNEE !");
            scanf("%d", &annee);
            printf("ENTRER LE MOIS !");
            scanf("%d", &mois);
    
            printf("TACHES FILTREES :\n");
            for (int i = 0; i < taille; i++) {
             if (tache1[i].date.annee == annee && tache1[i].date.mois == mois) {
            printf("\n---------------------\n");
            printf("TACHE NUMERO - %d  \n", i + 1);
            printf("CETTE TACHE EST ---> %s\n", tache1[i].pre.priorite);
            printf("LE NOME DE VOTRE TACHE EST : %s \n\n", tache1[i].tache_name);
            printf("LA DESCRIPTION DE VOTRE TACHE EST : %s \n\n", tache1[i].tache_des);
            printf("LA DATE DE VOTRE TACHE EST : JOUR %d / MOIS %d / ANNEE %d \n\n", tache1[i].date.jour, tache1[i].date.mois, tache1[i].date.annee);
            printf("\n---------------------\n");
        }else{
            printf("ENTRER LA DATE ET MOIS !!");
        }
            }
            
         break;
    default:
        printf("ENTRER NUMERO ENTER 1 ET 2 !");
        break;
    }

}

void menu() {
    int choice;
    do {
        printf("    \n< ---------- LA LISTE PRINCIPALE -------- >\n\n\n");
        printf("- 1 - AJOUTER UNE TACHE !\n");
        printf("- 2 - AFFICHER LES TACHES !\n");
        printf("- 3 - SUPPREMIR UNE TACHE !\n");
        printf("- 4 - MODIFIER UNE TACHE !\n");
        printf("- 5 - ORDONNER LES TACHES !\n");
        printf("- 6 - FILTRER LES TACHES ! \n\n");
        printf("ENTREZ VOTRE CHOIX (0 POUR QUITTER !) : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ajoutee();
                break;
            case 2:
                afficher();
                break;
            case 3:
                supprimerTache();
                break;
            case 4:
                modifierTache();
                break;
            case 5 :
                ordonnerTache();
                break; 
            case 6:
                filtrer();
                break;
            default:
                break;
        }
    } while (choice != 0);
}
 void checkUser() {
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
} 


int main() {
    checkUser();
    return 0;
}
