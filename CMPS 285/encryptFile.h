#ifndef ENCRYPTFILE_H

#define ENCRYPTFILE_H

#include "stdafx.h"
#include <string>
#include <stdexcept>

namespace encryption
{
	extern "C" { __declspec(dllexport) void encrypt_h(std::string iv, std::string key, std::string inputFile, std::string outputFile);}
	extern "C" { __declspec(dllexport) void encrypt_c(const char* iv, const char* key, const char* inputFile, const char* outputFile);}
}

void encrypt_h(std::string iv, std::string key, std::string inputFile, std::string outputFile);
void encrypt_c(std::string iv, std::string key, std::string inputFile, std::string outputFile);
void testCopy(const char* inputFile, const char* outputFile);
void test_copy_hex(const char* inFile, const char* outFile);

#endif // !ENCRYPTFILE_H
