# Hey Emacs, this is a -*- makefile -*-
#----------------------------------------------------------------------------
#
# Makefile for ChipWhisperer SimpleSerial-AES Program
#
#----------------------------------------------------------------------------
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make coff = Convert ELF to AVR COFF.
#
# make extcoff = Convert ELF to AVR Extended COFF.
#
# make program = Download the hex file to the device, using avrdude.
#                Please customize the avrdude settings below first!
#
# make debug = Start either simulavr or avarice as specified for debugging,
#              with avr-gdb or avr-insight as the front end for debugging.
#
# make filename.s = Just compile filename.c into the assembler code only.
#
# make filename.i = Create a preprocessed source file for use in submitting
#                   bug reports to the GCC project.
#
# To rebuild project do "make clean" then "make all".
#----------------------------------------------------------------------------


CRYPTO_TARGET = NONE

ifeq ($(ALGO), shiffthq)
	include ./lib/Makefile.shiffthq
	TARGET = ss-chacha20-shiffthq
	SRC += shiffthq.c
else ifeq ($(ALGO), libressl)
	TARGET = ss-chacha20-libressl
	include ./lib/Makefile.libressl
	SRC += libressl.c
else ifeq ($(ALGO), mbedtls)
	TARGET = ss-chacha20-mbedtls
	include ./lib/Makefile.mbedtls
	SRC += mbedtls.c
else ifeq ($(ALGO), nss)
	TARGET = ss-chacha20-nss
	include ./lib/Makefile.nss
	SRC += nss.c
else
	$(error Invalid or empty ALGO: $(ALGO). Known algos: shiffthq, libressl, mbedtls, nss)
endif

EXTRAINCDIRS += ./include

#Add simpleserial project to build
include ../simpleserial/Makefile.simpleserial

FIRMWAREPATH = ../.
include $(FIRMWAREPATH)/Makefile.inc
