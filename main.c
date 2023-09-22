#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//projet fin de sas
int count=0;
void menu (void){
    printf("_____________M E N U ________\n");
    printf("[1]_ajouter un nouvell tach \n");
     printf("[2]_Ajouter plusieurs nouvelles tâches. \n");
      printf("[3]_Afficher la liste de toutes les tâches (Identifiant, Titre, Description, Deadline, Statut)  \n");
       printf("[4]_Modifier une tâche \n");
        printf("[5]_Supprimer une tâche par identifiant \n");
         printf("[6]_Rechercher les Tâches \n");
          printf("[7]_Statistiques \n");
           printf("[0]_exite \n");
}
void NouvellTach (void){
    printf("[1]_To do \n");
     printf("[2]_Doing \n");
      printf("[3]_Done \n");
}
void AffichLalist (void){
    printf("[1]_Trier les tâches par ordre alphabétique \n");
     printf("[2]_Trier les tâches par deadline\n");
      printf("[3]_Afficher les tâches dont le deadline est dans 3 jours ou moins\n");
}
void ModifieTach (void){
    printf("[1]_Modifier la description dune tâche \n");
     printf("[2]_Modifier le statut dune tâche \n");
      printf("[3]_Modifier le deadline dune tâche. \n");
}
void Recherch (void){
    printf("[1]_Rechercher une tâche par son Identifiant\n");
     printf("[2]_Rechercher une tâche par son Titre\n");
}
void Statistiques (void){
    printf("[1]_Afficher le nombre total des tâches\n");
     printf("[2]_Afficher le nombre de tâches complètes et incomplètes\n");
      printf("[3]_Afficher le nombre de jours restants jusqu'au délai de chaque tâche\n");
}

struct Tach { //struct begin
    char title[30];
    char description[100];
    char status[100];
    int jour,mois,anne;
    int id;

            };//struct end
