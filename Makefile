include ./standard_def.mk

EXEC=$(ROOT)/$(DIR_BIN)/game

LIBR=$(ROOT)/$(DIR_LIB)/game.so


all: createdirectories $(EXEC)

createdirectories:
	@mkdir -p $(DIR_OBJ) $(DIR_BIN) $(DIR_LIB) $(DIR_ASM)

-include $(ROOT)/$(DIR_ALG)/src.mk
-include $(ROOT)/$(DIR_SRC)/src.mk

#lib:	createdirectories $(LIBR)

#-include $(ROOT)/$(DIR_SRC)/libsrc.mk

.PHONY: clean doc lib

doc:
	@echo -n "Generation de la DOC ... "
	@mkdir -p $(DIR_DOC)
	@doxygen 
	@echo "OK."

clean:
	@echo "Cleaning Project"
	@rm -rf $(DIR_OBJ) $(DIR_BIN) $(DIR_DOC) $(DIR_ASM)

raz: 
	@echo "Cleaning Project++"
	@rm -rf $(DIR_OBJ) $(DIR_LIB) $(DIR_BIN) $(DIR_DOC) $(DIR_PLO) $(DIR_OUT)
