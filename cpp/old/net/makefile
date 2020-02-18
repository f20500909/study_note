all:sever client
.PHONY:all


sever:sever.o
	gcc sever.cpp -o sever

client:client.o
	gcc client.cpp -o client

clean: sever client
	rm -f *.o
