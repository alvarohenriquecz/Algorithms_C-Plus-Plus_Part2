//
// Lexicographic ranking algorithm Implementation
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/strings
// https://github.com/allalgorithms/cpp
//
// Contributed by: Tushar Kanakagiri
// Github: @tusharkanakagiri
//
#include <stdio.h>
#include <string.h>

// A utility function to find factorial of n
int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n-1);
}

// A utility function to count smaller characters on right
// of arr[low]
int findSmallerInRight(char *str, int low, int high)
{
    int countRigth = 0, i;

    for (i = low + 1; i <=high; i++)
        if (str[i] < str[low])
            countRigth++;
    return countRigth;
}

// A function to find rank of a string in all permutations
// of characters
int findRank(char *str)
{
    int len = strlen(str);
    int mul = fact(len);
    int rank = 1;
    int countRight;

    int i;
    for (i = 0; i <= len; i++)
    {
        mul /= len - i;

        // count number of chars smaller than str[i]
        // from str[i+1] to str[len-1]
        countRight = findSmallerInRight(str, i, len - 1);

        rank += countRight * mul;
    }
    return rank;
}

// Driver program to test above function
int main()
{
    char str[] = ""; // Enter string here
    printf("%d", findRank(str));
    return 0;
}