#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Headless reproduction of VCOS Studio's New Project flow.

VCOS Studio's ui_adaptor layer imports PySide6, which needs libEGL (not
installed in this container). Therefore this script calls the same
non-GUI Studio modules that the ui_adaptor layer calls:

  ProjectFileParser.init_empty_project / init_sys_info / update_target_info
  ProjectFileParser.update_info_dict / save_file
  ModuleManagement.update_modules                 (GUI apply_modules_change)
  ArxmlSaveHandler.save_bsw_ecuc_arxml / save_internal_behavior_arxml /
  save_system_dir_arxml / save_all_swc_components_arxml
  ProjectHandler.update_bsw_module_cfg_path
  ProjectXmlInfoHandler.save_xml_file

All .vcosproject and ARXML content is written by this Studio code.
"""

import os
import sys
import json
import traceback

VCOS_ROOT = "/home/box/haloos/haloosspace/vcos"
STUDIO_PATH = os.path.join(VCOS_ROOT, "vcos_studio", "configurator")
PROJECT_DIR = os.path.join(VCOS_ROOT, "examples", "minimal_system5", "system_cfg", "pc")
PROJECT_FILE = os.path.join(PROJECT_DIR, "minimal_system5.vcosproject")
CONFIG_PATH = os.path.join(PROJECT_DIR, "config")
GENDATA_PATH = os.path.join(PROJECT_DIR, "gen_data")
LOG_PATH = os.path.join(PROJECT_DIR, "log")
APPLICATION_PATH = os.path.join(VCOS_ROOT, "examples", "minimal_system5", "apps")
SYSTEM_PATH = os.path.join(VCOS_ROOT, "components", "autoc_mcal", "configurator_plug_in")
MCAL_PATH = os.path.join(VCOS_ROOT, "components", "autoc_mcal")

TARGET = "PC_Common"
COMPILER = "vs20xx"
MCAL_VERSION = "PC_MCAL_0.1.0"

sys.path.insert(0, STUDIO_PATH)
sys.path.insert(0, os.path.join(STUDIO_PATH, "third_party"))


class ProgressSignal:
    def emit(self, message):
        print("[progress] {}".format(message), flush=True)


def ensure_dirs():
    os.makedirs(PROJECT_DIR, exist_ok=True)
    os.makedirs(APPLICATION_PATH, exist_ok=True)
    for sub in ("asw", "bsw", "system", "autosar", "internal_behavior", "service_components"):
        os.makedirs(os.path.join(CONFIG_PATH, sub), exist_ok=True)
    os.makedirs(GENDATA_PATH, exist_ok=True)
    os.makedirs(LOG_PATH, exist_ok=True)
    os.makedirs(os.path.join(APPLICATION_PATH, "asw_swc"), exist_ok=True)
    os.makedirs(os.path.join(APPLICATION_PATH, "bsw_user_callout"), exist_ok=True)
    # GUI update_sys_info_dict -> update_project_file creates the project file empty first.
    if not os.path.exists(PROJECT_FILE):
        with open(PROJECT_FILE, "w", encoding="utf-8"):
            pass


def main():
    ensure_dirs()

    from func_module.project_management.project_file_parser import ProjectFileParser
    from func_module.project_management.sys_info_class import SysInfoClass
    from func_module.project_management.project_handler import ProjectHandler
    from func_module.project_management.project_xml_info import ProjectXmlInfoHandler
    from func_module.module_management.module_management import ModuleManagement
    from func_module.module_management.arxml_handler.arxml_parse_save import (
        ArxmlParseHandler,
        ArxmlSaveHandler,
    )

    progress = ProgressSignal()

    # ---- load_studio_plugin_config_file_action + update_vcos_project_config_file ----
    parser = ProjectFileParser()
    parser.init_empty_project(SYSTEM_PATH)
    sys_info = SysInfoClass()
    if parser.init_sys_info(sys_info, SYSTEM_PATH) is False:
        raise RuntimeError("ProjectFileParser.init_sys_info failed")

    sys_info.project = "minimal_system5"
    sys_info.project_path = PROJECT_FILE
    sys_info.config_base_path = CONFIG_PATH
    sys_info.gendata_path = GENDATA_PATH
    sys_info.application_path = APPLICATION_PATH
    sys_info.swc_template_path = os.path.join(APPLICATION_PATH, "asw_swc")
    sys_info.bswcallout_path = os.path.join(APPLICATION_PATH, "bsw_user_callout")
    sys_info.user_plugin_output_path = os.path.join(CONFIG_PATH, "gen_data")
    sys_info.service_component_path = os.path.join(CONFIG_PATH, "service_components")
    sys_info.internal_behavior_path = os.path.join(CONFIG_PATH, "internal_behavior")
    sys_info.log_path = LOG_PATH
    sys_info.compiler_path = ""
    sys_info.compiler = COMPILER
    sys_info.target = TARGET
    sys_info.mcal_path = MCAL_PATH
    sys_info.mcal_gendata_path = ""
    sys_info.system_path = SYSTEM_PATH
    sys_info.mcal_version = MCAL_VERSION
    sys_info.studio_path = STUDIO_PATH
    sys_info.mode = "release"
    sys_info.generation_limit = "Error"

    if parser.update_target_info(sys_info) is False:
        raise RuntimeError("ProjectFileParser.update_target_info failed")
    sys_info.all_modules = parser.get_all_module_list(sys_info.system_target_info)
    if TARGET not in sys_info.system_target_info["target"]:
        raise RuntimeError("target {} not found in components_plug_in_cfg.json".format(TARGET))
    compilers = sys_info.system_target_info["target"][TARGET]["compiler"]
    mcal_versions = sys_info.system_target_info["target"][TARGET]["MCAL_VERSION"]
    if COMPILER not in compilers:
        raise RuntimeError("compiler {} not in {}".format(COMPILER, compilers))
    if MCAL_VERSION not in mcal_versions:
        raise RuntimeError("MCAL {} not in {}".format(MCAL_VERSION, mcal_versions))

    # FuncLogicLayer.update_vcos_project_config_file
    from func_module.module_management.base_config import BASE_CONFIG_PATH
    base_arxml_path = os.path.join(BASE_CONFIG_PATH, "base_arxml")
    system_autosar = ArxmlParseHandler.parse_system_dir_arxml(base_arxml_path)
    ignore_options = sys_info.system_target_info.get("validate", {}).get("ignore_option", {})
    if TARGET in ignore_options:
        sys_info.system_target_info["validate"]["ignore_option"] = ignore_options[TARGET]

    # FuncLogicLayer.copy_file
    ProjectHandler.copy_file(
        os.path.join(STUDIO_PATH, "func_module", "module_management", "base_config",
                     "base_arxml", "autosar", "PlatformTypes_AR4.arxml"),
        os.path.join(CONFIG_PATH, "autosar", "PlatformTypes_AR4.arxml"),
    )
    ProjectHandler.copy_dir(
        os.path.join(STUDIO_PATH, "vcos_tools", "make_support"), APPLICATION_PATH
    )
    ProjectHandler.copy_cur_dir(
        os.path.join(STUDIO_PATH, "script_demo", "cmd_demo"),
        os.path.join(APPLICATION_PATH, "script"),
    )

    print("== enable modules: EcuC, Os (ModuleManagement.update_modules) ==", flush=True)
    bsw_ecuc = {}
    bswmd = {}
    ib_dict = {}
    module_management = ModuleManagement(sys_info, bsw_ecuc, bswmd, ib_dict)
    module_management.update_modules(["EcuC", "Os"], system_autosar)
    print("enabled:", sorted(sys_info.enable_modules), flush=True)
    if not {"EcuC", "Os"}.issubset(sys_info.enable_modules):
        raise RuntimeError("failed to enable EcuC/Os: {}".format(sorted(sys_info.enable_modules)))

    # ---- FuncLogicLayer._save_vcos_project_config_file ----
    print("== save project (ArxmlSaveHandler + ProjectFileParser.save_file) ==", flush=True)
    module_list = set(sys_info.enable_modules)
    ArxmlSaveHandler.save_bsw_ecuc_arxml(bsw_ecuc, CONFIG_PATH, module_list)
    ArxmlSaveHandler.save_internal_behavior_arxml(ib_dict, CONFIG_PATH, module_list)
    ArxmlSaveHandler.save_system_dir_arxml(system_autosar, CONFIG_PATH)
    ArxmlSaveHandler.save_all_swc_components_arxml(None, CONFIG_PATH)

    project_handler = ProjectHandler()
    project_handler.update_bsw_module_cfg_path(sys_info)
    parser.update_info_dict(sys_info)
    if parser.save_file(PROJECT_FILE) is False:
        raise RuntimeError("ProjectFileParser.save_file failed")
    ProjectXmlInfoHandler.save_xml_file(PROJECT_FILE, {"asw_component": {}})
    progress.emit("project saved")

    # ---- report ----
    print("== result ==", flush=True)
    print("vcosproject exists:", os.path.exists(PROJECT_FILE), flush=True)
    with open(PROJECT_FILE, "r", encoding="utf-8") as f:
        info = json.load(f)
    print("file project:", info.get("project"), flush=True)
    print("file target :", info.get("target"), flush=True)
    print("file compiler:", info.get("compiler"), flush=True)
    print("file MCAL_VERSION:", info.get("MCAL_VERSION"), flush=True)
    print("file enabled:", info.get("modules_info", {}).get("enabled_module_list"), flush=True)
    print("file system_path:", info.get("path", {}).get("system_path"), flush=True)
    print("file mcal_path:", info.get("path", {}).get("mcal_path"), flush=True)
    print("file application_path:", info.get("path", {}).get("application_path"), flush=True)
    print("file config_path:", info.get("config_path"), flush=True)
    print("file gendata_path:", info.get("gendata_path"), flush=True)
    for root, dirs, files in os.walk(CONFIG_PATH):
        for name in sorted(files):
            print("generated:", os.path.join(root, name), flush=True)
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception:
        traceback.print_exc()
        sys.exit(1)
