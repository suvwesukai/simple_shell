#include "shell.h"

/**
 * the interactive will return interactive mode on condition if its active
 * @info: is the struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true or rather 0 if it is not true i.e. false
 */
int is_delim(char c, char *delim)
{
    while (*delim)
        if (*delim++ == c)
            return (1);
    return (0);
}

/**
 * _isalpha will determine if it is an alphabet.
 * @c: is the character to be keyed in
 * Return: 1 if c is alphabetic and 0 if not
 */

int _isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 * _atoi - is going to convert string to integer
 * @s: is actually the string that needs to be to be converted
 * Return: 0 if no numbers in string
 */

int _atoi(char *s)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return (output);
}