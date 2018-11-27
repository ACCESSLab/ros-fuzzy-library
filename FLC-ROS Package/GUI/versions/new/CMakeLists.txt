
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

project(FLS_Library_GUI)


# Set your files and resources here
set( SOURCES
    main.cpp
    mainwindow.cpp
    inputdialog.cpp
    outputdialog.cpp
    ruledialog.cpp
    inmfsdialog.cpp
    outmfsdialog.cpp
    addrulesdialog.cpp 
    intabledialog.cpp
    outtabledialog.cpp
    XMLReader.cpp
    XMLWriter.cpp
    MetaRecord.cpp )

set( HEADERS
    mainwindow.h
    inputdialog.h
    outputdialog.h
    ruledialog.h
    inmfsdialog.h
    outmfsdialog.h
    addrulesdialog.h
    intabledialog.h
    outtabledialog.h
    commondef.h
    XMLReader.h
    XMLWriter.h
    MetaRecord.h )

set( MOC_HEADERS
    mainwindow.h
    inputdialog.h
    outputdialog.h
    ruledialog.h
    inmfsdialog.h
    outmfsdialog.h
    addrulesdialog.h
    intabledialog.h
    outtabledialog.h )

set( UIs
    mainwindow.ui
    inputdialog.ui
    outputdialog.ui
    ruledialog.ui
    inmfsdialog.ui
    outmfsdialog.ui
    addrulesdialog.ui
    intabledialog.ui
    outtabledialog.ui )

include_directories(
     ${CMAKE_CURRENT_BINARY_DIR}
     ${CMAKE_CURRENT_SOURCE_DIR}
)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED QUIET)
qt5_wrap_ui(UI_SOURCES ${UIs})

# CMAKE_AUTOMOC in ON so the MocHEADERS will be automatically wrapped.
add_executable(FLS_Library_GUI ${SOURCES} ${HEADERS} ${UI_SOURCES} ${MOC_HEADERS})
qt5_use_modules(FLS_Library_GUI Core Gui Xml Widgets)
target_link_libraries(FLS_Library_GUI)

# generate proper GUI program on specified platform
if(WIN32) # Check if we are on Windows
	if(MSVC) # Check if we are using the Visual Studio compiler
		set_target_properties(${PROJECT_NAME} PROPERTIES
			WIN32_EXECUTABLE YES
			LINK_FLAGS "/ENTRY:mainCRTStartup"
		)
	elseif(CMAKE_COMPILER_IS_GNUCXX)
			# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
	else()
		message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
	endif(MSVC)
elseif(APPLE)
	set_target_properties(${PROJECT_NAME} PROPERTIES
			MACOSX_BUNDLE YES
	)
elseif(UNIX)
	# Nothing special required
else()
	message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)