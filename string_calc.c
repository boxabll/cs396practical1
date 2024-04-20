#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_strings(){
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
}

void sub_strings() {
  // read first string
  char* source = NULL;
  size_t source_len = 0;
  printf("Enter a string: ");
  getline(&source, &source_len, stdin);
  source[strlen(source)-1] = '\0';

  // read second string
  char* substring = NULL;
  size_t substring_len = 0;
  printf("Enter a substring to remove: ");
  getline(&substring, &substring_len, stdin);
  substring[strlen(substring)-1] = '\0';

  // won't work if substring longer than source string
  if (strlen(substring) > strlen(source)) {
    printf("Substring is longer than string. Operation not possible.\n");
  }
  else {
    char* sub_loc = strstr(source, substring);

    // if substring not found, source string will be printed unchanged

    if (sub_loc != NULL) {
      int loc = sub_loc - source; // index of substring in source

      // remove string in place from source
      int read = loc + strlen(substring); // index to read rest of source from 

      // move source chars from after substring until no more left
      while (read < strlen(source)) {
        source[loc] = source[read];
        read += 1;
        loc += 1;
      }
      // null terminate
      source[strlen(source) - strlen(substring)] = '\0';
    }

    printf("Result: %s\n", source);
  }

  // free strings used
  if (source != NULL) {
    free(source);
  }
  if (substring != NULL) {
    free(substring);
  }
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
    add_strings();
    
  } else if (strcmp(choice, "sub") == 0) {
    sub_strings();
    // should this remove all instances of substring? or just first?
    
  } else if (strcmp(choice, "rep") == 0) {
    // TODO
    // use strstr
    // and strncpy?
    // check that position given is valid (enough space to substitute)
  } else {
    printf(
        "Invalid choice. Make sure to enter \"add\", \"sub\", or \"rep\".\n");
  }

  // free memory 
  free(choice);
  
  return 0;
}
