#include <stdio.h>

int main(int argc, char* argv[])
{
    const int MAX_NUMBER = 100;
    const int STEP = -2; 

    for (int i = MAX_NUMBER; i > 0; i = i + STEP)
    {
        printf("%d", i);
        if (i != 2)
        {
            printf(", ");
        }
    }

    printf("\n");
    return 0;
}
