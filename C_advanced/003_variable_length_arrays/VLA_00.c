#include <stdio.h>
#include <stdint.h>

int main()
{
#ifdef __STDC_NO_VLA__
    printf("Variable length arrays are not supported\n");
    exit(1);
#endif

    uint32_t size = 0;

    printf("Enter the size of the arrays: ");
    scanf("%u", &size);

    uint8_t arr[size];
    uint32_t sum = 0;

    printf("Input elements: ");
    for(uint32_t i=0; i < size; i++)
    {
        scanf("%hhu", &arr[i]);
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);

    return 0;
}