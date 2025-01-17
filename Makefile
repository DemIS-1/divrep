MPUGMP = /src/perl/Math-Prime-Util-GMP
COUL = coulfact.c diag.c rootmod.c coultau.c pell.c prime_iterator.c
HOUL = coulfact.h diag.h rootmod.h coultau.h pell.h coul.h prime_iterator.h

GCC_MAJOR := $(shell gcc -dumpversion)
ifeq "${GCC_MAJOR}" "7"
  CC_EXTRA_OPT = -ftree-loop-linear -ftree-loop-distribution -ftree-loop-im
endif
CC_OPT = -O6 -fgcse-sm -fgcse-las -fgcse-after-reload -fivopts -ftracer -funroll-loops -fvariable-expansion-in-unroller -freorder-blocks-and-partition -funswitch-loops ${CC_EXTRA_OPT}
dcoul dpcoul dpcaul dsq12: CC_OPT = -O0

CFACTOR = ${MPUGMP}/factor.c ${MPUGMP}/ecm.c ${MPUGMP}/pbrent63.c ${MPUGMP}/isaac.c ${MPUGMP}/tinyqs.c ${MPUGMP}/squfof126.c ${MPUGMP}/simpqs.c ${MPUGMP}/primality.c ${MPUGMP}/utility.c ${MPUGMP}/gmp_main.c ${MPUGMP}/bls75.c ${MPUGMP}/real.c ${MPUGMP}/ecpp.c
HFACTOR = ${MPUGMP}/factor.h

DEFINES := -DSTANDALONE
coul pcoul dcoul dpcoul: DEFINES += -DTYPE_o
pcaul dpcaul: DEFINES += -DTYPE_a

pcoul dpcoul pcaul dpcaul ftest: DEFINES += -DPARALLEL
ifdef SQONLY
    DEFINES += -DSQONLY
endif
ifdef CHECK_OVERFLOW
    DEFINES += -DCHECK_OVERFLOW
endif
ifdef VERBOSE
    DEFINES += -DVERBOSE
endif
ifdef LARGE_MIN
    DEFINES += -DLARGE_MIN
endif
ifdef TRY_HARDER
    DEFINES += -DTRY_HARDER
endif
ifdef DEBUG_ALL
    DEFINES += -DDEBUG_ALL
endif

default: pcoul
all: pcoul dpcoul pcaul dpcaul

coul pcoul dcoul dpcoul pcaul dpcaul: Makefile coul.c ${COUL} ${HOUL} ${CFACTOR} ${HFACTOR}
	gcc -o $@ -g ${CC_OPT} ${DEFINES} coul.c ${COUL} ${CFACTOR} -I${MPUGMP} -lgmp -lm -lrt

test_pell: Makefile test_pell.c ${COUL} ${HOUL} ${CFACTOR} ${HFACTOR}
	gcc -o test_pell -g ${CC_OPT} ${DEFINES} test_pell.c ${COUL} ${CFACTOR} -I${MPUGMP} -lgmp -lm

ftest: Makefile ftest.c coultau.c prime_iterator.c ${HOUL} ${CFACTOR} ${HFACTOR}
	gcc -o ftest -g ${CC_OPT} ${DEFINES} ftest.c coultau.c prime_iterator.c ${CFACTOR} -I${MPUGMP} -lgmp -lm

speed: Makefile speed.c prime_iterator.c ${HFACTOR} ${MPUGMP}/gmp_main.c
	gcc -o speed -g ${CC_OPT} ${DEFINES} speed.c prime_iterator.c ${CFACTOR} -I${MPUGMP} -lgmp -lm

sq12 dsq12: Makefile sq12.c diag.c coultau.c prime_iterator.c diag.h coultau.h prime_iterator.h ${CFACTOR} ${HFACTOR}
	gcc -o $@ -g ${CC_OPT} ${DEFINES} sq12.c diag.c coultau.c prime_iterator.c ${CFACTOR} -I${MPUGMP} -lgmp -lm -lrt
