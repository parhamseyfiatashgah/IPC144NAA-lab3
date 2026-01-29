#include <stdio.h>


int isLower(char letter);
char toUpper(char letter);
int readAge(void);
int readDayOfWeek(void);
int readHasCoupon(void);
double ticketPrice(int age, int hasCoupon, int dayOfWeek);

int main(void);

int isLower(char letter)
{
    if (letter >= 'a' && letter <= 'z')
        return 1;
    return 0;
   }

char toUpper(char letter)
{
    if isLower(letter) == 1
        letter = letter - ('a' - 'A');            //ASCII 32 
    return letter;
  }

int readAge(void)
{
    int age;
    printf("Please enter the age of the customer: ");
    scanf("%d", &age);
    return age;
}

int readDayOfWeek(void)
{
    int day;

    printf("Days of the week\n");
    printf("1) Sunday\n");
    printf("2) Monday\n");
    printf("3) Tuesday\n");
    printf("4) Wednesday\n");
    printf("5) Thursday\n");
    printf("6) Friday\n");
    printf("7) Saturday\n");
    printf("Please enter the day of the week you wish to see the movie 1 to 7: ");
    scanf("%d", &day);

    return day;
}

int readHasCoupon(void)
{                                         //coupan yes or no
    char c;
    printf("Do you have a coupon? (Y or N): ");
    scanf(" %c", &c);         
    c = toUpper(c);

    if (c == 'Y')
        return 1;
    return 0; 
}

double ticketPrice(int age, int hasCoupon, int dayOfWeek)
{                                                     //assume day numbers 
    double price = 0.0;
    if (dayOfWeek == 2)
    {
        return 5.00;
    }

    if (dayOfWeek >= 3 && dayOfWeek <= 5)
    {                                              // younger than 12 , 7$ , older than 65 , 9$ , rest , 12$
        if (age <= 12)
            price = 7.00;
        else if (age >= 65)
            price = 9.00;
        else
            price = 12.00;
      }
    else
    {
                                                  // Weekend prices Fri-Sun
        if (age <= 12)
            price = 8.00;
        else if (age >= 65)
            price = 10.00;
        else
            price = 15.00;
    }

                                                      //coupan included
    if (hasCoupon == 1)
    {
        price = price * 0.80;
    }

    return price;
}

