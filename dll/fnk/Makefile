SOURCES := $(wildcard dll/fnk/lib/*.c)
OBJFILES := $(patsubst %.c,$(OUTDIR)/%.o,$(SOURCES))
CFLAGS += \
	-fno-pic \
	-fno-pie \
	-fno-asynchronous-unwind-tables
LDFLAGS += # I don't think this needs no-pie
#-no-pie
LIB := $(OUTDIR)/common/libcommon.o
TARGETS := $(OBJFILES) $(OUTDIR)/dll/fnk/fnk-intermediate.o $(OUTDIR)/dll/fnk.fnk
DEPFILES := $(patsubst %.c,$(OUTDIR)/%.d,$(SOURCES))