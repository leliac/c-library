void checkArgc(int, int, char *, char *);
FILE *openFile(char *, char *);

void checkArgc(int argc, int argcExp, char *argv0, char *argsFormat) {

        int i;

        if (argc != argcExp) {
                fprintf(stderr, "Error: %d parameter(s) entered, expecting %d. Run as '%s %s'.\n", argc-1, argcExp-1, argv0, argsFormat);
                exit(EXIT_FAILURE);
        }

	return;
}

FILE *openFile(char *name, char *mode) {

        FILE *file;

        if ((file = fopen(name, mode)) == NULL) {
                fprintf(stderr, "Error: cannot open file '%s' in '%s' mode.\n", name, mode);
                exit(EXIT_FAILURE);
        }

        return file;
}
