#include "my_str.h"
#include <stdio.h>
#include <string.h>


static char null_check(void * s)
{
    char ret=1;
    if(s==NULL)
    {
        ret=0;
    }
    else
    {

    }
    return ret;
}


int str_len(char str[]){
    int counter=0;
    if(null_check(str))
    {

        while(*(str+counter)!=NULL)
        {
            counter++;
        }
    }

    return counter;
}


static int min(int first,int second){
    int ret=0;
    if(first>second)
        ret=second;
    else
        ret=first;

    return ret;
}


void *memchr(const void *str, int c, size_t n){

    char *ret=NULL;

    if(null_check(str))
    {
        char *srch=str;
        for(int i=0;i<n;i++)
        {
            if(*(srch+i)==(char)c)
            {
                ret=(srch+i);
                break;
            }
            else
            {

                continue;
            }
        }
    }
    else{

    }


    return ret;

}


int memcmp(const void *str1, const void *str2, size_t n){

    int ret=0;

    if(null_check(str1)&&null_check(str2))
    {
        for(int i=0;i<n;i++)
        {
            if(*((char*)str1+i)==*((char*)str2+i))
            {
                continue;
            }
            else
            {
                if(*((char*)str1+i)>*((char*)str2+i))
                    ret=1;
                else
                    ret=-1;
                break;

            }

        }
    }

    else{}


    return ret;
}


void *memcpy(void *dest, const void * src, size_t n){

    if(null_check(dest)&&null_check(src))
    {
            for(int i=0;i<n;i++)
        {
            *((char*)dest+i)=*((char*)src+i);
        }
    }
    else{}

    return dest;
}


void *memmove(void *dest, const void * src, size_t n){

    if(null_check(dest)&&null_check(src))
    {
        char tmp[n];
        for(int i=0;i<n;i++)
        {
            tmp[i]=*((char*)src+i);
        }
        for(int i=0;i<n;i++)
        {
            *((char*)dest+i)=tmp[i];
        }
    }
    return dest;
}


void *memset(void *str, int c, size_t n){

    if(null_check(str))
    {
        for(int i=0;i<n;i++)
        {
            *((char*)str+i)=c;
        }

    }
    else{}
    return str;
}


char *strcat(char *dest, const char *src){

    if(null_check(dest)&&null_check(src))
    {
        int counter=str_len(dest);

        while(*src!=NULL)
        {
            *(dest+counter)=*src++;
            counter++;
        }
    }
    else{}
    return dest;
}


char *strchr(const char *str, int c){

    char *ret=NULL;

    if(null_check(str))
    {
        for(int i=0;i<str_len(str);i++)
        {
            if(*(str+i)==(char)c)
            {
                ret=(str+i);
                break;
            }
            else
            {

                continue;
            }
        }
    }
    else{

    }


    return ret;

}


int strcmp(const char *str1, const char *str2){

        int ret=0;

    if(null_check(str1)&&null_check(str2))
    {
        int len1=str_len(str1);
        int len2=str_len(str2);

        for(int i=0;i<min(len1,len2);i++)
        {
            if(*(str1+i)==*(str2+i))
            {
                continue;
            }
            else
            {
                if(*(str1+i)>*(str2+i))
                    ret=1;
                else
                    ret=-1;
                break;

            }

        }
    }

    else{}


    return ret;
}


int strncmp(const char *str1, const char *str2, size_t n){

    int ret=0;

    if(null_check(str1)&&null_check(str2))
    {
        for(int i=0;i<n;i++)
        {
            if(*(str1+i)==*(str2+i))
            {
                continue;
            }
            else
            {
                if(*(str1+i)>*(str2+i))
                    ret=1;
                else
                    ret=-1;
                break;

            }

        }
    }

    else{}


    return ret;
}


int strcoll(const char *str1, const char *str2){

    return strcmp(str1,str2);
}


