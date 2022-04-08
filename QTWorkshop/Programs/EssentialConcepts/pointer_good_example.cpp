//bin/true; g++ -o "/tmp/$0.bin" "$0" && "/tmp/$0.bin" "$@"; exit $?
#include <cstdint>
#include <iostream>

void increment_through_reference(int &c) {
	//references can't be NULL
	c++;
}

void increment_through_pointers(int *c) {
	// pointer arithmetic
	(*c)++;
}

int main() {
	int a = 12;
	int *pointerToA = &a; 

	std::cout << "Dereference pointerToA : " << *pointerToA << std::endl;

	increment_through_reference(a);
	std::cout << "Value of A : " << a << std::endl;
	std::cout << "Dereference pointerToA : " << *pointerToA << std::endl;

	increment_through_pointers(&a);
	std::cout << "Value of A : " << a << std::endl;
	std::cout << "Dereference pointerToA : " << *pointerToA << std::endl;


	// finding the size of array without using sizeOf operator 
  int array[] = {1,2,3,4,5};

		
	std::cout << array << std::endl;
	std::cout << &array << std::endl;

	std::cout << array+1 << std::endl;

	std::cout << &array+1 << std::endl;
	std::cout << *(&array+1) << std::endl; //pointer to pointer
	
	int size = *(&array + 1) - array;
	std::cout << size << std::endl;
}

