# Copyright 1994-2013 The MathWorks, Inc.
#
# File    : accel_vcx64.tmf   
#
# Abstract:
#       Accelerator template makefile for building a Windows-based,
#       generated mex-file of Simulink model using generated C code
#       and the
#          Microsoft Visual C/C++ compiler version 8.0 for x64
#
#       Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#         OPT_OPTS       - Optimization option. Specify OPT_OPTS=-g to
#                          create a mex file for debugging.
#         MEX_OPTS       - User specific mex options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see accel.tlc

#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = nmake
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = accel.tlc
COMPILER_TOOL_CHAIN = vcx64

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to where MATLAB is installed.
#  MATLAB_BIN      - Path to MATLAB executable.
#  S_FUNCTIONS     - List of S-functions.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  SOLVER          - Solver source file name
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  BUILDARGS       - Options passed in at the command line.
#  MEXEXT          - extension that a mex file has. See the MATLAB mexext 
#                    command

MODEL              = Leg_mech
MODULES            = Leg_mech_acc_data.c rtGetInf.c rtGetNaN.c rt_nonfinite.c 
MAKEFILE           = Leg_mech.mk
MATLAB_ROOT        = D:\Program Files\MATLAB\R2015a
ALT_MATLAB_ROOT    = D:\PROGRA~1\MATLAB\R2015a
MATLAB_BIN         = D:\Program Files\MATLAB\R2015a\bin
ALT_MATLAB_BIN     = D:\PROGRA~1\MATLAB\R2015a\bin
MASTER_ANCHOR_DIR  = 
START_DIR          = D:\HEXAPOD\HEXAPO~3\HARDWA~1
S_FUNCTIONS        = 
S_FUNCTIONS_LIB    = 
SOLVER             = 
NUMST              = 2
TID01EQ            = 1
NCSTATES           = 18
MEM_ALLOC          = RT_STATIC
BUILDARGS          =  ISPROTECTINGMODEL=NOTPROTECTING
MEXEXT             = mexw64

MODELREFS          = 
SHARED_SRC         = 
SHARED_SRC_DIR     = 
SHARED_BIN_DIR     = 
SHARED_LIB         = 
MEX_OPT_FILE       = -f "C:\Users\User\AppData\Roaming\MathWorks\MATLAB\R2015a\mex_C_win64.xml"
COMPUTER           = PCWIN64
VISUAL_VER         = 7.1SDK
OPTIMIZATION_FLAGS = /Od /Oy- /DNDEBUG
ADDITIONAL_LDFLAGS = 

#--------------------------- Model and reference models -----------------------
MODELLIB                  = Leg_mechlib.lib
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..\..\..
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif

#--------------------------- Tool Specifications ------------------------------

CPU = AMD64
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

MEX    = $(MATLAB_BIN)\mex
CC     = $(MATLAB_BIN)\mex -c
LIBCMD = lib
PERL   = $(MATLAB_ROOT)\sys\perl\win32\bin\perl

#----------------------------- Include/Lib Path -------------------------------
MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src

# Additional includes

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)\slprj\accel\Leg_mech
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\sm\core\c
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\pm_math\c
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\network_engine\c
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c


INCLUDE = .;$(RELATIVE_PATH_TO_ANCHOR);$(MATLAB_INCLUDES);$(ADD_INCLUDES);$(INCLUDE)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDE = $(INCLUDE);$(SHARED_SRC_DIR)
!endif

#----------------------- C and MEX optimization options -----------------------

DEFAULT_OPT_OPTS = -O

MEX_OPTS = 
OPT_OPTS = $(DEFAULT_OPT_OPTS)

!if "$(OPTIMIZATION_FLAGS)" != ""
MEX_OPT_OPTS = OPTIMFLAGS="$(OPTIMIZATION_FLAGS)"    # passed to 'mex -c'
!else
MEX_OPT_OPTS = $(OPT_OPTS)    # passed to 'mex -c'
!endif

!if "$(MEX_OPTS)" == "-g"
MEX_OPT_OPTS =
!endif

!if "$(ADDITIONAL_LDFLAGS)" != ""
MEX_LDFLAGS = LINKFLAGS="$$LINKFLAGS $(ADDITIONAL_LDFLAGS)"
!else
MEX_LDFLAGS =
!endif

#------------------------------- Mex Options  ---------------------------------

