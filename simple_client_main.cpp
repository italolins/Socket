#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>


#include <bitset> 

using namespace std;


int main ( int argc, char* argv[] ){
	string host;
	if(argv[1] == NULL ){
		host = "localhost";
	} else host = string(argv[1]);
	
	try{
		
		ClientSocket client_socket ( host, 30000 );

		string reply;

		try{
			cout << "entrada:" << endl;
			getline (cin, reply);
			
			//cin >> reply;

			bitset<8> baz (string("0101111001"));
			reply = baz.to_string();
			bitset<8> baz2;
			
			client_socket << reply; //"Test message.";
			client_socket >> reply;

			baz2 = (bitset<8>)reply;
			cout << "baz2: " << baz2 << endl;
				

		}catch ( SocketException& ) {}
		cout << "We received this response from the server:\n\"" << reply << "\"\n";;

	}catch ( SocketException& e ){
		cout << "Exception was caught:" << e.description() << "\n";
	}

	return 0;
}
