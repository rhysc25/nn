## Problems fixed:
* string needs to be std::string
* Semicolon needed after class definition
* Was indexing the matrix wrong. Should be [i * columns + j] for [i][j]
* No such thing as slicing a[3:4] in cpp
* To avoid multiple definition linker errors, have the declaration in .h but definition in .cpp
* Pass pointers into functions so you don't duplicate them
* If I am using a reference member in a class, I must bind it in an initialiser list, not an assignment in the body matrix::matrix (a&, b, c) : A(a), B(b), C(c) {}. The referenced vector must never be removed from memory
* Add encapsulation so your variables can't be recklessly changed without proper process