#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_help();
void handle_unknown_command(const char* command);

void process_input() {
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
                return;
            }
            inp = temp;

            inp[index++] = c;
            size++;
        }

        char *temp = realloc(inp, size + 1);
        if (!temp) {
            printf("Erreur d'allocation mémoire");
            free(inp);
            return;
        }
        inp = temp;
        inp[index] = '\0';

        printf("Saisie : %s\n", inp);

        if (strcmp(inp, "exit") == 0) {
            break;
        } else if (strcmp(inp, "h") == 0 || strcmp(inp, "help") == 0) {
            handle_help();
        } else {
            handle_unknown_command(inp);
        }
    }

    free(inp);
}

void handle_help() {
    printf("Help Menu:\n");
    printf("  h or help   - Display this help menu\n");
    printf("  exit        - Exit the RFSQL console\n");
}

void handle_unknown_command(const char* command) {
    printf("Unknown command: %s\n", command);
    printf("Type 'h' for help.\n");
}

int main(int argc, char* argv[]) {
    printf("Welcome to RFSQL console!\nType 'h' if you need any help.\n");
    
    process_input();

    printf("Exiting RFSQL console. Goodbye!\n");
    return 0;
}
