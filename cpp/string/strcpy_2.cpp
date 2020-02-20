//
// Created by Administrator on 2019/8/2.
//
#include <iostream>

using namespace std;


//char *strcpy(char *strDest, const char *strSrc) {
//    if ((strDest == NULL) || (strSrc == NULL))
//        return NULL;
//    char *strDestCopy = strDest;
//    while ((*strDest++ = *strSrc++) != '\0');
//    *strDest = '\0';
//    return strDestCopy;
//}

char *strcpy(char *cur, const char *src) {
    if (NULL == src || NULL == cur) return NULL;
    char *res = cur;
//    while (cur != '\0') {
//        *cur++ = *src++;
//    }
    while ((*cur++ = *src++) != '\0');
    *cur = '\0';
    return res;

}

char* strcpy2(char* dest,const char* src){
    if(nullptr==dest||nullptr==src)
        return nullptr;
    char* res=dest;
    while((*src)!='\0'){
        *(dest++)=*(src++);
    }

    *dest='\0';
    return res;
}


char *myStrcpy(char *dest, const char *src) {
    if (nullptr == dest || nullptr == src) return nullptr;
    char *res = dest;
    while ((*dest++ = *src++) != '\0') nullptr;
    *dest = '\0';
    return res;
}

int main34() {
    char *src = "abfdef";
    char cur[30];
    strcpy2(cur, src);
    cout << cur << endl;


    return 0;
}
