
#Declarations of variables
APPLICATION=socketapp
DIR_SOCKET=/home/sumsahu/Documents/Programming/git/repository/PracticeCpp/EmbeddedSoftware/demo_esw/
LDFLAGS=-L$(DIR_SOCKET)/build
CXX=g++
CFLAGS=-Wall \
		-c \
		-g \
		-D_GNU_SOURCE
LDLIBS = -lpthread
INCFLAGS = -I$(DIR_SOCKET)/include/
SRCFILESPATH=$(DIR_SOCKET)/src/

SRCFILES=$(wildcard $(SRCFILESPATH)*.cpp)

OBJ=$(patsubst %.cpp, %.o, $(SRCFILES))

all: $(APPLICATION);

$(APPLICATION): $(OBJ)
	$(CXX) -o $@ -g $(OBJ) $(LDFLAGS) $(LDLIBS)
$(OBJ): %.o: %.cpp
	$(CXX) $(CFLAGS) $(INCFLAGS) $^ -o $@ 
clean:
	rm -rf $(APPLICATION)
	rm -rf $(OBJ)