MEX_FLAGS = $(MODELREF_INC_PATH) $(MEX_ARCH) $(MEX_OPTS) $(MEX_OPT_OPTS) $(MEX_LDFLAGS) $(MEX_OPT_FILE)

#----------------------------- Source Files -----------------------------------
USER_SRCS =

SRCS = $(MODULES) $(USER_SRCS)

OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(MODEL)_acc.obj $(OBJS_C_UPPER:.c=.obj)

SHARED_OBJS = $(SHARED_SRC:.c=.obj)

#-------------------------- Additional Libraries ------------------------------

LIBS =

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\sm\ssci\lib\win64\sm_ssci_rtwsfcn_vcx64.lib
!else
LIBS = $(LIBS) sm_ssci.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\sm\core\lib\win64\sm_rtwsfcn_vcx64.lib
!else
LIBS = $(LIBS) sm.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\pm_math\lib\win64\pm_math_rtwsfcn_vcx64.lib
!else
LIBS = $(LIBS) pm_math.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\lib\win64\ssc_sli_rtwsfcn_vcx64.lib
!else
LIBS = $(LIBS) ssc_sli.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\lib\win64\ssc_core_rtwsfcn_vcx64.lib
!else
LIBS = $(LIBS) ssc_core.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\network_engine\lib\win64\ne_rtwsfcn_vcx64.lib
!else
LIBS = $(LIBS) ne.lib
!endif

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = $(LIBS) $(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\lib\win64\pm_rtwsfcn_vcx64.lib
!else
LIBS = $(LIBS) pm.lib
!endif



LIBUT          = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libut.lib
LIBMWMATHUTIL  = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwmathutil.lib
LIBMWIPP = $(MATLAB_ROOT)\lib\win64\libmwipp.lib
LIBMWSL_FILEIO = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsl_fileio.lib
LIBMWSIGSTREAM = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsigstream.lib
LIBMWSL_ASYNCIO = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsl_AsyncioQueue.lib
LIBMWSIMULINK = $(MATLAB_ROOT)\extern\lib\win64\microsoft\libmwsimulink.lib
LIBS     = $(LIBS) $(LIBUT) $(LIBMWMATHUTIL) $(LIBMWSL_FILEIO) $(LIBMWIPP) $(LIBMWSIGSTREAM) $(LIBMWSL_ASYNCIO) $(LIBMWSIMULINK)

CMD_FILE = $(MODEL).lnk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl

#--------------------------------- Rules ---------------------------------------
all: set_environment_variables ..\$(MODEL)_acc.$(MEXEXT)

..\$(MODEL)_acc.$(MEXEXT) : $(OBJS) $(SHARED_LIB) $(LIBS)
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(MEX) $(MEX_FLAGS) @$(CMD_FILE) $(S_FUNCTIONS_LIB) $(SHARED_LIB) $(LIBS) -outdir $(RELATIVE_PATH_TO_ANCHOR)
	@cmd /C "echo ### Created mex file: $(MODEL)_acc.$(MEXEXT)"

# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

# Additional sources

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\sm\core\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\pm_math\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\network_engine\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<

{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $<



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

{$(MATLAB_ROOT)\simulink\src}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

{$(MATLAB_ROOT)\toolbox\physmod\sm\ssci\c}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

{$(MATLAB_ROOT)\toolbox\physmod\sm\core\c}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

{$(MATLAB_ROOT)\toolbox\physmod\pm_math\c}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\sli\c}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

{$(MATLAB_ROOT)\toolbox\physmod\simscape\engine\core\c}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

{$(MATLAB_ROOT)\toolbox\physmod\simscape\compiler\core\c}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

{$(MATLAB_ROOT)\toolbox\physmod\network_engine\c}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

{$(MATLAB_ROOT)\toolbox\physmod\common\foundation\core\c}.cpp.obj : 
	@cmd /C "echo ### Compiling $< "
	$(CC) $(MEX_FLAGS) $< 

 

# Put these rules last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $(USER_INCLUDES) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(MEX_FLAGS) $(USER_INCLUDES) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	@if exist $*.pdb del $*.pdb
	@if exist ..\$(MODEL)_acc.pdb del ..\$(MODEL)_acc.pdb
	$(CC) $(MEX_FLAGS) $(USER_INCLUDES) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	@if exist $*.pdb del $*.pdb
	@if exist ..\$(MODEL)_acc.pdb del ..\$(MODEL)_acc.pdb
	$(CC) $(MEX_FLAGS) $(USER_INCLUDES) $<

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@cmd /C "echo ### Creating $@"
	@$(CC) $(MEX_FLAGS) -outdir $(SHARED_BIN_DIR)\ @<<
$?
<<
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@cmd /C "echo ### Created $@"
!endif

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)
	@set MATLAB=$(MATLAB_ROOT)

