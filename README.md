# Function Call Tracer

*  This code is a program analysis unit that can be incorporated with any C program
*  It traces the program's function calls and stores the trace results in a binary file
*  Visualizes the traces stored in that binary file
*  Code instrumentation is utilized. Namely, gcc's -finstrument-functions
*  Instrumentation unit collects function call trace information from an instrumented program
*  The function call traces are stored in an output file named after the program executable file. Stores the information about each call in one struct record in the output file
*  Has an independent program that can read a .calltrace file and prints its call trace records. Prints the filename followed by the details of each call trace record on a separate line in the order stored in the file
