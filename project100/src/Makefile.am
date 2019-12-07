## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project100

project100_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonctions.c fonctions.h \
	facture.c facture.h \
	Vol.c Vol.h \
	marouane.c marouane.h

project100_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

