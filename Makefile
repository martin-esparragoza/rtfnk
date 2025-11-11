## 3 step build process
# 1. Generate the starting build dependencies
# 2. Lookup to generate the list of objects
# 3. Imported makefile does the final binary assembly if needed

# Set this variable yourself (this is the TARGET compilation not the native one)
ARCH := testlinux

LD := ld
LDFLAGS :=
LDLINK :=

LDNATIVE := ld
LDNATIVEFLAGS :=
LDNATIVELINK :=

CCNATIVE := gcc
CNATIVEFLAGS := -O3 -Wall -std=c99
CNATIVELINK :=

CC := gcc
CFLAGS := \
	-Wall \
	-ffreestanding \
	-std=c99 \
	-fno-stack-protector \
	-fno-asynchronous-unwind-tables \
	-fno-unwind-tables
CLINK :=

INCFLAGS := -I ./ -I arch/$(ARCH)/include/ -I comp/$(CC)/include/

MAKEDIRS := arch \
			comp \
			elftofnk \
			common \
			boot/src/entry/$(ARCH) \
			boot \
			dll/fnk
# The directory that holds the target arch objects/deps
OUTDIR := out
# The directory that holds the native objects/deps
NOUTDIR = outnative

.PHONY: all clean $(MAKEDIRS)

ifeq ($(MODULE),)
# Enumerate
all:
	$(MAKE) $(MAKEDIRS) MAKECMDARGS=$@
clean:
	$(MAKE) $(MAKEDIRS) MAKECMDARGS=$@
	@rm -rf $(OUTDIR) $(NOUTDIR)

MAKECMDARGS ?= all # I don't know why recuring makefile calls discard the all qualifier but whatever

$(MAKEDIRS):
	$(MAKE) MODULE=$@ $(MAKECMDARGS)
else
#all: $(MAKEDIRS) # Ok. Genuinely I have no clue why this works. It makes the ENTIRE thing work, I added it a while ago, and now I don't know what the hell it does
# Defines all of our variables like TARGETS and DEPFILES
include $(MODULE)/Makefile

# Now we are in the process of building. Lets turn this build target into its requirements
include rules.mk
-include $(MODULE)/ruleoverride.mk # This is specifically so they can override stuff defined in rules.mk like %.o
.PHONY: all buildprereq clean $(EXTERNALPHONY) # buildprereq because we need the depfiles to be included before we build anything + for the target dir to be made
all: buildprereq $(TARGETS) # Attempt to make them
buildprereq:
-include $(DEPFILES)
clean:
	@echo removing $(TARGETS) $(DEPFILES) $(OUTDIR)/$(MODULE) $(NOUTDIR)/$(MODULE)
	@rm -rf $(OUTDIR)/$(MODULE)
	@rm -rf $(NOUTDIR)/$(MODULE)
endif