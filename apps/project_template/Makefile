#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := project_template

IOT_SOLUTION_PATH ?= $(abspath $(shell pwd)/../../)

#EXTRA_COMPONENT_DIRS += $(IOT_SOLUTION_PATH)/components/the_one_you_want_to_use

include $(IOT_SOLUTION_PATH)/Makefile
include $(IDF_PATH)/make/project.mk

clean:
	rm -rvf build sdkconfig sdkconfig.old
