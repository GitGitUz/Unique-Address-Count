#include "count.h"

int isEmptyFile(FILE * file){
	long offset = ftell(file);
	fseek(file, 0, SEEK_END);
	
	if(ftell(file) == 0){
		return 1;
	}
	
	fseek(file, offset, SEEK_SET);
	return 0;
}

int insert(unsigned long int hexD){

	int key;
	node * ptr, * prev;
	
	key = hexD % hSize;

	ptr = hashtable[key];
	
	//if there is no node in the hashtable spot
	if(hashtable[key] == NULL){	
		hashtable[key] = (node *)malloc(sizeof(node)*hSize);
		hashtable[key]->data = hexD;
		hashtable[key]->next = NULL;
		return 1;
	}
	
	//checks if the addresses are the same
	while(ptr!= NULL){
		if(ptr->data == hexD){
			return 0;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	
	//inserts address into LL node after previous one
	prev->next = (node*)malloc(sizeof(node));
	prev = prev->next;
	prev->data = hexD;
	prev->next = NULL;

	return 1;
}

int main(int argc, char * argv[]){

	FILE * fPointer = fopen(argv[1], "r");
	
	//checks if file exists
	if(fPointer == NULL){
		printf("error\n");
		return 0;
	}
	
	//checks if file is empty
	if(isEmptyFile(fPointer) == 1){
		printf("0\n");
		return 0;
	}

	//sets each node in the hashtable to NULL	
	int i;
	for(i = 0; i < hSize; i++){
		hashtable[i] = NULL;	
	}
	
	char * buffer = malloc(sizeof(char) * 100);
	while(!feof(fPointer)){
		fscanf(fPointer, "%s\n", buffer);
		//checks if line is a valid hexadecimal number
		if(buffer[0] == '0' && buffer[1] == 'x'){
			//converts the string into a hex. number
			hexD = (int)strtol(buffer, NULL, 0);
			occ += insert(hexD);
		}
	}
	
	fclose(fPointer);
	printf("%d\n", occ);

	return 0;
}
