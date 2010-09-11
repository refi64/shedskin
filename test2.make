CC=g++
CCFLAGS=-O2 -msse2 -fomit-frame-pointer -pipe -Wno-deprecated $(CPPFLAGS) -I. -I/home/srepmub/shedskin/shedskin/lib -g -fPIC -D__SS_BIND -I/usr/include/python2.6 -I/usr/include/python2.6
#CCFLAGS=-O0 -pipe -Wno-deprecated $(CPPFLAGS)
LFLAGS=-lgc -lpcre $(LDFLAGS) -shared -Xlinker -export-dynamic -lpthread -ldl  -lutil -lm -lpython2.6 -L/usr/lib/python2.6/config -L. -lVector4

all:	test2.so

CPPFILES=/home/srepmub/shedskin/shedskin/lib/builtin.cpp test2.cpp /home/srepmub/shedskin/shedskin/lib/re.cpp
HPPFILES=/home/srepmub/shedskin/shedskin/lib/builtin.hpp test2.hpp Vector4.hpp /home/srepmub/shedskin/shedskin/lib/re.hpp

test2.so:	$(CPPFILES) $(HPPFILES)
	$(CC)  $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o test2.so

test2.so_prof:	$(CPPFILES) $(HPPFILES)
	$(CC) -pg -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o test2.so_prof

test2.so_debug:	$(CPPFILES) $(HPPFILES)
	$(CC) -g -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o test2.so_debug

clean:
	rm -f test2.so test2.so_prof test2.so_debug

.PHONY: all run clean

