#ifndef DECRYPTFILE_H

#define DECRYPTFILE_H

#include "stdafx.h"
#include <string>
#include <stdexcept>

namespace decryption
{
	extern "C" { __declspec(dllexport) void decrypt_h(std::string iv, std::string key, std::string inputFile, std::string outputFile);}
	extern "C" { __declspec(dllexport) void decrypt_c(const char* iv, const char* key, const char* inputFile, const char* outputFile);}
}

void decrypt_h(std::string iv, std::string key, std::string inputFile, std::string outputFile);
void decrypt_c(std::string iv, std::string key, std::string inputFile, std::string outputFile);

#endif // !DECRYPTFILE_H
