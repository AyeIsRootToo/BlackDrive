#include "stdafx.h"

#pragma warning(disable:4996)
//strcpy was replaced with strcpy_s, but it only works with strcpt.  This disable allows it to compile

// g++ -g3 -ggdb -O0 -DDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread
// g++ -g -O2 -DNDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread

//This was copied as an example from http://programmingknowledgeblog.blogspot.de/2013/04/compiling-and-integrating-crypto-into.html
#include "..\cryptopp-master\osrng.h"
using CryptoPP::AutoSeededRandomPool;
//not sure what it used for, but I am also certain it is needed

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
//so we can use the standard versions of those without having to say std::

#include <fstream>
using std::ifstream;
using std::ofstream;
//needed for file IO

#include <cstdio>

#include <string>
using std::string;
//needed for strings

#include "..\cryptopp-master\cryptlib.h"
using CryptoPP::Exception;
//useful debugging feature

#include "..\cryptopp-master\hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;
//needed for later when we get the decrypt_h function working

#include "..\cryptopp-master\filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
//needed for CryptoPP stuff lol

#include "..\cryptopp-master\modes.h"
using CryptoPP::CBC_Mode;
//declares that CBC_Mode is being used in this way

#include "..\cryptopp-master\secblock.h"
using CryptoPP::SecByteBlock;
//not sure what is used for

#include "..\cryptopp-master\aes.h"
//needed for AES Library

#include <conio.h>
//used for _getch(); we will use it in debugging, the final version will not have this command

#include "decryptFile.h"

void decrypt_h(std::string iv, std::string key, std::string inputFile, std::string outputFile)
{//used for decrypting data given just HEX
	//DO NOT USE, for the moment, this function does work properly
	string line;
	string decryptedText;
	string result_string;
	unsigned int ch;
	char* n;
	const char* hex_str;
	std::ifstream ifs(inputFile);
	std::ofstream os(outputFile);
	string encoded;
	unsigned int a;
	CryptoPP::AES::Decryption aesDecryption((byte *)key.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, (byte *)iv.c_str());
	while (getline(ifs, line))
	{
		StringSource(line, true, new HexEncoder(new StringSink(encoded)));
		n = (char*)malloc(encoded.length() + 1);
		strcpy(n, encoded.c_str());
		hex_str = n;
		cout << hex_str << "\n";
		for (; std::scanf(hex_str, "%2x", &ch) == 1; hex_str += 2)
		{
			result_string += ch;
		}
		cout << result_string << "\n";
		CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedText));
		stfDecryptor.Put(reinterpret_cast<const unsigned char*>(result_string.c_str()), result_string.size() + 1);
		cout << "this is the decrypted text" << decryptedText << "\n";
		//stfDecryptor.MessageEnd();
		ifs.close();
		os.close();
	}
}

void decrypt_c(std::string iv, std::string key, std::string inputFile, std::string outputFile)
{//decrypt using the charactor form
	string line; //used for setting the current line in the text file
	string decryptedText; //literally what it sounds like, this is where the decryptedText is store temporarily
	string result_string; //this is the string that stores the current line so the original line is not corrupted
	std::ifstream ifs(inputFile); //this is used for reading the file line by line
	std::ofstream os(outputFile); //this is used for writing the decrypted information back to the string
	unsigned int b; //used for getting rid of the random space at the end of line when data is written
	CryptoPP::AES::Decryption aesDecryption((byte *)key.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
	//alright, time to break this down.  This is saying to create an object called aesDecryption using the byte form of the key and the max keylength
	CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, (byte *)iv.c_str());
	//this is saying to use aesDecrytion for decrypting starting at the initialization vector
	while (getline(ifs, line))
	{//while there are lines in the file
		result_string = line; //set a string equal to the line so as to not corrupt the original line
		CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedText));
		//time to break down this one too.
		//This is saying to create an object called stfDecryptor using cbcDecryption and store the result in decryptedText
		//this also adds it to whatever decryptedText has currently
		stfDecryptor.Put(reinterpret_cast<const unsigned char*>(result_string.c_str()), result_string.length());
		//this is saying to use the information from result_string to actually decrypt the information
		stfDecryptor.MessageEnd();
		//claim to finish (I think)
		b = decryptedText.length() - 1;
		//decryptedText normally comes with a " " at the end of it
		os << decryptedText.substr(0,b) << "\n";
		//so actually write decrypted text to the desired file without " " at the end
		decryptedText = "";
		//reset decryptedText because stfDecryptor just tacks on the decrypted text in addtion to whatever the current string is (in this case decryptedText)
	}
	ifs.close();
	os.close();
}

