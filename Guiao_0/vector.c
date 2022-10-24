#include  <stdio.h>
#include <stdlib.h>

void fill(int* vector, int size, int value)
{
    //Data declaration and initialization
    int i;

    for(i = 0; i < size; i++)   //This cycle will iterate though the entire array filling each position with the variable value
        vector[i] = value; // equivalent to *(vector + i) = value -> i = int sizeoff(type)
}

int find(int* vector, int size, int value)
{
    //Data declaration and initialization
    int i;

    for(i = 0; i < size; i++){  //This cycle will iterate though the entire array comparing each position to the variable value if the two values are the
        if(vector[i] == value)  //same the function will return the position if not the program will return the value of -1 (false)
            return i;
    }
}