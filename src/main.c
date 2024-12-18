#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    printf("Welcome to RFSQL console !\nType 'h' if you need any help.\n");

    char *inp = NULL; 
    size_t size = 0;  
    size_t index = 0; 
    char c;           

    while (1) {
        printf("\nDB > ");
        
        free(inp);
        inp = NULL;
        size = 0;
        index = 0;

        while (1) {
            scanf("%c", &c);
            if (c == '\n') {
                break;
            }
            
	    char *temp = realloc(inp, size + 1);
            if (!temp) {
                printf("Erreur d'allocation mémoire");
                free(inp);
                return 1;
            }
            inp = temp;

            inp[index++] = c;
            size++;
        }

        char *temp = realloc(inp, size + 1);
        if (!temp) {
            printf("Erreur d'allocation mémoire");
            free(inp);
            return 1;
        }
        inp = temp;
        inp[index] = '\0';

        printf("Saisie : %s\n", inp);

        if (strcmp(inp, "exit") == 0) {
            break;
        }
    }

    free(inp);
    return 0;
}
