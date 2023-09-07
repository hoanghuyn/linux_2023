#include <stdlib.h>
#include <stdio.h>

#include "string_functions.h"

int main()
{
  char temp[] = "jason &&''''Fedin";
  char temp2[] = "apple";
  char temp3[100];

  printf("Number of 'p's in apple is %d\n", number_of_characters_in_string(temp2, 'p'));

  remove_non_alpha_characters(temp);
  printf("String temp with alpha characters removed is: %s\n", temp);

  printf("String temp length is: %d\n", length_of_string(temp));

  str_concat(temp, temp2);
  printf("String concatenated with string2 is: %s\n", temp);

  str_copy(temp2, temp3);
  printf("String copied is: %s\n", temp3);

  substring(temp, 3, 8, temp3);
  printf("Substring is: %s\n", temp3);

  return 0;
}
