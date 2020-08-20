target:ser cli

ser:myserver.c server.c
	gcc myserver.c server.c -o ser

cli:myclient.c client.c
	gcc myclient.c client.c -o cli

.PHONY:clean

clean:
	rm cli ser