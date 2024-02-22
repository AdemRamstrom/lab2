


#include <stdio.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";


// Data declarations
int list1[20];
int list2[20];
int count = 0;
//end


void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

int main(void){
  work();

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}

//mah code

// C equivalent of function work()
void work() {
    char *textPtr[] = {text1, text2};
    int *listPtr[] = {list1, list2};
    
    for (int i = 0; i < 2; i++) {
        copycodes(textPtr[i], listPtr[i], &count);
    }
}

// C equivalent of function copycodes()
void copycodes(char *source, int *dest, int *counter) {
    while (*source != '\0') {
        *dest = *source;
        source++;
        dest++;
        (*counter)++;
    }
}
