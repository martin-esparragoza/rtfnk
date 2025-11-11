# TODO: Refactor this file for use in not devenv

BINARY := $(OUTDIR)/boot/boot_$(ARCH)

SOURCES := boot/src/main.c $(wildcard boot/lib/*.c)
OBJFILES := $(patsubst %.c,$(OUTDIR)/%.o,$(SOURCES))
DEPFILES := $(patsubst %.c,$(OUTDIR)/%.d,$(SOURCES))
TARGETS := $(OBJFILES) $(BINARY)

MODULEDEPS := $(OUTDIR)/boot/src/entry/$(ARCH)/entry.o $(OUTDIR)/arch/lib$(ARCH).o $(OUTDIR)/comp/lib$(CC).o $(OUTDIR)/common/libcommon.o

$(BINARY): boot/linker_$(ARCH).ld $(OBJFILES) $(MODULEDEPS)
	gcc -o $@ -Wl,--start-group $(OBJFILES) $(MODULEDEPS) -Wl,--end-group
#	$(LD) $(LDFLAGS) -o $@ -T $< -Wl,--start-group $(OBJFILES) $(LIBFILES) $(UPPEROBJS) -Wl,--end-group
# Funky stuff so it can run silly goose