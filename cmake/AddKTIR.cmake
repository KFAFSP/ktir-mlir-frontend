# Setup KTIR project targets.
if(NOT TARGET ktir-capi)
  add_custom_target(ktir-capi)
endif()
if(NOT TARGET ktir-doc)
  add_custom_target(ktir-doc)
endif()
if(NOT TARGET ktir-headers)
  add_custom_target(ktir-headers)
endif()

#
# TableGen related helpers
#

function(add_ktir_tablegen_target name)
  add_public_tablegen_target(${name})
  add_dependencies(ktir-headers ${name})
endfunction()

function(add_ktir_dialect dialect dialect_namespace)
  set(LLVM_TARGET_DEFINITIONS ${dialect}.td)
  mlir_tablegen(${dialect}.hpp.inc -gen-op-decls)
  mlir_tablegen(${dialect}.cpp.inc -gen-op-defs)
  mlir_tablegen(${dialect}Types.hpp.inc -gen-typedef-decls -typedefs-dialect=${dialect_namespace})
  mlir_tablegen(${dialect}Types.cpp.inc -gen-typedef-defs -typedefs-dialect=${dialect_namespace})
  mlir_tablegen(${dialect}Dialect.hpp.inc -gen-dialect-decls -dialect=${dialect_namespace})
  mlir_tablegen(${dialect}Dialect.cpp.inc -gen-dialect-defs -dialect=${dialect_namespace})
  add_ktir_tablegen_target(KTIR${dialect}IncGen)
endfunction()

function(add_ktir_doc doc_filename output_file output_directory command)
  # This is a copy from AddMLIR.cmake, which uses the right targets.

  set(LLVM_TARGET_DEFINITIONS ${doc_filename}.td)
  tablegen(MLIR ${output_file}.md ${command} -allow-hugo-specific-features ${ARGN})
  set(GEN_DOC_FILE ${KTIR_BINARY_DIR}/docs/${output_directory}${output_file}.md)
  add_custom_command(
          OUTPUT ${GEN_DOC_FILE}
          COMMAND ${CMAKE_COMMAND} -E copy
                  ${CMAKE_CURRENT_BINARY_DIR}/${output_file}.md
                  ${GEN_DOC_FILE}
          DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${output_file}.md)
  add_custom_target(${output_file}DocGen DEPENDS ${GEN_DOC_FILE})
  add_dependencies(ktir-doc ${output_file}DocGen)
endfunction()

#
# Target creation helpers
#

macro(add_ktir_executable name)
  add_llvm_executable(${name} ${ARGN})
  # TODO: Consider install instructions.
endmacro()

macro(add_ktir_tool name)
  if(NOT KTIR_BUILD_TOOLS)
    list(APPEND ARGN "EXCLUDE_FROM_ALL")
  endif()

  add_ktir_executable(${name} ${ARGN})
endmacro()

function(add_ktir_library name)
  add_mlir_library(${ARGV} DISABLE_INSTALL)
  # TODO: Consider install instructions.
endfunction()

function(add_ktir_public_c_api_library name)
  add_mlir_public_c_api_library(${ARGV} DISABLE_INSTALL)
  add_dependencies(ktir-capi ${name})
  # TODO: Consider install instructions.
endfunction()

function(add_ktir_dialect_library name)
  set_property(GLOBAL APPEND PROPERTY KTIR_DIALECT_LIBS ${name})
  add_ktir_library(${ARGV} DEPENDS ktir-headers)
endfunction()

function(add_ktir_conversion_library name)
  set_property(GLOBAL APPEND PROPERTY KTIR_CONVERSION_LIBS ${name})
  add_ktir_library(${ARGV} DEPENDS ktir-headers)
endfunction()
