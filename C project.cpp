
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

 
#define KEY "Enter the calculator Operation you want to do:"
 

char s[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

struct login                           // before the first use of `l`.
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};

void login (void);
void registration (void);
int tic();
int checkwin();
void board();

// Function prototype declaration 
void max();
void min();
void av();
void addition();
void subtraction();
void multiplication();
void division();
int area();
void multitable();
void sort();
void findfib();

int factorial();
int numcal();
int mean();
 int fib(int n);
void calculator_operations();
 int cal();
 
int main (void)
{
    char option;
    int X=1;
   while(X){
    printf("Press 'a' to Register\nPress 'b' to Login\n\n");
    scanf("%c",&option);

    getchar();           // catching newline.
 
 
    if(option == 'a')
        {
            system("CLS");
            registration();
        }

    else if(option == 'b')
        {
            system("CLS");
            login();
            if(option == 'c'){
            	 tic();
             if(option == 'd'){
            	 cal();
            }
			}
        }
    }
}

void login (void)
{
    char username[30],password[20];
    FILE *log;

    log = fopen("login.txt","r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    struct login l;

    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username:  ");
    scanf("%s",&username);
    printf("\nPassword: ");
    printf("\n");
   scanf("%s",&password);

    while(fread(&l,sizeof(l),1,log))
        {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

            {   
                printf("\nSuccessful Login\n");
                 tic();
                 cal();
            }
        else 
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
            }
        }

    fclose(log);

    return;
}




void registration(void)
{
    char firstname[15];
    FILE *log;

    log=fopen("login.txt","w");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }


    struct login l;

    printf("\nWelcome to your online course provider. We need to enter some details for registration.\n\n");
    printf("\nEnter First Name:\n");
    scanf("%c",l.fname);
    printf("\nEnter Surname:\n");
    scanf("%s",l.lname);

    printf("Thank you.\nNow please choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\nEnsure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n"); 

    printf("\nEnter Username:\n");
    scanf("%s",l.username);
    printf("\nEnter Password:\n");
    scanf("%s",l.password);


    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\nConfirming details...\n...\nWelcome, %s!\n\n",firstname);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
        getchar();
    system("CLS");
    login();
}

