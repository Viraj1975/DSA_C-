// vectors are dynamic arrays
// here we can resize when we want to insert or delete an element
// contiguous memory allocation


// 1. declaration 

// #include<vector>

// vector <datatype> vector-name

// no need to specify size but if we want to then 

// vector <datatype> vector-name(size)


// 2. size 

// vector-name.size -> gives the size of vector


// 3. resize

// vector-name.resize(new-size) -> used to give new size to the vector


// 4. capacity 

// vector-name.capacity()

// The capacity of a vector refers to the maximum number of elements that it can hold without needing 
// to allocate more memory.

// capacity of a vector is greater than or equals to size 

// capacity keeps on increasing as size becomes greater than it.

// capacity increases in the powers of 2 but that may vary according to the compiler. this happens because we want to 
// prevent copying original elements to the new memory location after resizing. 




