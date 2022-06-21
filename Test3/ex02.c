#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fprintf(stderr, "Invalid arguments!\n");
        return EXIT_FAILURE;
    }

    if (!strcmp(argv[3], "-TB"))
    {
        FILE *fr = fopen(argv[1], "r");
        if (NULL == fr)
        {
            fprintf(stderr, "Problem with reading!\n");
            return EXIT_FAILURE;
        }
        FILE *fw = fopen(argv[2], "wb");
        if (NULL == fw)
        {
            fprintf(stderr, "Problem with writing!\n");
            return EXIT_FAILURE;
        }
        uint16_t num;
        while (fscanf(fr, "%hd", &num) != EOF)
        {
            fwrite(&num, sizeof(num), 1, fw);
        }
        fclose(fw);
        fclose(fr);

        printf("Writing successfull!\n");
    } 
    else  if (!strcmp(argv[3], "-BT"))
    {
        FILE *fr = fopen(argv[1], "rb");
        if (NULL == fr)
        {
            fprintf(stderr, "Problem with reading!\n");
            return EXIT_FAILURE;
        }

        FILE *fw = fopen(argv[2], "w");
        if (NULL == fw)
        {
            fprintf(stderr, "Problem with writing!\n");
            return EXIT_FAILURE;
        }
        
        uint16_t num;
        while (fread(&num, sizeof(num), 1, fr))
        {
            fprintf(fw, "%hd\n", num);
        }
        fclose(fw);
        fclose(fr);
        printf("Writing successfull!\n");
    } 
    else 
    {
        fprintf(stderr, "Invalid option!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}