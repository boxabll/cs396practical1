#include <stdio.h>
#include <string.h>

int main() {
  printf("String Calculator\n");
  printf("Enter 'add' for addition (concatenation)\n");
  printf("Enter 'sub' for subtraction (remove substring)\n");
  printf("Enter 'rep' for replacement (insert substring)\n");
  printf("Enter your choice: ");

  char* choice;
  // TODO: read in user's choice

  if (strcmp(choice, "add") == 0) {
    // TODO
  } else if (strcmp(choice, "sub") == 0) {
    // TODO
  } else if (strcmp(choice, "rep") == 0) {
    // TODO
  } else {
    printf("Invalid choice. Make sure to enter \"add\", \"sub\", or \"rep\".\n");
  }

  return 0;
}