#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    for (i = 100; i > 0; i = i - 2)
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
