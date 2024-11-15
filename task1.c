#include <stdio.h>
#include <stdlib.h>

int main() {
   
    printf("size ");
    int size;
    scanf("%d",&size);
	
    int * var_x = (int*) malloc(size * sizeof(int));

    int * var_y= (int*) malloc(size * sizeof(int));
    
    int * var_z= (int*) malloc(size * sizeof(int));


  printf("Enter %d values for x:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &var_x[i]);  
    }

  printf("Enter %d values for y:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &var_y[i]);
    }

  int var_a;
  int var_b; 
printf("add a ");
    
    scanf("%d",&var_a);

    printf("add b ");

    scanf("%d",&var_b);




    
    
    printf("Resulting vector z:\n");
    for (int i = 0; i < size; i++) {
    var_z[i]= var_a * var_x[i] + var_b *var_y[i];
	    printf("%d ", var_z[i]);
    }
    printf("\n");
//mlooc3
  
    return 0;
}
