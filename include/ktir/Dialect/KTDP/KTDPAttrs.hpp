//===- KTDPAttrs.hpp - KTDP dialect attrs public header ---------*- C++ -*-===//
//
//===----------------------------------------------------------------------===//

#ifndef KTIR_DIALECT_KTDP_KTDPATTRS_HPP
#define KTIR_DIALECT_KTDP_KTDPATTRS_HPP

#include "ktir/Dialect/KTDP/KTDPAttrInterfaces.hpp"
#include "ktir/Dialect/KTDP/KTDPDialect.hpp"
#include "mlir/IR/Attributes.h"

#include "ktir/Dialect/KTDP/KTDPEnums.hpp.inc"

#define GET_ATTRDEF_CLASSES
#include "ktir/Dialect/KTDP/KTDPAttrs.hpp.inc"

#endif // KTIR_DIALECT_KTDP_KTDPATTRS_HPP
