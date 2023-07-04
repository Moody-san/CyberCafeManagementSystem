#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct
{
	int d, m, y;
}
DATE;

typedef struct
{
	char *name, sex, *cnic, *email, *pnum, *prem, *username, *password, *confirm;
	int age, bal;
	DATE dob;
}
USER;

typedef struct
{
	int burger;
	int pizza;
	int chickroll;
	int beefroll;
	int mayoroll;
	int zingburger;
	int sandwich;
	int pepsi;
	int dew;
	int marinda; 
}menu;

//global variables 
char **ptr,**str;
int i, z;
USER users;

// Function prototypes
void admin(void);
void login(void);
void signup(void);
void name(USER *u);
void age(USER *u);
void bday(USER *u);
void sex(USER *u);
void cnic(USER *u);
void email(USER *u);
void phone_num(USER *u);
void username(USER *u);
void password(USER *u);
void transfer_to_file(USER *u);
void Hassan_Mehmood(char *u);
void records(void);
void search_cnic(void);
void search_email(void);
void search_phonenum(void);
void search_username(void);
void search_password(void);
void balance(int line);
void ban(int line);
void mac(void);
void duration(int *rd,char *u);
int timer(int x, int *rd, char *u);
void freed(void);
int update_bal(int b, char *u);
int refund(int b, char *u);
void check_premium(int *rd, char *u);
int check(char *u);
void p_duration (int *rd, char *u);
int check_balance(char *u);
int date(char *u);
int book_session(char *u);
void booking_menu(char *u);
void p_menu(char*u);
int rooms(char *u, char *x);
int restaurant(char prem);
int upgrade(char *u);
void tech(void);

int main(void)
{
	printf("\t\t\t\tWELCOME TO MHM NETCAFE\n\n");
	int ans;
	printf("Admin or customer? Press 1 for admin and 2 for customer.\n\n");
	scanf("%d", &ans);
	if (ans != 1 && ans != 2)
	{
		do
		{
			printf("You can only enter 1 and 2. Please re-try: ");
			scanf("%d", &ans);
		}
		while (ans != 1 && ans != 2);
	}
	if (ans == 1)
	{
		system("cls");
		printf("\t\t\t\tADMIN LOGIN\n\n");
		admin();
	}
	else
	{
		system("cls");
		printf("\t\t\t\tCUSTOMER\n\n");
		printf("Login or Sign up? Press 1 for login and 2 for sign up.\n\n");
		scanf("%d", &ans);
		if (ans != 1 && ans != 2)
	    {
		    do
		    {
			    printf("You can only enter 1 and 2. Please re-try: ");
			    scanf("%d", &ans);
		    }
		    while (ans != 1 && ans != 2);
	    }
		if (ans == 1)
		{
			system("cls");
			printf("\t\t\t\tCUSTOMER LOGIN\n\n");
			login();
		}
		else
			signup();
	}
	return 0;
}

void signup(void)
{
	system("cls");
	printf("\t\t\t\tSIGN UP\n\n");
	name(&users);
	age(&users);
	bday(&users);
    sex(&users);
	cnic(&users);
	email(&users);
	phone_num(&users);
	username(&users);
	password(&users);
	users.bal = 0;
	users.prem = "regular";
	transfer_to_file(&users);
	free(users.name);
	free(users.cnic);
	free(users.email);
	free(users.pnum);
	free(users.username);
	free(users.password);
	free(users.confirm);
	printf("\n\nYour account has been made!\n");
}

