SOURCES := $(wildcard arch/$(ARCH)/lib/*.c)

LIB := $(OUTDIR)/arch/lib$(ARCH).o
OBJFILES := $(patsubst %.c,$(OUTDIR)/%.o,$(SOURCES))
TARGETS := $(OBJFILES) $(LIB)
DEPFILES := $(patsubst %.c,$(OUTDIR)/%.d,$(SOURCES))