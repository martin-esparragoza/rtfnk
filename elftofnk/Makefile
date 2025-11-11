SOURCES := $(wildcard elftofnk/src/*.c) $(wildcard elftofnk/lib/*.c)

# Native executable
NEXEC := $(NOUTDIR)/elftofnk/elftofnk.o
NOBJFILES := $(patsubst %.c,$(NOUTDIR)/%.o,$(SOURCES))
TARGETS := $(NOBJFILES) $(NEXEC)
DEPFILES := $(patsubst %.c,$(NOUTDIR)/%.d,$(SOURCES))
CNATIVELINK += -lbfd