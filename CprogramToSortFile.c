#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(FILE * fpin, FILE * fpout) { //function to copy

  char ch;

  fscanf(fpin, "%c", & ch); //read a char from infile

  while (!feof(fpin)) { //loop until end of file

    if (ch >= 'a' && ch <= 'z') { //character is a lower case letter

      ch -= 32; //convert it to upper case. ASCII value difference

    }

    fprintf(fpout, "%c", ch); //print character to outfile

    fscanf(fpin, "%c", & ch); //read next character from infile

  }

}

void sort(FILE * fpin, FILE * fpout) { //function to sort lines

  char lines[50][11];

  char line[10];

  int i = 0, j = 0, tlines = 0;

  char ch;

  fscanf(fpin, "%c", & ch); //read a character from infile

  while (!feof(fpin)) { //loop until eof

    if (ch == '\n') { //new line character

      lines[i][j] = '\0'; //end current line

      i++; //start new line

      j = 0;

    } else { //not a new line char

      if (j < 10) { //copy only 10 characters of a line

        lines[i][j] = ch; //copy character

        j++; //increment char count

      }

    }

    fscanf(fpin, "%c", & ch); //read next char

  }

  lines[i][j] = '\0'; //end end current line

  tlines = i + 1;

  //sort all lines using selection sort technique

  for (i = 0; i < tlines - 1; i++) {

    for (j = i + 1; j < tlines; j++) {

      if (strcmp(lines[i], lines[j]) > 0) {

        strcpy(line, lines[i]);

        strcpy(lines[i], lines[j]);

        strcpy(lines[j], line);

      }

    }

  }

  //print sorted lines to output file

  for (i = 0; i < tlines; i++) {

    fprintf(fpout, "%s\n", lines[i]);

  }

}

void wc(FILE * fpin, FILE * fpout) { //function to count words and lines

  int wc = 0, lc = 0; //initialize word and line counts to 0

  char ch;

  fscanf(fpin, "%c", & ch); //read a char from infile

  while (!feof(fpin)) { //loop until eof

    if (ch == '\n') { //new line character

      lc++; //increment line count

      wc++; //increment word count

    } else if (ch == ' ') { //space character

      wc++; //increment word count

    }

    fscanf(fpin, "%c", & ch); //read next char

  }

  wc++;

  lc++;

  //print word and line count to console

  printf("Number of words: %d\n", wc);

  printf("Number of lines: %d\n", lc);

  //print word and line count to out file

  fprintf(fpout, "Number of words: %d\n", wc);

  fprintf(fpout, "Number of lines: %d\n", lc);

}

int main() { //main method
    int choice;
    char file1[20];
    char file2[20];
    do{

        printf("Usage:\n\tThis program must be provided with three arguments through command line.\n"

        "\tchoice infile outfile\n\tchoice - is the choice of operation\n"

        "\tinfile - this is the input file name\n"

        "\toutfile - this is the output file name\n\n");

        printf("\n Please enter you choice: ");
        scanf("%d", &choice);

        printf("\n Enter input filename: ");
        scanf("%s", file1);
        FILE * fpin = fopen(file1, "r"); //open input file

        if (fpin == NULL) { //input file open failure

            //print error message and return

            printf("Error! No such file - infile\n");

            return 0;

        }
        printf("\n Enter output filename: ");
        scanf("%s", file2);
        FILE * fpout = fopen(file2, "w"); //open output file

        if (fpout == NULL) { //output file open failure

            //print error message and return

            printf("Error! Cannot save file - outfile\n");

            return 0;

        }

        switch (choice) { //switch input choice

            case 1: //first choice

                //call copy function to copy texts from input file to output

                copy(fpin, fpout);

                break;

            case 2: //second choice

                //call function to sort the lines of input file and

                //copy 10 characters from each lines to output file

                sort(fpin, fpout);

                break;

            case 3: //third choice

                //call function to count words and lines of input file

                //and print result to output file

                wc(fpin, fpout);

                break;

            default: //invalid choice

                //print error message and return

            printf("Wrong choice, the only available values are 1, 2, 3\n");

            return 0;

        }
    }while(choice == 1 || choice == 2 || choice == 3);

  return 0;

}
