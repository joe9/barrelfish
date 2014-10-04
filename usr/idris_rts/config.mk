CC              ?=cc
CABAL           :=cabal
# IDRIS_ENABLE_STATS should not be set in final release
# Any flags defined here which alter the RTS API must also be added to src/IRTS/CodegenC.hs
CFLAGS          :=-O2 -Wall $(CFLAGS)

#CABALFLAGS	:=
## Disable building of Effects
#CABALFLAGS :=-f NoEffects

	OS      :=unix

	SHLIB_SUFFIX    :=.so
