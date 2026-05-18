//===- ktdp-lsp-server.cpp - KTDP LSP server --------------------*- C++ -*-===//
//
//===----------------------------------------------------------------------===//

#include "mlir/IR/Dialect.h"
#include "mlir/InitAllDialects.h"
#include "mlir/Tools/mlir-lsp-server/MlirLspServerMain.h"

#include "ktir/Dialect/KTDP/KTDPDialect.hpp"

int main(int argc, char **argv) {
  mlir::DialectRegistry registry;

  registry.insert<mlir::ktdp::KTDPDialect>();
  mlir::registerAllDialects(registry);

  return failed(mlir::MlirLspServerMain(argc, argv, registry));
}
