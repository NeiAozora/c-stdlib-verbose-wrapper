/**
 * c_verbose.h - C Standard Library Wrapper with Verbose Names
 * 
 * This header provides human-readable, snake_case function names
 * that wrap the standard C library functions for easier learning.
 * 
 * Each function calls the original C function internally.
 */

#ifndef C_VERBOSE_H
#define C_VERBOSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <stdarg.h>

/* ==================== INPUT / OUTPUT FUNCTIONS ==================== */

/**
 * Print formatted output to console.
 * Wrapper for printf()
 */
static inline int print_to_console(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);
    return result;
}

/**
 * Print a string followed by newline to console.
 * Wrapper for puts()
 */
static inline int print_line_to_console(const char *str) {
    return puts(str);
}

/**
 * Print a single character to console.
 * Wrapper for putchar()
 */
static inline int print_character_to_console(int ch) {
    return putchar(ch);
}

/**
 * Read formatted input from console.
 * Wrapper for scanf()
 */
static inline int read_from_console(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int result = vscanf(format, args);
    va_end(args);
    return result;
}

/**
 * Read a line safely from input stream (e.g., stdin).
 * Wrapper for fgets()
 */
static inline char *read_line_from_input(char *buffer, int size, FILE *stream) {
    return fgets(buffer, size, stream);
}

/**
 * Read a single character from console.
 * Wrapper for getchar()
 */
static inline int read_character_from_console(void) {
    return getchar();
}

/**
 * Open a file with specified mode.
 * Wrapper for fopen()
 */
static inline FILE *open_file(const char *path, const char *mode) {
    return fopen(path, mode);
}

/**
 * Close an open file.
 * Wrapper for fclose()
 */
static inline int close_file(FILE *stream) {
    return fclose(stream);
}

/**
 * Read binary data from file into memory.
 * Wrapper for fread()
 */
static inline size_t read_binary_from_file(void *dest, size_t size, size_t count, FILE *stream) {
    return fread(dest, size, count, stream);
}

/**
 * Write binary data from memory to file.
 * Wrapper for fwrite()
 */
static inline size_t write_binary_to_file(const void *src, size_t size, size_t count, FILE *stream) {
    return fwrite(src, size, count, stream);
}

/**
 * Print formatted output to a file.
 * Wrapper for fprintf()
 */
static inline int print_to_file(FILE *stream, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int result = vfprintf(stream, format, args);
    va_end(args);
    return result;
}

/**
 * Read formatted input from a file.
 * Wrapper for fscanf()
 */
static inline int read_from_file(FILE *stream, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int result = vfscanf(stream, format, args);
    va_end(args);
    return result;
}

/**
 * Check if end-of-file indicator is set.
 * Wrapper for feof()
 */
static inline int is_end_of_file(FILE *stream) {
    return feof(stream);
}

/* ==================== MEMORY MANAGEMENT ==================== */

/**
 * Allocate uninitialized memory.
 * Wrapper for malloc()
 */
static inline void *allocate_memory(size_t bytes) {
    return malloc(bytes);
}

/**
 * Allocate zero-initialized memory for an array.
 * Wrapper for calloc()
 */
static inline void *allocate_zero_memory(size_t count, size_t size) {
    return calloc(count, size);
}

/**
 * Resize previously allocated memory block.
 * Wrapper for realloc()
 */
static inline void *resize_memory(void *ptr, size_t new_size) {
    return realloc(ptr, new_size);
}

/**
 * Free allocated memory.
 * Wrapper for free()
 */
static inline void free_memory(void *ptr) {
    free(ptr);
}

/**
 * Terminate program normally with exit status.
 * Wrapper for exit()
 */
static inline void exit_program(int status) {
    exit(status);
}

/**
 * Terminate program abnormally immediately.
 * Wrapper for abort()
 */
static inline void abort_program(void) {
    abort();
}

/* ==================== STRING CONVERSION FUNCTIONS ==================== */

/**
 * Convert string to integer (no error checking).
 * Wrapper for atoi() - UNSAFE, prefer string_to_long()
 */
static inline int string_to_integer_unsafe(const char *str) {
    return atoi(str);
}

/**
 * Convert string to long integer with error detection.
 * Wrapper for strtol()
 */
static inline long string_to_long(const char *str, char **endptr, int base) {
    return strtol(str, endptr, base);
}

/**
 * Convert string to unsigned long integer.
 * Wrapper for strtoul()
 */
static inline unsigned long string_to_ulong(const char *str, char **endptr, int base) {
    return strtoul(str, endptr, base);
}

/**
 * Convert string to double precision float.
 * Wrapper for strtod()
 */
static inline double string_to_double(const char *str, char **endptr) {
    return strtod(str, endptr);
}

/* ==================== STRING MANIPULATION FUNCTIONS ==================== */

/**
 * Get length of string (excluding null terminator).
 * Wrapper for strlen()
 */
static inline size_t string_length(const char *str) {
    return strlen(str);
}

/**
 * Copy string (no bounds checking - DANGEROUS).
 * Wrapper for strcpy()
 */
static inline char *copy_string_unsafe(char *dest, const char *src) {
    return strcpy(dest, src);
}

/**
 * Copy string with maximum length (may not null-terminate).
 * Wrapper for strncpy()
 */
static inline char *copy_string_safe(char *dest, const char *src, size_t n) {
    return strncpy(dest, src, n);
}

