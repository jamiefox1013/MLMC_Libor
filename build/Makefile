# Makefile for the MLMC_Libor Project

PROGRAM_NAME = mlmc_libor

# Variables containing directory names
CODEDIR = code
INCLUDEDIR = include
SRCDIR = src
OBJDIR = obj
LIBDIR = lib
BINDIR = bin
MAINDIR = mains

# Compiler
CXX = g++

# Compile Flags
CXXFLAGS = -g -Wall -m32

# Preprocessor Flags
CPPFLAGS = $(addprefix -I,../$(CODEDIR)/$(INCLUDEDIR))

# Linker flags
LDFLAGS = -lm -std=c++14 -m32 -pthread

# Gather dependencies
SOURCES = $(notdir $(wildcard ../$(CODEDIR)/$(SRCDIR)/*.cpp))
MAINS = $(notdir $(wildcard $(MAINDIR)/*.cpp))

# Define object files (one per source file)
OBJECTS = $(addprefix $(CODEDIR)/, $(SOURCES)) $(addprefix $(MAINDIR)/, $(MAINS))
OBJECTS := $(OBJECTS:%.cpp=$(OBJDIR)/%.o)

# Define libraries
LIBS = $(addsuffix .a, $(LIBDIR)/$(CODEDIR))

# Add static libraries to linker flags
LDFLAGS := -L$(LIBDIR) $(LDFLAGS)

#
# Targets
#
# Listing "all" target first, as $(MAKE) will default to executing 
# the recipe for the first target it finds
.PHONY: all clean check

all: $(LIBS)
	@echo Linking for $(PROGRAM_NAME)
	@mkdir -p $(BINDIR)
	@$(CXX) $(LDFLAGS) -o $(BINDIR)/$(PROGRAM_NAME) $^
	@echo "Build complete"

$(LIBS): $(OBJECTS)
	@echo Creating library $@
	@mkdir -p $(@D)
	@ar rcs $@ $^
	
$(OBJDIR)/$(CODEDIR)/%.o: ../$(CODEDIR)/$(SRCDIR)/%.cpp
	@echo Compiling $<
	@mkdir -p $(@D)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
	
$(OBJDIR)/$(MAINDIR)/%.o: $(MAINDIR)/%.cpp
	@echo Compiling $<
	@mkdir -p $(@D)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<


clean: 
	rm -rf $(BINDIR) $(OBJDIR) $(LIBDIR)
	

check:
	@echo "OBJECTS:    $(OBJECTS)"
	@echo "LIBS:       $(LIBS)"
	@echo "TARGET:     $(TARGET)"
	@echo "CXX:        $(CXX)"
	@echo "CPPFLAGS:   $(CPPFLAGS)"
	@echo "LDFLAGS:    $(LDFLAGS)"

