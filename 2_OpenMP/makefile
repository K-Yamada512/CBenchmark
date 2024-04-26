#
# makefile
#

# Variables Used by Implicit Rules
AR := ar rcvs
CC := gcc
CXX :=
RM := rm -rf
CFLAGS := -fopenmp -O1 -Iinclude
CPPFLAGS :=
LDFLAGS :=
LDLIBS := -lm

# Variables Used by My Rules
PROJECTNAME := OpenMP
LIBRARYNAME := openmp
OUTDIR := ./build
BINDIR := ./bin
INCDIR := ./include
SRCDIR := ./src
TESTDIR := ./test
RESULTFILENAME := ./result.plt

OBJDIR := $(OUTDIR)/obj
DEPDIR := $(OUTDIR)/dep
EXECUTEFILENAME := $(BINDIR)/$(PROJECTNAME).out
SRCS := $(wildcard $(SRCDIR)/*.c)
TESTS := $(wildcard $(TESTDIR)/*.c)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS := $(addprefix $(DEPDIR)/, $(notdir $(SRCS:.c=.d))) + $(addprefix $(DEPDIR)/, $(notdir $(TESTS:.c=.d)))

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

.PHONY: all
all : $(EXECUTEFILENAME)

$(EXECUTEFILENAME) : $(OBJS) | $(BINDIR)
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(DEPFLAGS) $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -c -o $@

$(OBJDIR)/%.o : $(TESTDIR)/%.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(DEPFLAGS) $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -c -o $@

include $(wildcard $(DEPS))

$(DEPS) :

$(BINDIR):
	@mkdir -p $@

$(OBJDIR):
	@mkdir -p $@

$(DEPDIR):
	@mkdir -p $@

.PHONY: clean
clean :
	$(RM) $(OBJDIR) $(DEPDIR) $(EXECUTEFILENAME)
	@echo "Remove \"$(OBJDIR) $(DEPDIR) $(EXECUTEFILENAME)\""

.PHONY: execute
execute :
	$(EXECUTEFILENAME) $(RESULTFILENAME)

.PHONY: debug
debug : CFLAGS += -D_DEBUG
debug : clean fclean $(EXECUTEFILENAME)

.PHONY: lib
lib : $(OBJS)
	@echo "\e[33mGenerate static library(lib$(LIBRARYNAME).a) from $(OBJS)\e[m"
	$(AR) lib$(LIBRARYNAME).a $(OBJS)
	@echo ""

.PHONY: inspect
inspect : lib$(LIBRARYNAME).a
	nm lib$(LIBRARYNAME).a
	@echo ""

.PHONY: plot
plot : $(RESULTFILENAME)
	./Plot.sh $<

.PHONY: help
help :
	@echo "option"
	@echo "  (default) : Compile"
	@echo "        all : Compile"
	@echo "    execute : Execute \"$(EXECUTEFILENAME)\""
	@echo "      clean : Crean (Remove \"$(OBJDIR) $(DEPDIR) $(EXECUTEFILENAME)\")"
	@echo "      debug : "
	@echo "        lib : "
	@echo "    inspect : "
	@echo "       plot : "
	@echo "       help : This"
