#include <stdio.h>
//user defined string functions
int mystrlen(const char *s);
char* mystrcpy(char *s1, const char *s2);
char* mystrncpy(char *s1, const char *s2, int n);
char* mystrcat(char *s1, const char *s2);
char* mystrncat(char *s1, const char *s2, int n);
int mystrcmp(const char* s1, const char* s2);
int mystrncmp(const char* s1, const char* s2, int n);

int main()
{
    char s1[100] = "   ";
    char s2[100] = "Mashal";
    char s3[100] = "FA23-BCS-187";
    int n2 = 6;
    int n3 = 12;
    int m;

    printf("First string: %s", s2);
    printf("\nSecond string: %s", s3);
    printf("\nLength of first string: %d", mystrlen(s2));
    printf("\nLength of second string: %d", mystrlen(s3));
    printf("\nCopying second string to the first: %s", mystrcpy(s1, s2));
    printf("\nCopying second string to the first till length of first string: %s", mystrncpy(s1, s2, n2));
    printf("\nAppending the second string to first string: %s", mystrcat(s1, s2));
    printf("\nAppending the first string to second string: %s", mystrcat(s2, s1));
    printf("\nConcatenate at most %d characters from string2 to string1: %s", n2, mystrncat(s1, s2, n2));
    printf("\nConcatenate at most %d characters from string1 to string2: %s", n2, mystrncat(s2, s1, n2));
    m = mystrcmp(s1, s2);
    if (m==0)
    {
        printf("\nTwo entered strings are same!!\n");
    }
    else
    {
        printf("\nTwo entered strings are not same!!\n");
    }

}

// function to calculate the length of a string
int mystrlen(const char *s)
{
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

//function to copy one string to another
char* mystrcpy(char *s1, const char *s2)
{
    int i = 0;
    while ((s1[i] = s2[i]) != '\0') {
        i++;
    }
    return s1;
}

//function to copy one string to another so that string 2 is copied till the size of string 1
char* mystrncpy(char *s1, const char *s2, int n)
{
    int i = 0;
    for (i=0 ; i<n && s2[i]!='\0' ; ++i)
    {
        s1[i] = s2[i];
    }
    while (i<n) {
        s1[i] = '\0';
        ++i;
    }
    return s1;
}

// function to concatenate strings
char* mystrcat(char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] != '\0') {
        i++;
    }

    int j = 0;
    while ((s1[i] = s2[j]) != '\0') {
        i++;
        j++;
    }
    return s1;
}

char* mystrncat(char *s1, const char *s2, int n)
{
    int i = 0, j = 0;
    for (i=0 ; s1[i]!='\0' ; ++i)

        for (j=0 ; j<n && s2[j]!='\0' ; ++j, ++i)
        {
            s1[i] = s2[j];
        }
    s1[i]!='\0';

    return s1;
}

int mystrcmp(const char* s1, const char* s2)
{
    int length1 = 0, length2 = 0, flag;
    for (int i=0 ; s1[i]!='\0' ; i++)
    {
        length1++;
    }
    for (int i=0 ; s2[i]!='\0' ; i++)
    {
        length2++;
    }
    if (length1!=length2)
    {
        return 1;
    }
    else
    {
        for (int i=0 ; i<length1 ; i++)
        {
            if (s1[i]!=s2[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
  }
}

int mystrncmp(const char* s1, const char* s2, int n)
{
    int i;
    for (i=0 ; s1[i]!='\0' && s2[i]!='\0' ; i++)
    {
        if (s1[i]!=s2[i]);
        {
            return s1[i]-s2[i];
        }
    }

    if (i==n)
    {
        return 0;
    }

    return s1[i]-s2[i];

}



