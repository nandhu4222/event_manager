IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)
ODIR=../bin

_DEPS = module.h evt_mgr.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = init.o module.o event_mgr.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

eventmake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
