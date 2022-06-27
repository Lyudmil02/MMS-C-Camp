#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    FILE *fr = fopen(argv[1], "r");
    if (NULL == fr)
    {
        fprintf(stderr, "Reading problem!\n");
        return EXIT_FAILURE;
    }
    FILE *fw = fopen(argv[2], "wr");
    if (NULL == fw)
    {
        fprintf(stderr, "Writting problem!\n");
        return EXIT_FAILURE;
    }

    int num;
    int sum = 0;
    while (fscanf(fr, "%d", &num) != EOF)
    {
        sum += (int)num;
    }
    fwrite(&sum, sizeof(sum), 1, stdout);
    
    fclose(fw);
    fclose(fr);
}