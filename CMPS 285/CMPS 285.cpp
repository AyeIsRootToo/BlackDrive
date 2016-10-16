/*

Here is the main .cpp file that is compiled and used as a testing bed to make sure all of the functions defined in the other cpp files
are working properly before we define how they are used in our C# GUI code.

I am going to comment what everything does so that everything will understand what is going on.
-AyeIsRootToo
*/

// g++ -g3 -ggdb -O0 -DDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread
// g++ -g -O2 -DNDEBUG -I/usr/include/cryptopp Driver.cpp -o Driver.exe -lcryptopp -lpthread

//This was copied as an example from http://programmingknowledgeblog.blogspot.de/2013/04/compiling-and-integrating-crypto-into.html
#include "stdafx.h"
//precompiled header for this project; may want to get rid of it later for use in our C# code

#include <conio.h>
//used for the _getch() function

#include "encryptFile.h"
//This is our custom header file that defines encrypt_c

#include "decryptFile.h"
//same as above only for decrypt_c

#include <string>
//used to hold the data needed for pretty much this entire project lol

using std::string;
//this way we do not have to type "using namespace std;" or "std::string"
//"using namespace std;" copies the entire std namespace, which chews up data unnecessarily

#include <iostream>
//used for the cout function
using std::cout;
//same as the story with string

int main(int argc, char* argv[])
{//this is only here as a testing bed to make sure our functions work properly so they will be compiled to a .dll for use in C# as mentioned above
	/*
	  AES encryption uses a secret key of a variable length (128-bit, 196-bit or 256-bit).
	  This key is secretly exchanged between two parties before communication begins.
	*/
	//const char* key = "0123456789abcdef"; //this is the key, this algorithm will not work without it
	string key = "0123456789abcdef";
	const char *test = "0123456789abcdef";
	const char *nIv = "aaaaaaaaaaaaaaaa";
	const char *ts = "input.txt";
	const char *to = "re_input.txt";
	//const char* iv = "aaaaaaaaaaaaaaaa"; //this is called the "initialization vector" and is used for CBC to speed up the process.  When we actually finish this, we will make this random so our files
	string iv = "aaaaaaaaaaaaaaaa";
	//will be more secure.
	//encryption::encrypt_c(nIv, test, "source.cpp", "encrypted.dat"); //calling the encrypt_c function using those arguments
	//encrypt_c(iv, key, "input.txt", "encrypted.dat");
	//decrypt_c(iv, key, "encrypted.dat", "decrypted.txt");
	//testCopy(ts, to);
	test_copy_hex(ts, to);

	//decryption::decrypt_c(nIv, test, "encrypted.dat", "dec.cpp"); //calling the decrypt_c function using those arguments
	cout << "Press any key to exit the program. . ."; //a command telling the user to exit
	//_getch(); //wait for user input
	return 0; //return no errors/end program
}
