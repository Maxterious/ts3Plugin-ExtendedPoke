#pragma once

//write api_key into config txt file
void writeConfig(const char* new_api_key);

//read api_key from config txt file
char* readConfig(char* buffer, size_t bufSize);