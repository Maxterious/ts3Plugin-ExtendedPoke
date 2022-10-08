#include <stdio.h>
#include "config.h"

FILE* fptr;

void writeConfig(const char* new_api_key) {
	if ((fptr = fopen("extendedPokeConfig.txt", "w")) == NULL) {
		printf("Error opening file");
	} else {
		fprintf(fptr, "%s", new_api_key);
		fclose(fptr);
	}
}

char* readConfig(char* buffer, size_t bufSize) {
	if ((fptr = fopen("extendedPokeConfig.txt", "r")) == NULL) {
		return "error opening config file";
	} else {
		if ((fgets(buffer, bufSize, fptr)) == NULL) {
			fclose(fptr);
			return "error reading config file";
		}
		else {
			fclose(fptr);
			return buffer;
		}
	}
}