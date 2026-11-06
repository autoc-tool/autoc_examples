# Host-side evidence for MinimalSystem SYS-DIA-001. Not part of the NuttX image.
CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Werror -Iinclude -I../asw_swc

.PHONY: test clean

test: test_cmd_timeout
	./test_cmd_timeout

test_cmd_timeout: test_cmd_timeout.c ../asw_swc/MinimalSystem.c ../asw_swc/MinimalSystem.h include/Rte_MinimalSystem.h include/Std_Types.h
	$(CC) $(CFLAGS) -o $@ test_cmd_timeout.c ../asw_swc/MinimalSystem.c

clean:
	rm -f test_cmd_timeout