# Libraries:



MODULES_sm_ssci = \
          sm_ssci_3dd14f0a.obj \
          sm_ssci_646478c5.obj \
          sm_ssci_916e6db1.obj \
          sm_ssci_b2b6b422.obj \
          sm_ssci_c16a187b.obj \
          

sm_ssci.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_sm_ssci)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_sm_ssci)
	@cmd /C "echo ### Created $@"

MODULES_sm = \
          sm_440126a7.obj \
          sm_62d41fb5.obj \
          sm_6fbd150d.obj \
          sm_73d210b9.obj \
          sm_b402b573.obj \
          sm_bc63e36c.obj \
          sm_c0ba649d.obj \
          sm_d3d946fd.obj \
          sm_e8bab6d7.obj \
          sm_efdfa66e.obj \
          sm_f7683dd1.obj \
          

sm.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_sm)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_sm)
	@cmd /C "echo ### Created $@"

MODULES_pm_math = \
          pm_math_1966ea7d.obj \
          pm_math_1ad202b7.obj \
          pm_math_1c69d5b2.obj \
          pm_math_2cdd2951.obj \
          pm_math_3463da5d.obj \
          pm_math_360e4b46.obj \
          pm_math_48bd51fb.obj \
          pm_math_646fa971.obj \
          pm_math_a001e9ec.obj \
          pm_math_b7b980b1.obj \
          pm_math_bad43c87.obj \
          pm_math_d1be0f30.obj \
          pm_math_da630bd2.obj \
          pm_math_f760e8f6.obj \
          

pm_math.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_pm_math)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_pm_math)
	@cmd /C "echo ### Created $@"

MODULES_ssc_sli = \
          ssc_sli_0763c151.obj \
          ssc_sli_0bd269e6.obj \
          ssc_sli_360cfd63.obj \
          ssc_sli_43618287.obj \
          ssc_sli_466b08dd.obj \
          ssc_sli_4e028390.obj \
          ssc_sli_51dbd3b5.obj \
          ssc_sli_550a4805.obj \
          ssc_sli_5a0cb974.obj \
          ssc_sli_62d81790.obj \
          ssc_sli_77063d8b.obj \
          ssc_sli_7a618260.obj \
          ssc_sli_7f630b0f.obj \
          ssc_sli_89d0f30a.obj \
          ssc_sli_8a64c4e2.obj \
          ssc_sli_9c030181.obj \
          ssc_sli_c7dda239.obj \
          ssc_sli_dcd66f69.obj \
          ssc_sli_eb0a5702.obj \
          ssc_sli_fa0ce53e.obj \
          ssc_sli_fbdf29da.obj \
          

ssc_sli.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ssc_sli)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ssc_sli)
	@cmd /C "echo ### Created $@"

