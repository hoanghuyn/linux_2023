#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

void checkForError()
{
    char *error = NULL;

    if ((error = dlerror()) != NULL)
    {
        fputs(dlerror(), stderr);
        exit(1);
    }
    dlerror();
}

int main()
{
    void *handle = NULL;

    // set up function pointers
    int (*num_chars)(char*, char) = NULL;
    int (*remove_non_alpha)(char*) = NULL;
    int (*length_string)(char *) = NULL;
    int (*str_concat)(char *, char *) = NULL;
    int (*str_copy)(char *, char *) = NULL;
    int (*sub_string)(char *, int, int, char *) = NULL;

    char temp[] = "jason &&''''Fedin";
    char temp2[] = "apple";
    char temp3[100];

    handle = dlopen("/home/py/c_advanced/17_static_libs_and_shared_objs/challenge/test/lib/shared/libstring_utils.so", RTLD_LAZY);

    if (!handle)
    {
        fputs(dlerror(), stderr);
        exit(1);
    }
    dlerror();

    num_chars = dlsym(handle, "number_of_characters_in_string");
    checkForError();
    printf("Number of 'p's in apple is %d\n", (*num_chars)(temp2, 'p'));
    printf("String temp with alpha characters removed is: %s\n", temp);

    remove_non_alpha = dlsym(handle, "remove_non_alpha_characters");
    checkForError();
    (*remove_non_alpha)(temp);

    length_string = dlsym(handle, "length_of_string");
    checkForError();
    printf("String temp length is: %d\n", (*length_string)(temp));

    str_concat = dlsym(handle, "str_concat");
    checkForError();
    (*str_concat)(temp, temp2);
    printf("String concatenated with string2 is: %s\n", temp);

    str_copy = dlsym(handle, "str_copy");
    checkForError();
    (*str_copy)(temp2, temp3);
    printf("String copied is: %s\n", temp3);

    sub_string = dlsym(handle, "substring");
    checkForError();
    (*sub_string)(temp, 3, 8, temp3);
    printf("Substring is: %s\n", temp3);

    dlclose(handle);

    return 0;
}