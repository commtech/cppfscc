TARGET = cppfscc

CFC_DIR = libs\cfscc
SOURCES = src/fscc.cpp src/sys_exception.cpp
HEADERS = src/fscc.hpp src/sys_exception.hpp $(CFC_DIR)/src/fscc.h
LIBS = $(CFC_DIR)\cfscc.lib
LIBSD = $(CFC_DIR)\cfsccd.lib

all: $(TARGET).dll
debug: $(TARGET)d.dll

$(TARGET).dll:$(SOURCES) $(HEADERS) $(LIBS)
  rc $(TARGET).rc
  cl /W4 /WX $(SOURCES) /I$(CFC_DIR)\src\ $(LIBS) /EHsc /Fe$@ /LD $(TARGET).res

$(TARGET)d.dll:$(SOURCES) $(HEADERS) $(LIBSD)
  rc /d _DEBUG /fo $(TARGET)d.res $(TARGET).rc
  cl /W4 /WX $(SOURCES) /I$(CFC_DIR)\src\ $(LIBSD) /EHsc /Fe$@ /LDd /Zi $(TARGET)d.res

$(LIBS):
  pushd $(CFC_DIR) & nmake & popd

$(LIBSD):
  pushd $(CFC_DIR) & nmake DEBUG & popd

clean:
  del *.dll *.obj *.lib *.pdb