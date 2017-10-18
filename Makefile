all: llDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

llDemo: llist.o llDemo.o
	cc -o $@ $^

llist.o: llist.c llist.h
	cc -c $(CFLAGS) llist.c

llDemo.o: llDemo.c llist.h
	cc -c $(CFLAGS) llDemo.c

clean:
	rm -f *.o llDemo

demo: llDemo
	(echo first; echo "second line"; echo "third and last") | ./llDemo


ilistme: listme.o tree.o
	cc -o $@ $^

tree.o: tree.c tree.h
	cc -c $(CFLAGS) tree.c

listme.o: listme.c  tree.h
	cc -c $(CFLAGS) listme.c

cleanTree:
	rm -f *.o ilistme

myTree: ilistme
	./ilistme
