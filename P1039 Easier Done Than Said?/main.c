#include <stdio.h>
#include <string.h>
#include <stdbool.h>

_Bool is_vowel(char c){
  switch(c){
  case 'a':case 'e':case 'i':case 'o':case 'u':return 1;
  default: return 0;
  }
}

char buf[5000];

int main(){
  while (~scanf(" %s",buf) && strcmp(buf, "end")){
    _Bool hasVowel=false,isOK=true;
    int prevVowel=0,prevConsecutive=0,prevE=0,prevO=0;
    for (int i=0;buf[i];i++){
      if (is_vowel(buf[i])){
	hasVowel=true;
	prevVowel++;
	prevConsecutive=0;
      }else{
	prevConsecutive++;
	prevVowel=0;
      }
      if (buf[i]=='e'){
	prevE++;prevO=0;
      } else if (buf[i]=='o'){
	prevE=0;prevO++;
      } else if (i && buf[i]==buf[i-1]){
	isOK=false;
	break;
      } else {
	prevE=prevO=0;
      }
      if (prevE == 3 || prevO == 3 || prevConsecutive == 3 || prevVowel ==3){
	isOK=false;
	break;
      }
    }
    if (isOK && hasVowel) printf("<%s> is acceptable.\n",buf);
    else printf("<%s> is not acceptable.\n", buf);
  }
  return 0;
}
