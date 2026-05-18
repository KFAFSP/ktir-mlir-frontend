//===- ktdp-opt.cpp - KTDP MLIR optimizer driver ----------------*- C++ -*-===//
//
//===----------------------------------------------------------------------===//

#include "mlir/IR/Dialect.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllExtensions.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

#include "ktir/Dialect/KTDP/KTDPDialect.hpp"

using namespace mlir;

int main(int argc, char **argv) {
  registerAllPasses();

  DialectRegistry registry;
  registry.insert<mlir::ktdp::KTDPDialect>();
  registerAllDialects(registry);
  registerAllExtensions(registry);

  return asMainReturnCode(
      MlirOptMain(argc, argv, "KTDP optimizer driver\n", registry));
}
