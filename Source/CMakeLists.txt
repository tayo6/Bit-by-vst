cmake_minimum_required(VERSION 3.22)

project(HuhBlueprint VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/MP /bigobj)
endif()

# ---------------------------------------------------------------------------
#  JUCE 7.0.12, pinned
# ---------------------------------------------------------------------------
include(FetchContent)

FetchContent_Declare(JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        7.0.12
    GIT_SHALLOW    TRUE)

FetchContent_MakeAvailable(JUCE)

# ---------------------------------------------------------------------------
#  Target
# ---------------------------------------------------------------------------
juce_add_gui_app(HuhBlueprint
    PRODUCT_NAME  "HUH Blueprint"
    COMPANY_NAME  "Niran Audioz"
    VERSION       "0.1.0")

target_sources(HuhBlueprint PRIVATE
    Source/Main.cpp
    Source/MainComponent.cpp
    Source/MainComponent.h
    Source/UI/Theme.h
    Source/UI/GridLayer.cpp
    Source/UI/GridLayer.h
    Source/UI/BlueprintSheet.cpp
    Source/UI/BlueprintSheet.h
    Source/UI/BlueprintButton.cpp
    Source/UI/BlueprintButton.h
    Source/UI/TextLabel.h
    Source/UI/HeaderBar.cpp
    Source/UI/HeaderBar.h
    Source/UI/SheetViewport.cpp
    Source/UI/SheetViewport.h)

target_include_directories(HuhBlueprint PRIVATE Source)

target_compile_definitions(HuhBlueprint PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:HuhBlueprint,JUCE_PRODUCT_NAME>"
    JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:HuhBlueprint,JUCE_VERSION>")

target_link_libraries(HuhBlueprint
    PRIVATE
        juce::juce_gui_extra
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags)