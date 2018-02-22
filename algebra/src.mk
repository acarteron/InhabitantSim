SRCALG=$(wildcard $(ROOT)/$(DIR_ALG)/*.pl)
ALGE=$(SRCALG:$(ROOT)/$(DIR_ALG)/%.pl=$(ROOT)/$(DIR_ASM)/%.s)

# Compilation from sources (.pl) to asm (.s)
$(ROOT)/$(DIR_ASM)/%.s: $(ROOT)/$(DIR_ALG)/%.pl
	@echo "Compiling ... : $@"
	@$(GPL) -S -o $@ $<
