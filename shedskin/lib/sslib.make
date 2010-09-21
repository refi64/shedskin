CC=g++
CCFLAGS=-O2 -msse2 -fomit-frame-pointer -pipe -Wno-deprecated $(CPPFLAGS) -I. -I/home/srepmub/shedskin/shedskin/lib -g -fPIC -D__SS_BIND -I/usr/include/python2.6 -I/usr/include/python2.6
LFLAGS=-lgc -lpcre $(LDFLAGS) -shared -Xlinker -export-dynamic -lpthread -ldl  -lutil -lm -lpython2.6 -L/usr/lib/python2.6/config

all:	sslib.so

CPPFILES=sslib.cpp
HPPFILES=sslib.hpp

sslib.so:	$(CPPFILES) $(HPPFILES)
	$(CC)  $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o sslib.so

clean:
	rm -f sslib.so

.PHONY: all run clean

