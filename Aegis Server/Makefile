test: test server client

server: lock_server.o Aegis.o
	g++ lock_server.o Aegis.o -o lock_server

client: lock_client.o Aegis.o
	g++ lock_client.o Aegis.o -o lock_client

test: test.o Aegis.o
	g++ test.o Aegis.o -o test

test.o: test.cc
	g++ -c test.cc

Aegis.o: Aegis.cc
	g++ -c Aegis.cc

lock_server.o: lock_server.cc
	g++ -c lock_server.cc

lock_client.o: lock_client.cc
	g++ -c lock_client.cc
clean:
	rm *.o test