int tic()
{
    int p = 1, i, c;

    char mark;
    do
    {
        board();
        p = (p % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", p);
        scanf("%d", &c);

        mark = (p == 1) ? 'X' : 'O';

        if (c == 1 && s[1] == '1')
            s[1] = mark;
            
        else if (c == 2 && s[2] == '2')
            s[2] = mark;
            
        else if (c == 3 && s[3] == '3')
            s[3] = mark;
            
        else if (c == 4 && s[4] == '4')
            s[4] = mark;
            
        else if (c == 5 && s[5] == '5')
            s[5] = mark;
            
        else if (c == 6 && s[6] == '6')
            s[6] = mark;
            
        else if (c == 7 && s[7] == '7')
            s[7] = mark;
            
        else if (c == 8 && s[8] == '8')
            s[8] = mark;
            
        else if (c == 9 && s[9] == '9')
            s[9] = mark;
            
        else
        {
            printf("Invalid move ");

            p--;
            getch();
        }
        i = checkwin();

        p++;
    }while (i ==  - 1);
    
    board();
    
    if (i == 1)
        printf("==>\aPlayer %d win ", --p);
    else
        printf("==>\aGame draw");

    getch();

    return 0;
}

/*********************************************

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

int checkwin()
{
    if (s[1] == s[2] && s[2] == s[3])
        return 1;
        
    else if (s[4] == s[5] && s[5] == s[6])
        return 1;
        
    else if (s[7] == s[8] && s[8] == s[9])
        return 1;
        
    else if (s[1] == s[4] && s[4] == s[7])
        return 1;
        
    else if (s[2] == s[5] && s[5] == s[8])
        return 1;
        
    else if (s[3] == s[6] && s[6] == s[9])
        return 1;
        
    else if (s[1] == s[5] && s[5] == s[9])
        return 1;
        
    else if (s[3] == s[5] && s[5] == s[7])
        return 1;
        
    else if (s[1] != '1' && s[2] != '2' && s[3] != '3' &&
        s[4] != '4' && s[5] != '5' && s[6] != '6' && s[7] 
        != '7' && s[8] != '8' && s[9] != '9')

        return 0;
    else
        return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[1], s[2], s[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", s[4], s[5], s[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", s[7], s[8], s[9]);

    printf("     |     |     \n\n");
}
int cal()
{
    int X=1;
    char Calc_oprn;
 
    // Function call 
    calculator_operations();
 
    while(X)
    {
        printf("\n");
        printf("%s : ", KEY);
 
        Calc_oprn=getche();
 
        switch(Calc_oprn)
        {
        	case '>': max();
                      break;
                      
           	case '<': min();
                      break;
                      
            case '&': av();
                      break;
            case ':': mean();
                      break;
        	
            case '+': addition();
                      break;
 
            case '-': subtraction();
                      break;
 
            case '*': multiplication();
                      break;
 
            case '/': division();
                      break;
                      
            case ',': numcal();
                      break;
 
            case '?': multitable();
                      break;
 
            case '!': factorial();
                      break;
             case '#': findfib();
                      break;     
            case '.': area();
                      break;
            case '^': sort();
                      break;
 
            case 'H':
            case 'h': calculator_operations();
                      break;
 
            case 'Q':
            case 'q': exit(0);
                      break;
            case 'c':
            case 'C': system("cls");
                      calculator_operations();
                      break;
 
            default : system("cls");
 
    printf("\n**********You have entered unavailable option");
    printf("***********\n");
    printf("\n*****Please Enter any one of below available ");
    printf("options****\n");
                      calculator_operations();
        }
    }
}
 
//Function Definitions
 
void calculator_operations()
{
    //system("cls");  use system function to clear 
    //screen instead of clrscr();
    printf("\n             Welcome to C calculator \n\n");
 
    printf("******* Press 'Q' or 'q' to quit ");
    printf("the program ********\n");
    printf("***** Press 'H' or 'h' to display ");
    printf("below options *****\n\n");
    printf("Enter 'C' or 'c' to clear the screen and");
    printf(" display available option \n\n");
 
    printf("Enter > symbol for max \n");
    printf("Enter < symbol for min \n");
    printf("Enter & symbol for avarege \n");
    printf("Enter : symbol for mean \n");
    printf("Enter + symbol for Addition \n");
    printf("Enter - symbol for Subtraction \n");
    printf("Enter * symbol for Multiplication \n");
    printf("Enter / symbol for Division \n");
    printf("Enter , symbol for namcal \n");
    printf("Enter ? symbol for multitable\n");
    printf("Enter ^ symbol for Sort\n");
    printf("Enter # symbol for fiboncci\n");
	printf("Enter . symbol for Area\n");
    printf("Enter ! symbol for Factorial \n\n");
}
 
 
 void max() {
  int n,i;
  double arr[100];
  printf("Enter the number of elements (1 to 100): ");
  scanf("%d", &n);

  for ( i = 0; i < n; ++i) {
    printf("\nEnter number%d: ", i + 1);
    scanf("%lf", &arr[i]);
  }

  for (i = 1; i < n; ++i) {
    if (arr[0] < arr[i]) {
      arr[0] = arr[i];
    }
  }

  printf("Largest element = %.2lf", arr[0]);

}

void min()
{
  int array[100], s, c, l = 0;

  printf("\nEnter number of elements in array\n");
  scanf("%d", &s);

  printf("Enter %d integers\n", s);

  for (c = 0; c < s; c++)
    scanf("%d", &array[c]);

  for (c = 1; c < s; c++)
    if (array[c] < array[l])
      l = c;

  printf("Minimum element value is %d.\n",array[l]);
  
}

void av() {
    int n, i;
    float num[100], sum = 0.0, avg;

    printf("Enter the numbers of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        printf("%d. Enter number: ", i + 1);
        scanf("%f", &num[i]);
        sum += num[i];
    }

    avg = sum / n;
    printf("Average = %.2f", avg);
    
}

int mean()
{
    int i, size;
    float num, sum, am;
    printf("How many number to enter ? ");
    scanf("%d", &size);
    sum = 0;
    printf("Enter %d Numbers: ", size);
    for(i=0; i<size; i++)
    {
        scanf("%f", &num);
        sum = sum+num;
    }
    am = sum/size;
    printf("\n mean= %0.2f", am);
    getch();
    return 0;
}
 
void addition()
{
    int n, total=0, k=0, number;
    printf("\nEnter the number of elements you want to add:");
    scanf("%d",&n);
    printf("Please enter %d numbers one by one: \n",n);
    while(k<n)
    { 
        scanf("%d",&number);
        total=total+number;
        k=k+1;
    }
    printf("Sum of %d numbers = %d \n",n,total);
}
 
void subtraction()
{ 
    int a, b, c = 0; 
    printf("\nPlease enter first number  : "); 
    scanf("%d", &a); 
    printf("Please enter second number : "); 
    scanf("%d", &b); 
    c = a - b; 
    printf("\n%d - %d = %d\n", a, b, c); 
}
 
void multiplication()
{
    int a, b, mul=0; 
    printf("\nPlease enter first numb   : "); 
    scanf("%d", &a); 
    printf("Please enter second number: "); 
    scanf("%d", &b);
    mul=a*b;
    printf("\nMultiplication of entered numbers = %d\n",mul);
}
 
void division()
{
    int a, b, d=0; 
    printf("\nPlease enter first number  : "); 
    scanf("%d", &a); 
    printf("Please enter second number : "); 
    scanf("%d", &b);
    d=a/b;
    printf("\nDivision of entered numbers=%d\n",d);
}

int factorial()
{
    int i,fact=1,num;
 
    printf("\nEnter a number to find factorial : ");
    scanf("%d",&num);
 
    if (num<0)
    {
        printf("\nPlease enter a positive number to");
        printf(" find factorial and try again. \n");
        printf("\nFactorial can't be found for negative");
        printf(" values. It can be only positive or 0  \n");
        return 1;
    }               
 
    for(i=1;i<=num;i++)
    fact=fact*i;
    printf("\n");
    printf("Factorial of entered number %d is:%d\n",num,fact);
    return 0;
}

void findfib()
{
  int n ;
  scanf("%d",&n);

  
  printf("%d", fib(n));
  
  
}
 int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}

int area()
{
    char op;
    float tri,rec,cir;
    float a,b,c,d,h,i;
    scanf("%c",&op);
    

        if(op=='e') {
		scanf("%f %f", &a, &b);
            tri = 0.5*a*b;
            printf("%0.2f",tri);
        }
        else if(op=='f') {
		     scanf("%f %f", &c, &d);
            rec = c*d;
            printf("%0.2f",rec);
        }
            
            else if(op=='g') {
		      scanf("%f", &h);
            cir = 3.1416*h*h;
            printf("%0.2f",cir);
        }
        
   
  
}
 int numcal()
{
    char op;
    int a[10],i,j,n;
    int b,c;
    int X=1;
    int rem,base=1,dm=0,hx=0;
    
   char hex[17], bin[65] = "";
    int k= 0;
    char ot;
    
    scanf("%c",&ot);
    
     
	 
	 
        if(op=='e') {
        	scanf("%d", &n);
		while(n != 0)
    {
        a[i++] = n % 2;
        n = n / 2;
    }
    
    printf("\n Binary Number of a Given Number =  ");
    for(j = i - 1; j > 0; j--)  {
        printf("%d", a[j]);
    }
        }
       else if(ot=='f') {
        scanf("%d", &b);
           while ( b > 0)  
    {  
        rem = b % 10; /* divide the binary number by 10 and store the remainder in rem variable. */  
        dm = dm + rem * base;  
        b = b / 10; // divide the number with quotient  
        base = base * 2;  
    }  
     printf ("  The decimal number is %d\n", dm);
        	
        	
        }
        
         else if(ot=='g') {
        scanf("%d", &c);
           while ( c != 0)  
    {  
        rem = c % 10; /* divide the binary number by 10 and store the remainder in rem variable. */  
        hx = hx + rem * base;
		
        c = c / 10; // divide the number with quotient  
        base = base * 2;  
    }  
     printf ("The hexadecimal number is %d\n", hx);
        	
        }
        else if(ot=='h') {
         printf("Enter any hexadecimal number: ");
         gets(hex);

    /* Extract first digit and find binary of each hex digit */
    for(i=0; hex[k]!='\0'; i++)
    {
        switch(hex[k])
        {
            case '0':
                strcat(bin, "0000");
                break;
            case '1':
                strcat(bin, "0001");
                break;
            case '2':
                strcat(bin, "0010");
                break;
            case '3':
                strcat(bin, "0011");
                break;
            case '4':
                strcat(bin, "0100");
                break;
            case '5':
                strcat(bin, "0101");
                break;
            case '6':
                strcat(bin, "0110");
                break;
            case '7':
                strcat(bin, "0111");
                break;
            case '8':
                strcat(bin, "1000");
                break;
            case '9':
                strcat(bin, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin, "1111");
                break;
            default:
                printf("Invalid hexadecimal input.");
        }
    }

    printf("Binary number = %s", bin);

        	
        }
        
   return 0;
 
}

   
 
void multitable(){

   int n, i;
  printf("\nEnter an integer: ");
  scanf("%d", &n);
  for (i = 1; i <= 10; ++i) {
    printf("%d * %d = %d \n", n, i, n * i);
  }
}

void sort()
{
     int array[100], n, c, d, swap;

  printf("\nEnter number of elements\n");
  scanf("%d", &n);

  

  for (c = 0; c < n; c++){
  
    scanf("%d", &array[c]);
}
  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) 
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for (c = 0; c < n; c++){
  
  printf("%d ", array[c]);
}
  }
 

