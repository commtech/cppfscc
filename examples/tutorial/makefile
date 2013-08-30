TARGET = tutorial

SOURCES = tutorial.c
CPP_DIR = ..\..
LIBS = $(CPP_DIR)\cppfscc.lib

all: $(TARGET).exe

$(TARGET).exe:$(SOURCES) $(HEADERS) $(LIBS)
  cl /D_WIN32_WINNT=0x0502 /W4 /MT $(SOURCES) $(LIBS) /I $(CPP_DIR) /I $(CPP_DIR)/src/ /Fe$@
  
clean:
  del *.exe