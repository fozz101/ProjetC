## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project114

project114_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonctions.c fonctions.h \
	facture.c facture.h \
	Vol.c Vol.h \
	marouane.c marouane.h \ 
	reclamation.c reclamation.h


project114_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

