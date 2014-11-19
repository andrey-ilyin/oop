#include <stdio.h>

int main(int argc, char* argv[])
{
    for (int i = 100; i > 0; i -= 2)
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
