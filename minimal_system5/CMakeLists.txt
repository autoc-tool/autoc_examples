# examples/minimal_system5 â€?PC_Common + autoc_mcal on NuttX arch/sim
if(DEFINED BOARD_NAME)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/system_cfg/${BOARD_NAME} ${CMAKE_CURRENT_BINARY_DIR}/${BOARD_NAME})
    # Explicit sources: skip sysm_init_user_callout (EcuM) for PC Os+autoc_mcal MVP
    set(CSRCS
         ${CMAKE_CURRENT_LIST_DIR}/apps/system.c
         ${CMAKE_CURRENT_LIST_DIR}/apps/os_task_init.c
         ${CMAKE_CURRENT_LIST_DIR}/apps/canif_mcal_adapter.c
         ${CMAKE_CURRENT_LIST_DIR}/apps/asw_swc/asw_minimal.c
         ${CMAKE_CURRENT_LIST_DIR}/apps/bsw_user_callout/hook_user_callout.c
         ${CMAKE_CURRENT_LIST_DIR}/apps/ecum_stubs.c)

    if(CONFIG_RT_FRAMEWORK)
      set(INCLUDE_DIRS  ${CMAKE_CURRENT_LIST_DIR}
                        ${CMAKE_CURRENT_LIST_DIR}/apps
                        ${CMAKE_CURRENT_LIST_DIR}/apps/include
                        ${CMAKE_CURRENT_LIST_DIR}/apps/asw_swc
                        ${CMAKE_CURRENT_LIST_DIR}/apps/bsw_user_callout
                        ${NUTTX_APPS_DIR}/components/rt_framework/inc
                        ${NUTTX_APPS_DIR}/components/include/autosar
                        ${NUTTX_APPS_DIR}/components/include/
                        ${NUTTX_APPS_DIR}/components/maintaining/vcos_log/inc
                        ${NUTTX_APPS_DIR}/components/communication/net_manager/comm/inc
                        ${NUTTX_APPS_DIR}/components/communication/net_manager/cansm/inc
                        ${NUTTX_APPS_DIR}/components/communication/net_dev/canif/inc
                        ${NUTTX_APPS_DIR}/components/communication/pdu_router/inc
                        ${NUTTX_APPS_DIR}/components/communication/rt_com/inc
                        ${NUTTX_APPS_DIR}/../components/autoc_mcal/Can/inc
                        ${GENDATA_DIR}/Can
                        ${GENDATA_DIR}/CanIf
                        ${GENDATA_DIR}/Com
                        ${GENDATA_DIR}/PduR
                        ${GENDATA_DIR}/Rte
                        ${GENDATA_DIR}/Os)
      nuttx_add_library(start_rt_framework STATIC)
      target_sources(start_rt_framework PRIVATE ${CSRCS} ${GENDATA_SRC_FILES})
      target_include_directories(start_rt_framework PRIVATE ${INCLUDE_DIRS} ${GENDATA_INC_DIRS} ${PLATFORM_INCLUDE_DIRS})
      target_link_libraries(start_rt_framework PRIVATE ${SIM_LIBS})
      if(TARGET pc_can_driver)
        target_link_libraries(start_rt_framework PRIVATE pc_can_driver)
      endif()
    endif()
endif()
