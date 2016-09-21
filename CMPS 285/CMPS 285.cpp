#include "stdafx.h"

#include <conio.h>

#include <stdio.h>

#pragma warning(disable:4996)

// g++ -g3 -ggdb -O0 -DDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread
// g++ -g -O2 -DNDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread

//This was copied as an example from http://programmingknowledgeblog.blogspot.de/2013/04/compiling-and-integrating-crypto-into.html
#include <cstdio>
#include <iostream>
#include "..\cryptopp-master\osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "..\cryptopp-master\cryptlib.h"
using CryptoPP::Exception;

#include "..\cryptopp-master\hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "..\cryptopp-master\filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include "..\cryptopp-master\des.h"
using CryptoPP::DES_EDE2;

#include "..\cryptopp-master\modes.h"
using CryptoPP::CBC_Mode;

#include "..\cryptopp-master\secblock.h"
using CryptoPP::SecByteBlock;
#include <iostream>
#include <string>
#include "..\cryptopp-master\modes.h"
#include "..\cryptopp-master\aes.h"
#include "..\cryptopp-master\filters.h"
/*
CryptoPP::SecByteBlock HexDecodeString(const char *hex)
{
CryptoPP::StringSource ss(hex, true, new CryptoPP::HexDecoder);
CryptoPP::SecByteBlock result((size_t)ss.MaxRetrievable());
ss.Get(result, result.size());
return result;
}*/


int main(int argc, char* argv[]) {

	//HMODULE DLL = LoadLibrary(_T("cryptopp.dll"));
	//
	// Key and IV setup
	//AES encryption uses a secret key of a variable length (128-bit, 196-bit or 256-
	//bit). This key is secretly exchanged between two parties before communication
	//begins. DEFAULT_KEYLENGTH= 16 bytes
	std::string key = "0123456789abcdef";
	std::string iv = "aaaaaaaaaaaaaaaa";
	string plain = "CBC Mode Test";
	string cipher, encoded, recovered;

	std::cout << "Enter your text to encrypt:\n";
	std::string plaintext = "";
	std::getline(std::cin, plaintext);
	std::cout << "\n";
	std::string ciphertext;
	std::string decryptedtext;

	std::cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
	std::cout << plaintext;
	std::cout << "\n\n";

	CryptoPP::AES::Encryption aesEncryption((byte *)key.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, (byte *)iv.c_str());

	CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
	stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length() + 1);
	stfEncryptor.MessageEnd();
	cout << "cipher text plain: " << ciphertext << endl;
	std::cout << "Cipher Text (" << ciphertext.size() << " bytes)" << std::endl;
	cout << endl;
	cout << endl;
	std::cout << "cipher text In HEX FORM:: ";
	for (int i = 0; i < ciphertext.size(); i++) {

		std::cout << "0x" << std::hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
	}
	cout << endl;
	cout << endl;
	/*********************************\
	\*********************************/

	// Pretty print
	encoded.clear();
	StringSource(ciphertext, true,
		new HexEncoder(
			new StringSink(encoded)
		) // HexEncoder
	); // StringSource
	cout << "cipher text In HEX FORM (Modified):: " << encoded << endl;
	cout << endl;
	cout << endl;
	char *name2;
	name2 = (char*)malloc(encoded.length() + 1); // don't forget to free!!!!
												 //s2 = Database_row_count; // I forget if the string class can implicitly be converted to char*
												 //s2[0] = '1';
	strcpy(name2, encoded.c_str());

	const char* hex_str = name2;

	std::string result_string;
	unsigned int ch;
	for (; std::sscanf(hex_str, "%2x", &ch) == 1; hex_str += 2)
		result_string += ch;
	cout << "HEX FORM to cipher text :: ";
	std::cout << result_string << '\n';
	cout << endl;
	cout << endl;
	/*********************************\
	\*********************************/


	CryptoPP::AES::Decryption aesDecryption((byte *)key.c_str(), CryptoPP::AES::MAX_KEYLENGTH);
	CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, (byte *)iv.c_str());

	CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
	stfDecryptor.Put(reinterpret_cast<const unsigned char*>(result_string.c_str()), result_string.size());
	stfDecryptor.MessageEnd();
	std::cout << "Decrypted Text: " << std::endl;
	std::cout << decryptedtext;
	std::cout << std::endl << std::endl;

	std::cout << "Press any key to exit the program. . .";
	_getch();

	return 0;
}