MODULES_ssc_core = \
          ssc_core_01d712d7.obj \
          ssc_core_01db7fea.obj \
          ssc_core_01dcc633.obj \
          ssc_core_026ff268.obj \
          ssc_core_04da2c69.obj \
          ssc_core_05058dd9.obj \
          ssc_core_06ba677c.obj \
          ssc_core_06ba68a6.obj \
          ssc_core_0764a3ad.obj \
          ssc_core_0768a42c.obj \
          ssc_core_076b7741.obj \
          ssc_core_0864e4ae.obj \
          ssc_core_09b5fa6e.obj \
          ssc_core_0bd666aa.obj \
          ssc_core_0f019bd9.obj \
          ssc_core_0f0420a6.obj \
          ssc_core_1108d1b5.obj \
          ssc_core_166caddf.obj \
          ssc_core_1b0315f1.obj \
          ssc_core_1b0cafd5.obj \
          ssc_core_1c64d74c.obj \
          ssc_core_1c656373.obj \
          ssc_core_1c6b0332.obj \
          ssc_core_1fd25120.obj \
          ssc_core_24b4cdee.obj \
          ssc_core_2568b075.obj \
          ssc_core_280c0222.obj \
          ssc_core_29d2a20c.obj \
          ssc_core_2a669a14.obj \
          ssc_core_2cd54448.obj \
          ssc_core_2d095f25.obj \
          ssc_core_30bf43ef.obj \
          ssc_core_3169e4b7.obj \
          ssc_core_330dceec.obj \
          ssc_core_37d4ea84.obj \
          ssc_core_38d9af99.obj \
          ssc_core_38df7cb7.obj \
          ssc_core_390bbe0e.obj \
          ssc_core_3dd7f5fc.obj \
          ssc_core_40d704a7.obj \
          ssc_core_40db6c85.obj \
          ssc_core_41017299.obj \
          ssc_core_440f9cd3.obj \
          ssc_core_4666b45b.obj \
          ssc_core_466b06df.obj \
          ssc_core_48b08af1.obj \
          ssc_core_48b1386a.obj \
          ssc_core_4965213d.obj \
          ssc_core_4ad7a19e.obj \
          ssc_core_4ad9135b.obj \
          ssc_core_4db6bd68.obj \
          ssc_core_4db86fcc.obj \
          ssc_core_4e04eecd.obj \
          ssc_core_500718de.obj \
          ssc_core_51d5b9a3.obj \
          ssc_core_53b3fda6.obj \
          ssc_core_54d55ae9.obj \
          ssc_core_54d63c45.obj \
          ssc_core_550a9a70.obj \
          ssc_core_550d4b87.obj \
          ssc_core_56b1a2bf.obj \
          ssc_core_59b034b8.obj \
          ssc_core_5a07074f.obj \
          ssc_core_5a0fdaac.obj \
          ssc_core_5d6ba758.obj \
          ssc_core_616494c7.obj \
          ssc_core_6167281d.obj \
          ssc_core_67d1f118.obj \
          ssc_core_68da074b.obj \
          ssc_core_6b6b89d2.obj \
          ssc_core_6c0642ff.obj \
          ssc_core_6dd833f3.obj \
          ssc_core_6e6bba26.obj \
          ssc_core_706e4ae5.obj \
          ssc_core_71b6e960.obj \
          ssc_core_73d9c2b7.obj \
          ssc_core_76d825be.obj \
          ssc_core_780fa54b.obj \
          ssc_core_79dd08ab.obj \
          ssc_core_7a613edb.obj \
          ssc_core_7bb79f23.obj \
          ssc_core_7d0b92a7.obj \
          ssc_core_7ebac74c.obj \
          ssc_core_820e26d8.obj \
          ssc_core_820f4eaa.obj \
          ssc_core_856738f2.obj \
          ssc_core_8569edc5.obj \
          ssc_core_870cc9ba.obj \
          ssc_core_880d3897.obj \
          ssc_core_8a6471dc.obj \
          ssc_core_8bb063d9.obj \
          ssc_core_8d0064b8.obj \
          ssc_core_8f61989f.obj \
          ssc_core_93052d9d.obj \
          ssc_core_96061071.obj \
          ssc_core_97d767fe.obj \
          ssc_core_97dcde38.obj \
          ssc_core_9b6a1dd2.obj \
          ssc_core_9c01d168.obj \
          ssc_core_9dd110ad.obj \
          ssc_core_9fb0e229.obj \
          ssc_core_9fb0e6d6.obj \
          ssc_core_9fb25b4f.obj \
          ssc_core_9fb2efdc.obj \
          ssc_core_a00457ac.obj \
          ssc_core_a1d393be.obj \
          ssc_core_a1d6f570.obj \
          ssc_core_a4d3adaf.obj \
          ssc_core_a4d4c45e.obj \
          ssc_core_a4da1d0a.obj \
          ssc_core_a6b78ccc.obj \
          ssc_core_a6bce7bb.obj \
          ssc_core_a7672daf.obj \
          ssc_core_a867d880.obj \
          ssc_core_a9bb7f35.obj \
          ssc_core_a9bf1ff2.obj \
          ssc_core_aa0efe9f.obj \
          ssc_core_abd5e7b4.obj \
          ssc_core_acb64294.obj \
          ssc_core_acb6462e.obj \
          ssc_core_b0d62444.obj \
          ssc_core_b1038cbb.obj \
          ssc_core_b10e34f4.obj \
          ssc_core_b2b3b239.obj \
          ssc_core_b402b40d.obj \
          ssc_core_b407dc7e.obj \
          ssc_core_b40edf20.obj \
          ssc_core_b8b01afe.obj \
          ssc_core_b8be7371.obj \
          ssc_core_b96ebc21.obj \
          ssc_core_bb0b2992.obj \
          ssc_core_be01a0db.obj \
          ssc_core_c168ace6.obj \
          ssc_core_c3003040.obj \
          ssc_core_c5b63cb2.obj \
          ssc_core_c605b061.obj \
          ssc_core_c607b660.obj \
          ssc_core_c8d83e88.obj \
          ssc_core_c8df395b.obj \
          ssc_core_c90f4384.obj \
          ssc_core_cab615c8.obj \
          ssc_core_cab87eff.obj \
          ssc_core_cabdc251.obj \
          ssc_core_cb63b745.obj \
          ssc_core_cc067f58.obj \
          ssc_core_ce6a84bb.obj \
          ssc_core_d1beb31a.obj \
          ssc_core_d3d34d7c.obj \
          ssc_core_d3df2fff.obj \
          ssc_core_d4ba8ed2.obj \
          ssc_core_d708bbfb.obj \
          ssc_core_d9d13dac.obj \
          ssc_core_dcda6edd.obj \
          ssc_core_deb7fd8d.obj \
          ssc_core_e0d0866d.obj \
          ssc_core_e2b61d72.obj \
          ssc_core_e400c1c2.obj \
          ssc_core_e4061965.obj \
          ssc_core_e407adf8.obj \
          ssc_core_eb093eda.obj \
          ssc_core_ee000fbe.obj \
          ssc_core_ee01086d.obj \
          ssc_core_ee0f0141.obj \
          ssc_core_f2610835.obj \
          ssc_core_f3b47568.obj \
          ssc_core_f867a7f6.obj \
          ssc_core_f9b6dbed.obj \
          ssc_core_fa09e9e6.obj \
          ssc_core_fbd34e62.obj \
          ssc_core_fd6bfe36.obj \
          ssc_core_fede7425.obj \
          ssc_core_ff06d9a4.obj \
          

