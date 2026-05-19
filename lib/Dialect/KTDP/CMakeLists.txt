add_ktir_dialect_library(KTIRKTDPDialect
    KTDPAttrInterfaces.cpp
    KTDPAttrs.cpp
    KTDPDialect.cpp
    KTDPOps.cpp
    KTDPTypes.cpp

  ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/include/ktir/Dialect/KTDP

  DEPENDS
    KTIRKTDPAttrInterfacesIncGen
    KTIRKTDPAttrsIncGen
    KTIRKTDPIncGen

  LINK_LIBS PUBLIC
    MLIRIR
    MLIRInferTypeOpInterface
    MLIRAffineDialect
    MLIRMemRefDialect
    MLIRTensorDialect
    MLIRSCFDialect
    MLIRFuncDialect
    MLIRArithDialect
)
