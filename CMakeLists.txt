#############################################################################################################################
# file:  CMakeLists.txt
# brief: Template "CMakeLists.txt" for building of executables and static libraries.
#
# usage: Edit "VARIABLES"-section to suit project requirements.
#        For debug build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Debug -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
#          make -C Debug VERBOSE=1 -j
#        For release build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Release -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
#          make -C Release VERBOSE=1 -j
#############################################################################################################################
cmake_minimum_required(VERSION 3.20)

###################### CONSTANTS ######################################
set (PROJECT_TYPE_EXECUTABLE          "exe")
set (PROJECT_TYPE_STATIC_LIBRARY      "static-lib")
set (MCPU_CORTEX_M0				      "-mcpu=cortex-m0")
set (MCPU_CORTEX_M0PLUS				  "-mcpu=cortex-m0plus")
set (MCPU_CORTEX_M3				      "-mcpu=cortex-m3")
set (MCPU_CORTEX_M4				      "-mcpu=cortex-m4")
set (MCPU_CORTEX_M7				      "-mcpu=cortex-m7")
set (MCPU_CORTEX_M33				  "-mcpu=cortex-m33")
set (MCPU_CORTEX_M55				  "-mcpu=cortex-m55")
set (MCPU_CORTEX_M85				  "-mcpu=cortex-m85")
set (MFPU_FPV4_SP_D16                 "-mfpu=fpv4-sp-d16")
set (MFPU_FPV5_D16                    "-mfpu=fpv5-d16")
set (RUNTIME_LIBRARY_REDUCED_C        "--specs=nano.specs")
set (RUNTIME_LIBRARY_STD_C            "")
set (RUNTIME_LIBRARY_SYSCALLS_MINIMAL "--specs=nosys.specs")
set (RUNTIME_LIBRARY_SYSCALLS_NONE    "")
set (MFLOAT_ABI_SOFTWARE              "-mfloat-abi=soft")
set (MFLOAT_ABI_HARDWARE              "-mfloat-abi=hard")
set (MFLOAT_ABI_MIX                   "Debug")
#######################################################################

###################### VARIABLES ######################################
set (CMAKE_BUILD_TYPE		  "Debug")
set (PROJECT_NAME             "stm32f427-digital-potentiometer")
set (PROJECT_TYPE             "exe")
set (LINKER_SCRIPT            "../STM32F427ZGTX_FLASH.ld")
set (MCPU                     "-mcpu=Cortex-M4")
set (MFPU                 "-mfpu=fpv4-sp-d16")
set (MFLOAT_ABI               "-mfloat-abi=hard")
set (RUNTIME_LIBRARY          "--specs=nano.specs")
set (RUNTIME_LIBRARY_SYSCALLS "--specs=nosys.specs")


file(GLOB_RECURSE APP_SOURCES
		"src/*.c"
		"src/*.s"
		"lib/CMSIS/Device/ST/STM32F4xx/Src/*.c"
		"startup_stm32f427zgtx.s"
)

file(GLOB_RECURSE UTILS_SOURCES
		"utils/src/*.c"
)

file(GLOB_RECURSE HAL_SOURCES
		"lib/HAL/Src/*.c"
)

set (PROJECT_SOURCES
		# LIST SOURCE FILES HERE
		${APP_SOURCES}
		${UTILS_SOURCES}
		${HAL_SOURCES}
)

set (PROJECT_DEFINES
		# LIST COMPILER DEFINITIONS HERE
		STM32F427xx
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set (DEBUG_DEFINES
			USE_FULL_ASSERT
	)
endif()

set (PROJECT_INCLUDES
		# LIST INCLUDE DIRECTORIES HERE
    	include
		drivers/inc
		utils/inc
		lib/CMSIS/Include
		lib/CMSIS/Device/ST/STM32F4xx/Include
		lib/HAL/Include
)

############ MODIFY ACCORDING TO REQUIREMENTS) ########################

#######################################################################

################## PROJECT SETUP ######################################
project(${PROJECT_NAME})
enable_language(ASM)

# Debug/Release specific flags
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g3 -O0 -DDEBUG")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -O0 -DDEBUG")
	set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -g3")
	message(STATUS "Debug build configuration")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os -DRELEASE")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -DRELEASE")
	message(STATUS "Release build configuration")
else()
	# Default to Debug if not specified
	set(CMAKE_BUILD_TYPE "Debug")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g3 -O0 -DDEBUG")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -O0 -DDEBUG")
	set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -g3")
	message(STATUS "Default Debug build configuration")
endif()

if (${PROJECT_TYPE} MATCHES ${PROJECT_TYPE_EXECUTABLE})
  add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
  add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${CMAKE_PROJECT_NAME}>)
elseif (${PROJECT_TYPE} MATCHES ${PROJECT_TYPE_STATIC_LIBRARY})
  add_library(${PROJECT_NAME} ${PROJECT_SOURCES})
endif()

add_compile_definitions (${PROJECT_DEFINES} ${DEBUG_DEFINES})
include_directories (${PROJECT_INCLUDES})

set (CMAKE_EXECUTABLE_SUFFIX ".elf")
set (CMAKE_STATIC_LIBRARY_SUFFIX ".a")
set (CMAKE_C_FLAGS "${MCPU} -std=gnu11 ${MFPU} ${MFLOAT_ABI} ${RUNTIME_LIBRARY} -mthumb -Wall -Werror")
set (CMAKE_EXE_LINKER_FLAGS "-T${LINKER_SCRIPT} ${RUNTIME_LIBRARY_SYSCALLS} -Wl,-Map=test.map -Wl,--gc-sections -static -Wl,--start-group -lc -lm -Wl,--end-group")
set (CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS} -x assembler-with-cpp")
