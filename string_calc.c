#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

// returns 0 if contains nonnumeric chars, 1 if it doesn't
int is_numeric(char* str) {
  while (*str != '\0') {
    if (isdigit(*str) == 0) {
      return 0;
    }
    str += 1;
  }
  return 1; // all chars are numeric
} 

void rep_strings() {
  // variables for replacement string
  char* rep = NULL;
  size_t rep_len = 0;

  // read source string
  char* source = NULL;
  size_t source_len = 0;
  printf("Enter a string: ");
  getline(&source, &source_len, stdin);
  source[strlen(source)-1] = '\0';

  char* pos_str = NULL;
  size_t pos_len = 0;
  printf("Enter the position at which to begin replacing: ");
  getline(&pos_str, &pos_len, stdin);
  pos_str[strlen(pos_str)-1] = '\0';
  int pos;

  if (is_numeric(pos_str) == 0) {
    printf("Invalid input. Must enter a non-negative number\n");
  }
  else {
    pos = atoi(pos_str); // numeric so convert from string to int

    if (pos >= strlen(source)) {
      printf("Invalid index. Must be within source string\n");
    }
    else {
      // read second string
      printf("Enter the string to replace with: ");
      getline(&rep, &rep_len, stdin);
      rep[strlen(rep)-1] = '\0';

      // rep string won't go past end of source string
      if (strlen(rep) <= strlen(source) - pos) {
        // until run out of rep string chars
        int read = 0; // index to read from rep
        while (read < strlen(rep)) {
          // copy chars over
          source[pos] = rep[read];
          pos += 1;
          read += 1;
        }
      }

      printf("Result: %s\n", source);
    }
  }

  // free memory used
  if (source != NULL) {
    free(source);
  }
  if (rep != NULL) {
    free(rep);
  }
  if (pos_str != NULL) {
    free(pos_str);
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
    
  } else if (strcmp(choice, "rep") == 0) {
    rep_strings();
    
  } else {
    printf(
        "Invalid choice. Make sure to enter \"add\", \"sub\", or \"rep\".\n");
  }

  // free memory 
  free(choice);
  
  return 0;
}
