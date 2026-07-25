## Problems fixed:
* string needs to be std::string
* Semicolon needed after class definition
* Was indexing the matrix wrong. Should be [i * columns + j] for [i][j]
* No such thing as slicing a[3:4] in cpp