int main(){ //main begin
struct Tach tach [100];
int choix,choix1,choix2,choix3,choix4,choix5,choix6;
int NumberTach,i,j;
char newdesc[200];
int newid;
char newtitle[40];
int Newjour,Newmois,Newanne;
struct Tach temp;
do{ // do while begin
   menu();
printf("______________sélectionner un numéro : ");
scanf("%d",&choix);
switch(choix){ //switch begin
    case 1: printf("enter your tach id : \n");
            scanf("%d",&tach[count].id);
            printf("entre le nom de tach \n");
            scanf("%s",tach[count].title);
            printf("entrer le description \n");
            scanf(" %[^\n]s",tach[count].description);
            printf("entrer le date jour mois anne \n");
            scanf("%d %d %d",&tach[count].jour,&tach[count].mois,&tach[count].anne);
            printf("when do you wanna put it \n");
            NouvellTach();
            scanf("%d",&choix1);
            switch(choix1){
                case 1: strcpy(tach[count].status,"To do");
                        printf("the transformation went succesfuly \n");
                    break;
                case 2: strcpy(tach[count].status,"Doing");
                        printf("the transformation went succesfuly \n");
                    break;
                case 3:strcpy(tach[count].status,"Done");
                       printf("the transformation went succesfuly \n");
                    break;
                         }
                         count++;
    break;

    case 2:
           printf("how many tach you wanna add ? \n");
           scanf("%d",&NumberTach);
           for(i=1;i<=NumberTach;i++){
               printf("enter the id of your tach : ");
               scanf("%d",&tach[count].id);
               printf("entre le nom de tach %d \n",i);
               scanf("%s",tach[count].title);
               printf("entrer le description de tach %d \n",i);
               scanf(" %[^\n]s",tach[count].description);
               printf("entrer le date (jour mois anne) de tach %d \n",i);
               scanf("%d %d %d",&tach[count].jour,&tach[count].mois,&tach[count].anne);
               printf("when do you wanna put your %d tach  \n",i);
               NouvellTach();
                 scanf("%d",&choix1);
                 switch(choix1){
                 case 1: strcpy(tach[count].status,"To do");
                        printf("the transformation went succesfuly \n");
                    break;
                 case 2: strcpy(tach[count].status,"Doing");
                        printf("the transformation went succesfuly \n");
                    break;
                 case 3:strcpy(tach[count].status,"Done");
                       printf("the transformation went succesfuly \n");
                    break;
                   }
                   count++;
                                 } // for loop end
    break;
    case 3: AffichLalist();
            printf("_____________selectionner un numero : ");
            scanf("%d",&choix2);
            switch(choix2){
                case 1: for(i=0;i<count;i++){
                           for(j=i+1;j<count;j++){

                               if(strcmp(tach[i].title,tach[j].title)>0) {
                                  temp=tach[i];
                                tach[i]=tach[j];
                                  tach[j]=temp;

                                                        }
                                }
                    printf("le %d tach est :\n  id : %d \n Title:  %s \n description :  %s \n status : %s \n  le dead ligne : %d %d %d \n",i+1,tach[i].id,tach[i].title,tach[i].description,tach[i].status,tach[i].jour,tach[i].mois,tach[i].anne);
                                            }

                    break;
                case 2:
                    break;
                case 3:
                    break;
                          }
    break;
    case 4: ModifieTach();
            printf("_____________selectionner un numero : ");
            scanf("%d",&choix3);
            switch(choix3){
                case 1:  printf("entrer the id of the tach you wanna modifie : ");
                         scanf("%d",&newid);
                         printf("entrer le new desc : \n");
                         scanf(" %[^\n]s",newdesc);
                        for(i=0;i<count;i++){
                            if(tach[i].id==newid){
                                strcpy(tach[i].description,newdesc);
                                                                }
                        }
                    break;
                case 2:  printf("entrer the id of the tach you wanna modifie : ");
                         scanf("%d",&newid);
                         for(i=0;i<count;i++){
                            if(newid==tach[i].id){
                                NouvellTach();
                                printf("\n when do you wanna put it : ");
                                scanf("%d",&choix6);
                                switch(choix6){
                                    case 1: strcpy(tach[i].status,"TO DO");
                                        break;
                                    case 2: strcpy(tach[i].status,"Doing");
                                        break;
                                    case 3: strcpy(tach[i].status,"Done");
                                        break;
                                              } //switch end
                                                                    } //if end
                            else
                                printf("the title you put is not exist \n");
                                               } //for end
                    break;
                case 3: printf("enter the id of the tach you wanna modifie : ");
                        scanf("%d",&newid);
                        for(i=0;i<count;i++){
                            if(newid==tach[i].id){
                                printf("enter a new date jour mois anne : ");
                                scanf(" %d %d %d",&Newjour,&Newmois,&Newanne);
                                tach[i].jour=Newjour;
                                tach[i].mois=Newmois;
                                tach[i].anne=Newanne;
                            }
                            else
                                printf("the title you input is not exist \n");
                        }
                    break;
                        }
    break;
    case 5: printf("entre the id of the tach you wanna delete : ");
            scanf("%d",&newid);

                for(i=0;i<count;i++){
                    if(tach[i].id==newid){
                        tach[i]=tach[i+1];
                                     }
                                        }
                 count--;
    break;
    case 6: Recherch();
            printf("_____________selectionner un numero : ");
            scanf("%d",&choix4);
            switch(choix4){
                case 1: printf("enter the id of your tach : ");
                        scanf("%d",&newid);
                        for(i=0;i<count;i++){
                            if(newid==tach[i].id){
                                printf("we found your tach : \n");
                                printf("the tach id is : %d \n",tach[i].id);
                                printf("the tach title is : %s \n",tach[i].title);
                                printf("the tach description is : %s \n",tach[i].description);
                                printf("the tach status is : %s \n",tach[i].status);
                                printf("the tach dead line is : %d/%d/%d",tach[i].jour,tach[i].mois,tach[i].anne);
                            }
                        }
                    break;
                case 2: printf("entre the title of your tach : \n");
                        scanf("%s",newtitle);
                        for(i=0;i<count;i++){
                            if(strcmp(newtitle,tach[i].title)==0){
                                printf("we found your tach : \n");
                                printf("the tach id is : %d \n",tach[i].id);
                                printf("the tach title is : %s \n",tach[i].title);
                                printf("the tach description is : %s \n",tach[i].description);
                                printf("the tach status is : %s \n",tach[i].status);
                                printf("the tach dead line is : %d/%d/%d",tach[i].jour,tach[i].mois,tach[i].anne);
                            }
                        }
                    break;
                          }
    break;
    case 7: Statistiques();
            printf("_____________selectionner un numero : ");
            scanf("%d",&choix5);
            switch(choix5){
                case 1:
                break;
                case 2:
                break;
                case 3:
                break;
                         }
    break;
                    } //switch end

}while(choix != 0);

    return 0;
 // do while end
} // main ends