/**
 * Append string to another (no bounds checking).
 * Wrapper for strcat()
 */
static inline char *append_string_unsafe(char *dest, const char *src) {
    return strcat(dest, src);
}

/**
 * Compare two strings lexicographically.
 * Returns: 0 if equal, negative if s1 < s2, positive if s1 > s2
 * Wrapper for strcmp()
 */
static inline int compare_strings(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}

/**
 * Compare first n characters of two strings.
 * Wrapper for strncmp()
 */
static inline int compare_strings_n(const char *s1, const char *s2, size_t n) {
    return strncmp(s1, s2, n);
}

/**
 * Find first occurrence of a character in a string.
 * Returns pointer to character or NULL.
 * Wrapper for strchr()
 */
static inline char *find_char_in_string(const char *str, int ch) {
    return strchr(str, ch);
}

/**
 * Find first occurrence of a substring in a string.
 * Returns pointer to substring or NULL.
 * Wrapper for strstr()
 */
static inline char *find_substring(const char *haystack, const char *needle) {
    return strstr(haystack, needle);
}

/**
 * Find length of initial segment not containing any rejected characters.
 * Useful for removing newline: str[strcspn(str, "\n")] = '\0'
 * Wrapper for strcspn()
 */
static inline size_t find_first_not_of(const char *str, const char *reject) {
    return strcspn(str, reject);
}

/* ==================== MEMORY BLOCK OPERATIONS ==================== */

/**
 * Copy non-overlapping memory blocks.
 * Wrapper for memcpy()
 */
static inline void *copy_memory(void *dest, const void *src, size_t n) {
    return memcpy(dest, src, n);
}

/**
 * Copy memory blocks that may overlap.
 * Wrapper for memmove()
 */
static inline void *move_memory(void *dest, const void *src, size_t n) {
    return memmove(dest, src, n);
}

/**
 * Fill a memory block with a constant byte.
 * Wrapper for memset()
 */
static inline void *fill_memory(void *ptr, int value, size_t n) {
    return memset(ptr, value, n);
}

/**
 * Compare two memory blocks.
 * Returns: 0 if equal, negative if s1 < s2, positive if s1 > s2
 * Wrapper for memcmp()
 */
static inline int compare_memory(const void *s1, const void *s2, size_t n) {
    return memcmp(s1, s2, n);
}

/* ==================== CHARACTER CLASSIFICATION ==================== */

/**
 * Check if character is a digit (0-9).
 * Wrapper for isdigit()
 */
static inline int is_digit(int ch) {
    return isdigit(ch);
}

/**
 * Check if character is a letter (A-Z or a-z).
 * Wrapper for isalpha()
 */
static inline int is_letter(int ch) {
    return isalpha(ch);
}

/**
 * Check if character is alphanumeric (letter or digit).
 * Wrapper for isalnum()
 */
static inline int is_alphanumeric(int ch) {
    return isalnum(ch);
}

/**
 * Check if character is whitespace (space, tab, newline, etc.).
 * Wrapper for isspace()
 */
static inline int is_whitespace(int ch) {
    return isspace(ch);
}

/**
 * Convert character to lowercase if possible.
 * Wrapper for tolower()
 */
static inline int to_lowercase(int ch) {
    return tolower(ch);
}

/**
 * Convert character to uppercase if possible.
 * Wrapper for toupper()
 */
static inline int to_uppercase(int ch) {
    return toupper(ch);
}

/* ==================== ERROR HANDLING ==================== */

/**
 * Print error message based on current errno value.
 * Wrapper for perror()
 */
static inline void print_error(const char *msg) {
    perror(msg);
}

/**
 * Get error message string for a given error number.
 * Wrapper for strerror()
 */
static inline char *get_error_string(int errnum) {
    return strerror(errnum);
}

/* ==================== MATHEMATICS FUNCTIONS ==================== */

/**
 * Calculate square root.
 * Wrapper for sqrt()
 */
static inline double square_root(double x) {
    return sqrt(x);
}

/**
 * Calculate power (x^y).
 * Wrapper for pow()
 */
static inline double power(double base, double exp) {
    return pow(base, exp);
}

/**
 * Calculate absolute value for double.
 * Wrapper for fabs()
 */
static inline double absolute_value(double x) {
    return fabs(x);
}

/**
 * Round down to nearest integer (floor).
 * Wrapper for floor()
 */
static inline double floor_value(double x) {
    return floor(x);
}

/**
 * Round up to nearest integer (ceiling).
 * Wrapper for ceil()
 */
static inline double ceil_value(double x) {
    return ceil(x);
}

/* ==================== TIME FUNCTIONS ==================== */

/**
 * Get current calendar time.
 * Wrapper for time()
 */
static inline time_t get_current_time(time_t *t) {
    return time(t);
}

/**
 * Calculate time difference in seconds (end - begin).
 * Wrapper for difftime()
 */
static inline double time_difference(time_t end, time_t begin) {
    return difftime(end, begin);
}

/**
 * Get processor time used by the program.
 * Wrapper for clock()
 */
static inline clock_t get_cpu_time(void) {
    return clock();
}

/**
 * Format time structure into a string according to format.
 * Wrapper for strftime()
 */
static inline size_t format_time(char *buffer, size_t max, const char *format, const struct tm *tm) {
    return strftime(buffer, max, format, tm);
}

#endif /* C_VERBOSE_H */