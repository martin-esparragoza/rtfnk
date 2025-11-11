SOURCES := $(wildcard common/lib/*.c)

LIB := $(OUTDIR)/common/libcommon.o
NLIB := $(NOUTDIR)/common/libcommon.o
OBJFILES := $(patsubst %.c,$(OUTDIR)/%.o,$(SOURCES))
NOBJFILES := $(patsubst %.c,$(NOUTDIR)/%.o,$(SOURCES))
TARGETS := $(OBJFILES) $(NOBJFILES) $(LIB) $(NLIB)
DEPFILES := $(patsubst %.o,%.d,$(OBJFILES)) $(patsubst %.o,%.d,$(NOBJFILES))