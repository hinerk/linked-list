test-linked-list: linked-list.c main.c
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@


clean:
	rm -f test-linked-list test-linked-list.exe
