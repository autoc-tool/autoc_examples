nuttx_add_subdirectory()
set_property(GLOBAL PROPERTY LD_SCRIPT "${NUTTX_BOARD_DIR}/scripts/linkscript.ld")

if(CONFIG_RT_FRAMEWORK)
    set(SIM_LIBS "" CACHE INTERNAL "")
    # autoc_mcal include path for CanIf / BSW
    list(APPEND PLATFORM_INCLUDE_DIRS
        ${NUTTX_APPS_DIR}/../components/autoc_mcal/Can/inc
    )
    list(APPEND PLATFORM_INCLUDE_DIRS ${VENDOR_THIRD_PARTY_DRIVER_INCDIR})
    set(PLATFORM_INCLUDE_DIRS ${PLATFORM_INCLUDE_DIRS} CACHE INTERNAL "")
endif()
