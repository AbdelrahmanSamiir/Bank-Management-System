#include <stdio.h>
#include "STD_TYPES.h"
#include <stdlib.h>

void adminwindow(void);
void clientwindow(void);
void adminexistingacc(void);
void creatnewacc(void);

void transaction(u8 Accdetector);
void changestatus(u8 Accdetector);
void changepassword(u8 Accdetector);
void getcash(u8 Accdetector);
void deposite(u8 Accdetector);

u8 generateAccountID(void);
u8 generatePassword(void);

u32 AdminsID = 1234;
u32 AdminPass = 0000;

typedef struct
{
	u8 FullName[50];
	u8 FullAddress[50];
	u8 NationalID[13];
	u8 Age;
	u32 BankAccID;
	u8 Guardian[50];
	u8 GuardianNationalID[13];
	u32 Balance;
	u8 Password;
	u8 *AccountStatus;
}BankAcc;

BankAcc c;
BankAcc arr[100];
u8 NumOfAcc = 0;

void main(void)
{
	u32 windowchoice;
	printf("\n---------welcome to MainMenu---------\n\n");
	printf("Please choose a number from the below choices :\n");
	printf("1- Admin Window\n2- Client Window\n");
	scanf("%d",&windowchoice);
	switch(windowchoice)
	{
		case 1:
			adminwindow();
			break;
		case 2:
			clientwindow();
			break;
		default:
			printf("Error: Choose Again\n");
			main();
			break;
	}
}

									//Admin Window and Client Window
void adminwindow(void)
{
	u32 adminID;
	u32 adminPassword;
	printf("Please enter Admin's ID : ");
	scanf("%d",&adminID);
	printf("Please enter Admin's password : ");
	scanf("%d",&adminPassword);
	
	if(AdminsID == adminID && AdminPass == adminPassword)
	{
		u8 adminchoice;
		printf("---------welcome to admin window---------\n\n");
		printf("Please choose a number from the below choices :\n");
		printf("1- Create New Account\n2- Open Existing Account\n3- Exit System\n");
		scanf("%d",&adminchoice);
		switch(adminchoice)
		{
			case 1:
				creatnewacc();
				break;
			case 2:
				adminexistingacc();
				break;
			case 3:
				main();
				break;
			default:
				printf("Error,Choose Again:\n");
				break;
		}
	}
	else
	{
		printf("Wrong Admin ID or Password\n\n");
	}
	adminwindow();
}

void clientwindow(void)
{	
	u32 AccID;
	u32 Pass;
	printf("please enter the account id:\n ");
	scanf("%d",&AccID);
	printf("please enter the Pass:\n ");
	scanf("%d",&Pass);
	for (u8 Accdetector = 0; Accdetector < NumOfAcc; Accdetector++)
	{
		if (arr[Accdetector].BankAccID == AccID && arr[Accdetector].Password == Pass)
		{
			u32 clientchoice;
			printf("-------------welcome to client window--------------\n\n");
			printf("Please choose a number from the below choices :\n");
			printf("1- Make Transaction\n2- Change Account Password\n3- Get Cash\n4- Deposit in Account\n5- Return to main Menu\n");
			scanf("%d",&clientchoice);
			switch(clientchoice)
			{
				case 1:
					transaction(Accdetector);
					break;
				case 2:
					changepassword(Accdetector);
					break;
				case 3:
					getcash(Accdetector);
					break;
				case 4:
					deposite(Accdetector);
					break;
				case 5:
					main();
					break;
				default:
					printf("Error");
					break;
			}
			main();
		}
	}
	printf("wrong credentials,Try Again :\n");
	clientwindow();
}
											//Admin Functions

void adminexistingacc(void)
{
	u32 AccID;
	printf("please enter the account id:\n ");
	scanf("%d",&AccID);
	for (int Accdetector = 0; Accdetector < NumOfAcc; Accdetector++)
	{
		if (arr[Accdetector].BankAccID == AccID)
		{
			u32 existingaccchoice;
			printf("\nPlease choose a number from the below choices :\n");
			printf("1- Make Transaction\n2- Change Account Status\n3- Get Cash\n4- Deposit in Account\n5- Return to main Menu\n");
			scanf("%d",&existingaccchoice);
			switch(existingaccchoice)
			{
				case 1:
					transaction(Accdetector);
					break;
				case 2:
					changestatus(Accdetector);
					break;
				case 3:
					getcash(Accdetector);
					break;
				case 4:
					deposite(Accdetector);
					break;
				case 5:
					main();
					break;
				default:
					printf("Error");
					main();
					break;
			}
		}
	}
	printf("Wrong Account ID,Try Again :\n");
	adminexistingacc();
}


u8 generateAccountID()
{
    return rand() % (999 - 100 + 1) + 100;
}
u8 generatePassword()
{
    return rand() % (9999 - 1000 + 1) + 1000;
}


