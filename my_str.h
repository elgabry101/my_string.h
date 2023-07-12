#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


void *memchr(const void *str, int c, size_t n);

int memcmp(const void *str1, const void *str2, size_t n);

void *memcpy(void *dest, const void * src, size_t n);

void *memmove(void *dest, const void * src, size_t n);

void *memset(void *str, int c, size_t n);

char *strcat(char *dest, const char *src);

char *strchr(const char *str, int c);

int strcmp(const char *str1, const char *str2);

int strncmp(const char *str1, const char *str2, size_t n);

int strcoll(const char *str1, const char *str2);

char *strcpy(char *dest, const char *src);

char *strncpy(char *dest, const char *src, size_t n);

int str_len(char str[]);

size_t strcspn(const char *str1, const char *str2);

char *strpbrk(const char *str1, const char *str2);

char *strrchr(const char *str, int c);

char *strerror1(int errnum);

size_t strspn(const char *str1, const char *str2);

char *strstr(const char *haystack, const char *needle);

char *strtok(char *str, const char *delim);

size_t strxfrm(char *dest, const char *src, size_t n);
