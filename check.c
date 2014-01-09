#include <stdio.h>
#include <stdlib.h>

#define DEFLINES 10
#define MAXBUFF  20000

int findTail(char *lines[][2], int nlines, char buff[], int maxbuff);

/* main() processes optional cli argument '-n', where n is a number of lines.
 * The default is 10.  findTail finds the last n lines from the input so that
 * they can be printed. */

main(int argc, char *argv[])
{
  int nlines; char *endptr;

  endptr = NULL;
  nlines = DEFLINES;
  if (argc > 2) {
    printf("error: too many arguments.\n");
    return EXIT_FAILURE;
  }
  else if (argc == 2) {
    if (*argv[1] == '-') {
      nlines = strtol(argv[1] + 1, &endptr, 10);
      if (*endptr != '\0') {
        printf("error: not a number of lines: %s\n", argv[1] + 1);
        return EXIT_FAILURE;
      }
    }
    else {
      printf("error: malformed argument: %s\n", argv[1]);
      return EXIT_FAILURE;
    }
  }

  int i;
  char *lines[nlines][2], buff[MAXBUFF];

  findTail(lines, nlines, buff, MAXBUFF);
  for (i=0; i < nlines; ++i) {
    if (lines[i][0] != NULL)
      printf(lines[i][0]);
    if (lines[i][1] != NULL)
      printf(lines[i][1]);
  }
}

#define TRUE     1
#define FALSE    0

void shift(char *lines[][2], int nlines);
void testForRoom(char *lines[][2], int index, char *buffp);

/* findTail stores characters from stdin in the buffer 'buff'. When it finds
 * the end of a line, it stores the pointer for the beginning of that line in
 * 'lines'. once nlines have been found, pointers to previous lines are shifted
 * off of the end of 'lines'. If there is space at the start of 'buff' not
 * pointed to by 'lines', then the end of a line that hits the end of the
 * buffer can continue its storage at the beginning of the buffer. This makes
 * the best use of a fixed-sized buffer for long input. */

int findTail(char *lines[][2], int nlines, char buff[], int maxbuff)
{
  char *buffp, *linestart;
  int i, c, wrap, nfound;

  for (i=0; i < nlines; ++i) {
    lines[i][0] = NULL; // [0] for storing line, or beginning of wrapped line
    lines[i][1] = NULL; // [1] for storing second half of a wrapped line
  }

  nfound = 0;
  wrap = FALSE;
  linestart = buffp = buff;
  while ((c=getchar()) != EOF) {
    if (buffp == linestart && wrap == FALSE) {
      if (nfound < nlines)
        ++nfound;
      shift(lines, nlines);
    }

    if (buffp - buff == maxbuff - 1) {
      *buffp = '\0';
      lines[nlines - 1][0] = linestart;
      wrap = TRUE;
      linestart = buffp = buff;
    }

    testForRoom(lines, nlines - nfound, buffp);

    *buffp++ = c;
    if (c == '\n') {
      *buffp++ = '\0';
      lines[nlines - 1][wrap] = linestart;
      wrap = FALSE;
      if (buffp - buff >= maxbuff - 1)
        buffp = buff;
      linestart = buffp;
    }

  }
  // this is in case the input ended without a newline.
  if (c == EOF && buffp != buff && buffp[-1] != '\0') {
    testForRoom(lines, nlines - nfound, buffp);
    *buffp = '\0';
    lines[nlines - 1][wrap] = linestart;
  }

}

/* shift is used upon finding a character that starts a new line. It shifts
 * line pointers in the pointer array to the left, making room for new line
 * pointer(s) and forgetting the pointer(s) for the oldest line in memory. */

void shift(char *lines[][2], int nlines)
{
  int i;
  for (i=0; i < nlines - 1; ++i) {
    lines[i][0] = lines[i + 1][0];
    lines[i][1] = lines[i + 1][1];
  }
  lines[nlines - 1][0] = NULL;
  lines[nlines - 1][1] = NULL;
}

/* testForRoom tests to see if the location for (or the location following the)
 * next character that would be placed in the buffer is pointed to by a line in
 * the lines pointer array. */

void testForRoom(char *lines[][2], int index, char *buffp) {
  if (buffp == lines[index][0]
      || buffp + 1 == lines[index][0]) {
    printf("error: not enough room in buffer.\n");
    exit(EXIT_FAILURE);
  }
}
