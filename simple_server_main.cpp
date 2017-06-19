#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include<iostream>

using namespace std;

int main ( int argc, int argv[] ){
	cout << "running....\n";

	try{
		// Create the socket
		// on port 30000
		ServerSocket server ( 30000 );

		while ( true ){

			ServerSocket new_sock;
			server.accept ( new_sock );

			try{
				while ( true ){
					string data;
					new_sock >> data;
					if(data == "mano"){
						data = data + " cassota ";
					}
					new_sock << (data + " bla bla");
				}
			}catch ( SocketException& ) {}

		}
	}catch ( SocketException& e ){
		cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}

	return 0;
}
