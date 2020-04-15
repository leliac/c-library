#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STRLEN_MAX 100

void checkArgc(int, int, char [], char []);
FILE *myFopen(char [], char []);

int * callocIntArray(int);

char ***mallocStringMatrix(int, int);
char **mallocStringArray(int);
char *mallocString(int);

char * myStrdup(char *);

void freeStringArray(char **, int);
void freeStringMatrix(char ***, int, int);

void freadStrings(FILE *, char **, int);
void fscanfStringMatrix(FILE *, char ***, int, int);

void fprintfStringArray(FILE *, char **, int);
void printfStringMatrix(char ***, int, int);

void checkStrlen(char [], int);
void tolowerString(char []);
int stringsUnsorted(char [], char[]);
void sortStrings(char **, int);


void checkArgc(int argc, int argcExp, char argv0[], char argNames[]) {

        int i;

        if (argc != argcExp) {
                fprintf(stderr, "Error: %d parameter(s) entered, expecting %d. Run as '%s %s'.\n", argc-1, argcExp-1, argv0, argNames);
                exit(EXIT_FAILURE);
        }
}

FILE *myFopen(char fileName[], char mode[]) {

        FILE *file;

        if ((file = fopen(fileName, mode)) == NULL) {
                printf("Error: cannot open file '%s' in '%s' mode.\n", fileName, mode);
                exit(EXIT_FAILURE);
        }
        return file;
}

int * callocIntArray(int dim) {

	int *array;

	if ((array = calloc(dim, sizeof(int))) == NULL) {
		fprintf(stderr, "Error: cannot allocate %lu bytes for %d integers.\n", dim*sizeof(int), dim);
		exit(EXIT_FAILURE);
	}

	return array;
}

char ***mallocStringMatrix (int rows, int cols) {

	char ***stringMatrix;
	int i;

        if ((stringMatrix = malloc(rows*sizeof(char **))) == NULL) {
                printf("Error: cannot allocate %lu bytes for %d char **.\n", rows*sizeof(char **), rows);
                exit(EXIT_FAILURE);
        }
	for (i = 0; i < rows; i++) {
		stringMatrix[i] = mallocStringArray(cols);
	}

        return stringMatrix;
}

char **mallocStringArray (int dim) {

        char **array;

        if ((array = malloc(dim*sizeof(char *))) == NULL) {
                printf("Error: cannot allocate %lu bytes for %d char pointers.\n", dim*sizeof(char *), dim);
                exit(EXIT_FAILURE);
        }

        return array;
}

char *mallocString(int stringLen) {

        char *string;

        if ((string = malloc((stringLen+1)*sizeof(char))) == NULL) {
                printf("Error: cannot allocate %lu bytes for %d char.\n", (stringLen+1)*sizeof(char), stringLen+1);
                exit(EXIT_FAILURE);
        }
        return string;
}

void freeStringArray(char **array, int dim) {

        int i;

        for (i = 0; i < dim; i++) {
                free(array[i]);
        }
        free(array);

	return;
}

void freeStringMatrix(char ***matrix, int rows, int cols) {

	int r;

	for (r = 0; r < rows; r++) {
		freeStringArray(matrix[r], cols);
	}
	free(matrix);

	return;
}

char * myStrdup(char *original) {

	char *duplicate;

	if ((duplicate = strdup(original)) == NULL) {
		fprintf(stderr, "Error: cannot duplicate string '%s'.\n", original);
		exit(EXIT_FAILURE);
	}

	return duplicate;
}

void freadStrings(FILE *file, char **strings, int numStrings) {

	int i;
	int stringLen;
	char string[STRLEN_MAX+1];

	for (i = 0; i < numStrings; i++) {
		fscanf(file, "%s", string);
		stringLen = strlen(string);
		if (stringLen > STRLEN_MAX) {
			printf("Error: string %d ('%s') has length %d. Maximum length allowed is %d.\n", i+1, string, stringLen, STRLEN_MAX);
			exit(EXIT_FAILURE);
		}
		strings[i] = mallocString(stringLen+1);
		strcpy(strings[i], string);
	}
}

int stringsUnsorted(char string1[], char string2[]) {

	int i, minStringLen;

	minStringLen = (strlen(string1) < strlen(string2) ? strlen(string1) : strlen(string2));
	for (i = 0; i < minStringLen; i++) {
		if (tolower(string1[i]) > tolower(string2[i])) {
			return 1;
		} else if (tolower(string1[i]) < tolower(string2[i])) {
			return 0;
		}
	}
	return (strlen(string1) > strlen(string2) ? 1 : 0);
}

void sortStrings(char **strings, int numStrings) {

	char tempString[STRLEN_MAX+1];
	int i, j;
	char unsorted;

	for (i = 0, unsorted = 1; i < numStrings && unsorted; i++) {
		for (j = 0, unsorted = 0; j < numStrings-1-i; j++) {
			if (stringsUnsorted(strings[j], strings[j+1])) {
				unsorted = 1;
				strcpy(tempString, strings[j]);
				strcpy(strings[j], strings[j+1]);
				strcpy(strings[j+1], tempString);
			}
		}
	}
}

void fprintfStringArray(FILE *file, char **array, int dim) {

	int i;

	for (i = 0; i < dim; i++) {
		fprintf(file, "%s\n", array[i]);
	}

	return;
}

void checkStrlen(char *string, int maxLen) {

        if (strlen(string) > maxLen) {
                fprintf(stderr, "Error: string '%s' is too long (%lu characters, expecting %d at most).\n", string, strlen(string), maxLen);
                exit(EXIT_FAILURE);
        }

        return;
}

void tolowerString(char string[]) {

        int i;

        for (i = 0; string[i]!='\0'; i++) {
                string[i] = tolower(string[i]);
        }

        return;
}

void fscanfStringMatrix(FILE *file, char ***stringMatrix, int R, int C) {

        int r, c;
        char string[STRLEN_MAX];

        for (r = 0; r < R; r++) {
                for (c = 0; c < C; c++) {
                        fscanf(file, "%s", string);
                        stringMatrix[r][c] = mallocString(strlen(string));
                        strcpy(stringMatrix[r][c], string);
                }
        }

        return;
}

void printfStringMatrix(char ***stringMatrix, int R, int C) {

        int r, c;

        printf("stringMatrix =\n");
        for (r = 0; r < R; r++) {
                for (c = 0; c < C; c++) {
                        printf("%s ", stringMatrix[r][c]);
                }
                printf("\n");
        }

        return;
}

