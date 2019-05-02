#### Common variables for Makefiles

## Directories
ROOT=$(shell pwd)
DIR_ALG=algebra
DIR_ASM=asm
DIR_BIN=bin
DIR_SRC=src
DIR_OBJ=obj
DIR_LIB=lib
DIR_HDR=includes
DIR_DOC=doc
DIR_IN=libgame

## Compilation
GXX=g++
GPL=/usr/share/gprolog/bin/gplc 

# Flags for linking
CFLAGS= /usr/share/gprolog/lib/*.a -I $(ROOT)/$(DIR_HDR) -lsfml-graphics -lsfml-window -lsfml-system -lopencv_imgproc  -lopencv_highgui  -lopencv_core -lopencv_imgcodecs 
# Flags for objects
CFLAGS_OBJ=-I $(ROOT)/$(DIR_HDR) -I/usr/include/opencv4/ -I/usr/share/gprolog/include/ -O0 -Wall -Wextra -std=c++14 
# Flags for libraries objects
CFLAGS_DYNAMIC_LIBS_OBJ=-fPIC 
# Flags for libraries linkins
CFLAGS_DYNAMIC_LIBS=-shared

