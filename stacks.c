#include <stdio.h>

void push(int arr[], int* top, int length) {
    if(*top == length-1){
        printf("Overflow \n");
    }
    else{
        *top = *top + 1;
        printf("Enter number to push : ");
        scanf("%d", &arr[*top]);
    }
    return;
}

void pop(int arr[], int *top, int length) {
    if(*top == -1){
        printf("Underflow \n");
    }
    else{
        printf("Number popped : %d \n", arr[*top]);
        *top = *top - 1;
    }
    return;
}

int main() {

    int values[5];
  
    int selection;
    int top = -1;

    while(1==1)
    {
        printf("Enter 1 to push 2 to pop, anything else to exit and display current stack value: ");
        scanf("%d", &selection);
        if(selection == 1){
            push(values, &top, 5);
        }
        else if(selection == 2){
            pop(values, &top, 5);
        }
        else{
            break;
        }
    }

    printf("Final Stack values: \n");
    for(int i = 0; i < 5; ++i) {
        printf("%d ", values[i]);
    }
    return 0;
}