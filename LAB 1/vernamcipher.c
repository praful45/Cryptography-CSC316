#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* alphabets() {
  char *alpha = malloc(26*sizeof(char*));
  for(int i = 0, j=65; i<26, j<=90; ++i, ++j) {
    *(alpha + i) = j; 
  }
  return alpha;
}
void toUpper(char *text,int len) {
  for(int i = 0; i <len; ++i) {
    if(text[i] >='a' &&  text[i] <='z') {
      text[i] -=32;
    }
  } 
}

int indexOf(char letter, char *alpha) {
  int index;
  for(int i = 0; i < 26; i++) {
    if(letter == alpha[i])
      return i;
  } 
}

void encrypt(char *plain,char *key,char *C) {
  char *alpha=alphabets();
  int indexP,indexK,index;
  for(int i=0,j=0;i<strlen(plain),j<strlen(plain); ++i,++j) {
    indexP = indexOf(plain[i],alpha);
    indexK = indexOf(key[j],alpha);
    index = indexP + indexK;
    if (index > 25) 
        index %=26;
    C[i] = alpha[index];
  } 
}

void decrypt(char *cipher, char *key, char *D) {
  char *alpha=alphabets();
  int indexP,indexK,index;
  for(int i=0; i<strlen(cipher); ++i) {
    index = indexOf(cipher[i],alpha);
    indexK = indexOf(key[i],alpha);
    indexP = index - indexK; 
    if(indexP <0) {
      indexP %=26;
      if (indexP < 0) 
        indexP +=26;
    }
    D[i] = alpha[indexP];
  }

}


int main() {
  char *P;
  printf("Enter your plain text: ");
  scanf("%ms",&P);
  toUpper(P,strlen(P));

  char *K;
  printf("Enter the key: ");
  KeyLabel:
  scanf("%ms",&K);
  toUpper(K,strlen(K));

  printf("\n\nthe plain text is : %s of length %ld\n",P,strlen(P));
  printf("the key is : %s of length %ld\n",K,strlen(K));
  
  if(strlen(P) != strlen(K)) {
    printf("[x] Incorrect length of Key!!\n\nEnter the key of length %ld: ",strlen(P));
    goto KeyLabel;
  }

  char *C = malloc(strlen(P)*sizeof(char*)); 
  char *D = malloc(strlen(P)*sizeof(char*)); 

  /* ENCRYPTION */
  encrypt(P,K,C);
  printf("\n\nThe cipher text is: ");
  printf("%s\n",C);


  printf("================================================\n");
   /* DECRYPTION */
  decrypt(C,K,D);
  printf("From above encrypted text: %s\n",C);
  printf("The deciphered text is: ");
  printf("%s\n",D);
}

