#include "utils.h"

void  skip_separators(char **str, char separator);
int   get_next_word_size(char *str, char separator);

/**
 * @brief The `getNextWord` function takes a string as a parameter,
 *        and returns the next word in str. 
 *        It also advances the pointer of str,
 *        to the first letter after the next word.
 * 
 * @param str The address of a string.
 * @param separator The separator betewen each word in str.
 * 
 * @return  A string contains the next word in str 
 *          or NULL if str == NULL 
*/
char  *get_next_word(char **str, char separator)
{
  char   *next_word;
  int     next_word_size;

  if (str == NULL || (*str) == NULL)
    return (NULL);
  skip_separators(&(*str), ' ');
  if ((**str) == '\0')
    return (NULL);
  next_word_size = get_next_word_size(*str, separator);
  next_word = malloc(sizeof(char) * (next_word_size + 1));
  if (!next_word)
    return (NULL);
  strncpy(next_word, (*str), next_word_size);
  next_word[next_word_size] = '\0';
  (*str) += next_word_size;
  return (next_word);
}

/**
 * @brief Call at the beginning of get_next_word() for skip separator at
 *        the beginning of the string str.
 * 
 * @param str The address of a string.
 * @param separator The separator betewen each word in str.
 * 
 * @return void
*/
void  skip_separators(char **str, char separator)
{
  int i;

  i = 0;
  while ((*str)[i] && (*str)[i] == separator)
    i++;
  (*str) += i;
  return;
}

int get_next_word_size(char *str, char separator)
{
  int index;

  index = 0;
  while (str[index] && separator != str[index])
    index++;
  return index;
}
