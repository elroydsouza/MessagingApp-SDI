Coding Standards Guide

Versions
C++ 17 should be used throughout the project to maintain compatibility.

Header Files
All C++ files should have an equivalent header file (.h) that contains the declarations of classes and functions in the equivalent .cpp file unless it is completely unnecessary to do so.
All header files should be able to compile individually.
All header files should be defined by the define guard; the format of the define guard must be <project>_<path>_<file>_H_.
Include headers in lieu of forward declaration whenever possible.

Scoping
Code should be included in a namespace whenever possible.
Namespaces should be used to avoid the reuse of class of function names (to avoid conflicts).
Declare variables as close to the first use as possible to make it easier for the reader to find.

Classes
Classes should be used as often as possible to improve the organisation and accessibility of the code.
Make sure to use a struct only for carrying data, whilst having everything else within a class.
Sub-classes should be used to avoid creating multiple classes with similar attributes.
Attributes should be private wherever possible unless it is required elsewhere.
Similar declarations should be grouped together with public attributes being foremost, followed by protected attributes, and finally private attributes.

Functions
Functions should be used to reduce the amount of repeated code within the codebase.
Multiple shorter functions are preferred over fewer, larger, more convoluted functions.
Function overloading should only be used where the reader will have a good understanding of the functions use case without having to look at the definition.
Default arguments should be used wherever possible to improve the ease of use of functions.
 
Other C++ Features
Friend functions in classes should only be used when or if necessary.
Use streams whenever necessary, such as using I/O for debugging purposes.
The most appropriate type of integer should be used for each given situation.
Standard C++ library, including functions such as STOI, sort and search functions used as often as possible and wherever necessary to reduce the amount of lower-level code written.
The Boost library should be used whenever necessary whether in source code or to include tests using the Boost test library.

Naming
Variable names should use camel case when needed when comprised of more than one word. Variable names should also be worded aptly dependant on its use case or content.
Classes and functions should also be capitalised appropriately with ‘Pascal case’ (where each word is capitalised in a compound word).
The names of namespaces should all be lowercase.

Comments
Comments should be included throughout the codebase in both header and source files where deemed appropriate.
Comments should be used to explain parts of the code that could be confusing to the reader.
Special comment blocks should be used with the intention of using Doxygen for automatic generation of documentation.

Formatting
Lines of code should not be too long to prevent the use of unnecessary side scrolling to therefore improve readability of the code.
Similar variables should be grouped together, and spaces should be used between dissimilar sections of code.
Try use as little vertical whitespace (1 or 2 lines maximum) as possible to improve readability.
When using conditionals, a space should be present between the if/else keyword and the condition to be met.

Exceptions to the Rules
Try to conform to the style that others working on the same codebase have used to ensure consistency and therefore improve readability.
