cipherdecrypt:	cipherdecrypt.o 
	gcc -Wall cipherdecrypt.o -o cipherdecrypt
cipherdecrypt.o: cipherdecrypt.c 

test: test1 test2
test1:
	./cipher 1 13 page.txt pagecrypt.txt
	./cipherdecrypt pagecrypt.txt
	diff -s page.txt decryptfile.txt
test2: 
	./cipher 1 3 paragraph.txt paragraphcrypt.txt
	./cipherdecrypt paragraphcrypt.txt
	diff -s paragraph.txt decryptfile.txt
