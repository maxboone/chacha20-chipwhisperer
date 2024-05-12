# Setup Simpleserial
SS_VER = SS_VER_1_1
CDEFS += -DSS_VER=$(SS_VER)

# Setup CWNANO Platform HAL (firmware)
PLATFORM = CWNANO
HAL = stm32f0_nano
PLTNAME = CWNANO Built-in Target (STM32F030)
include ./firmware/hal/$(HAL)/Makefile.$(HAL)
CDEFS += -DHAL_TYPE=HAL_$(HAL) -DPLATFORM=$(PLATFORM)

# Whatever we need to build
SRC += shiffthq.c
