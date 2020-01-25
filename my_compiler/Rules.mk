# Standard things

sp 		:= $(sp).x
dirstack_$(sp)	:= $(d)
d		:= $(dir)


# Local rules and targets

TGTS_$(d)	:= $(d)/my_compiler
DEPS_$(d)	:= $(TGTS_$(d):%=%.d)

TGT_BIN		:= $(TGT_BIN) $(TGTS_$(d))
CLEAN		:= $(CLEAN) $(TGTS_$(d)) $(DEPS_$(d))

$(TGTS_$(d)):	$(d)/Rules.mk

$(TGTS_$(d)):	CF_TGT := -Iprog2-1 -DRADDB=\"$(DIR_ETC)\"
$(TGTS_$(d)):	LL_TGT := $(S_LL_INET) prog2-1/prog2-1.a
$(TGTS_$(d)):	$(d)/list.cpp prog2-1/prog2-1.a
		$(COMPLINK)


# Standard things

-include	$(DEPS_$(d))

d		:= $(dirstack_$(sp))
sp		:= $(basename $(sp))
