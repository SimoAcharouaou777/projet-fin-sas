#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
// projet fin de sas
time_t current_time;
struct tm *time_info;
int count = 0; //pour calculer combien des tach lutilisaueur ajouter ou supprime
int s=0; // pour calculer combien des tach finallese
int z=0; // pour calculer combien des tach non finalese ( en cors de realisation est pour realise)
void menu(void)
{
    printf(" ___________________________________________________________________________________________________________\n");
    printf(" |                               M E N U                                                                    |\n");
    printf(" | [1]_ajouter un nouvell tach                                                                              |\n");
    printf(" | [2]_Ajouter plusieurs nouvelles tâches.                                                                  |\n");
    printf(" | [3]_Afficher la liste de toutes les tâches (Identifiant, Titre, Description, Deadline, Statut)           |\n");
    printf(" | [4]_Modifier une tâche                                                                                   |\n");
    printf(" | [5]_Supprimer une tâche par identifiant                                                                  |\n");
    printf(" | [6]_Rechercher les Tâches                                                                                |\n");
    printf(" | [7]_Statistiques                                                                                         |\n");
    printf(" | [0]_exite                                                                                                |\n");
    printf(" |__________________________________________________________________________________________________________|\n");
}
void NouvellTach(void)
{
    printf("________________________\n");
    printf("|[1]    To do           | \n");
    printf("|[2]    Doing           | \n");
    printf("|[3]    Done            | \n");
    printf("|-----------------------|\n");
}
void AffichLalist(void)
{
    printf("[1]_Trier les tâches par ordre alphabétique \n");
    printf("[2]_Trier les tâches par deadline\n");
    printf("[3]_Afficher les tâches dont le deadline est dans 3 jours ou moins\n");
}
void ModifieTach(void)
{
    printf("[1]_Modifier la description dune tâche \n");
    printf("[2]_Modifier le statut dune tâche \n");
    printf("[3]_Modifier le deadline dune tâche. \n");
}
void Recherch(void)
{
    printf("[1]_Rechercher une tâche par son Identifiant\n");
    printf("[2]_Rechercher une tâche par son Titre\n");
}
void Statistiques(void)
{
    printf("[1]_Afficher le nombre total des tâches\n");
    printf("[2]_Afficher le nombre de tâches complètes et incomplètes\n");
    printf("[3]_Afficher le nombre de jours restants jusqu'au délai de chaque tâche\n");
}

