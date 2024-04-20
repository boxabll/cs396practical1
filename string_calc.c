#include <stdio.h>
#include <string.h>


char* add_strings(char* str1, char* str2){
  return "";
}

int main() {
  printf("String Calculator\n");
  printf("Enter 'add' for addition (concatenation)\n");
  printf("Enter 'sub' for subtraction (remove substring)\n");
  printf("Enter 'rep' for replacement (insert substring)\n");
  printf("Enter your choice: ");

  char choice[4];
  if (fgets(choice, 4, stdin) == NULL) {
    printf(
        "Invalid choice. Make sure to enter \"add\", \"sub\", or \"rep\".\n");
  }

  if (strcmp(choice, "add") == 0) {
    
    printf("Enter a string: ");

    printf("\nEnter another string: ");

    // printf("\nResult: %s", add_strings(str1, str2));
  } else if (strcmp(choice, "sub") == 0) {
    // TODO
  } else if (strcmp(choice, "rep") == 0) {
    // TODO
  } else {
    printf(
        "Invalid choice. Make sure to enter \"add\", \"sub\", or \"rep\".\n");
  }

  return 0;
}
