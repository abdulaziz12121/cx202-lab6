#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ReverseString(const char* str) {
    int length = strlen(str); 
    char* reversed = (char*)malloc((length + 1) * sizeof(char)); 

    if (reversed == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';

    return reversed; 
}

int main() {
    char input[100];

    printf("Enter a string : ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char* reversed = ReverseString(input);

    printf("Reversed string: %s\n", reversed);

    free(reversed);

    return 0;
} 
