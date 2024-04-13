.PHONY: clean run help

AR := ar rcvs
CC := gcc
CXX :=
RM := rm -rf
CFLAGS := -fopenmp -O1 -Iinclude
CPPFLAGS :=
LDFLAGS := -Llib
LDLIBS := -lm

PROJECTNAME := OpenMP
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

test :
	@echo ""

help :
	@echo "option"
	@echo "  (default) : Compile"
	@echo "        run : Run (Execute $(PROJECTNAME).out)"
	@echo "      clean : Crean (Remove \"build\")"
	@echo "       help : This"
