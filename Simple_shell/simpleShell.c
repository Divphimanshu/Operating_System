#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64
#define DELIM " \t\r\n\a"

// Function to read a line of input from stdin
char *read_line() {
    char *line = NULL;
    ssize_t bufsize = 0; // getline will allocate buffer
    if (getline(&line, &bufsize, stdin) == -1) {
        if (feof(stdin)) {  // End of file (Ctrl+D)
            exit(0);
        } else {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}

// Function to split the line into tokens (arguments)
char **split_line(char *line) {
    int bufsize = MAX_ARGS, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIM);
    while (token != NULL) {
        tokens[position++] = token;

        if (position >= bufsize) {
            bufsize += MAX_ARGS;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL; // Null terminate argument list
    return tokens;
}

// Built-in command: change directory
int shell_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }
    return 1;
}

// Execute command
int shell_execute(char **args) {
    pid_t pid, wpid;
    int status;

    if (args[0] == NULL) {
        // Empty command
        return 1;
    }

    // Built-in commands
    if (strcmp(args[0], "cd") == 0) {
        return shell_cd(args);
    }
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    // Fork a child process
    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("shell");
    } else {
        // Parent process waits for child to finish
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

void shell_loop() {
    char *line;
    char **args;
    int status;

    do {
        printf("mysh> ");
        line = read_line();
        args = split_line(line);
        status = shell_execute(args);

        free(line);
        free(args);

    } while (status);
}

int main(int argc, char **argv) {
    printf("Welcome to Simple Shell. Type 'exit' to quit.\n");
    shell_loop();
    return EXIT_SUCCESS;
}
