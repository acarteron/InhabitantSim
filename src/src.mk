SRC=$(wildcard $(ROOT)/$(DIR_SRC)/*.cpp)
OBJ=$(SRC:$(ROOT)/$(DIR_SRC)/%.cpp=$(ROOT)/$(DIR_OBJ)/%.o)

# Compilation of the program
$(EXEC): $(ALGE) $(OBJ) $(DYNAMIC_LIBS:%=$(ROOT)/$(DIR_SRC)/$(DIR_IN)/%.so)
	@echo "Linking ..... : $@"
	@$(GXX) -ldl -o $@ $^ $(CFLAGS)

# Compilation from sources (.cpp) to objects (.o)
$(ROOT)/$(DIR_OBJ)/%.o: $(ROOT)/$(DIR_SRC)/%.cpp
	@echo "Compiling ... : $@"
	@$(GXX) -ldl -c -o $@ $< $(CFLAGS_OBJ)
