#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
    int id;
    char userName[50];
    int age;
    int amount;
    char location[50];
    char password[20];


};

int main ()
{
    FILE *file;
    int dataInsert;
    int userInput;
    printf("Press 1 to insert data \nPress 2 to find data \n");
    printf("Your input : ");
    scanf("%d",&userInput);

    struct user u[30];
    if(userInput == 2){
        file = fopen("user.txt","r");
        if(file == NULL){
            printf("There is no data in file");

        }
        else{
            while(fread(&u,sizeof(struct user),1,file))

            printf("User id : %d\n UserName : %s\n User age %d\n User amount %d\n User Location %s\n user password %s\n",u->id , u->userName,u->age,u->amount,u->location,u->password);
            }
        }
    else if(userInput == 1){
    printf("How Many User You want to insert : ");
    scanf("%d",&dataInsert);

    file = fopen("user.txt","a+");
    for(int i = 0;i<dataInsert;i++){
        printf("Enter User ID : ");
        scanf("%d",&u[i].id);
         printf("Enter User Name : ");
        scanf("%s",&u[i].userName);
         printf("Enter User age : ");
        scanf("%d",&u[i].age);
         printf("Enter amount : ");
        scanf("%d",&u[i].amount);
         printf("Enter User Location : ");
        scanf("%s",&u[i].location);
         printf("Enter User Password : ");
        scanf("%s",&u[i].password);

        fwrite(&u[i],sizeof(struct user),1,file);
        printf("Data Inserted Successfully");
    }
    }

    else{
        printf("wrong input");
    }

    fclose(file);
return 0;
}
