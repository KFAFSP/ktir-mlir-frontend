//===- KTDPDialect.cpp - KTDP dialect definition --------------------------===//
//
//===----------------------------------------------------------------------===//

#include "ktir/Dialect/KTDP/KTDPDialect.hpp"

#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/SCF/IR/SCF.h"
#include "mlir/Dialect/Tensor/IR/Tensor.h"
#include "mlir/IR/DialectImplementation.h"

// Generated dialect definitions
#include "ktir/Dialect/KTDP/KTDPDialect.cpp.inc"

using namespace mlir;
using namespace mlir::ktdp;

void KTDPDialect::initialize() {
  registerOps();
  registerTypes();
  registerAttributes();
}
