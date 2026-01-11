#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline_one(char line[], int length);
void copy(char to[], char from[]);
void reverse(char s[], char r[]);

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE], reversed[MAXLINE];

    max = 0;
    while ((len = getline_one(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
        if (len >= 80)
        {
            printf("Length over 80 chars - %s", line);
        }
        reverse(longest, reversed);
        printf("Reversed line - \"%s\"", reversed);
    }
    if (max > 0)
        printf("Length string - %d\n%s", max, longest);
    return 0;
}

int getline_one(char s[], int len)
{
    int c, i, size = 0;
    for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (c != '\t' && c != ' ')
            s[size++] = c;
    }
    if (c == '\n')
    {
        s[size++] = c;
        ++i;
    }
    s[size] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void reverse(char s[], char r[])
{
    int start  = 0;
    int end  = strlen(s) - 1;
    while ( start < strlen(s))
        r[start++] = s[end--];
    r[strlen(s)] = '\0';
}