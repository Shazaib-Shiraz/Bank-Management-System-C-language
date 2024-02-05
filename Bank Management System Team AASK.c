#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void backtomenu();
void menu();
void createaccount();       //Function to Create Account
void deposit();            //Function to Deposit
void withdraw();          //Function to Withdraw amount
void checkbalance();     //Function to check the balance
void quitprogram();     //exit function  
void Continue();       //checks whether user wanted to access this section
void option_check();  //verfies your existence in the first section which allows you to access other sections

//Some Global variable Declarations

int balance, initial_amount, credit_amount, Withdraw_amount,check=0; //Everything an account does
char pass[20],cpass[20];                                            //password & confirm password strings
int confirmation,confirmation2;                                    //password verifications
int length;                                                       //length of password which determines its strength
int choice=0;                                                    //switch case variable
int main () 
{
	do{
		menu();    //function to print main menu
	    printf("\nPlease Choose any option : ");
        scanf("%d",&choice);           
	switch(choice){
    case 1:
        createaccount();   //Function to Create Account
        break;
       
    case 2:
        deposit();          //Function to Deposit
        break;
    case 3:
        withdraw();         //Function to Withdraw amount
        break;
    case 4:
        checkbalance();     //Function to check the balance
        break;
    case 5:
        quitprogram();      //exit function  
        break;
              default:
      	printf("Invalid Menu option");
      	break;
      }

    } while (1);            //To run loop multiple times
  }
  
    void menu(){
	system("cls");          // Built-in Function To Clear Screen
     system ("color B");
    printf("\n------------------------------------------------------------------------\n");
    printf("\t\tCustomer Account Banking Management System!\n\t");
    printf("\n------------------------------------------------------------------------\n");
    printf("\n\t\t|\xB9\xB9\xB9\xB9\xB9\xB9\xB9| WELCOME TO THE MAIN MENU |\xB9\xB9\xB9\xB9\xB9\xB9\xB9|\n");
    printf("\n------------------------------------------------------------------------\n\n");
	printf("\t==> [1] Create Account\n\n");
	printf("\t==> [2] Deposit/Credit \n\n");
    printf("\t==> [3] Withdraw\n\n");
    printf("\t==> [4] Check your Balance\n\n");
    printf("\t==> [5] Exit\n\n");
    printf("\n-----------------------------------------\n");
}
    void createaccount(){         //Function to Create Account
	 system("cls");              // Built-in Function To Clear Screen
	 printf("--------------------------------------------------------------------------------\n");
	 printf("\t\xB9\xB9\xB9 CREATING NEW ACCOUNT \xB9\xB9\xB9\n");
	 printf("--------------------------------------------------------------------------------");
	 //Continue function wasnt working here [Reason: Unknown] 	
     char name[20], phone_number[15],account_type,CNIC[15];
     int dd,mm,yy; 
     option_check();  //This is what allows you to access other sections
     printf("\n=> Enter your name: ");
     scanf("%s",&name);

    // Validate phone number
    do {
        printf("\n=> Enter Your Contact Number: +92");
        scanf("%s", &phone_number);
        if (strlen(phone_number) != 10) {
            printf("Invalid Contact number <<<RETRY>>>\n");
        } else {
            break;
        }
    } while (1);     //To run loop for as long as the phone number limit is true

    while(1)
     {
         printf("\n=> Enter your day of birth (date): ");
        scanf("%2d", &dd);
        printf("\n=> Enter your date of birth (Month): ");
        scanf("%2d",&mm);
        printf("\n=> Enter your date of birth (Year): ");
        scanf("%4d",&yy);
        if ((dd < 1 || dd > 31) || (mm < 1 || mm > 12) || (yy < 1900 || yy > 2024)) {
            printf("Invalid date format <<<RETRY>>>\n");
        } else {
            break;
        }
	 }
    // Validate CNIC
    do {
        printf("\n=> Enter your CNIC Number (13 digits): ");
        scanf("%s", &CNIC);
        if (strlen(CNIC) != 13) {
            printf("\nIncorrect CNIC <<<RETRY>>>\n");
        } else {
            break;
        }
    } while (1);     //To run loop multiple times

    // Validate initial amount
    do {
        printf("\n=> Enter Amount More Than 1000/=Rs to Create Your Account: ");
        scanf("%d",&initial_amount);
     
        if (initial_amount < 1000) {
            printf("\nInvalid Amount <<<RETRY>>>\n");
        } else {
            break;
        }
          
    } while (1);      //To run loop multiple times

     balance +=initial_amount;
   printf("\n=> Enter your password: ");
   scanf("%s",&pass);
   length=strlen(pass);
   if(length>10){
 
  	printf("\t[Strong Password]"); }
	 else {
		printf("\t[ Weak Password]"); 
	}
                                    
	printf("\n\n\n\t---------X Your Account is Successfully Created X----------");
	
	 FILE *fp;                     //Filing to create file to store user account info
    fp = fopen("Userinfo.txt", "w");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        exit(1);
    }
    fprintf(fp, "=>UserName: %s \n=> User Phone Number: +92 %s \n=> Date of Birth: %2d/%2d/%4d \n=> CNIC No: %s \n=> User Password: %s\n\n=> User initial Amount: %d /=Rs", name, phone_number, dd, mm, yy, CNIC,pass,initial_amount);
    fclose(fp);

    backtomenu();
   
   }
   
    void deposit(){      //Function to Deposit
	 system("cls");      // Built-in Function To Clear Screen
	printf("------------------------------------------------------------------------------\n");
	printf("\t\xB9\xB9\xB9 DEPOSITING AMOUNT \xB9\xB9\xB9\n");
	printf("-----------------------------------------------------------------------------");
		if(check==1)  //this checks if you already have an account or not
	{
       Continue();
	}
	else
	{
	    printf("\n Go Create an Account First");
		sleep(2);
		main();
	}
b:
	 printf("Enter your password: ");
	 scanf("%s",&cpass);
	 confirmation=strcmp(pass,cpass);
	 confirmation2=strcmp(cpass,pass);
	 if(confirmation==confirmation2)
	 {
	 	printf("\n Identity Confirmed [Access Granted]\n");
	 	goto a;
	 }
	 else 
	 {
	 	printf("\n Identiy Uncomfirmed [Access Denied]\n");
	 	goto b;
	 }
	 a:
    printf("\nEnter the amount you wish to credit: ");
    scanf("%d", &credit_amount);
    balance += credit_amount;
    
    FILE *fp;                     //Filing to append the credit amount in user account info
    fp = fopen("Userinfo.txt", "a");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        exit(1);
    }

    fprintf(fp, "\n=> Deposit Amount: %d /=Rs",credit_amount);
    fclose(fp);
}
   
    void withdraw(){    //Function to Withdraw amount
	system("cls");      // Built-in Function To Clear Screen
    printf("--------------------------------------------------------------------------------\n");
	printf("\t\xB9\xB9\xB9 WITHDRAWAL AMOUNT \xB9\xB9\xB9\n");
	printf("--------------------------------------------------------------------------------");

	
	if(check==1)  //this checks if you already have an account or not
	{
       Continue();
	}
	else
	{
		printf("\n Go Create an Account First");
		sleep(2);
		main();
	}
b:
		 printf("\nEnter your password: ");
	 scanf("%s",&cpass);
	 confirmation=strcmp(pass,cpass);
	 confirmation2=strcmp(cpass,pass);
	 if(confirmation==confirmation2)
	 {
	 	printf("\n Identity Confirmed [Access Granted]");
	 	goto a;
	 }
	 else 
	 {
	 	printf("\n Identiy Uncomfirmed [Access Denied]");
	   goto b;
	 }
	 a:
    printf("\nEnter withdrawal amount: ");
    scanf("%d", &Withdraw_amount);
    if (Withdraw_amount > balance) {
        printf("\nInsufficient balance!\n");
    } else {
        balance -= Withdraw_amount;
        
        printf("\nWithdrawal successful!\n");
        
        FILE *fp;                    //Filing to append the Withdraw amount in user account info
    fp = fopen("Userinfo.txt", "a");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        exit(1);
    }

    fprintf(fp, "\n=> Withdraw Amount: %d /=Rs",Withdraw_amount);
    fclose(fp);
    }

    backtomenu();
}

    void checkbalance(){        //Function to check the balance
	 system("cls");              // Built-in Function To Clear Screen
    printf("--------------------------------------------------------------------------------\n");
	printf("\t\xB9\xB9\xB9 ACCOUNT BALANCE STATUS  \xB9\xB9\xB9\n");
	printf("--------------------------------------------------------------------------------");
	if(check==1)
	{
		Continue();
		goto b;
	}
	else 
	{ 
	    printf("\n Go Create an Account First");
		sleep(2);
	     main();
	}
	b:
    balance = initial_amount + credit_amount - Withdraw_amount;
    
    printf("\nYour Current Balance is %d", balance);
    
        FILE *fp;                     //Filing to append the current balance in user account info
	fp = fopen("Userinfo.txt", "a");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        exit(1);
    }

	fprintf(fp, "\n=> Current Balance: %d /=Rs",balance);
    fclose(fp);
    backtomenu();
}
  
    void quitprogram(){         //function to Exit program  
	system("cls");              // Built-in Function To Clear Screen
	printf("----------------------------------------------------------------------------------\n");
	printf("\t\xB9\xB9\xB9 Exiting program..... Goodbye! \xB9\xB9\xB9\n");
	printf("\nCreated By Shazaib | Abdul Rehman | Arman | Karan | Aliyan \n");
	printf("\n--------------------------------------------------------------------------------");
    exit(0);                     // Exit program successfully};
   }
   
    void backtomenu(){
	int i;
    printf("\n----------------------------------------------\n");
	printf ("\nPress 1 to move back to main menu: ");
	scanf("%d",&i);
	printf("\n----------------------------------------------\n");
	if(i==1){
	menu();
	}
	else 
	{
    printf("\nInvalid Key is being pressed!\n");
    
   }
   
}
void Continue(){
	int i;
	printf("\nPress [1] to continue with this section! || Press [2] to revisit menu: ");
	scanf("%d",&i);
    printf("--------------------------------------------------------------------\n");
	if(i==2){
		menu();
	}
	else if(i==1)
	{
		printf("\n Continuing....\n");
	}
	
}
void option_check()
{
	do{
	
    printf("\n Enter [1] to Continue in this section: ");
     scanf("%d",&check);  //without this check you will not be able to access other options 
     if(check==1)
  {
          	printf("\n Thank You!\n");
          	printf("--------------------------------------------------------------------------------");
          break;
  }
  else
  {
  	  menu();
  }
  }while(1);
}
