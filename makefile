#---------------------------------------------------------------
# HCS12X blinkLED
#---------------------------------------------------------------
TOOLS_PATH=$(CURDIR)/Prog
HC12_LIB=/home/sources/X/lib
APP_NAME=blink_led.abs
PRMFILE=prm/Project.prm
BBLFILE=prm/burner.bbl
BUILDLOG=build.log
#---------------------------------------------------------------
# Tools definition
#---------------------------------------------------------------
CC   = $(TOOLS_PATH)/chc12
LD   = $(TOOLS_PATH)/linker
BURN = $(TOOLS_PATH)/burner
#---------------------------------------------------------------
# Build tool options
#---------------------------------------------------------------
CFLAGS = -I"$(HC12_LIB)/hc12c/include"  -CPUHCS12X -D__NO_FLOAT__
-D__FAR_DATA -Mb -PSegObj
LD_FLAGS  = -M
#---------------------------------------------------------------
CFILES = mc9s12xep100.h main.c datapage.c start12.c derivative.h
#---------------------------------------------------------------
#---------------------------------------------------------------
BINDIR=bin
OFILES = $(patsubst %.c,$(BINDIR)/%.o,$(filter %.c,$(CFILES)))
OFILES += $(patsubst %.cpp,$(BINDIR)/%.o,$(filter %.cpp,$(CFILES)))
VPATH = $(PWD)/src 
#---------------------------------------------------------------
#---------------------------------------------------------------
# Required libraries
#---------------------------------------------------------------
LIBS = "$(HC12_LIB)/hc12c/lib/ansixbi.lib"
#---------------------------------------------------------------
#---------------------------------------------------------------
# Targets
#---------------------------------------------------------------
absfile: .INIT $(OFILES)
       @echo -n "Linking ..."
       @$(LD) $(PRMFILE) $(COMMON_FLAGS) $(LD_FLAGS) -Add{$(LIBS)} 
         -Add{$(OFILES)} -O${APP_NAME} >> $(BUILDLOG)
       @echo "done"
srec: absfile
    @echo -n "Generating srecord ..."
    @$(BURN) -Env"ABS_FILE=$(APP_NAME)" -f $(BBLFILE) >> $(BUILDLOG)
    @echo "done"
$(BINDIR)/%.o : %.c 
    @echo -n "*** Compiling $< ... -->$@ ..." 
    @$(CC) $(CFLAGS) -objn="$@" $< >> $(BUILDLOG)  
    @echo "done"
$(BINDIR)/mc9s12xdp512.o:$(HC12_LIB)/hc12c/src/mc9s12xdp512.c
    @echo -n "*** Compiling $< ... -->$@ ..."
    @$(CC) $(CFLAGS) -objn="$@" $< >> $(BUILDLOG)
    @echo "done"
.INIT :
    @if [ ! -e $(BINDIR) ];then mkdir $(BINDIR);fi
    @if [ -e $(BUILDLOG) ];then rm -f $(BUILDLOG);fi
    @echo $(OFILES)
#---------------------------------------------------------------
# Cleanup
#---------------------------------------------------------------
clean:
       -rm -f $(OFILES)
       -rm -f *.abs
       -rm -f *.map
       -rm -f *.bpt
       -rm -f *.mrk   
       -rm -f *.log 
       -rm -f *.phy
       -rm -f *.s19
       -rm -f *.map
