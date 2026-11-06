# ##############################################################################
# applications/CMakeLists.txt
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################


# Variables
set(PROJECT_NAME minimal_system5 CACHE INTERNAL "")
set(PROJECT_FILE_PATH ${CMAKE_CURRENT_LIST_DIR}/../ CACHE INTERNAL "") # project file path relative to gen_data directory
set(GENDATA_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE INTERNAL "")
# Target chip selected.
set(TAREGET PC_Common CACHE INTERNAL "")
# Compiler selected.
set(COMPILER vs20xx CACHE INTERNAL "")
# Compiler path relative to gen_data directory.
set(COMPILER_PATH  CACHE INTERNAL "")
# module enable
set(VCOS_MODULE_CONFIG_LIST)

file(GLOB GENDATA_SRC_FILES CONFIGURE_DEPENDS ${GENDATA_DIR}/Rte/*.c)
set(GENDATA_SRC_FILES ${GENDATA_SRC_FILES} CACHE INTERNAL "")
set(GENDATA_INC_DIRS
    ${GENDATA_DIR}/sysm/BswM
    ${GENDATA_DIR}/Can
    ${GENDATA_DIR}/CanIf
    ${GENDATA_DIR}/CanSM
    ${GENDATA_DIR}/Com
    ${GENDATA_DIR}/ComM
    ${GENDATA_DIR}/Crc
    ${GENDATA_DIR}/Det
    ${GENDATA_DIR}/EcuC
    ${GENDATA_DIR}/sysm/EcuM
    ${GENDATA_DIR}/Appl
    ${GENDATA_DIR}/Os
    ${GENDATA_DIR}/Memmap
    ${GENDATA_DIR}/PduR
    ${GENDATA_DIR}/Rte
    CACHE INTERNAL ""
)