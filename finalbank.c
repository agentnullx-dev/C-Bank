#include <stdio.h>
#include <string.h>

char username[100][50];
char password[100][7];
float balance[100];
int totalusers =0;
int currentuser = -1;

void registeruser(){
printf("\nenter ur username- ");
fgets(username[totalusers],50,stdin);
username[totalusers][strlen(username[totalusers]) -1] = '\0';

printf("\nenter ur password- ");
scanf("%s",password[totalusers]);
balance[totalusers] = 0;
getchar();
totalusers++;

}

int loginuser()
{

    char entereduser[50];
    char enteredpass[7];
    

    printf("\nenter ur username- ");
    fgets(entereduser,sizeof(entereduser),stdin);
    entereduser[strlen(entereduser) -1 ] = '\0';

    printf("\nenter ur password- ");
    scanf("%s",enteredpass);
    getchar();


    for(int i=0;i<totalusers;i++)
    {
        if(strcmp(entereduser,username[i]) == 0 &&
           strcmp(enteredpass,password[i]) == 0)
           {

            currentuser = i;
            printf("\n=================================");
            printf("\nlogin successful");
            printf("\n=================================");

            return 1;
           }
    }
    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    printf("invalid details try again later");
    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    return 0;




}

void cheakbalance (){    
    printf("\nur current balance is $%f\t",balance[currentuser]);
}

void deposit ()
    {
        float depositamt;
    printf("\nenter the amount u want to deposit-");
    scanf("%f",&depositamt);

    if(depositamt > 0){
        balance[currentuser] += depositamt;
        printf("\ndeposited your amount of $%f",depositamt);
        cheakbalance ();

    }
    else{
        printf("\ninvalid amount entered try again");
    }

}

void withdraw (){
    float withdrawamt;
    printf("\nenter the amount u want to withdraw-");
    scanf("%f",&withdrawamt);
    if(withdrawamt <= balance[currentuser]){
        balance[currentuser] = balance[currentuser] - withdrawamt;
        cheakbalance();

    }
    else{
        printf("\nur current balance is insufficient try a lower amount");
        printf("\nu can withdraw a maximum amount of %f",balance[currentuser]);
    }
    
}

void exitprogram (){
    printf("\n=================================");
    printf("\n u have chosen to exit");
    printf("\n Thank You For Banking With Us!");
    printf("\n Have A Great Day :)");
    printf("\n=================================\n");
}

void bankprogram(){
    int choice;
     do{/*main do while loop*/
    printf("\n--------------------------------------");
    printf("\nwelcome to the banking menu");
    printf("\n--------------------------------------");
    printf("\nchoose the following options to proceed");
    printf("\n1.cheakbalance");
    printf("\n2.withdraw");
    printf("\n3.deposit");
    printf("\n4.exit\n");

    scanf("%d",&choice);/*choice input*/
    switch(choice)
    {
        case 1:     /*cheak balance*/
                    printf("\nyou chose to cheak ur balance");
                    cheakbalance();
                    break;

        case 2:     /*withdraw*/
                    printf("\nyou chose to withdraw");
                    withdraw();
                    break;

        case 3:     /*deposit*/                                    
                    printf("\nyou chose to deposit");
                    deposit();
                    break;

        case 4:     /*exit*/
                    exitprogram();
                    break;

        default:    /*in case of invalid choice*/
                    printf("\ninvalid choice enter a valid one");
        

    }
        
    }while(choice !=4);
}

int main(){
    int mainchoice;

    do{
        printf("\n--------------------------------------");
        printf("\nwelcome to the banking program");
        printf("\n--------------------------------------");
        printf("\nchoose the following options to proceed");
        printf("\n 1.register");
        printf("\n 2.login");
        printf("\n 3.exit");
        printf("\nenter your choice- ");
        scanf(" %d",&mainchoice);
        getchar();

        switch(mainchoice){
            case 1:
                    registeruser();
                    break;
                
            case 2:
                    if(loginuser()){

                        bankprogram();
                    }

                    else{
                        printf("login failed");
                    }
                    break;
        }

    }while(mainchoice != 3);

       return 0;

}