#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int ConvertToDecima(char * binaryCode){
    int i, codeLength = strlen(binaryCode);
    char codeChar;
    int codeNumber, decima = 0;

    for (i = 0; i < codeLength; i++){
        codeChar = binaryCode[codeLength - i - 1];
        codeNumber = codeChar - '0';

        if(codeNumber){
            decima += 1 << i;
        }
    }

    return decima;
}

int main(){
  char * s = malloc(1);

  s = realloc(s, 10);
  strcpy(s, "123456789");

  s = realloc(s, 5);
  char * s2 = malloc(6);
  strcpy(s2, "12345");

  printf("%s\n", s);
}
