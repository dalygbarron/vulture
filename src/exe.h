#ifndef EXE_H
#define EXE_H

/**
 * Executes a script with a dictionary of read only variables to expose to it.
 * @param script is the script to run.
 * @param env    is the set of variables.
 */
char *exe_runStringEnv(char const *script, struct Dict const *env);

/**
 * Executes a script in the form of a string.
 * @param script is the string of code to execute.
 */
char *exe_runString(char const *script);

#endif
