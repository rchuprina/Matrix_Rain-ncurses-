#include "header.h"


int mx_strlen(const char *s)
{
	int i;

	for (i = 0; s[i]; i++);
	return i;
}

char *mx_strcpy(char *dst, const char *src)
{
    int i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = src[i];
    return dst;
}

char *mx_strdup (const char *s)
{
  char *new = (char *)malloc((mx_strlen(s) + 1) * sizeof(char));

  if (new == NULL)
    return NULL;
  return mx_strcpy(new, s);
}

int mx_strcmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] || s2[i]; i++)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}

bool to_lowercase(char *str)
{
  while (*str)
  {
    if (*str >= 'A' && *str <= 'Z')
      *str -= 32;
    else
    {
      if (*str < 'a' || *str > 'z')
        return false;
    }
    str++;
  }
  return true;
}

int get_color(char *str)
{
  if (!mx_strcmp(str, "red"))
    return 1;
  if (!mx_strcmp(str, "green"))
    return 2;
  if (!mx_strcmp(str, "yellow"))
    return 3;
  if (!mx_strcmp(str, "blue"))
    return 4;
  if (!mx_strcmp(str, "magenta"))
    return 5;
  if (!mx_strcmp(str, "cyan"))
    return 6;
  if (!mx_strcmp(str, "white"))
    return 7;
  return -1;
}