void creatnewacc(void)
{
	printf("please enter Fullname :\n");
	scanf(" %[^\n]",&c.FullName);
	
	printf("please enter Fulladdress :\n");
	scanf(" %[^\n]",&c.FullAddress);
	
	printf("please enter the age :\n");
	scanf("%d",&c.Age);
	
	if (c.Age < 21 && c.Age > 0)
	{
		printf("Enter Guardian Name: ");
		scanf(" %[^\n]",&c.Guardian);
        printf("Enter Guardian National ID: ");
		scanf(" %[^\n]",&c.GuardianNationalID);
    }
	else if(c.Age >= 21 && c.Age <100)
	{
		printf("please enter the NationalID :\n");
		scanf(" %[^\n]",&c.NationalID);
	}
	else
	{
		printf("Error:enter a valid age\n");
		creatnewacc();
	}
	printf("please enter the Balance :\n");
	scanf("%d",&c.Balance);
	
	c.BankAccID = generateAccountID();
	printf("Account ID: %d\n", c.BankAccID);
	
	c.Password = generatePassword();
	printf("Account Password: %d\n", c.Password);
	
	c.AccountStatus = "Active";
	printf("Account status : %s \n\n",c.AccountStatus);
	
	printf("Account created successfully\n\n\n");
	
	arr[NumOfAcc] = c;
	NumOfAcc++;
	
	for (int i = 0; i < NumOfAcc; i++) 
	{
		printf("name: %s\n", arr[i].FullName);
		printf("addr: %s\n", arr[i].FullAddress);
		printf("Balance: %d\n", arr[i].Balance);
		printf("\n\n\n");
	}
	adminwindow();
}

											//Common Functions
void transaction(u8 Accdetector)
{
	if(arr[Accdetector].AccountStatus == ( void * )"Active")
	{
		u32 TransactionAmount;
		u32 RecieverBankAccID;
		printf("Enter the amount: ");
		scanf("%d",&TransactionAmount);
		printf("Enter the Bank Account ID you want to transfer money to: ");
		scanf("%d",&RecieverBankAccID);
	//	for (u8 j = 0; j < NumOfAcc; j++)
	//	{
	//		if (arr[j].BankAccID == RecieverBankAccID)
	//		{
				if(TransactionAmount<= arr[Accdetector].Balance)
				{
					arr[Accdetector].Balance = arr[Accdetector].Balance - TransactionAmount ;
	//				arr[j].Balance = arr[j].Balance + TransactionAmount ;
					printf("Money transfered\n");
					printf("Current Balance: %d\n",arr[Accdetector].Balance);
					//printf("rec Current Balance: %d\n",arr[j].Balance);
					main();
				}	
				else
				{
					printf("Process failed: insufficient amount\n");
					main();
				}
	//		}
	//		else
	//		{
	//			printf("Reciever Bank Acc ID not found\n");
	//			break;
	//		}
	//	}
	}
	else
	{
		printf("Account Closed or Restricted\n");
	}
	main();
}



void changestatus(u8 Accdetector)
{
	u8 choice;
	printf("Choose Account Status:\n1- Active\n2- Restricted\n3- Closed\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			arr[Accdetector].AccountStatus = "Active";
			printf("Account status updated\n");
			break;
		case 2:
			arr[Accdetector].AccountStatus = "Restricted";
			printf("Account status updated\n");
			break;
		case 3:
			arr[Accdetector].AccountStatus = "Closed";
			printf("Account status updated\n");
			break;
		default:
			printf("Error\n");
			break;
	}
	printf("%s\n",arr[Accdetector].AccountStatus);
	
	adminwindow();
}



void changepassword(u8 Accdetector)
{
	if(arr[Accdetector].AccountStatus ==( void * ) "Active")
	{
		u8 OldPass;
		u8 NewPass;
		u8 ConfirmPass;
		printf("Enter your Old Password: ");
		scanf("%d",&OldPass);
		if(OldPass == arr[Accdetector].Password)
		{
			printf("Enter your New Password: ");
			scanf("%d",&NewPass);
			printf("Confirm Password: ");
			scanf("%d",&ConfirmPass);
			if(NewPass == ConfirmPass)
			{
				arr[Accdetector].Password = ConfirmPass;
				printf("Password changed\n");
				clientwindow();
			}
			else
			{
				printf("Password dosen't Match\n");
				clientwindow();
			}
		}
		else
		{
			printf("Wrong Password\n");
			clientwindow();
		}
	}
	else
	{
		printf("Account Closed or Restricted\n");
		clientwindow();
	}
}



void getcash(u8 Accdetector)
{
	if(arr[Accdetector].AccountStatus == ( void * )"Active")
	{
		u32 WithdrawAmount ;
		printf("Enter the amount you want to withdraw: ");
		scanf("%d",&WithdrawAmount);
		if(WithdrawAmount <= arr[Accdetector].Balance)
		{
			arr[Accdetector].Balance = arr[Accdetector].Balance - WithdrawAmount;
			printf("successful Process\n");
			printf("Current Balance: %d\n",arr[Accdetector].Balance);
		}
		else 
		{		
			printf("Process failed: insufficient amount\n");
		}
	}
	else
	{
		printf("Account Closed or Restricted\n");
	}
	main();
}



void deposite(u8 Accdetector)
{
	if(arr[Accdetector].AccountStatus == ( void * )"Active")
	{
		u32 DepositeAmount;
		printf("Enter the amount that you want to deposite: \n");
		scanf("%d",&DepositeAmount);
		arr[Accdetector].Balance = arr[Accdetector].Balance + DepositeAmount;
		printf("Money Deopsited\n");
		printf("Current Balance: %d\n",arr[Accdetector].Balance);
	}
	else 
	{		
		printf("Account Closed or Restricted\n");
	}
	main();
}