void name(USER *u)
{
	printf("Name: ");
	u->name = (char *) malloc (1 * sizeof(char));
	if (u->name == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int i = 0, j = 0;
	do
	{
		u->name = (char *) realloc (u->name, (i + 1) * sizeof(char));
		if (u->name == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
		*(u->name + i) = getche();	
		i++;
	}
	while (*(u->name + i - 1) != 13);
	*(u->name + i) = '\0';
	for (j; j < i - 1; j++) // Ensuring only letters and spaces are allowed in name
	{
		if ((*(u->name + j) < 65 && *(u->name + j) != 32) || (*(u->name + j) > 90 && *(u->name + j) < 97) || *(u->name + j) > 122)
		{
			printf("\nName must only contain letters and spaces.\nPlease re-enter. ");
			free(u->name);
			name(&users);
			break;
		}
	}
}

void age(USER *u)
{
	printf("\nAge: ");
	scanf("%d", &u->age);
	if (u->age < 10 || u->age > 99) // Ensuring age is between 10 and 99
	{
		do
		{
			printf("Age must be between 10 and 99.\nPlease re-enter: ");
			scanf("%d", &u->age);
		}
		while (u->age < 10 || u->age > 99);
	}
}

void bday(USER *u)
{
	printf("Date of birth (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &u->dob.m, &u->dob.d, &u->dob.y);
	if (u->dob.y > 2010 || u->dob.y < 1921) // Validation for year
	{
		printf("Incorrect date. Year must be between 1921 and 2010.\nPlease re-enter. ");
		bday(&users);
	}
	if (u->dob.m > 12 || u->dob.m < 1) // Validation for month
	{
		printf("Incorrect date. Month must be between 1 and 12.\nPlease re-enter. ");
		bday(&users);
	}
	switch(u->dob.m) // Validation for day
	{
	    case 1:
	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
	    	if (u->dob.d < 1 || u->dob.d > 31)
	    	{
	    		printf("Incorrect date. Day must be between 1 and 31.\nPlease re-enter. ");
		        bday(&users);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (u->dob.d < 1 || u->dob.d > 30)
	    	{
	    		printf("Incorrect date. Day must be between 1 and 30.\nPlease re-enter. ");
		        bday(&users);
			}
			break;
		default:
			if (u->dob.d < 1 || u->dob.d > 28) // Assuming no lunar year
			{
				printf("Incorrect date. Day must be between 1 and 28.\nPlease re-enter. ");
		        bday(&users);
			}
			break;
	}
	fflush(stdin);
}

void sex(USER *u)
{
	printf("Sex (M or F or O): ");
	scanf("%c", &u->sex);
	fflush(stdin);
	if (u->sex != 'M' && u->sex != 'F' && u->sex != 'O') // Ensuring no other input accepted
	{
		do
		{
			printf("You can enter only M or F or O.\nPlease re-enter: ");
			scanf("%c", &u->sex);
			fflush(stdin);
		}
		while (u->sex != 'M' && u->sex != 'F' && u->sex != 'O');
	}
}

void cnic(USER *u)
{
	printf("CNIC: ");
	u->cnic = (char *) malloc (1 * sizeof(char));
	if (u->cnic == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int i = 0, j = 0;
	do
	{
		u->cnic = (char *) realloc (u->cnic, (i + 1) * sizeof(char));
		if (u->cnic == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
		*(u->cnic + i) = getche();	
		i++;
	}
	while (*(u->cnic + i - 1) != 13);
	*(u->cnic + i) = '\0';
	for (j; j < i - 1; j++) // Ensuring only numbers and - allowed in CNIC
	{
		if ((*(u->cnic + j) < 48 && *(u->cnic + j) != 45) || (*(u->cnic + j) > 57))
		{
			printf("\nCNIC must contain only numbers and -\nPlease re-enter. ");
			free(u->cnic);
			cnic(&users);
			break;
		}
	}
}

void email(USER *u)
{
	printf("\nEmail: ");
	u->email = (char *) malloc (1 * sizeof(char));
	if (u->email == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int i = 0;
	do
	{
		u->email = (char *) realloc (u->email, (i + 1) * sizeof(char));
		if (u->email == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
		*(u->email + i) = getche();	
		i++;
	}
	while (*(u->email + i - 1) != 13);
	*(u->email + i) = '\0';
}

void phone_num(USER *u)
{
	printf("\nPhone Number: ");
	u->pnum = (char *) malloc (1 * sizeof(char));
	if (u->pnum == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int i = 0, j = 0;
	do
	{
		u->pnum = (char *) realloc (u->pnum, (i + 1) * sizeof(char));
		if (u->pnum == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
		*(u->pnum + i) = getche();
		i++;
	}
	while (*(u->pnum + i - 1) != 13);
	*(u->pnum + i) = '\0';
	for (j; j < i - 1; j++) // Ensuring only numbers, *, #, and - allowed in phone number
	{
		if ((*(u->pnum + j) < 48 && *(u->pnum + j) != 45 && *(u->pnum + j) != 42 && *(u->pnum + j) != 35) || (*(u->pnum + j) > 57))
		{
			printf("\nPhone number must contain only numbers, *, #, and -. Please re-enter.");
			free(u->pnum);
			phone_num(&users);
			break;
		}
	}
}

void username(USER *u)
{
	printf("\nUsername: ");
	u->username = (char *) malloc (1 * sizeof(char));
	if (u->username == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int i = 0;
	do
	{
		u->username = (char *) realloc (u->username, (i + 1) * sizeof(char));
		if (u->username == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
		*(u->username + i) = getche();
		i++;
	}
	while (*(u->username + i - 1) != 13);
	*(u->username + i) = '\0';
}

void password(USER *u)
{
	char c;
	printf("\nPassword: ");
	u->password = (char *) malloc (1 * sizeof(char));
	if (u->password == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int i = 0;
	c = getch();
	while (c != 13)
	{
		printf("*");
		u->password = (char *) realloc (u->password, (i + 1) * sizeof(char));
		if (u->password == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
		*(u->password + i) = c;
		i++;
		c = getch();
	}
	*(u->password + i) = '\0';
	printf("\nConfirm Password: "); // Confirming password
	u->confirm = (char *) malloc (1 * sizeof(char));
	if (u->confirm == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
    i = 0;
	c = getch();
	while (c != 13)
	{
		printf("*");
		u->confirm = (char *) realloc (u->confirm, (i + 1) * sizeof(char));
		if (u->confirm == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
		*(u->confirm + i) = c;
		i++;
		c = getch();
	}
	*(u->confirm + i) = '\0';
	if (strcmp(u->password, u->confirm) != 0)
	{
		printf("\nPassword must be same. Please re-enter.");
		free(u->password);
		free(u->confirm);
		password(&users);
	}
}

void transfer_to_file(USER *u)
{
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "a");
	if (customer == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	fprintf(customer, "\nName: %s\nAge: %d\nDate of birth: %d/%d/%d\nSex: %c\nCNIC: %s\nEmail: %s\nPhone Number: %s\nUsername: %s\nPassword: %s\nBalance: %d\nAccount Type: %s\nDate: 1/20/2021 \nSession: 21(date)16(hour)30(min)\nRoom: STRATEGY ROOM  \n"
	        , u->name, u->age, u->dob.d, u->dob.m, u->dob.y, u->sex, u->cnic, u->email, u->pnum, u->username, u->password, u->bal, u->prem); // We have hardcoded default values.
	fclose(customer);
}

void admin(void)
{
	char c, *nm = (char *) malloc (1 * sizeof(char)), *pw = (char *) malloc (1 * sizeof(char));
	if (nm == NULL || pw == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	printf("Username: ");
	int i = 0;
	c = getche();
	while (c != 13)
	{
		nm = (char *) realloc (nm, (i + 1) * sizeof(char));
		if (nm == NULL)
		{
			printf("\nError. Not enough space in memory.");
		    exit(0);
		}
		*(nm + i) = c;
		i++;
		c = getche();
	}
	*(nm + i) = '\0';
	printf("\nPassword: ");
	i = 0;
	c = getch();
	while (c != 13)
	{
		printf("*");
		pw = (char *) realloc (pw, (i + 1) * sizeof(char));
		if (pw == NULL)
		{
			printf("\nError. Not enough space in memory.");
		    exit(0);
		}
		*(pw + i) = c;
		i++;
		c = getch();
	}
	*(pw + i) = '\0';
	FILE *adm = fopen("D:\\dev\\PROGRAMS\\admin.txt", "r");
	if (adm == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	char *au = (char *) malloc (1 * sizeof(char));
	if (au == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	fseek(adm, 10, SEEK_CUR);
	i = 0;
	while ((c = fgetc(adm)) != '\n')
	{
		au = (char *) realloc (au, (i + 1) * sizeof(char));
		if (au == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
            exit(0);
	    }
		*(au + i) = c;
		i++;
	}
	*(au + i) = '\0';
	if (strcmp(nm ,au) == 0)
	{
		char *ap = (char *) malloc (1 * sizeof(char));
		if (ap == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
	    fseek(adm, 12, SEEK_CUR);
	    i = 0;
	    while ((c = fgetc(adm)) != '\n')
	    {
		    ap = (char *) realloc (ap, (i + 1) * sizeof(char));
		    if (ap == NULL)
	        {
		        printf("\nError. Not enough space in memory.");
                exit(0);
	        }
		    *(ap + i) = c;
		    i++;
	    }
	    *(ap + i) = '\0';
	    if (strcmp(pw, ap) == 0)
	    {
	    	free(nm);
	    	free(pw);
	    	free(au);
	    	free(ap);
	    	fclose(adm);
	    	records();
		}
	    else
	    {
	    	printf("\n\nIncorrect password.\n\n");
	    	free(nm);
	    	free(pw);
	    	free(au);
		    free(ap);
		    fclose(adm);
	    	admin();
		}
	}
	else
	{
		printf("\n\nIncorrect username.\n\n");
		free(nm);
		free(pw);
		free(au);
		fclose(adm);
		admin();
	}
}

void login(void)
{
	char c, *nm = (char *) malloc (1 * sizeof(char)), *pw = (char *) malloc (1 * sizeof(char));
	if (nm == NULL || pw == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	printf("Username: ");
	int i = 0;
	c = getche();
	while (c != 13)
	{
		nm = (char *) realloc (nm, (i + 1) * sizeof(char));
		if (nm == NULL)
		{
			printf("\nError. Not enough space in memory.");
		    exit(0);
		}
		*(nm + i) = c;
		i++;
		c = getche();
	}
	*(nm + i) = '\0';
	printf("\nPassword: ");
	i = 0;
	c = getch();
	while (c != 13)
	{
		printf("*");
		pw = (char *) realloc (pw, (i + 1) * sizeof(char));
		if (pw == NULL)
		{
			printf("\nError. Not enough space in memory.");
		    exit(0);
		}
		*(pw + i) = c;
		i++;
		c = getch();
	}
	*(pw + i) = '\0';
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "r"); // Checking username and password
	if (customer == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int n = 0, j = 1;
	while ((c = fgetc(customer)) != EOF)
	{
		if (c == '\n')
		    n++;
		if (n == (15 * j - 7))
		{
			char *chu = (char *) malloc (1 * sizeof(char));
			if (chu == NULL)
			{
				printf("\nError. Not enough space in memory.");
		        exit(0);
			}
			j++;
			fseek(customer, 10, SEEK_CUR);
			i = 0;
			while ((c = fgetc(customer)) != '\n')
			{
				chu = (char *) realloc (chu, (i + 1) * sizeof(char));
				if (chu == NULL)
	            {
		            printf("\nError. Not enough space in memory.");
		            exit(0);
	            }
				*(chu + i) = c;
				i++;
			}
			n++;
			*(chu + i) = '\0';
			if (strcmp(nm, chu) == 0)
			{
				char *chp = (char *) malloc (1 * sizeof(char));
				if (chp == NULL)
				{
					printf("\nError. Not enough space in memory.");
		            exit(0);
				}
				fseek(customer, 10, SEEK_CUR);
			    i = 0;
			    while ((c = fgetc(customer)) != '\n')
			    {
				    chp = (char *) realloc (chp, (i + 1) * sizeof(char));
			 	    if (chp == NULL)
	                {
		                printf("\nError. Not enough space in memory.");
		                exit(0);
	                }
				    *(chp + i) = c;
				    i++;
			    }
			    *(chp + i) = '\0';
			    if (strcmp(pw, chp) == 0)
			    {
			    	free(nm);
			    	free(pw);
			    	free(chp);
			    	fclose(customer);
			    	Hassan_Mehmood(chu);
			    	free(chu);
			    	exit(0);
				}
				else
				{
					printf("\n\nIncorrect password.\n\n");
					free(nm);
					free(pw);
					free(chu);
					free(chp);
					fclose(customer);
					login();
				}
			}
			free(chu);
		}
	}
	printf("\n\nIncorrect username.\n\n");
	free(nm);
	free(pw);
	fclose(customer);
	login();
}

void Hassan_Mehmood(char *u)
{
	system("cls");
	printf("\t\t\t\tWELCOME BACK\n\n");
	srand(time(0)); //to generate a random number
	int r = rand() % 5; //to generate a random number between 1 and 5. This number is used for assignment of IP.
	mac(); //to assign an IP address
	duration(&r, u); //Main function
}

void records(void)
{
	system("cls");
	printf("\t\t\t\tCUSTOMER RECORDS\n\n");
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "r");
	if (customer == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	char c;
	while((c = fgetc(customer)) != EOF)
	    printf("%c", c);
	printf("\nPress S to search for any customer. Press Esc to end the program.\n\n");
	c = getche();
	if (c != 'S' && c != 27) // 27 is the ASCII code for Esc
	{
		do
		{
			printf("\nInvalid command. Please re-try: ");
			c = getche();
		}
		while (c != 'S' && c != 27);
	}
	if (c == 'S')
	{
		int a;
		printf("\n\nSelect any of the following numbers:\n1) Search by CNIC\n2) Search by email\n3) Search by phone number\n4) Search by username\n5) Search by password\n\n");
		scanf("%d", &a);
		if (a < 1 || a > 5)
		{
			do
			{
				printf("Enter a valid number. Please re-try: ");
				scanf("%d", &a);
			}
			while (a < 1 || a > 5);
		}
		fclose(customer);
	    system("cls");
	    printf("\t\t\t\tSEARCHING\n\n");
	    switch(a)
	    {
	    	case 1:
	    		search_cnic();
	    		break;
	    	case 2:
	    		search_email();
	    		break;
	    	case 3:
	    		search_phonenum();
	    		break;
	    	case 4:
	    		search_username();
	    		break;
	    	default:
	    		search_password();
	    		break;
		}
	}
	else
	    fclose(customer);
}

void search_cnic(void)
{
	char c, *cn = (char *) malloc (1 * sizeof(char));
	if (cn == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	printf("Enter CNIC: ");
	int i = 0;
	c = getche();
	while (c != 13)
	{
		cn = (char *) realloc (cn, (i + 1) * sizeof(char));
		if (cn == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
	    *(cn + i) = c;
	    i++;
	    c = getche();
	}
	*(cn + i) = '\0';
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "r");
	if (customer == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int n = 0, j = 1, l;
	while ((c = fgetc(customer)) != EOF)
	{
		if (c == '\n')
		    n++;
		if (n == (15 * j - 10))
		{
			char *chc = (char *) malloc (1 * sizeof(char));
			if (chc == NULL)
			{
				printf("\nError. Not enough space in memory.");
		        exit(0);
			}
			j++;
			fseek(customer, 6, SEEK_CUR);
			i = 0;
			while ((c = fgetc(customer)) != '\n')
			{
				chc = (char *) realloc (chc, (i + 1) * sizeof(char));
				if (chc == NULL)
	            {
		            printf("\nError. Not enough space in memory.");
		            exit(0);
	            }
				*(chc + i) = c;
				i++;
			}
			n++;
			*(chc + i) = '\0';
			if (strcmp(cn, chc) == 0)
			{
				printf("\n\n");
				l = n;
				n = 0;
				rewind(customer);
				while (n != l - 5)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
				}
				while (n != l + 9)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
					printf("%c", c);
				}
				printf("\n\nPress B to update balance; press N to ban this customer; press Esc to go back.\n\n");
				c = getche();
				if (c != 'B' && c != 'N' && c != 27) // 27 is ASCII code of Esc
				{
					do
					{
						printf("\nInvalid command. Please re-try: ");
						c = getche();
					}
					while (c != 'B' && c != 'N' && c != 27);
				}
				if (c == 'B')
				{
					free(cn);
					free(chc);
					fclose(customer);
					balance(l - 6);
					exit(0);
				}
				else if (c == 'N')
				{
					free(cn);
					free(chc);
					fclose(customer);
					ban(l - 6);
					exit(0);
				}
				else
				{
					free(cn);
					free(chc);
					fclose(customer);
					records();
					exit(0);
				}
			}
			free(chc);
		}
	}
	printf("\n\nIncorrect CNIC.\n\n");
	free(cn);
	fclose(customer);
	search_cnic();
}

void search_email(void)
{
	char c, *e = (char *) malloc (1 * sizeof(char));
	if (e == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	printf("Enter email: ");
	int i = 0;
	c = getche();
	while (c != 13)
	{
		e = (char *) realloc (e, (i + 1) * sizeof(char));
		if (e == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
	    *(e + i) = c;
	    i++;
	    c = getche();
	}
	*(e + i) = '\0';
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "r");
	if (customer == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int n = 0, j = 1, l;
	while ((c = fgetc(customer)) != EOF)
	{
		if (c == '\n')
		    n++;
		if (n == (15 * j - 9))
		{
			char *che = (char *) malloc (1 * sizeof(char));
			if (che == NULL)
			{
				printf("\nError. Not enough space in memory.");
		        exit(0);
			}
			j++;
			fseek(customer, 7, SEEK_CUR);
			i = 0;
			while ((c = fgetc(customer)) != '\n')
			{
				che = (char *) realloc (che, (i + 1) * sizeof(char));
				if (che == NULL)
	            {
		            printf("\nError. Not enough space in memory.");
		            exit(0);
	            }
				*(che + i) = c;
				i++;
			}
			n++;
			*(che + i) = '\0';
			if (strcmp(e, che) == 0)
			{
				printf("\n\n");
				l = n;
				n = 0;
				rewind(customer);
				while (n != l - 6)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
				}
				while (n != l + 8)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
					printf("%c", c);
				}
				printf("\n\nPress B to update balance; press N to ban this customer; press Esc to go back.\n\n");
				c = getche();
				if (c != 'B' && c != 'N' && c != 27) // 27 is ASCII code of Esc
				{
					do
					{
						printf("\nInvalid command. Please re-try: ");
						c = getche();
					}
					while (c != 'B' && c != 'N' && c != 27);
				}
				if (c == 'B')
				{
					free(e);
					free(che);
					fclose(customer);
					balance(l - 7);
					exit(0);
				}
				else if (c == 'N')
				{
					free(e);
					free(che);
					fclose(customer);
					ban(l - 7);
					exit(0);
				}
				else
				{
					free(e);
					free(che);
					fclose(customer);
					records();
					exit(0);
				}
			}
			free(che);
		}
	}
	printf("\n\nIncorrect email.\n\n");
	free(e);
	fclose(customer);
	search_email();
}

void search_phonenum(void)
{
	char c, *no = (char *) malloc (1 * sizeof(char));
	if (no == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	printf("Enter phone number: ");
	int i = 0;
	c = getche();
	while (c != 13)
	{
		no = (char *) realloc (no, (i + 1) * sizeof(char));
		if (no == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
	    *(no + i) = c;
	    i++;
	    c = getche();
	}
	*(no + i) = '\0';
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "r");
	if (customer == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int n = 0, j = 1, l;
	while ((c = fgetc(customer)) != EOF)
	{
		if (c == '\n')
		    n++;
		if (n == (15 * j - 8))
		{
			char *chn = (char *) malloc (1 * sizeof(char));
			if (chn == NULL)
			{
				printf("\nError. Not enough space in memory.");
		        exit(0);
			}
			j++;
			fseek(customer, 14, SEEK_CUR);
			i = 0;
			while ((c = fgetc(customer)) != '\n')
			{
				chn = (char *) realloc (chn, (i + 1) * sizeof(char));
				if (chn == NULL)
	            {
		            printf("\nError. Not enough space in memory.");
		            exit(0);
	            }
				*(chn + i) = c;
				i++;
			}
			n++;
			*(chn + i) = '\0';
			if (strcmp(no, chn) == 0)
			{
				printf("\n\n");
				l = n;
				n = 0;
				rewind(customer);
				while (n != l - 7)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
				}
				while (n != l + 7)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
					printf("%c", c);
				}
				printf("\n\nPress B to update balance; press N to ban this customer; press Esc to go back.\n\n");
				c = getche();
				if (c != 'B' && c != 'N' && c != 27) // 27 is ASCII code of Esc
				{
					do
					{
						printf("\nInvalid command. Please re-try: ");
						c = getche();
					}
					while (c != 'B' && c != 'N' && c != 27);
				}
				if (c == 'B')
				{
					free(no);
					free(chn);
					fclose(customer);
					balance(l - 8);
					exit(0);
				}
				else if (c == 'N')
				{
					free(no);
					free(chn);
					fclose(customer);
					ban(l - 8);
					exit(0);
				}
				else
				{
					free(no);
					free(chn);
					fclose(customer);
					records();
					exit(0);
				}
			}
			free(chn);
		}
	}
	printf("\n\nIncorrect phone number.\n\n");
	free(no);
	fclose(customer);
	search_phonenum();
}

void search_username(void)
{
	char c, *nm = (char *) malloc (1 * sizeof(char));
	if (nm == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	printf("Enter username: ");
	int i = 0;
	c = getche();
	while (c != 13)
	{
		nm = (char *) realloc (nm, (i + 1) * sizeof(char));
		if (nm == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
	    *(nm + i) = c;
	    i++;
	    c = getche();
	}
	*(nm + i) = '\0';
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "r");
	if (customer == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int n = 0, j = 1, l;
	while ((c = fgetc(customer)) != EOF)
	{
		if (c == '\n')
		    n++;
		if (n == (15 * j - 7))
		{
			char *chu = (char *) malloc (1 * sizeof(char));
			if (chu == NULL)
			{
				printf("\nError. Not enough space in memory.");
		        exit(0);
			}
			j++;
			fseek(customer, 10, SEEK_CUR);
			i = 0;
			while ((c = fgetc(customer)) != '\n')
			{
				chu = (char *) realloc (chu, (i + 1) * sizeof(char));
				if (chu == NULL)
	            {
		            printf("\nError. Not enough space in memory.");
		            exit(0);
	            }
				*(chu + i) = c;
				i++;
			}
			n++;
			*(chu + i) = '\0';
			if (strcmp(nm, chu) == 0)
			{
				printf("\n\n");
				l = n;
				n = 0;
				rewind(customer);
				while (n != l - 8)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
				}
				while (n != l + 6)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
					printf("%c", c);
				}
				printf("\n\nPress B to update balance; press N to ban this customer; press Esc to go back.\n\n");
				c = getche();
				if (c != 'B' && c != 'N' && c != 27) // 27 is ASCII code of Esc
				{
					do
					{
						printf("\nInvalid command. Please re-try: ");
						c = getche();
					}
					while (c != 'B' && c != 'N' && c != 27);
				}
				if (c == 'B')
				{
					free(nm);
					free(chu);
					fclose(customer);
					balance(l - 9);
					exit(0);
				}
				else if (c == 'N')
				{
					free(nm);
					free(chu);
					fclose(customer);
					ban(l - 9);
					exit(0);
				}
				else
				{
					free(nm);
					free(chu);
					fclose(customer);
					records();
					exit(0);
				}
			}
			free(chu);
		}
	}
	printf("\n\nIncorrect username.\n\n");
	free(nm);
	fclose(customer);
	search_username();
}

void search_password(void)
{
	char c, *pw = (char *) malloc (1 * sizeof(char));
	if (pw == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	printf("Enter password: ");
	int i = 0;
	c = getche();
	while (c != 13)
	{
		pw = (char *) realloc (pw, (i + 1) * sizeof(char));
		if (pw == NULL)
	    {
		    printf("\nError. Not enough space in memory.");
		    exit(0);
	    }
	    *(pw + i) = c;
	    i++;
	    c = getche();
	}
	*(pw + i) = '\0';
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "r");
	if (customer == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	int n = 0, j = 1, l;
	while ((c = fgetc(customer)) != EOF)
	{
		if (c == '\n')
		    n++;
		if (n == (15 * j - 6))
		{
			char *chp = (char *) malloc (1 * sizeof(char));
			if (chp == NULL)
			{
				printf("\nError. Not enough space in memory.");
		        exit(0);
			}
			j++;
			fseek(customer, 10, SEEK_CUR);
			i = 0;
			while ((c = fgetc(customer)) != '\n')
			{
				chp = (char *) realloc (chp, (i + 1) * sizeof(char));
				if (chp == NULL)
	            {
		            printf("\nError. Not enough space in memory.");
		            exit(0);
	            }
				*(chp + i) = c;
				i++;
			}
			n++;
			*(chp + i) = '\0';
			if (strcmp(pw, chp) == 0)
			{
				printf("\n\n");
				l = n;
				n = 0;
				rewind(customer);
				while (n != l - 9)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
				}
				while (n != l + 5)
				{
					c = fgetc(customer);
					if (c == '\n')
					    n++;
					printf("%c", c);
				}
				printf("\n\nPress B to update balance; press N to ban this customer; press Esc to go back.\n\n");
				c = getche();
				if (c != 'B' && c != 'N' && c != 27) // 27 is ASCII code of Esc
				{
					do
					{
						printf("\nInvalid command. Please re-try: ");
						c = getche();
					}
					while (c != 'B' && c != 'N' && c != 27);
				}
				if (c == 'B')
				{
					free(pw);
					free(chp);
					fclose(customer);
					balance(l - 10);
					exit(0);
				}
				else if (c == 'N')
				{
					free(pw);
					free(chp);
					fclose(customer);
					ban(l - 10);
					exit(0);
				}
				else
				{
					free(pw);
					free(chp);
					fclose(customer);
					records();
					exit(0);
				}
			}
			free(chp);
		}
	}
	printf("\n\nIncorrect password.\n\n");
	free(pw);
	fclose(customer);
	search_password();
}

void balance(int line)
{
	int b;
	printf("\nEnter new balance: ");
	scanf("%d", &b);
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "r");
	FILE *f = fopen("D:\\dev\\PROGRAMS\\tmp.txt", "w");
	if (customer == NULL || f == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	char c;
	int n = 0;
	while ((c = fgetc(customer)) != EOF)
	{
		if (c == '\n')
		    n++;
		if (n == line + 10)
		{
			fprintf(f, "\nBalance: %d", b);
			fscanf(customer, "%*s %*s");
			continue;
		}
		fputc(c, f);
	}
	fclose(customer);
	fclose(f);
	remove("D:\\dev\\PROGRAMS\\cus.txt");
	rename("D:\\dev\\PROGRAMS\\tmp.txt", "D:\\dev\\PROGRAMS\\cus.txt");
	printf("\nBalance has been updated successfully!\n\nPress Esc key to go back.");
	c = getche();
	while (c != 27)
	{
		printf("\nInvalid command. Press Esc to return.");
		c = getche();
	}
	records();
	exit(0);
}

void ban(int line)
{
	FILE *customer = fopen("D:\\dev\\PROGRAMS\\cus.txt", "r");
	FILE *f = fopen("D:\\dev\\PROGRAMS\\tmp.txt", "w");
	if (customer == NULL || f == NULL)
	{
		printf("\nError. Not enough space in memory.");
		exit(0);
	}
	char c;
	int n = 0;
	while ((c = fgetc(customer)) != EOF)
	{
		if (c == '\n')
		    n++;
		if ((n >= line) && (n <= line + 14))
		    continue;
		fputc(c, f);
	}
	fclose(customer);
	fclose(f);
	remove("D:\\dev\\PROGRAMS\\cus.txt");
	rename("D:\\dev\\PROGRAMS\\tmp.txt", "D:\\dev\\PROGRAMS\\cus.txt");
	printf("\nCustomer has been banned, and his/her record has been deleted.\n\nPress Esc key to go back.");
	c = getche();
	while (c != 27)
	{
		printf("\nInvalid command. Press Esc to return.");
		c = getche();
	}
	records();
	exit(0);
}

void mac(void)
{
    ptr = malloc (5 * sizeof(char*));
    for (i = 0; i < 5; i++)
    	ptr[i] = malloc (18 * sizeof(char));
	str = malloc (5 * sizeof(char*));
    for (i = 0; i < 5; i++)
    	str[i] = malloc (15 * sizeof(char));
    
    //ptr is for MAC addresses and str is for IP addresses
    
	strcpy (ptr[0],"b7:51:28:2e:3c:34");
	strcpy (ptr[1],"e2:18:99:98:26:6c");
	strcpy (ptr[2],"7c:ca:cc:51:17:e2");
	strcpy (ptr[3],"ef:d0:a4:05:ab:7a");
	strcpy (ptr[4],"4d:a3:10:cf:7e:2d");
	strcpy (str[0],"151.169.143.57");
	strcpy (str[1],"156.109.72.218");
	strcpy (str[2],"41.237.219.116");
	strcpy (str[3],"67.231.125.236");
	strcpy (str[4],"58.145.254.161");
}

void duration(int *rd,char *u)
{
	char ch;
	float x;
	system("cls");
	printf("Please select duration of session from the options below......");
	printf("\n1 -|1 hour for 100 Pkr|-");
	printf("\n2 -|2 hour for 190 Pkr|-");
	printf("\n3 -|3 hour for 280 Pkr|-");
	printf("\n4 -|Premium discounts!|-");
	printf("\n5 -|logout and exit   |-");
	printf("\n6 -|BOOKINGS          |-");
	printf("\n7 -|CHECK BALANCE     |-");
	printf("\n8 -|UPGRADE TO PREMIUM|-");
	printf("\n9 -|Restuarant        |-");
	printf("\na -|Technician        |-");
	printf("\n\n Your Choice: ");
	fflush(stdin);
	scanf("%c",&ch);
	switch (ch){
		case '1':
			update_bal(100,u);
			date(u);
			x=(float)timer(1,rd,u);
			if(x!=0){
				if(x>=0.9*3600)
				refund(100,u);
			}
			break;
		case '2':
			update_bal(190,u);
			date(u);
			x=(float)timer(2,rd,u);
			if(x!=0){
				if(x>=0.9*7200)
				refund(190,u);
			}
			break;
		case '3':
			update_bal(280,u);
			date(u);
			x=(float)timer(3,rd,u);
			if(x!=0){
				if(x>=0.9*10800)
				refund(280,u);
			}
			break;
		case '4':
			check_premium(rd,u);
			exit(0);
		case '5':
			system("cls");
			printf("\nCome back Another time :)\nPress any key to continue.....");	
			getch();
			break;
		case '6':
			system("cls");
			booking_menu(u);
			duration(rd,u);	
		case '7':
			system("cls");
			check_balance(u);
			duration(rd,u);	
		case '8':
			if(!check(u)){
				system("cls");
				upgrade(u);
				update_bal(500,u);
				printf("ACCOUNT UPGRADED\npress any key to continue...");
				getch();
				duration(rd,u);
			}
			else{
				printf("\nYou are already premium member ;)\npress any key to continue...");
				getch();
			}
			duration(rd,u);
		case '9':
			if(check(u)){
				system("cls");
				update_bal(restaurant('y'),u);
			}
			else{
				system("cls");
				update_bal(restaurant('n'),u);
			}	
			duration(rd,u);
		case 'a':
			system("cls");
			tech();
			duration(rd,u);	
		default:
			system("cls");
			printf("Please choose from options (1-9):\nPress any key to continue....");
			getch();
			duration(rd,u);						
	}
	fflush(stdin);
	exit(0);
}

int timer(int x, int *rd, char *u)
{
	int flag=0;
	char chr;
	system ("cls");
	x=x*3600;
	while(flag==0){
		printf("\n\nMAC-ADDRESS:%s\nIP-ADDRESS:%s",ptr[*rd],str[*rd]);
		printf("\n\n\n\nREMAINING TIME(Press 5 to End Session) : %d",x);
		x--;
		sleep(1);
		system ("cls");
		if(x==0){
			flag=1;
			break;
		}
		if(kbhit()){
			chr=getch();
			if(chr==53)
			break;		
		}
	}
	freed();
	if(flag==1){
		printf("\nSession has expired:\nPress any key to continue....");
		getch();
	}
	else{
		printf("\nSession Terminated with %d seconds remaining. \n\nPress any key to continue....",x);
		getch();
        return x;
	}
	return 0;	
}

void freed(void)
{
	for (i = 0; i < 5; i++)
	{
    	free(str[i]);
    	free(ptr[i]);
	}
	free(str);
	free(ptr);
}

int update_bal(int b, char *u)
{
	char cr,c,*S;
	int j=0,bal,r;
	i=1;
	S=malloc(25*sizeof(char));
	FILE *customer =fopen("D:\\dev\\PROGRAMS\\cus.txt","r+");
	if( customer == NULL ) {
      perror("Error: ");
      free(S);
      return(-1);
   }
	else{
		cr=fgetc(customer);
		while(cr!=EOF){
			if(cr=='\n'){
				i++;
				if(i==9){
					fseek(customer,10,1);
					i=-5;
					c=fgetc(customer);
					for(z=0;z<strlen(S);z++){
						S[z]=0;
					}
					z=0;
					while(c!='\n'){
						S[j]=c;
						c=fgetc(customer);
						j++;
					}
					S[j]='\0';
					j=0;
					if(strcmp(S,u)==0){
						i=9;
						j=0;
						cr=fgetc(customer);
						while(i!=15&&cr!=EOF){
							if(cr=='\n'){
								i++;
								if(i==10){
									fseek(customer,9,1);
									r=ftell(customer);
									c=fgetc(customer);
									for(z=0;z<strlen(S);z++){
										S[z]=0;
									}
									while(c!='\n'){
										S[j]=c;
										c=fgetc(customer);
										j++;
									}
									S[j]='\0';
									z=strlen(S);
									bal=atoi(S)-b;
									itoa(bal,S,10);
									fseek(customer,r,0);
									if(strlen(S)<z){
										for(i=0;i<(strlen(S)-z);i++){
											strcat(S," ");
										}
									}
									for(z=0;z<strlen(S);z++){
										putc(S[z],customer);
									}
									free(S);
									fclose(customer);
									return 0;
								}
							}
							cr=fgetc(customer);
						}
					}
				}
			}
			cr=fgetc(customer);
		}
	}
	free(S);
	fclose(customer);
	return 0;
}

int refund(int b, char *u)
{
	char cr,c,*S;
	int j=0,bal=0,r;
	i=1;
	S=malloc(25*sizeof(char));
	FILE *customer =fopen("D:\\dev\\PROGRAMS\\cus.txt","r+");
	if( customer == NULL ) {
      perror("Error: ");
      free(S);
      return(-1);
   }
	else{
		cr=fgetc(customer);
		while(cr!=EOF){
			if(cr=='\n'){
				i++;
				if(i==9){
					fseek(customer,10,1);
					i=-5;
					c=fgetc(customer);
					for(z=0;z<strlen(S);z++){
						S[z]=0;
					}
					z=0;
					while(c!='\n'){
						S[j]=c;
						c=fgetc(customer);
						j++;
					}
					S[j]='\0';
					j=0;
					if(strcmp(S,u)==0){
						i=9;
						j=0;
						cr=fgetc(customer);
						while(i!=15&&cr!=EOF){
							if(cr=='\n'){
								i++;
								if(i==10){
									fseek(customer,9,1);
									r=ftell(customer);
									c=fgetc(customer);
									for(z=0;z<strlen(S);z++){
										S[z]=0;
									}
									while(c!='\n'){
										S[j]=c;
										c=fgetc(customer);
										j++;
									}
									S[j]='\0';
									z=strlen(S);
									bal=atoi(S)+b;
									itoa(bal,S,10);
									fseek(customer,r,0);
									if(strlen(S)<z){
										for(i=0;i<(z-strlen(S));i++){
											strcat(S," ");
										}
									}
									for(z=0;z<strlen(S);z++){
										putc(S[z],customer);
									}
									free(S);
									fclose(customer);
									return 0;
								}
							}
							cr=fgetc(customer);
						}
					}
				}
			}
			cr=fgetc(customer);
		}
	}
	free(S);
	fclose(customer);
	return 0;
}

void check_premium(int *rd, char *u)
{
	if(check(u))
		p_duration(rd,u);
	else
	{
		printf("\n\nPlease upgrade to Premium first :)");
		getch();
		duration(rd,u);
	}
}

int check(char *u)
{
	char cr,c,S[25],T[25];
	int j=0,flg=0;
	i=1;
	FILE *customer =fopen("D:\\dev\\PROGRAMS\\cus.txt","r+");
	if( customer == NULL )
	{
      perror("Error: ");
      return(-1);
    }
	else
	{
		cr=fgetc(customer);
		while(cr!=EOF){
			if(cr=='\n'){
				i++;
				if(i==9){
					fseek(customer,10,1);
					i=-5;
					c=fgetc(customer);
					for(z=0;z<strlen(S);z++){
						S[z]=0;
						T[z]=0;
					}
					z=0;
					while(c!='\n'){
						S[j]=c;
						c=fgetc(customer);
						j++;
					}
					S[j]='\0';
					j=0;
					if(strcmp(S,u)==0){
						i=9;
						j=0;
						cr=fgetc(customer);
						while(i!=15&&cr!=EOF){
							if(cr=='\n'){
								i++;
								if(i==11){
									fseek(customer,14,1);
									c=fgetc(customer);
									for(z=0;z<strlen(S);z++){
										S[z]=0;
									}
									while(c!='\n'){
										S[j]=c;
										c=fgetc(customer);
										j++;
									}
									strcpy(T,"premium");
									T[j]='\0';
									S[j]='\0';
									
									for(z=0;z<7;z++){
										if(S[z]!=T[z]){
											flg=1;
											break;
										}
									}
									if(!flg){
										fclose(customer);
										return 1;
									}
								}
							}
							cr=fgetc(customer);
						}
					}
				}
			}
			cr=fgetc(customer);
		}
	}
	fclose(customer);
	return 0;
}

void p_duration (int *rd, char *u)
{
	char ch;
	float x;
	system("cls");
	printf("Please select duration of session from the premimum options below......");
	printf("\n1 -|1 hour for 50 Pkr |-");
	printf("\n2 -|2 hour for 100 Pkr|-");
	printf("\n3 -|3 hour for 150 Pkr|-");
	printf("\n4 -|logout and exit   |-");
	printf("\n5 -|CHECK BALANCE     |-");
	printf("\n\nYour Choice: ");
	fflush(stdin);
	scanf("%c",&ch);
	switch (ch)
	{
		case '1':
			update_bal(50,u);
			date(u);
			x=(float)timer(1,rd,u);
			if(x!=0){
				if(x>=0.9*3600)
				refund(50,u);
			}
			break;
		case '2':
			update_bal(100,u);
			date(u);
			x=(float)timer(2,rd,u);
			if(x!=0){
				if(x>=0.9*7200)
				refund(100,u);
			}
			break;
		case '3':
			update_bal(150,u);
			date(u);
			x=(float)timer(3,rd,u);
			if(x!=0){
				if(x>=0.9*10800)
				refund(150,u);
			}
			break;
		case '4':
			system("cls");
			printf("\nCome back Another time :)\nPress any key to continue.....");	
			getch();
			break;
		case '5':
			system("cls");
			check_balance(u);
			p_duration(rd,u);			
		default:
			system("cls");
			printf("Please choose from options (1-5):\nPress any key to continue....");
			getch();
			p_duration(rd,u);						
	}
	fflush(stdin);
	exit(0);
}

int check_balance(char *u)
{
	char cr,c,*S;
	int j=0,bal;
	i=1;
	S=malloc(25*sizeof(char));
	FILE *customer =fopen("D:\\dev\\PROGRAMS\\cus.txt","r+");
	if( customer == NULL)
	{
      perror("Error: ");
      free(S);
      return(-1);
    }
	else{
		cr=fgetc(customer);
		while(cr!=EOF){
			if(cr=='\n'){
				i++;
				if(i==9){
					fseek(customer,10,1);
					i=-5;
					c=fgetc(customer);
					for(z=0;z<strlen(S);z++){
						S[z]=0;
					}
					z=0;
					while(c!='\n'){
						S[j]=c;
						c=fgetc(customer);
						j++;
					}
					S[j]='\0';
					j=0;
					if(strcmp(S,u)==0){
						i=9;
						j=0;
						cr=fgetc(customer);
						while(i!=15&&cr!=EOF){
							if(cr=='\n'){
								i++;
								if(i==10){
									fseek(customer,9,1);
									c=fgetc(customer);
									for(z=0;z<strlen(S);z++){
										S[z]=0;
									}
									while(c!='\n'){
										S[j]=c;
										c=fgetc(customer);
										j++;
									}
									S[j]='\0';
									z=strlen(S);
									bal=atoi(S);
									free(S);
									fclose(customer);
									printf("Your balance: %d\npress any key to continue.....",bal);
									getch();
									return 0;
								}
							}
							cr=fgetc(customer);
						}
					}
				}
			}
			cr=fgetc(customer);
		}
	}
	free(S);
	fclose(customer);
	printf("access denied error...press any key to continue");
	getch();
	return 0;
}

int date(char *u)
{
	char cr,c,*S;
	int j=0,r;
	i=1;
	S=malloc(25*sizeof(char));
	FILE *customer =fopen("D:\\dev\\PROGRAMS\\cus.txt","r+");
	if( customer == NULL ) {
      perror("Error: ");
      free(S);
      return(-1);
   }
	else{
		cr=fgetc(customer);
		while(cr!=EOF){
			if(cr=='\n'){
				i++;
				if(i==9){
					fseek(customer,10,1);
					i=-5;
					c=fgetc(customer);
					for(z=0;z<strlen(S);z++){
						S[z]=0;
					}
					z=0;
					while(c!='\n'){
						S[j]=c;
						c=fgetc(customer);
						j++;
					}
					S[j]='\0';
					j=0;
					if(strcmp(S,u)==0){
						i=9;
						j=0;
						cr=fgetc(customer);
						while(i!=15&&cr!=EOF){
							if(cr=='\n'){
								i++;
								if(i==12){
									fseek(customer,6,1);
									r=ftell(customer);
									c=fgetc(customer);
									for(z=0;z<strlen(S);z++){
										S[z]=0;
									}
									while(c!='\n'){
										S[j]=c;
										c=fgetc(customer);
										j++;
									}
									S[j]='\0';
									z=strlen(S);
									fseek(customer,r,0);
									time_t currentTime;
									time(&currentTime);
									struct tm *myTime=localtime(&currentTime);
									sprintf(S,"%d/%d/%d",myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900);
									if(strlen(S)<z){
										for(i=0;i<(z-strlen(S));i++){
											strcat(S," ");
										}
									}
									for(z=0;z<strlen(S);z++){
										putc(S[z],customer);
									}
									free(S);
									fclose(customer);
									return 0;
								}
							}
							cr=fgetc(customer);
						}
					}
				}
			}
			cr=fgetc(customer);
		}
	}
	free(S);
	fclose(customer);
	return 0;
}

int book_session(char *u)
{
	char cr,c,*S;
	int j=0,r;
	i=1;
	S=malloc(25*sizeof(char));
	FILE *customer =fopen("D:\\dev\\PROGRAMS\\cus.txt","r+");
	if( customer == NULL ) {
      perror("Error: ");
      free(S);
      return(-1);
   }
	else{
		cr=fgetc(customer);
		while(cr!=EOF){
			if(cr=='\n'){
				i++;
				if(i==9){
					fseek(customer,10,1);
					i=-5;
					c=fgetc(customer);
					for(z=0;z<strlen(S);z++){
						S[z]=0;
					}
					z=0;
					while(c!='\n'){
						S[j]=c;
						c=fgetc(customer);
						j++;
					}
					S[j]='\0';
					j=0;
					if(strcmp(S,u)==0){
						i=9;
						j=0;
						cr=fgetc(customer);
						while(i!=15&&cr!=EOF){
							if(cr=='\n'){
								i++;
								if(i==13){
									fseek(customer,9,1);
									r=ftell(customer);
									c=fgetc(customer);
									for(z=0;z<strlen(S);z++){
										S[z]=0;
									}
									while(c!='\n'){
										S[j]=c;
										c=fgetc(customer);
										j++;
									}
									S[j]='\0';
									z=strlen(S);
									fseek(customer,r,0);
									time_t currentTime;
									struct tm *myTime=localtime(&currentTime);
									do{
										printf("Enter day(1-31):");
										scanf("%d",&myTime->tm_mday);
									}while((myTime->tm_mday)<1||(myTime->tm_mday)>31);
									do{
										printf("\nEnter hour(24-hour format):");
										scanf("%d",&myTime->tm_hour);
									}while(myTime->tm_hour<0||myTime->tm_hour>24);
									do{
										printf("\nEnter min(upto 59):");
										scanf("%d",&myTime->tm_min);
									}while(myTime->tm_min<0||myTime->tm_min>60);
									sprintf(S,"%d(date)%d(hour)%d(min)",myTime->tm_mday,myTime->tm_hour,myTime->tm_min);
									if(strlen(S)<z){
										for(i=0;i<(z-strlen(S));i++){
											strcat(S," ");
										}
									}
									for(z=0;z<strlen(S);z++){
										putc(S[z],customer);
									}
									printf("\n\n Session has been booked for %d(date) at %d : %d \nPress any key to continue...",myTime->tm_mday,myTime->tm_hour,myTime->tm_min);
									getch();
									free(S);
									fclose(customer);
									return 0;
								}
							}
							cr=fgetc(customer);
						}
					}
				}
			}
			cr=fgetc(customer);
		}
	}
	free(S);
	fclose(customer);
	return 0;
}

void booking_menu(char *u)
{
	char ch,*x;
	x=malloc(25*sizeof(char));
	for(z=0;z<strlen(x);z++){
		x[z]=0;
	}
	system("cls");
	printf("Please select type of room......");
	printf("\n1 -|PRIVATE ROOM AT 150 |-");
	printf("\n2 -|MATCH ROOM AT 200   |-");
	printf("\n3 -|STRATEGY ROOM AT 350|-");
	printf("\n4 -|PREMIUM OFFERS      |-");
	printf("\n\nYour Choice: ");
	fflush(stdin);
	scanf("%c",&ch);
	switch(ch){
		case '1':
			strcpy(x,"PRIVATE ROOM");
			rooms(u,x);
			book_session(u);
			update_bal(150,u);
			break;
		case '2':
			strcpy(x,"MATCH ROOM");
			rooms(u,x);
			book_session(u);
			update_bal(200,u);
			break;
		case '3':
			strcpy(x,"STRATEGY ROOM");
			rooms(u,x);
			book_session(u);
			update_bal(350,u);
			break;
		case '4':
			if(check(u)){
				p_menu(u);
			}
			else{
				printf("\nPlease upgrade to premium first :)");
			}
			break;
		default:
				system("cls");
				printf("Please choose from options (1-4):\nPress any key to continue....");
				getch();
				booking_menu(u);				
	}
	free(x);
}

void p_menu(char*u)
{
	char ch,*x;
	x=malloc(25*sizeof(char));
	for(z=0;z<strlen(x);z++){
		x[z]=0;
	}
	system("cls");
	printf("Please select type of room......");
	printf("\n1 -|PRIVATE ROOM AT 80  |-");
	printf("\n2 -|MATCH ROOM AT 130   |-");
	printf("\n3 -|STRATEGY ROOM AT 200|-");
	printf("\n\nYour Choice: ");
	fflush(stdin);
	scanf("%c",&ch);
	switch(ch){
		case '1':
			strcpy(x,"Private");
			rooms(u,x);
			book_session(u);
			update_bal(80,u);
			break;
		case '2':
			strcpy(x,"MATCH ROOM");
			rooms(u,x);
			book_session(u);
			update_bal(130,u);
			break;
		case '3':
			strcpy(x,"STRATEGY ROOM");
			rooms(u,x);
			book_session(u);
			update_bal(200,u);
			break;
		default:
				system("cls");
				printf("Please choose from options (1-3):\nPress any key to continue....");
				getch();
				p_menu(u);		
	}
	free(x);
}

int rooms(char *u, char *x)
{
	char cr,c,*S;
	int j=0,r;
	i=1;
	S=malloc(25*sizeof(char));
	FILE *customer =fopen("D:\\dev\\PROGRAMS\\cus.txt","r+");
	if( customer == NULL ) {
      perror("Error: ");
      free(S);
      return(-1);
   }
	else{
		cr=fgetc(customer);
		while(cr!=EOF){
			if(cr=='\n'){
				i++;
				if(i==9){
					fseek(customer,10,1);
					i=-5;
					c=fgetc(customer);
					for(z=0;z<strlen(S);z++){
						S[z]=0;
					}
					z=0;
					while(c!='\n'){
						S[j]=c;
						c=fgetc(customer);
						j++;
					}
					S[j]='\0';
					j=0;
					if(strcmp(S,u)==0){
						i=9;
						j=0;
						cr=fgetc(customer);
						while(i!=15&&cr!=EOF){
							if(cr=='\n'){
								i++;
								if(i==14){
									fseek(customer,6,1);
									r=ftell(customer);
									c=fgetc(customer);
									for(z=0;z<strlen(S);z++){
										S[z]=0;
									}
									while(c!='\n'){
										S[j]=c;
										c=fgetc(customer);
										j++;
									}
									S[j]='\0';
									z=strlen(S);
									fseek(customer,r,0);
									strcpy(S,x);
									if(strlen(S)<z){
										for(i=0;i<=(z-strlen(S))+1;i++){
											strcat(S," ");
										}
									}
									for(z=0;z<strlen(S);z++){
										putc(S[z],customer);
									}
									free(S);
									fclose(customer);
									return 0;
								}
							}
							cr=fgetc(customer);
						}
					}
				}
			}
			cr=fgetc(customer);
		}
	}
	free(S);
	fclose(customer);
	return 0;
}

int restaurant(char prem)
{
	menu menu;
	int i=0,j=0,k=0,l=0,m =0,y=0,o=0,p=0,q=0,r=0;
	char ch='y';
	char time[10];
	int boot;
	int sum=0;
	int total=0;
	int a,n;
	menu.burger=200;
	menu.pizza=400;
	menu.chickroll=100;
	menu.beefroll=110;
	menu.mayoroll=120;
	menu.zingburger=250;
	menu.sandwich=100;
	menu.pepsi=70;
	menu.dew=70;
	menu.marinda=70;
	printf("\t******MENU******\n");
	printf("Burger Price = 200Rs           ||Press 1 for burger:\n");
	printf("pizza Price = 400Rs            ||Press 2 for pizza:\n");
	printf("Chicken Roll Price = 100Rs     ||Press 3 for chicken roll:\n");
	printf("BeefRoll Price = 110Rs         ||Press 4 for Beef Roll:\n");
	printf("Chicken Mayo Roll Price = 120Rs||Press 5 for chicken mayo roll :\n");
	printf("Zinger Burger Price = 250Rs    ||Press 6 for Zinger burger:\n");
	printf("Sandwich Price = 100Rs         ||Press 7 for Sandwich:\n");
	printf("PepsiPrice = 70Rs              ||Press 8 for pepsi:\n");
	printf("Dew Price = 70Rs               ||Press 9 for Dew:\n");
	printf("Marinda Price = 70Rs           ||Press 10 for Marinda:\n");
	
	while(ch=='y')
	{
		printf("Enter the item number you want to order:");
		scanf("%d",&n);
		printf("Enter the number of times you want to order it:");
		scanf("%d",&a);
		if(n==1){
			i=i+menu.burger*a;
			
		}
		else if(n==2){
			j=j+menu.pizza*a;
			
		}
		else if(n==3){
			k=k+menu.chickroll*a;
		}
		else if(n==4){
		    l=l+menu.beefroll*a;
			
		}
		else if(n==5){
			m=m +menu.mayoroll*a;
			
		}
		else if(n==6){
			y=y+menu.zingburger*a;
			
		}
		else if(n==7){
			o=o+menu.sandwich*a;
			
		}
		else if(n==8){
			p=p+menu.pepsi*a;
			
		}
		else if(n==9){
			q=q+menu.dew*a;
			
		}
		else if(n==10){
			r=r+menu.marinda*a;
			
		}
		printf("Do you want to order more:\npress y for yess||press n for no\n");
		scanf(" %c",&ch);
	}
	sum=i+j+k+l+m+y+o+p+q+r;
	printf("Enter the time of order:");
	scanf(" %s",&time);
	printf("enter the booth number for location:");
	scanf(" %d",&boot);
	if(prem=='y')
		total=sum*75/100;
	else if(prem=='n')
		total=sum;
	printf("The Total bill is :%dRs\n",total);
	printf("location=%d booth number\n",boot);
	printf("time:%s",time);
	printf("\npress any key to continue...");	
	getch();
	return total;
}

int upgrade(char *u)
{
	char cr,c,*S,*x;
	int j=0,r;
	i=1;
	x=malloc(25*sizeof(char));
	S=malloc(25*sizeof(char));
	FILE *customer =fopen("D:\\dev\\PROGRAMS\\cus.txt","r+");
	if( customer == NULL)
	{
      perror("Error: ");
      free(S);
      free(x);
      return(-1);
    }
	else
	{
		cr=fgetc(customer);
		while(cr!=EOF){
			if(cr=='\n'){
				i++;
				if(i==9){
					fseek(customer,10,1);
					i=-5;
					c=fgetc(customer);
					for(z=0;z<strlen(S);z++){
						S[z]=0;
					}
					z=0;
					while(c!='\n'){
						S[j]=c;
						c=fgetc(customer);
						j++;
					}
					S[j]='\0';
					j=0;
					if(strcmp(S,u)==0){
						i=9;
						j=0;
						cr=fgetc(customer);
						while(i!=15&&cr!=EOF){
							if(cr=='\n'){
								i++;
								if(i==11){
									fseek(customer,14,1);
									r=ftell(customer);
									c=fgetc(customer);
									for(z=0;z<strlen(S);z++){
										S[z]=0;
										x[z]=0;
									}
									while(c!='\n'){
										S[j]=c;
										c=fgetc(customer);
										j++;
									}
									strcpy(x,"premium");
									x[j]='\0';
									S[j]='\0';
									z=strlen(S);
									fseek(customer,r,0);
									strcpy(S,x);
									for(z=0;z<strlen(S);z++){
										putc(S[z],customer);
									}
									free(S);
									free(x);
									fclose(customer);
									return 0;
								}
							}
							cr=fgetc(customer);
						}
					}
				}
			}
			cr=fgetc(customer);
		}
	}
	free(S);
	free(x);
	fclose(customer);
	return 0;
}

void tech(void)
{
	int i,n,a;
	printf("\t*****Issues name***** \n");
	printf("For Net Issues        ||press1 for details\n");
	printf("For fps Issues        ||press2 for details\n");
	printf("For peripheral issues ||press3 for details\n");
	printf("For CPU issues        ||press4 for details\n");
	printf("For game issues       ||press5 for details\n");
	printf("\nEnter the number of problems you are facing: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("\nEnter the issue # %d you are facing : ", i+1);
		scanf("%d",&a);
		if (a < 1 || a > 5)
	    {
		    do
		    {
			    printf("Number must be between 1 and 5. Re-enter: ");
			    scanf("%d", &a);
		    }
		    while(a < 1 || a > 5);
	    }
		if(a==1)
			printf("\nThe technician name is: Aslam\nphone no:034567890\n");
		else if(a==2)
			printf("\nThe technician name is: Moiz\nphone no:0344545450\n");
		else if(a==3)
			printf("\nThe technician name is: Kashif\nphone no:034565560\n");
		else if(a==4)
			printf("\nThe technician name is: Raza\nphone no:034333890\n");
		else
			printf("\nThe technician name is: Omer\nphone no:034567123\n");
	}
	printf("press any key to continue...");
	getch();
}

