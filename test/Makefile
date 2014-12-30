OBJS = run_tests.o process_test.o
EXE = run_tests
CFLAGS += -g --std=c++11 -I..
LFLAGS = -lcppunit
FDES_STREAM_LOC=../../socket_server_2
CFLAGS += -I${FDES_STREAM_LOC}

.cpp.o:
	g++ -c ${CFLAGS} $<

all: ${OBJS}
	g++ -o ${EXE} ${OBJS} ${LFLAGS}

clean:
	rm -f *~ ${EXE} ${OBJS} core
