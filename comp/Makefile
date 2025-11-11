SOURCES := $(wildcard comp/$(CC)/lib/*.c)

LIB := $(OUTDIR)/comp/lib$(CC).o
OBJFILES := $(patsubst %.c,$(OUTDIR)/%.o,$(SOURCES))
TARGETS := $(OBJFILES) $(LIB)
DEPFILES := $(patsubst %.c,$(OUTDIR)/%.d,$(SOURCES))