/**
 * @param str string to search
 * @param search_character character to look for
 * @return type - int : count for the number of times the search_character is found in the string
 */
int number_of_characters_in_string(char *str, char search_character);

/**
 * @brief removes all non-alpha characters from the source string
 * @param source source string
 * @return type - int : 0 on success
 */
int remove_non_alpha_characters(char *source);

/**
 * @brief returns the length of the string
 * @param source source string
 * @return type - int : length of the string
 */
int length_of_string(char *source);

/**
 * @brief Concatenates two strings
 * @param str1 string to concatenate to (resulting string)
 * @param str2 second string to concatenate from
 * @return type - int : 0 on success
 */
int str_concat(char *str1, char *str2);

/**
 * @brief Copies a string manually without using strcpy
 * @param source source string
 * @param destination destination string
 * @return type - int : 0 on success
 */
int str_copy(char *source, char *destination);

/**
 * @brief Find the substring of a given string
 * @param source source string
 * @param from starting index from where you want to get substring
 * @param n number of characters to be copied in substring
 * @param target target string in which you want to store target string
 * @return type - int : 0 on success
 */
int substring(char *source, int from, int n, char *target);