struct Tach // pour stocker les information de chaque tach
{ // struct begin
    char title[30];
    char description[100];
    char status[100];
    int jour, mois, anne;
    int id;

}; // struct end
int main()
{ // main begin
    struct Tach tach[100]; // ici, nous avons appele la fucntion pour travailler avec ell a linterieur de main
    int choix; // pour stocker les choix de lutilisateur
    int NumberTach, i, j; // ona declater 3 varible le premier pour savoir combien de taches lutilisateur souhaite saisir est le dernier deux pour les boukles
    char newdesc[200]; // cett variable pour stocker le nouveau description
    int newid; // nous aurons besoin de cette variable lorsque nous demanderons a lutilisateur de saisir l id de sa tache
    char newtitle[40]; // le meme chose pour cett variable
    int Newjour, Newmois, Newanne; // nous aurons besoin de cette variable lorsque lutilisateur souhaite changer la date
    struct Tach temp; //voici la meme function que nous avons creer
    time(&current_time);
    time_info = localtime(&current_time);
    int day = time_info->tm_mday;
    int month = time_info->tm_mon + 1;
    int year = time_info->tm_year + 1900;
    int date = day + (month * 30) + (year * 365);

    do
    { // do while begin
        menu();
        printf("sélectionner un numéro : ");
        scanf("%d", &choix); //choix
        switch (choix) //choix
        { // switch begin
        case 1:
            printf("enter your tach id : ");
            scanf("%d", &tach[count].id);
            printf("entre le nom de tach :  ");
            scanf("%s", tach[count].title);
            printf("entrer le description : ");
            scanf(" %[^\n]s", tach[count].description);
            printf("entrer le date jour mois anne :");
            scanf("%d %d %d", &tach[count].jour, &tach[count].mois, &tach[count].anne);
            printf("when do you wanna put it \n");
            NouvellTach();
            scanf("%d", &choix); //choix1
            switch (choix) //choix1
            {
            case 1:
                strcpy(tach[count].status, "To do"); // strcpy pour copier les strings seulement
                printf("the transformation went succesfuly \n");
                break;
            case 2:
                strcpy(tach[count].status, "Doing");
                printf("the transformation went succesfuly \n");
                break;
            case 3:
                strcpy(tach[count].status, "Done");
                printf("the transformation went succesfuly \n");
                break;
            }
            count++;
            break;

        case 2:
            printf("how many tach you wanna add ? \n");
            scanf("%d", &NumberTach);
            for (i = 1; i <= NumberTach; i++)
            {
                printf("enter the id of your tach : ");
                scanf("%d", &tach[count].id);
                printf("entre le nom de tach %d \n", i);
                scanf("%s", tach[count].title);
                printf("entrer le description de tach %d \n", i);
                scanf(" %[^\n]s", tach[count].description);
                printf("entrer le date (jour mois anne) de tach %d \n", i);
                scanf("%d %d %d", &tach[count].jour, &tach[count].mois, &tach[count].anne);
                printf("when do you wanna put your %d tach  \n", i);
                NouvellTach();
                scanf("%d", &choix); //choix1
                switch (choix) //choix1
                {
                case 1:
                    strcpy(tach[count].status, "To do");
                    printf("the transformation went succesfuly \n");
                    break;
                case 2:
                    strcpy(tach[count].status, "Doing");
                    printf("the transformation went succesfuly \n");
                    break;
                case 3:
                    strcpy(tach[count].status, "Done");
                    printf("the transformation went succesfuly \n");
                    break;
                }
                count++;
            } // for loop end
            break;
        case 3:
            AffichLalist();
            printf("_____________selectionner un numero : ");
            scanf("%d", &choix); //choix2
            switch (choix) //CHOIX2
            {
            case 1:
                for (i = 0; i < count; i++)
                {
                    for (j = i + 1; j < count; j++)
                    {

                        if (strcmp(tach[i].title, tach[j].title) > 0)
                        {
                            temp = tach[i];
                            tach[i] = tach[j];
                            tach[j] = temp;
                        }
                    }
                    printf("le %d tach est :\n  id : %d \n Title:  %s \n description :  %s \n status : %s \n  le dead ligne : %d %d %d \n", i + 1, tach[i].id, tach[i].title, tach[i].description, tach[i].status, tach[i].jour, tach[i].mois, tach[i].anne);
                }

                break;
            case 2:

                for (i = 0; i < count; i++)
                {
                    for (j = i + 1; j < count; j++)
                    {
                        if (tach[i].jour + tach[i].mois * 30 + tach[i].anne * 365 > tach[j].jour + tach[j].mois * 30 + tach[j].anne * 365)
                        {
                            temp = tach[i];
                            tach[i] = tach[j];
                            tach[j] = temp;
                        }
                    }
                    printf("le %d tach est :\n  id : %d \n Title:  %s \n description :  %s \n status : %s \n  le dead ligne : %d %d %d \n", i + 1, tach[i].id, tach[i].title, tach[i].description, tach[i].status, tach[i].jour, tach[i].mois, tach[i].anne);
                }
                break;

            case 3:
                for (i = 0; i < count; i++)
                {
                    if ((tach[i].jour + tach[i].mois * 30 + tach[i].anne * 365) - date <= 3 && (tach[i].jour + tach[i].mois * 30 + tach[i].anne * 365) - date > 0)
                    {
                        printf("le %d tach est :\n  id : %d \n Title:  %s \n description :  %s \n status : %s \n  le dead ligne : %d %d %d \n", i + 1, tach[i].id, tach[i].title, tach[i].description, tach[i].status, tach[i].jour, tach[i].mois, tach[i].anne);
                    }

                }
                break;
            }
            break;
        case 4:
            ModifieTach();
            printf("_____________selectionner un numero : ");
            scanf("%d", &choix); //CHOIX 3
            switch (choix) //CHOIX3
            {
            case 1:
                printf("entrer the id of the tach you wanna modifie : ");
                scanf("%d", &newid);
                printf("entrer le new desc : \n");
                scanf(" %[^\n]s", newdesc);
                for (i = 0; i < count; i++)
                {
                    if (tach[i].id == newid)
                    {
                        strcpy(tach[i].description, newdesc);
                    }
                }
                break;
            case 2:
                printf("entrer the id of the tach you wanna modifie : ");
                scanf("%d", &newid);
                for (i = 0; i < count; i++)
                {
                    if (newid == tach[i].id)
                    {
                        NouvellTach();
                        printf("\n when do you wanna put it : ");
                        scanf("%d", &choix); //CHOIX6
                        switch (choix) //6
                        {
                        case 1:
                            strcpy(tach[i].status, "TO DO");
                            break;
                        case 2:
                            strcpy(tach[i].status, "Doing");
                            break;
                        case 3:
                            strcpy(tach[i].status, "Done");
                            break;
                        } // switch end
                    }     // if end
                    else
                        printf("the title you put is not exist \n");
                } // for end
                break;
            case 3:
                printf("enter the id of the tach you wanna modifie : ");
                scanf("%d", &newid);
                for (i = 0; i < count; i++)
                {
                    if (newid == tach[i].id)
                    {
                        printf("enter a new date jour mois anne : ");
                        scanf(" %d %d %d", &Newjour, &Newmois, &Newanne);
                        tach[i].jour = Newjour;
                        tach[i].mois = Newmois;
                        tach[i].anne = Newanne;
                    }
                    else
                        printf("the title you input is not exist \n");
                }
                break;
            }
            break;
        case 5: //supprime
            printf("entre the id of the tach you wanna delete : ");
            scanf("%d", &newid);

            for (i = 0; i < count; i++)
            {
                if (tach[i].id == newid)
                {
                    for(j=i;j<count;j++){
                        tach[j] = tach[j + 1];
                    }
                    count--;
                }
            }
            break;
        case 6:
            Recherch();
            printf("_____________selectionner un numero : ");
            scanf("%d", &choix); //4
            switch (choix) //4
            {
            case 1:
                printf("enter the id of your tach : ");
                scanf("%d", &newid);
                for (i = 0; i < count; i++)
                {
                    if (newid == tach[i].id)
                    {
                        printf("we found your tach : \n");
                        printf("the tach id is : %d \n", tach[i].id);
                        printf("the tach title is : %s \n", tach[i].title);
                        printf("the tach description is : %s \n", tach[i].description);
                        printf("the tach status is : %s \n", tach[i].status);
                        printf("the tach dead line is : %d/%d/%d", tach[i].jour, tach[i].mois, tach[i].anne);
                    }
                }
                break;
            case 2:
                printf("entre the title of your tach : \n");
                scanf("%s", newtitle);
                for (i = 0; i < count; i++)
                {
                    if (strcmp(newtitle, tach[i].title) == 0)
                    {
                        printf("we found your tach : \n");
                        printf("the tach id is : %d \n", tach[i].id);
                        printf("the tach title is : %s \n", tach[i].title);
                        printf("the tach description is : %s \n", tach[i].description);
                        printf("the tach status is : %s \n", tach[i].status);
                        printf("the tach dead line is : %d/%d/%d", tach[i].jour, tach[i].mois, tach[i].anne);
                    }
                }
                break;
            }
            break;
        case 7:
            Statistiques();
            printf("_____________selectionner un numero : ");
            scanf("%d", &choix); //5
            switch (choix) //5
            {
            case 1:
                printf("number of your taches are : %d \n", count);
                break;
            case 2:
                for(i=0;i<count;i++){
                    if(strcmp(tach[i].status,"Done")==0){
                        s++;
                    }else
                     z++;

                }
                 printf("le nombre des taches complet est %d uncomplet est : %d \n",s,z);
                break;
            case 3:
                for(i=0;i<count;i++){
                    printf("le tach id : [%d ],[jour restant : %d ] \n",tach[i].id,(tach[i].jour + tach[i].mois*30 + tach[i].anne*365)-date);
                }
                break;
            }
            break;
        } // switch end

    } while (choix != 0);

    return 0;
    // do while end
} // main ends
