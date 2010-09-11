CC=g++
CCFLAGS=-O2 -msse2 -fomit-frame-pointer -pipe -Wno-deprecated $(CPPFLAGS) -I. -I/home/srepmub/shedskin/shedskin/lib -g -fPIC -D__SS_BIND -I/usr/include/python2.6 -I/usr/include/python2.6
#CCFLAGS=-O0 -pipe -Wno-deprecated $(CPPFLAGS)
LFLAGS=-lgc -lpcre $(LDFLAGS) -shared -Xlinker -export-dynamic -lpthread -ldl  -lutil -lm -lpython2.6 -L/usr/lib/python2.6/config

all:	Vector4.so

CPPFILES=/home/srepmub/shedskin/shedskin/lib/builtin.cpp Vector4.cpp /home/srepmub/shedskin/shedskin/lib/re.cpp
HPPFILES=/home/srepmub/shedskin/shedskin/lib/builtin.hpp Vector4.hpp /home/srepmub/shedskin/shedskin/lib/re.hpp

Vector4.so:	$(CPPFILES) $(HPPFILES)
	$(CC)  $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o Vector4.so

Vector4.so_prof:	$(CPPFILES) $(HPPFILES)
	$(CC) -pg -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o Vector4.so_prof

Vector4.so_debug:	$(CPPFILES) $(HPPFILES)
	$(CC) -g -ggdb $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o Vector4.so_debug

clean:
	rm -f Vector4.so Vector4.so_prof Vector4.so_debug

.PHONY: all run clean

