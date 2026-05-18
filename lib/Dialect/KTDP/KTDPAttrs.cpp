//===- KTDPAttrs.cpp - KTDP dialect attr implementations ------------------===//
//
//===----------------------------------------------------------------------===//

#include "ktir/Dialect/KTDP/KTDPAttrs.hpp"

#include "mlir/IR/Builders.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

#include "ktir/Dialect/KTDP/KTDPDialect.hpp"

using namespace mlir;
using namespace mlir::ktdp;

#include "ktir/Dialect/KTDP/KTDPEnums.cpp.inc"

#define GET_ATTRDEF_CLASSES
#include "ktir/Dialect/KTDP/KTDPAttrs.cpp.inc"

//===----------------------------------------------------------------------===//
// SpyreMemorySpaceAttr::verify
//===----------------------------------------------------------------------===//

LogicalResult SpyreMemorySpaceAttr::verify(
    function_ref<InFlightDiagnostic()> emitError,
    SpyreMemorySpaceKind value, int32_t core) {
  // Core affinity is only meaningful for core-local memory spaces.
  if (core == -1)
    return success();

  if (core < 0)
    return emitError() << "core affinity must be non-negative, but got: "
                       << core;

  if (value != SpyreMemorySpaceKind::LX) {
    return emitError()
           << "core affinity is only valid for LX memory spaces, "
              "but got memory space '"
           << stringifySpyreMemorySpaceKind(value) << "' with core = " << core;
  }
  return success();
}

//===----------------------------------------------------------------------===//
// KTDPDialect
//===----------------------------------------------------------------------===//

void KTDPDialect::registerAttributes() {
  addAttributes<SpyreMemorySpaceAttr>();
}
