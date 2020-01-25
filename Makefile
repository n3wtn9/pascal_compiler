### Build flags for all targets
#
CF_ALL          =
LF_ALL          = 
LL_ALL          =

### Build tools
# 
CC 		= clang++ -Wno-c++11-extensions
# INST		= ./build/install
COMP            = $(CC) $(CF_ALL) $(CF_TGT) -o $@ -c $<
LINK            = $(CC) $(LF_ALL) $(LF_TGT) -o $@ $^ $(LL_TGT) $(LL_ALL)
COMPLINK        = $(CC) $(CF_ALL) $(CF_TGT) $(LF_ALL) $(LF_TGT) -o $@ $< $(LL_TGT) $(LL_ALL)

### Standard parts
#
include Rules.mk