namespace decryption
{
	void decrypt_h(std::string iv, std::string key, std::string inputFile, std::string outputFile)
	{//used for decrypting data given just HEX
	 //DO NOT USE, for the moment, this function does work properly
		string line;
		string decryptedText;
		string result_string;
		unsigned int ch;
		char* n;
		const char* hex_str;
		std::ifstream ifs(inputFile);
		std::ofstream os(outputFile);
		string encoded;
		unsigned int a;
		CryptoPP::AES::Decryption aesDecryption((byte *)key.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
		CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, (byte *)iv.c_str());
		while (getline(ifs, line))
		{
			StringSource(line, true, new HexEncoder(new StringSink(encoded)));
			n = (char*)malloc(encoded.length() + 1);
			strcpy(n, encoded.c_str());
			hex_str = n;
			cout << hex_str << "\n";
			for (; std::scanf(hex_str, "%2x", &ch) == 1; hex_str += 2)
			{
				result_string += ch;
			}
			cout << result_string << "\n";
			CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedText));
			stfDecryptor.Put(reinterpret_cast<const unsigned char*>(result_string.c_str()), result_string.size() + 1);
			cout << "this is the decrypted text" << decryptedText << "\n";
			//stfDecryptor.MessageEnd();
			ifs.close();
			os.close();
		}
	}
	void decrypt_c(const char* iv, const char* key, const char* inputFile, const char* outputFile)
	{//decrypt using the charactor form
		string inv(iv);
		string theKey(key);
		string in(inputFile);
		string out(outputFile);
		string test;
		string line; //used for setting the current line in the text file
		string decryptedText; //literally what it sounds like, this is where the decryptedText is stored temporarily
		string result_string; //this is the string that stores the current line so the original line is not corrupted
		//FILE *ptr = fopen(inputFile, "rb");
		ofstream newOut("testErrors.txt");
		ifstream ifs;
		ifs.open(in, std::ios::binary);
		//string test;
		//ifstream ifs(in, ifstream::); //this is used for reading the file line by line
		ofstream ofs; //this is used for writing the decrypted information back to the string
		ofs.open(out, std::ios::binary);
		unsigned int b; //used for getting rid of the random space at the end of line when data is written
		CryptoPP::AES::Decryption aesDecryption((byte *)theKey.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
		//alright, time to break this down.  This is saying to create an object called aesDecryption using the byte form of the key and the max key length
		CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, (byte *)inv.c_str());
		//this is saying to use aesDecrytion for decrypting starting at the initialization vector
		/*string seeLine;
		while (ptr)
		{
			fseek(ptr, 0, SEEK_END);
			size_t size = ftell(ptr);
			rewind(ptr);
			const char* temp = new char[size];
			cout << temp;
			_getch();
			fscanf(ptr, "%s", temp);
			fwrite(ptr, 0, size, newOut);
			delete temp;
		}
		ptr = NULL;
		newOut = NULL;*/

		while (getline(ifs, line))
		{//while there are lines in the file
			try
			{
				b = 0;
				result_string = line; //set a string equal to the line so as to not corrupt the original line
				CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedText));
				//time to break down this one too.
				//This is saying to create an object called stfDecryptor using cbcDecryption and store the result in decryptedText
				//this also adds it to whatever decryptedText has currently
				stfDecryptor.Put(reinterpret_cast<const unsigned char*>(result_string.c_str()), result_string.length());
				//this is saying to use the information from result_string to actually decrypt the information
				stfDecryptor.MessageEnd();
				//claim to finish (I think)
				//b = decryptedText.length() - 1;
				//decryptedText normally comes with a " " at the end of it
				//write a code that tells if there is another line in the program for later...
				//to be used to ensure complete copies
				test = decryptedText;
				if (test.length() == 0)
				{
					cout << "decryptedText is nothing\n";
					b = 0;
					ofs << endl;
					continue;
				}
				b = decryptedText.length() - 1;
				ofs << decryptedText;//.substr(0, b);
				//so actually write decrypted text to the desired file without " " at the end
				decryptedText = "";
				//reset decryptedText because stfDecryptor just tacks on the decrypted text in addtion to whatever the current string is (in this case decryptedText)
			}
			catch (const CryptoPP::InvalidCiphertext e)
			{
				newOut << "CryptoPP::InvalidCiphertext: " << e.GetWhat() << "\n";
				newOut << "decryptedText == " << decryptedText << "\nb = " << b << "\n";
				//_getch();
			}
			catch (const std::bad_alloc c)
			{
				newOut << "std::bad_alloc detected: " << c.what() << "\n";
				newOut << "decryptedText == " << decryptedText << "\nb = " << b << "\n";
				//_getch();
			}
		}
		ifs.close();
		ofs.close();
		newOut.close();
	}
}