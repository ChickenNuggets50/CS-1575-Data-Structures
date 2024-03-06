// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <102>
// Date: <9/28/2022>
// File: fishbomb.cpp
// Purpose: Calculate the most amount of fish that could be caught
#include <iostream>
using namespace std;

void testcase(int case_num){
  int height;
  int width;
  int num;
  int height_largest_total = 0;
  int height_index = 0;
  int height_current_total = 0;
  int width_largest_total = 0;
  int width_index = 0;
  int width_current_total = 0;

  cin >> height >> width;
  int** arr = new int*[height];

  for (int i = 0; i < height; i++) 
  {
    arr[i] = new int[width];
  }

  for (int i = 0; i < height; i++) 
  {
    for (int j = 0; j < width; j++)
    {
      cin >> num;
      arr[i][j] = num;
    }
  }

  for (int i = 0; i < height; i++) 
  {
    for (int j = 0; j < width; j++) 
    {
      for (int k = 0; k < height; k++) 
      {
        height_current_total += arr[k][j];
      } 

      for (int l = 0; l < width; l++) 
      {
        width_current_total += arr[i][l];
      } 
     
      if (height_current_total + width_current_total - arr[i][j] > height_largest_total + width_largest_total - arr[height_index][width_index])
      {
        height_largest_total = height_current_total;
        height_index = i;
        width_largest_total = width_current_total;
        width_index = j;
      }
      height_current_total = 0;
      width_current_total = 0;
    }
  }

  cout << "#" << case_num << ": at (" << height_index << "," << width_index << ") Bender catches " << height_largest_total + width_largest_total - arr[height_index][width_index] << " fish." << endl;

  for (int i = 0; i < height; i++)
    delete[] arr[i];
  delete[] arr; 
  arr = NULL;
}


int main(){
  int test_cases = 0;
  cin >> test_cases;
  for (int i = 0; i < test_cases; i++)
  {
    testcase (i);
  }
  return 0;
}

