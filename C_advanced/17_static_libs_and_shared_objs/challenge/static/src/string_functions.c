#include <stdio.h>
#include "string_functions.h"

/**
 * @param str string to search
 * @param search_character character to look for
 * @return type - int : count for the number of times the search_character is found in the string
*/
int number_of_characters_in_string(char *str, char search_character)
{
    int count = 0;
    while(*str != '\0')
    {
        if(*str == search_character)
        {
            count++;
        }
        str++;
    }
    return count;
}

/**
 * @brief removes all non-alpha characters from the source string
 * @param source source string
 * @return type - int : 0 on success
*/
int remove_non_alpha_characters(char *source)
{
    char *i = source;
    char *j = source;
    while(*j != '\0')
    {
        *i = *j++;  // *i = *j; j = j + 1;
        if((*i >= 'A' && *i <= 'Z') || (*i >= 'a' && *i <= 'z'))
        {
            i++;
        }
    }
    *i = '\0';
    return 0;
}

/**
 * @brief returns the length of the string
 * @param source source string
 * @return type - int : length of the string
*/
int length_of_string(char *source)
{
    int length = 0;
    
    for(length = 0; source[length] != '\0'; ++length);

    return length;
}

/**
 * @brief Concatenates two strings
 * @param str1 string to concatenate to (resulting string)
 * @param str2 second string to concatenate from
 * @return type - int : 0 on success
*/
int str_concat(char *str1, char *str2)
{
    while(*str1 != '\0')
    {
        str1++;
    }
    while(*str2 != '\0')
    {
        *str1++ = *str2++;
    }
    *str1 = '\0';
    
    return 0;
}

/**
 * @brief Copies a string manually without using strcpy
 * @param source source string
 * @param destination destination string
 * @return type - int : 0 on success
*/
int str_copy(char *source, char *destination)
{
    while(*source != '\0')
    {
        *destination++ = *source++;
    }
    *destination = '\0';
    
    return 0;
}

/**
 * @brief Find the substring of a given string
 * @param source source string
 * @param from starting index from where you want to get substring
 * @param n number of characters to be copied in substring
 * @param target target string in which you want to store targe string
 * @return type - int : 0 on success
*/
int substring(char *source, int from, int n, char *target)
{
    int length = 0;
    
    // get string length
    for(length = 0; source[length] != '\0'; ++length);

    if(from > length)
    {
        printf("Starting index is invalid.\n");
        return 1;
    }

    if(from + n > length)
    {
        // get substring till end
        n = length - from;
    }

    source += from;

    while(n > 0)
    {
        *target++ = *source++;
        n--;
    }
    *target = '\0';
    return 0;
}