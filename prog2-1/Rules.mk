# Standard things

sp 		:= $(sp).x
dirstack_$(sp)	:= $(d)
d		:= $(dir)

# Local variables

OBJS_$(d)	:= $(d)/buffer.o $(d)/common.o $(d)/error.o

DEPS_$(d)	:= $(OBJS_$(d):%=%.d)

CLEAN		:= $(CLEAN) $(OBJS_$(d)) $(DEPS_$(d))

# Local rules

$(OBJS_$(d)):	CF_TGT := -I$(d)

$(d)/prog2-1.a:	$(d)/prog2-1.a($(OBJS_$(d)))


# Standard things

-include	$(DEPS_$(d))

d		:= $(dirstack_$(sp))
sp		:= $(basename $(sp))
