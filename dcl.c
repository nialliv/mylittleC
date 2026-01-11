#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN 100
#define MAX_OUT 1000
#define MAX_BUFF 100

enum { NAME, PARENS, BRACKETS }; // PARENS вместо PARENTS

/* Прототипы функций */
void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int);

char buf[MAX_BUFF];
int bufp = 0;

int tokentype;
char token[MAX_TOKEN];
char name[MAX_TOKEN];
char datatype[MAX_TOKEN];
char out[MAX_OUT];

int main() {
  while (gettoken() != EOF) {
    strcpy(datatype, token);
    out[0] = '\0';
    dcl();
    if (tokentype != '\n') {
      printf("syntax error\n");
    }
    printf("%s: %s %s\n", name, out, datatype);
  }
  return EXIT_SUCCESS;
}

int gettoken(void) {
  int c;
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t') {
    ; /* пропускаем пробелы */
  }

  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS; // PARENS, не PARENTS
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']';) {
      ; /* читаем размер массива */
    }
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch());) {
      *p++ = c;
    }
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    return tokentype = c;
  }
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= MAX_BUFF) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

void dirdcl(void) {
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')') {
      printf("error: missing ')'\n");
    }
  } else if (tokentype == NAME) {
    strcpy(name, token);
  } else {
    printf("expected name or (dcl)\n");
  }

  while ((type = gettoken()) == PARENS || type == BRACKETS) {
    if (type == PARENS) {
      strcat(out, " function returning");
    } else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  }
}

void dcl(void) {
  int ns;

  for (ns = 0; gettoken() == '*';) {
    ns++;
  }
  dirdcl();
  while (ns-- > 0) {
    strcat(out, " pointer to");
  }
}
