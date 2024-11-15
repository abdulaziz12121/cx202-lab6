#include <stdio.h>
#include <stdlib.h>

void displayStack(int* stack, int size) {
    if (size == 0) {
        printf("The stack is empty.\n");
        return;
    }

    printf("Current stack: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int* stack = NULL;   
    int top = 0;        
    char command;        

    printf("Dynamic Stack Implementation\n");

    while (1) {
        printf("Enter a command (p: push, o: pop, d: display, e: exit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'p': { 
                int value;
                printf("Enter an integer to push: ");
                scanf("%d", &value);

                stack = (int*)realloc(stack, (top + 1) * sizeof(int));
                if (stack == NULL) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }

                stack[top] = value; 
                top++;
                break;
            }

            case 'o': { 
                if (top == 0) {
                    printf("The stack is empty. Nothing to pop.\n");
                } else {
                    printf("Popped value: %d\n", stack[top - 1]);
                    top--;

                    
                    if (top > 0) {
                        stack = (int*)realloc(stack, top * sizeof(int));
                        if (stack == NULL) {
                            printf("Memory reallocation failed.\n");
                            return 1;
                        }
                    } else {
                        free(stack); 
                        stack = NULL;
                    }
                }
                break;
            }

            case 'd': { 
                displayStack(stack, top);
                break;
            }

            case 'e': { 
                printf("Exiting the program. All memory has been freed.\n");
                free(stack); 
                return 0;
            }

                printf("Invalid command. Please enter 'p', 'o', 'd', or 'e'.\n");
                break;
        }
    }

    return 0;
}

