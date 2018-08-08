cmake_minimum_required(VERSION 3.1)
if(NOT TARGET score_plugin_engine)
    return()
endif()
project(score_addon_presetstate LANGUAGES CXX)

score_common_setup()

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
  "${CMAKE_CURRENT_SOURCE_DIR}/score_addon_presetstate.hpp"
)
set(SRCS
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Model.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Preset.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Inspector/Widget.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Executor/StateComponent.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Commands/SetPresetFile.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/PresetState/Commands/PresetStateCommandFactoryKey.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/score_addon_presetstate.cpp"
)

add_library(${PROJECT_NAME} ${SRCS} ${HDRS})

score_generate_command_list_file(${PROJECT_NAME} "${HDRS}")

target_link_libraries(${PROJECT_NAME} PUBLIC
  Qt5::Core Qt5::Widgets
  score_lib_process score_lib_inspector score_plugin_engine)
setup_score_plugin(${PROJECT_NAME})
