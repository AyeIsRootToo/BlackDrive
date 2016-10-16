#include <conio.h>
//used for _getch)()

#include "stdafx.h"
//used so it will compile (pre-compiled header)
#include <conio.h>

#pragma warning (disable : 4996)

//below are just the compiler settings for compiling with g++ (I think...)
// g++ -g3 -ggdb -O0 -DDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread
// g++ -g -O2 -DNDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread

//This was adapted as from an example here http://programmingknowledgeblog.blogspot.de/2013/04/compiling-and-integrating-crypto-into.html

#include "..\cryptopp-master\osrng.h"
using CryptoPP::AutoSeededRandomPool;
//used for something, but dunno what yet

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::hex;
//used so these will work properly
#include <iomanip>

#include <fstream>
using std::fstream;
//used for getline() and for stuff with the istream and ostream

#include <string>
using std::string;
//so we do not have to type std::string

#include "..\cryptopp-master\cryptlib.h"
using CryptoPP::Exception;
//useful for debugging and catching exceptions

#include "..\cryptopp-master\filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
//used so we can use all of those functions

#include "..\cryptopp-master\modes.h"
using CryptoPP::CBC_Mode;
//so we can use CBC_Mode

#include "..\cryptopp-master\aes.h"

#include "encryptFile.h"

void encrypt_h(string iv, string key, std::string inputFile, std::string outputFile)
{//encrypt using the hex form
	//DO NOT USE, for the moment this one does not work properly
	string ciphertext;
	CryptoPP::AES::Encryption aesEncryption((byte *)key.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, (byte *)iv.c_str());
	std::ifstream ifs(inputFile);
	std::ofstream os(outputFile);
	string line;
	unsigned int a;
	while (getline(ifs, line))
	{
		a = line.length();
		CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
		stfEncryptor.Put(reinterpret_cast<const unsigned char*>(line.c_str()), line.length() + 1);
		stfEncryptor.MessageEnd();
		for (int i = 0; i < ciphertext.length(); i++)
		{
			os << std::hex << (0xFF & static_cast<byte>(ciphertext.at(i))) << std::endl;
		}
	}
	os.close();
	ifs.close();
	system(outputFile.c_str());
}

void encrypt_c(string iv, string key, string inputFile, string outputFile)
{//encrypt using the character form
	//this function works properly, but only for text files
	string cipherText;
	CryptoPP::AES::Encryption aesEncryption((byte *)key.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, (byte *)iv.c_str());
	std::ifstream ifs(inputFile);
	std::ofstream os(outputFile);
	string line;
	unsigned int a;
	unsigned int b;
	while (getline(ifs, line))
	{
		a = line.length();
		CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(cipherText));
		stfEncryptor.Put(reinterpret_cast<const unsigned char*>(line.c_str()), a + 1);
		stfEncryptor.MessageEnd();
		b = cipherText.length();
		for (int i = 0; i < b; i++)
		{
			os << cipherText.at(i);
		}
		os << endl;
		cipherText = "";
	}
	os.close();
	ifs.close();
}

void testCopy(const char* inputFile, const char* outputFile)
{//this is a debug function to test and see if it is copying data correctly
	std::ifstream ifs(inputFile, std::ios::binary | std::ios::in);
	std::ifstream ahead_1(inputFile, std::ios::binary | std::ios::out);
	std::ofstream os(outputFile, std::ios::binary | std::ios::out);
	std::ifstream readSize(inputFile, std::ios::binary | std::ios::in);
	string line;
	FILE *p = NULL;
	p = fopen(inputFile, "rb");
	fseek(p, 0, SEEK_END);
	unsigned long fileSize = ftell(p);
	unsigned long strTotalSize = 0;
	unsigned long lineSize;
	line = "";
	string nextLine;
	while (getline(ifs, line))
	{
		//os.write(line.c_str(), sizeof(line));
		lineSize = line.size();
		getline(ahead_1, nextLine);
		if (line == "")
		{
			os << endl;
			//_getch();
		}
		if (nextLine != "")
		{
			if (strTotalSize == 0)
			{
				strTotalSize++;
			}
			else os << endl;
		}
		os << line;
		nextLine = "";
		lineSize = 0;
	}
	fclose(p);
	os.close();
	ifs.close();
	//system(outputFile.c_str());
}

void test_copy_hex(const char* inFile, const char* outFile)
{
	std::ifstream ifs(inFile, std::ios::binary || std::ios::in);
	std::ifstream ahead_1(inFile, std::ios::binary || std::ios::out);
	std::ofstream os(outFile, std::ios::binary || std::ios::out);
	std::ifstream readSize(inFile, std::ios::binary || std::ios::in);
	string line;
	//FILE *p = NULL;
	ifs >> std::noskipws;
	unsigned char x;
	int b = 0;
	while (getline(ifs, line))
	{
		ifs >> x;
		os << std::hex << std::setw(2) << std::setfill('0') << (int)x << " ";
		if (b % 16 == 0)
		{
			os << endl;
		}
		b++;
	}
	//fclose(p);
	os.close();
	ifs.close();
	//system(outputFile.c_str());
}

namespace encryption
{
	void encrypt_h(string iv, string key, std::string inputFile, std::string outputFile)
	{//encrypt using the hex form
	 //DO NOT USE, for the moment this one does not work properly
		string ciphertext;
		CryptoPP::AES::Encryption aesEncryption((byte *)key.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
		CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, (byte *)iv.c_str());
		std::ifstream ifs(inputFile);
		std::ofstream os(outputFile);
		string line;
		unsigned int a;
		while (getline(ifs, line))
		{
			a = line.length();
			CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
			stfEncryptor.Put(reinterpret_cast<const unsigned char*>(line.c_str()), line.length() + 1);
			stfEncryptor.MessageEnd();
			for (int i = 0; i < ciphertext.length(); i++)
			{
				os << std::hex << (0xFF & static_cast<byte>(ciphertext.at(i))) << std::endl;
			}
		}
		os.close();
		ifs.close();
		system(outputFile.c_str());
	}

	void encrypt_c(const char* iv, const char* key, const char* inputFile, const char* outputFile)
	{//encrypt using the character form
	 //this function works properly, but only for text files
		string inv(iv);
		string theKey(key);
		string cipherText;
		string in(inputFile);
		string out(outputFile);
		CryptoPP::AES::Encryption aesEncryption((byte *)theKey.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
		CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, (byte *)inv.c_str());
		std::ifstream ifs(in);
		std::ofstream os(out);
		string line;
		unsigned int a;
		unsigned int b;
		while (getline(ifs, line))
		{
			a = line.length();
			CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(cipherText));
			stfEncryptor.Put(reinterpret_cast<const unsigned char*>(line.c_str()), a);
			stfEncryptor.MessageEnd();
			b = cipherText.length();
			for (int i = 0; i < b; i++)
			{
				os << cipherText.at(i);
			}
			os << "\n";
			cipherText = "";
		}
		os.close();
		ifs.close();
	}
}