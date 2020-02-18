//
// Created by root on 19-7-20.
//
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;


//char * strcpy(char* strDest, const char* strSrc)
//{
//    if(strSrc!=NULL&&strDest!=NULL)
//    {
//        if(strDest==strSrc ) {  return strDest;    }
//        char* address=strDest;
//        while((*strDest++=*strSrc++)!='\0');
//        return address;
//    }
//    return NULL;
//}

char *strcpy(char *str, const char *strSrc) {
    if (NULL == str || NULL == strSrc) return NULL;
    if (str == strSrc) return str;
    char *res = str;
    while (*strSrc != '\0') {
        *str++ = *strSrc++;
    }
    return res;
}


int main() {
    char *str2 = "szdfgsdf";
    char b[3];
    cout << strcpy(b, str2) << endl;

    return 0;
}





