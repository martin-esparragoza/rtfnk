# Arch rules
$(OUTDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP $(INCFLAGS) -c $< -o $@ $(CLINK)

$(LIB): $(OBJFILES)
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -r -o $@ $^ $(LDLINK)

# Library combiner
$(OUTDIR)/%-intermediate.o: $(OBJFILES) $(LIBFILES)
	@mkdir -p $(dir $@)
	$(LD) -r $(LDFLAGS) -o $@ $(OBJFILES) $(LIBFILES) $(LDLINK)

$(MODULEDEPS):
	$(MAKE) MODULE=$(patsubst $(NOUTDIR)%,%,$(patsubst $(OUTDIR)/%,%,$(dir $@))) $@

# Native rules
$(NOUTDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CCNATIVE) $(CNATIVEFLAGS) -MMD -MP $(INCFLAGS) -c $< -o $@ $(CNATIVELINK)

$(NEXEC): $(NOBJFILES)
	@mkdir -p $(dir $@)
	$(CCNATIVE) $(CNATIVEFLAGS) -MMD -MP $(INCFLAGS) $< -o $@ $(filter-out $<,$^) $(CNATIVELINK)

$(NLIB): $(NOBJFILES)
	@mkdir -p $(dir $@)
	$(LDNATIVE) $(LDNATIVEFLAGS) -r -o $@ $^ $(LDNATIVEFLAGS)