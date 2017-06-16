#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

using namespace std;

int main ( int argc, int argv[] ){
	try{

		ClientSocket client_socket ( "192.168.130.89", 30000 );

		string reply;

		try{
			cout << "entrada:" << endl;
			getline (cin, reply);
			//cin >> reply;
			client_socket << reply; //"Test message.";
			client_socket >> reply;
		}catch ( SocketException& ) {}
		cout << "We received this response from the server:\n\"" << reply << "\"\n";;

	}catch ( SocketException& e ){
		cout << "Exception was caught:" << e.description() << "\n";
	}

	return 0;
}
