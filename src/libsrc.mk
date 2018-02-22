SRC=$(wildcard $(ROOT)/$(DIR_SRC)/*.cpp)
OBJ=$(SRC:$(ROOT)/$(DIR_SRC)/%.cpp=$(ROOT)/$(DIR_OBJ)/%.o)

# Compilation of the program
$(LIBR): $(OBJ) #$(DYNAMIC_LIBS:%=$(ROOT)/$(DIR_SRC)/$(DIR_IN)/%.so)
	@echo "Linking ..... : $@"
	@$(GXX) $(CFLAGS_DYNAMIC_LIBS) -o $@ $^ $(CFLAGS) 

# Compilation from sources (.cpp) to objects (.o)
$(OBJ): $(SRC) #$(ROOT)/$(DIR_SRC)/%.cpp
	@echo "Compiling ... : $@"
	@$(GXX) $(CFLAGS_DYNAMIC_LIBS_OBJ) -c -o $@ $< $(CFLAGS_OBJ)

