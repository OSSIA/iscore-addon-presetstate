cmake_minimum_required(VERSION 3.1)
if(NOT TARGET iscore_plugin_engine)
    return()
endif()
project(iscore_addon_presetstate LANGUAGES CXX)

iscore_common_setup()

# Packages
find_package(Qt5 5.3 REQUIRED COMPONENTS Core Widgets)

# Files & main target
set(HDRS
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Factory.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Metadata.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Model.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Preset.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Inspector/Widget.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Inspector/WidgetFactory.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Executor/StateComponent.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Commands/SetPresetFile.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Commands/PresetStateCommandFactoryKey.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/iscore_addon_presetstate.hpp"
)
set(SRCS
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Model.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Preset.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Inspector/Widget.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Inspector/WidgetFactory.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Executor/StateComponent.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Commands/SetPresetFile.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Commands/PresetStateCommandFactoryKey.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/iscore_addon_presetstate.cpp"
)

add_library(${PROJECT_NAME} ${SRCS} ${HDRS})

iscore_generate_command_list_file(${PROJECT_NAME} "${HDRS}")

target_link_libraries(${PROJECT_NAME} PUBLIC
  Qt5::Core Qt5::Widgets
  iscore_lib_process iscore_lib_inspector iscore_plugin_engine)
setup_iscore_plugin(${PROJECT_NAME})