ssc_core.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ssc_core)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ssc_core)
	@cmd /C "echo ### Created $@"

MODULES_ne = \
          ne_03b6336b.obj \
          ne_06b3d331.obj \
          ne_16631e46.obj \
          ne_1dbdc793.obj \
          ne_21b3fe2a.obj \
          ne_23d90911.obj \
          ne_38dea646.obj \
          ne_390cbc71.obj \
          ne_3ab8881f.obj \
          ne_3b664010.obj \
          ne_3c033af4.obj \
          ne_3fb96ad2.obj \
          ne_42b0ffc8.obj \
          ne_45d43f88.obj \
          ne_47b9c424.obj \
          ne_48b6562f.obj \
          ne_4c607df4.obj \
          ne_550a94df.obj \
          ne_57686ca9.obj \
          ne_59b4e14a.obj \
          ne_5bd7a7a4.obj \
          ne_5f045abc.obj \
          ne_6469a614.obj \
          ne_6b61eb1c.obj \
          ne_71b28889.obj \
          ne_83d4e865.obj \
          ne_95b22d2e.obj \
          ne_9fbe8f50.obj \
          ne_a1d5f1af.obj \
          ne_af03741f.obj \
          ne_b0dd440f.obj \
          ne_b40304b0.obj \
          ne_b7b159c5.obj \
          ne_c3033fa8.obj \
          ne_d9dde03a.obj \
          ne_df6be635.obj \
          ne_e2be7d51.obj \
          ne_e8bbbd86.obj \
          ne_e960a484.obj \
          ne_eb048896.obj \
          ne_ee0cb880.obj \
          ne_f26d0c55.obj \
          ne_fd61f8e5.obj \
          

ne.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_ne)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_ne)
	@cmd /C "echo ### Created $@"

MODULES_pm = \
          pm_26dc3230.obj \
          

pm.lib : rtw_proj.tmw $(MAKEFILE) $(MODULES_pm)
	@cmd /C "echo ### Creating $@"
	$(LIBCMD) /nologo /out:$@ $(MODULES_pm)
	@cmd /C "echo ### Created $@"



#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw
