#pragma once

//write api_key into config txt file
char* writeConfig(const char* new_api_key, char* buffer, size_t bufSize);

//read api_key from config txt file
char* readConfig(char* buffer, size_t bufSize);