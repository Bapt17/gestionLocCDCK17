cmake_minimum_required(VERSION 3.16)

project(GestionLocCDCK17 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Sql)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appGestionLocCDCK17
    main.cpp
)

qt_add_qml_module(appGestionLocCDCK17
    URI GestionLocCDCK17
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES modeles/client.h modeles/client.cpp
        SOURCES modeles/contrat.h modeles/contrat.cpp
        SOURCES modeles/prestation.h modeles/prestation.cpp
        SOURCES modeles/lignecontrat.h modeles/lignecontrat.cpp
        SOURCES utils/databasemanager.h utils/databasemanager.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appGestionLocCDCK17 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appGestionLocCDCK17
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appGestionLocCDCK17
    PRIVATE Qt6::Quick
    Qt6::Sql
)

include(GNUInstallDirs)
install(TARGETS appGestionLocCDCK17
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
