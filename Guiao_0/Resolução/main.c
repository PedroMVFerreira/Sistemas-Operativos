#include "vector.h"
#include  <stdio.h>

#define SIZE 10

int main()
{
    //Data declaration and initialization 
    int vINT[SIZE];
    int fillValue, i;

    //Input 
    printf("Enter a value for the array to be filled with\t");
    scanf("%i", &fillValue);
    //Invoke the function responsible for filling the array
    fill(vINT, SIZE, fillValue);
    //Printing the filled array for test purposes 
    for(i= 0; i < SIZE; i++)
        printf("%i\t", vINT[i]);
    printf("\n\n");
    //Data declaration and initialization 
    int foundPosition, valueToFound;
    int aInt[SIZE]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //Input
    printf("Enter the value you want to find in the vector\t");
    scanf("%i", &valueToFound);
    //Printing the new array and value to found for test purposes
    printf("\nFinding %d in the vector {", valueToFound);
    for(i = 0; i < SIZE; i++)
        printf("%i, ", aInt[i]);
    printf("}\n\n");
    //Invoking the function responsible for find the desire value in the array
    foundPosition= find(aInt, SIZE, valueToFound);
    /*If the return value is between 0 (first index of the array) and SIZE - 1 (last index of the array) a valid index the number is present in the array
    and was found so the position of the number in the array will be printed to the user, otherwise the number could not be found and a message stating that
    will be presented to the user*/
    if(foundPosition >= 0 && foundPosition < SIZE)
        printf("Value %i found in index %i of vector\n\n", valueToFound, foundPosition);
    else
        printf("Value %i not found\n\n", valueToFound);
    //Data declaration and initialization 
    int startIndex, endIndex;
    //Input 
    printf("Enter the value you want to find in the vector\t"); //Value to be found
    scanf("%i", &valueToFound);
    printf("\nEnter the index where you want your search to start\t");
    scanf("%i", &startIndex);
    printf("\nEnter the value where you want your search to end\t");
    scanf("%i", &endIndex);
    //Invoking the function responsible for find the desire value in the array
    foundPosition = find(aInt + startIndex, endIndex - startIndex - 1, valueToFound);
    /*If the return value is between the startIndex (we passed the start address plus the index to start the search so we will be passing the address 
    of the startIndex (pointer arithmetic explained on vector.h line 10) and the endIndex if valid index the number is present in the array
    and was found so the position of the number in the array will be printed to the user, otherwise the number could not be found and a message stating that
    will be presented to the user*/
    if(foundPosition >= startIndex && foundPosition <= endIndex)
        printf("\n\nValue %i found in index %i of vector\n\n", valueToFound, foundPosition + startIndex);
    else
        printf("\n\nValue %i not found\n\n", valueToFound);
    //End of program
    return 0;
}