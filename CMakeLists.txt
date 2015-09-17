project(pietcreator)
cmake_minimum_required(VERSION 2.8.12)

set( CMAKE_BUILD_TYPE Debug)
set( DEBUG_BUILD_TYPE ON )

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Test)

add_subdirectory( npiet )

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ./npiet .)

set( pietcreator_SRCS
    main.cpp
    MainWindow.cpp
    ImageModel.cpp
    PixelDelegate.cpp
    KColorCells.cpp
    KColorMimeData.cpp
    KColorPatch.cpp
    ViewMonitor.cpp
    Command.cpp
    CommandsModel.cpp
    CommandDelegate.cpp
    ResizeDialog.cpp
    RunController.cpp
    NPietObserver.cpp
    CommandWidget.cpp
    DebugWidget.cpp
    CommandImpl.cpp
    FlowCompass.cpp
    UndoCommands.cpp
    UndoHandler.cpp )

set( pietcreator_RCS
    fallback.qrc
    pietcreator.qrc )

qt5_add_resources( pietcreator_SRCS ${pietcreator_RCS} )

#qt4_automoc(${pietcreator_SRCS})

qt5_wrap_ui( pietcreator_SRCS MainWindow.ui DebugWidget.ui )

if(WIN32)
add_executable(pietcreator ${pietcreator_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/pietcreator.rc)
else()
add_executable(pietcreator ${pietcreator_SRCS})
endif(WIN32)

target_link_libraries( pietcreator
                       Qt5::Core
                       Qt5::Widgets
                       npiet
                         )
