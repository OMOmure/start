#include<iostream>
using namespace std;
#define MAXSIZE 255

typedef struct String 
{
    char ch[MAXSIZE];
    int length;
}String;

void initString(String &string)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        string.ch[i]='\0';
    }
    string.length=0;
}

void strAssign(String &string , char *str)
{
    int i,j;
    for ( i = 0; i < strlen(str); i++)
    {
        string.ch[i]=str[i];
    }
    for ( j = 0; i < string.length; j++)
    {
        string.ch[i]='\0';
    }
    string.length=strlen(str);
}

void strCopy(String &string,String str) //thos copy is cover
{
    int i,j;
    for ( i = 0; i < strlen(str.ch); i++)
    {
        string.ch[i]=str.ch[j];
    }
    for ( j = 0; i < strlen(string.ch); i++)
    {
        string.ch[i]='\0';
    }
    string.length=strlen(str.ch);
}

bool strIsEmpty(String string)
{
    if(string.length == 0)    return true;
    else    return false;
}

int strCompare(String string,String str)
{
    for(int i=0;i<string.length &&i<str.length; i++)
    {
        if(string.ch[i]!=str.ch[i])
        {
            return string.ch[i]-str.ch[i];
        }
    }
    return string.length - str.length;
}

bool subString (String &sub , String string ,int pos,int len)
{
    if (pos +len > string.length)
    {
        return false;
    }
    for (int i = 0; i < pos + len; i++)
    {
        sub.ch[i-pos]=string.ch[i];
    }
    sub.length = len;
    return true;
}

void strConcat(String &sub, String string , String str)
{
    int i;
    for ( i = 0; i < string.length; i++)
    {
        sub.ch[i]=string.ch[i];
    }
     for ( int j = 0; i < str.length; i++,j++)
    {
        sub.ch[i]=string.ch[j];
    }
    sub.length = string.length + str.length;
}

int strIndex(String string , String str)
{
    int i=0 ,n=string.length,m=str.length;
    String sub;
    while(i<=n-m)
    {
        subString(sub,string,i,m);
        if(strCompare(sub,str)!=0)  i++;
        else    return i;
    }
    return 0;
}

void strClear(String &string)
{
    for(int i=0 ; i<string.length ; i++)
    {
        string.ch[i]='\0';
    }
    string.length=0;
}