char *strcpy(char *dest, const char *src){

    if(null_check(dest)&&null_check(src))
    {
            for(int i=0;i<str_len(src);i++)
        {
            *(dest+i)=*(src+i);
        }
    }
    else{}

    return dest;

}


char *strncpy(char *dest, const char *src, size_t n){

    if(null_check(dest)&&null_check(src))
    {
    return memcpy(dest,src,n);
    }
    else{}
}


size_t strcspn(const char *str1, const char *str2){

    int len1=str_len(str1);
    int len2=str_len(str2);
    int flag=0;
    int ret=-1;

    if(null_check(str1)&&null_check(str2))
    {
    for(int i=0;i<len1;i++)
    {
        char tmp=*(str1+i);
        for(int n=0;n<len2;n++)
        {
            if(*(str2+n)==tmp)
            {
                flag++;
                break;

            }

        }
        if(flag>0)
        {
            ret=i;
            break;
        }
    }
    }
    else{}


    return ret;

}


char *strpbrk(const char *str1, const char *str2){

    char* ret=NULL;
    if(null_check(str1)&&null_check(str2))
    {
    int s=strcspn(str1,str2);
    if (s!=-1)
        ret=str1+s;
    }
    else{}

    return ret;
}


char *strerror1(int errnum){

    return strerror(errnum);
}


char *strrchr(const char *str, int c){

    int len=str_len(str)-1;
    char* ret=NULL;
    while(len>=0)
    {
        if(*(str+len)==c)
        {
            ret=str+len;
            break;
        }
        len--;
    }

    return ret;
}


size_t strspn(const char *str1, const char *str2){

    int len1=str_len(str1);
    int len2=str_len(str2);
    int ret=0;

    if(null_check(str1)&&null_check(str2))
    {
        for(int i=0;i<len1;i++)
        {
            char tmp=*(str1+i);
            int flag=0;
            for(int n=0;n<len2;n++)
            {
                if(*(str2+n)==tmp)
                {
                    ret++;
                    flag++;
                    break;
                }

            }
            if(flag==0)
            {
                break;
            }
        }
    }
    else{}


    return ret;
}


char *strstr(const char *haystack, const char *needle){

    char *ret=NULL;
    if(null_check(haystack)&&null_check(needle))
    {
        int len=str_len(needle);
        int flag=0;
        haystack=strchr(haystack, *needle);
        if(haystack!=NULL)
        {
            for(int i=1;i<len;i++)
            {
                haystack++;
                if(*haystack!=*(needle+i))
                {
                    break;
                }
                else if(i==len-1)
                {
                    ret=haystack-i;
                }
            }
            if(ret==NULL&&haystack!=NULL)
            {
                ret=strstr(haystack,needle);
            }
        }
    }
    else{}

    return ret;
}


char *strtok(char *str, const char *delim){

    int len=str_len(str);
    static char *ret=NULL;
    static int s=0;
    int count=0;
    if(s==-1)
        ret=NULL;
    else if(null_check(str)&&null_check(delim))
    {
        while(*str==*delim)
        {
            memmove(str,str+1,len-1);
            *(str+len-count)=NULL;
            count++;
        }
        len-=count;
        s=strcspn(str,delim);
        if(s!=-1)
        {
            *(str+s)=NULL;
            ret=str;
        }
        else
        {
            ret=NULL;
        }

    }
    else if(str==NULL&&delim!=NULL)
    {

        ret+=s+1;
        int len2=str_len(ret);
        while(*ret==*delim)
        {
            memmove(ret,ret+1,len2-1);
            *(ret+len2-count)=NULL;
            count++;
        }
        s=strcspn(ret,delim);
        if(s!=-1)
        {
            *(ret+s)=NULL;
        }
        else
        {
        }

    }

    return ret;
}


size_t strxfrm(char *dest, const char *src, size_t n){

    memmove(dest,src,n);

    return str_len(dest);

}
