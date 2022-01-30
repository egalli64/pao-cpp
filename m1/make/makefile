MY_NAME := hello
MY_SRCS := $(wildcard *.cpp)
MY_OBJS := ${MY_SRCS:.cpp=.o}
MY_INCLUDE_DIRS :=
MY_LIBRARY_DIRS :=
MY_LIBRARIES :=

CXXFLAGS += $(foreach includedir,$(MY_INCLUDE_DIRS),-I$(includedir))
CXXFLAGS += -Wall -g
LDFLAGS += $(foreach librarydir,$(MY_LIBRARY_DIRS),-L$(librarydir))
LDLIBS += $(foreach library,$(MY_LIBRARIES),-l$(library))

.PHONY: all clean

all: ${MY_NAME}

$(MY_NAME): $(MY_OBJS)
	$(LINK.cc) $(MY_OBJS) -o $(MY_NAME) $(LDLIBS)

clean:
	@- rm -rf $(MY_OBJS) $(MY_NAME)
