ENCODER_ENABLE = yes
ifeq ($(strip $(ENCODER_ENABLE)), yes)
	ENCODER_MAP_ENABLE = yes
	SRC += features/encoder.c
endif

EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
LTO_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
UNICODE_ENABLE = yes

AUTO_SHIFT_ENABLE = yes
ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes)
	SRC += features/auto_shift.c
endif

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += rgb/rgb.c
endif

OLED_ENABLE = no
OLED_DRIVER = ssd1306
ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled/oled.c
endif


# Save space
# https://docs.qmk.fm/#/squeezing_avr?id=squeezing-the-most-out-of-avr
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes
SRC += avr.c
