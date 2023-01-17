// of get_allocator function
#include <iostream>
#include <vector>
  
using namespace std;
  
// Function for allocating
char* Allocate(vector<char> arr, int size)
{
  // allocate space for size(s) elements
  //It returns a copy of the allocator object associated with the container
  return arr.get_allocator().allocate(size); 
}
  
void Construct(vector<char> arr,char* point, int size)
{
    for (int iter = 0; iter < size; ++iter)
      
      // construct values in-place on the array:
      arr.get_allocator().construct(&point[iter],iter + 97); 
}
  
// Function for Deallocating
void deAllocate(vector<char> arr,char* point, int size)
{
    for (int iter = 0; iter < size; ++iter)
        arr.get_allocator().destroy(&point[iter]);
      
    // free allocated memory    
    arr.get_allocator().deallocate(point, size); 
}
  
// Driver code
int main()
{
    vector<char> array;
    char* pointer;
    int size = 8;
      
    pointer = Allocate(array, size);
    cout << "here function allocate it return -->" << pointer[0] << endl;
    Construct(array, pointer, size);
  
    cout << "Array elements:  ";
    for (int iter = 0; iter < size; ++iter)
        cout << pointer[iter] << " ";
  
    deAllocate(array, pointer, size);
  
    return 0;
}