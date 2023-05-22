#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: is address of the pointer to free
 *
 * Return: 1 if freed, else NULL or 0
 */
int bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return (1);
    }
    return (0);
}