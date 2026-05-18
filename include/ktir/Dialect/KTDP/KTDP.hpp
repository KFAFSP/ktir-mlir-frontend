//===- KTDP.hpp - KTDP dialect public header --------------------*- C++ -*-===//
//
//===----------------------------------------------------------------------===//

#ifndef KTIR_DIALECT_KTDP_KTDP_HPP
#define KTIR_DIALECT_KTDP_KTDP_HPP

#include "mlir/Bytecode/BytecodeOpInterface.h"
#include "mlir/Dialect/Affine/IR/AffineMemoryOpInterfaces.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/IntegerSet.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/ControlFlowInterfaces.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"
#include "mlir/Interfaces/ViewLikeInterface.h"
#include "mlir/Support/LLVM.h"

#include "ktir/Dialect/KTDP/KTDPAttrs.hpp"
#include "ktir/Dialect/KTDP/KTDPDialect.hpp"
#include "ktir/Dialect/KTDP/KTDPTypes.hpp"

#define GET_OP_CLASSES
#include "ktir/Dialect/KTDP/KTDP.hpp.inc"

#endif // KTIR_DIALECT_KTDP_KTDP_HPP
