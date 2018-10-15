############################ Common compiler flags ############################
# GCC compatible flags
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "QCC")

   #### Protobuf generated code visibility issue
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=default -fvisibility-inlines-hidden")
   ############################################################################

   #### Default compiler flags
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsign-compare")
   if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshorten-64-to-32")
   elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "QCC")
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wnarrowing")
       # GNU flavor has too many false positives on unreachable code
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=return-type")
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-return-type")
   endif()
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsign-conversion")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
   ############################################################################

   #### Position independent code
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
   ############################################################################

   #### Linker options: check for undefined symbols
   if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
       set(LINKER_DISABLE_UNDEFINED_SYMBOLS -Wl,-undefined,error)
   elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "QCC")
       set(LINKER_DISABLE_UNDEFINED_SYMBOLS -Wl,--no-undefined)
   endif()
   #### Apply to shared libraries
   set(CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} ${LINKER_DISABLE_UNDEFINED_SYMBOLS}")
   #### Apply to executables
   set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINKER_DISABLE_UNDEFINED_SYMBOLS}")
   ############################################################################
endif()

if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /bigobj /MP /W4 /WX")
    add_definitions(-D_ENABLE_ATOMIC_ALIGNMENT_FIX)
endif()

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
###############################################################################

################################### Definitions ################################
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    add_definitions(-D_USE_MATH_DEFINES)
endif()
###############################################################################
