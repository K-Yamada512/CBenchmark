.PHONY: clean run switch help

AR := ar rcvs
CC := gcc
CXX :=
RM := rm -rf
CFLAGS := -O1 -Iinclude
CPPFLAGS :=
LDFLAGS :=
LDLIBS := -lblas

PROJECTNAME := BLAS
BUILDPATH := build/
MAINFILENAME := src/source.c

LIBRARYNAME :=
SRCFILEPATH := src/
SRCS :=

SRCFILENAME := $(SRCS:%=$(SRCFILEPATH)%)
OBJFILEPATH := $(BUILDPATH)tmp/
OBJS := $(SRCS:%.c=%.o)
OBJFILENAME := $(OBJS:%=$(OBJFILEPATH)%)

$(BUILDPATH)$(PROJECTNAME).out : $(MAINFILENAME) $(OBJFILENAME)
	@mkdir -p $(BUILDPATH)
	$(CC) $(MAINFILENAME) $(OBJFILENAME) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $@

run :
	./$(BUILDPATH)$(PROJECTNAME).out

clean :
	$(RM) $(BUILDPATH)
	@echo "Remove \"$(BUILDPATH)\""

switch :
	@echo "Switch to Library (BLAS,LAPACK)"
	@sudo update-alternatives --config libblas.so-x86_64-linux-gnu
	@sudo update-alternatives --config libblas.so.3-x86_64-linux-gnu
	@sudo update-alternatives --config liblapack.so-x86_64-linux-gnu
	@sudo update-alternatives --config liblapack.so.3-x86_64-linux-gnu

help :
	@echo "option"
	@echo "  (default) : Compile"
	@echo "        run : Run (Execute $(PROJECTNAME).out)"
	@echo "      clean : Crean (Remove \"build\")"
	@echo "     switch : Switch to Library"
	@echo "       help : This"
