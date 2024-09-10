#include <iostream>
#include "functions.h"

int main() {
  
  // Read data from file
  readFile("A1input.txt");

  // Example operations
  int index = findInteger(5);
  if (index != -1) {
    
    std::cout << "found 5 at index " << index << std::endl;
    } 
    
    else {
      std::cout << "5 not found" << std::endl;
    }
    
  modifyValue(2, 10);
  addInteger(20);
  replaceOrRemove(3, true);

  return 0;
}