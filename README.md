# Unique-Address-Count

This project uses a hash table to count the number of unique addresses accessed
by a program. The hash table implements chaining to provide collision resolution. 

The input of the program is a trace consisting of 64-bit addresses and it prints out the number of unique
address in the trace.

Input format: This program takes a file name as argument from the command line. The file can
              have from a few lines to millions of lines. Each line contains an address in hexadecimal format, i.e.
              0x7f1a91026b00. Each address is represented as a 64-bit hexadecimal number.

Output format: The program prints the number of unique addresses in the file.Program prints “error” (and nothing else) if the file does                  not exist.

Note: test cases are provided
