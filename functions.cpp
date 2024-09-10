#include "functions.h"
#include <iostream>
#include <fstream>

const int max_capacity = 100;
int arr[max_capacity];
int num_items = 0;

// read int from a file into array
void readFile(const char* filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "error cannot open file" << std::endl;
    return;
    }
    
    num_items = 0;

    while (file >> arr[num_items] && num_items < max_capacity) {
      num_items++;
    }

  file.close();
}

// check if certain integer exists in  array
int findInteger(int value) {
  for (int i = 0; i < num_items; ++i) {
    
    if (arr[i] == value) {
      return i;
      }
      
    }
    return -1; 
}

// modify value of int in array
void modifyValue(int index, int newValue) {
  try {
    if (index < 0 || index >= num_items) {
      throw std::out_of_range("index out of range");
      }
      
      int oldValue = arr[index];
      arr[index] = newValue;
      std::cout << "old value: " << oldValue << ", new value: " << arr[index] << std::endl;
      } 
      
      catch (const std::out_of_range& ex) {
        std::cerr << ex.what() << std::endl;
        }
}

// add new int to end
void addInteger(int value) {
  try {
    if (num_items >= max_capacity) {
      throw std::overflow_error("array full");
      }
      
      arr[num_items++] = value;
      } 
      
      catch (const std::overflow_error& ex) {
        std::cerr << ex.what() << std::endl;
        }
}

// replace the value with 0 or remove
void replaceOrRemove(int index, bool remove) {
  try {
    if (index < 0 || index >= num_items) {
      throw std::out_of_range("index out of range");
      }
      
      if (remove) {
        for (int i = index; i < num_items - 1; ++i) {
          arr[i] = arr[i + 1];
          }
          
        num_items--;
      }
      
      else {
        arr[index] = 0;
        } 
      } 
            
      catch (const std::out_of_range& ex) {
        std::cerr << ex.what() << std::endl;
        }
}