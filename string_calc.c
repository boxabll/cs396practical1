#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* add_strings(char* result, char* str1, char* str2){
  strcat(result, str1);
  strcat(result, str2);
  
  return result;
}

int main() {
  printf("String Calculator\n");
  printf("Enter 'add' for addition (concatenation)\n");
  printf("Enter 'sub' for subtraction (remove substring)\n");
  printf("Enter 'rep' for replacement (insert substring)\n");
  printf("Enter your choice: ");

  char* choice = NULL;
  size_t choice_len = 0;
  ssize_t chars_read;

  chars_read = getline(&choice, &choice_len, stdin);
  
  if (chars_read != 4) {
    printf("Invalid choice. Make sure to enter \"add\", \"sub\", or \"rep\".\n");
    return 0;
  }
  else if (chars_read < 0) {
    puts("couldn't read the input");
    free(choice);
    return 1;
  }

  // null terminate the string (getline delimiter is \n)
  choice[3] = '\0';

  if (strcmp(choice, "add") == 0) {
    // read first string
    char* str1 = NULL;
    size_t len1 = 0;
    printf("Enter a string: ");
    getline(&str1, &len1, stdin);
    str1[strlen(str1)-1] = '\0';

    // read second string
    char* str2 = NULL;
    size_t len2 = 0;
    printf("Enter another string: ");
    getline(&str2, &len2, stdin);
    str2[strlen(str2)-1] = '\0';

    // calculate and display result
    char result[strlen(str1) + strlen(str2)];
    strcpy(result, str1);
    strcat(result, str2);
    printf("Result: %s\n", result);

    if(str1 != NULL) {
      free(str1);
    }
    if(str2 != NULL) {
      free(str2);
    }
    
  } else if (strcmp(choice, "sub") == 0) {
    // TODO
  } else if (strcmp(choice, "rep") == 0) {
    // TODO
  } else {
    printf(
        "Invalid choice. Make sure to enter \"add\", \"sub\", or \"rep\".\n");
  }

  // free memory 
  free(choice);
  
  return 0;
}
