/* C Program by Abdullah Mohammad Mahi for CS 1311

 o            o
  \          /
   \        /
    :-'""'-:
 .-'  ____  `-.
( (  (_()_)  ) )
 `-.   ^^   .-'
    `._==_.'
    __)(___

*This program asks user for 7 numbers (positive integers) from 1 to 50. In the same time 
*it generates 7 random numbers from 1 to 50 using srand(time(NULL)) and rand() function. 
*We made a bubble search function to sorts a list of 7 numbers using the bubble sort algorithm
*(named bubble).Later, we print out the users guess and computer generated numbers without order 
*and with numeric order. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*bubble sort function */
void bubble(int arr[]) 
{ 
    int i, j,temp;
    for (i = 0; i < 7; i++) 
    {
        for (j = 0; j < 6; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// function to print out an array
void print_array(int arr[]) 
{
    int i;
    for (i = 0; i < 7; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");  // add a newline character
}


void main(void) 
{
   	int range, num_numbers;
    int user_numbers[50];
    int lottery_numbers[50];
    int num_matches = 0;
    int i, j;

    
    // get user's guesses
    printf("+------+------+------+WELCOME TO THE ST MARY'S LOTTERY BOARD+------+------+------+\n\n");
    printf(" 1.Here, users will provide 7 numbers from 1 to 50.\n 2. Computer will"
           " create a random number set between the range.\n 3. Numbers that match"
           " in both sides get printed also showing how many numbers got matched.\n\n");
    
	printf(" Enter the range of numbers (e.g. 1-50): ");
    scanf("%d", &range);

    printf(" Enter the number of numbers you want to select: ");
    scanf("%d", &num_numbers);
	       
    printf(" Enter 7 unique numbers between 1 and 50:\n");
    for (i = 0; i < 7; i++) 
    {   
        printf(" Your Number: ");
        scanf("%d", &user_numbers[i]);
        
        
        if ( user_numbers[i] < 1 || user_numbers[i] > 50) 
        {
            printf(" Please follow the directions. Keep your number inside the range.\n");
             printf(" Your Number: ");
			scanf("%d", &user_numbers[i]);
        }
        else 
        {
            // check for duplicates
            for (j = 0; j < i; j++) 
            {
                if (user_numbers[i] == user_numbers[j]) 
                {
                    printf(" Please enter a unique number.\n");
                    i--;
                }
            }
        }
    }

    // generate lottery numbers
    srand(time(NULL));
    for (j = 0; j < 7; j++) 
    {   
        lottery_numbers[j] = rand() % 50 + 1;
    }
    
    
    /* print out user's numbers without orde */
    printf("\n Your numbers without orde: ");
    print_array(user_numbers);
    
    /*sort user's guesses*/
    bubble(user_numbers);
    
	/* print out user's guesses */
    printf(" Your numbers in numerical order: ");
    print_array(user_numbers);
    
    /* print out lottery numbers without orde */
    printf("\n Lottery numbers without order: ");
    print_array(lottery_numbers);
    
    /*sort lottery numbers*/
    bubble(lottery_numbers);
	
	/* print out lottery numbers */
    printf(" Lottery numbers in numerical order: ");
    print_array(lottery_numbers);

    // count number of matches
    for (i = 0; i < 7; i++) 
    {
        for (j = 0; j < 7; j++) 
        {
            if (user_numbers[i] == lottery_numbers[j]) 
            {
                num_matches++;
            }
        }
    }

    // print out number of matches and which numbers matched
    printf("\n Number of matches: %d\n", num_matches);
	
	if (num_matches > 0) 
    {
        printf("Matched numbers: ");
        for (i = 0; i < num_numbers; i++) 
        {
            for (j = 0; j < num_numbers; j++) 
            {
                if (user_numbers[i] == lottery_numbers[j]) 
                {
                    printf("%d ", user_numbers[i]);
                }
            }
        }
        printf("\n");
    }
}

