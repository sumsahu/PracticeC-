#declarations of variables

CXX=g++
APPLICATION=clientapp
DIR_SOCKET=/home/sumsahu/Documents/Programming/git/nokia_git/EmbeddedSoftware/ECLI/
DIR_DEMO_ESW=/home/sumsahu/Documents/Programming/git/nokia_git/EmbeddedSoftware/demo_esw/
LDFLAGS=-L$(DIR_SOCKET)/build
CFLAGS=-Wall \
		-c \
		-g \
		-std=c++0x
LDLIBS= -lpthread 
INCFLAGS += \
	-I$(DIR_SOCKET)/include	-I$(DIR_DEMO_ESW)/include

SRCFILEPATH=$(DIR_SOCKET)src/
SRCFILES=$(wildcard $(SRCFILEPATH)*.cpp )
SRCFILES_DEMO_ESW=$(wildcard $(DIR_DEMO_ESW)src/*.cpp)
SRCFILES_DEMO_ESW:= $(subst $(DIR_DEMO_ESW)src/main.cpp,,$(SRCFILES_DEMO_ESW))

OBJ=$(patsubst %.cpp, %.o, $(SRCFILES))
OBJ_DEMO_ESW=$(patsubst %.cpp, %.o, $(SRCFILES_DEMO_ESW))

all: $(APPLICATION);

$(APPLICATION): $(OBJ) $(OBJ_DEMO_ESW)
	$(CXX) -o $@ -g $(OBJ) $(OBJ_DEMO_ESW) $(LDFLAGS) $(LDLIBS)
$(OBJ): %.o: %.cpp
	$(CXX) $(CFLAGS) $(INCFLAGS) $^ -o $@ 

$(OBJ_DEMO_ESW): %.o: %.cpp
	$(MAKE) -C $(DIR_DEMO_ESW)/build/

clean:
	rm -rf $(APPLICATION)
	rm -rf $(OBJ)
	
clean_all:
	rm -rf $(APPLICATION)
	rm -rf $(OBJ)
	$(MAKE) clean -C $(DIR_DEMO_ESW)/build/


