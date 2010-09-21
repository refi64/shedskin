CC=g++
CCFLAGS=-O2 -msse2 -fomit-frame-pointer -pipe -Wno-deprecated $(CPPFLAGS) -I. -I/home/srepmub/shedskin/shedskin/lib -g -fPIC -D__SS_BIND -I/usr/include/python2.6 -I/usr/include/python2.6
LFLAGS=-lgc -lpcre $(LDFLAGS) -shared -Xlinker -export-dynamic -lpthread -ldl  -lutil -lm -lpython2.6 -L/usr/lib/python2.6/config

all:	builtin.so

CPPFILES=collections.cpp itertools.cpp glob.cpp socket.cpp stat.cpp getopt.cpp csv.cpp random.cpp sys.cpp signal.cpp bisect.cpp time.cpp fnmatch.cpp ConfigParser.cpp re.cpp cStringIO.cpp heapq.cpp datetime.cpp copy.cpp builtin.cpp math.cpp string.cpp os/__init__.cpp os/path.cpp

HPPFILES=collections.hpp itertools.hpp glob.hpp socket.hpp stat.hpp getopt.hpp csv.hpp random.hpp sys.hpp signal.hpp bisect.hpp time.hpp fnmatch.hpp ConfigParser.hpp re.hpp cStringIO.hpp heapq.hpp datetime.hpp copy.hpp builtin.hpp math.hpp string.hpp os/__init__.hpp os/path.hpp

builtin.so:	$(CPPFILES) $(HPPFILES)
	$(CC)  $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o builtin.so

clean:
	rm -f builtin.so

.PHONY: all run clean

