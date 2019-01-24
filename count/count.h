#ifndef _count_h
#define _count_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define hSize 1000

typedef struct node{
	unsigned long int data;
	struct node * next;
}node;

int occ;
unsigned long int hexD;
node * hashtable[hSize];

int isEmptyFile(FILE * file);

int insert(size_t hex);

#endif
