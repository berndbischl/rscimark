#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#include "Random.h"
#include "kernel.h"
#include "constants.h"

/*
 * This is a straightforward copy/adaptation of scimark2.c:main.
 *
 * @note: default to the (small) cache-contained version.
 *
 * @param s_large [logical(1)]
 *   Perform SciMark LARGE, i.e., memory-focused version of the benchmark?
 *   Default is FALSE.
 * @param s_min_time [numeric(1)]
 *   Minimum time to run each of the benchmarks, in seconds.
 * @return [numeric(6)]
 */
SEXP c_rscimark(SEXP s_large, SEXP s_min_time) {
  int large = asLogical(s_large);
  double min_time = asReal(s_min_time);

  int FFT_size = FFT_SIZE;
  int SOR_size =  SOR_SIZE;
  int Sparse_size_M = SPARSE_SIZE_M;
  int Sparse_size_nz = SPARSE_SIZE_nz;
  int LU_size = LU_SIZE;

  Random R = new_Random_seed(RANDOM_SEED);

  if (large) {
    FFT_size = LG_FFT_SIZE;
    SOR_size = LG_SOR_SIZE;
    Sparse_size_M = LG_SPARSE_SIZE_M;
    Sparse_size_nz = LG_SPARSE_SIZE_nz;
    LU_size = LG_LU_SIZE;
  }

  /* allocate memory for return value */
  SEXP s_res = NEW_NUMERIC(6);
  double* res = REAL(s_res);

  /* do the benchmark stuff */
  res[1] = kernel_measureFFT(FFT_size, min_time, R);
  res[2] = kernel_measureSOR(SOR_size, min_time, R);
  res[3] = kernel_measureMonteCarlo(min_time, R);
  res[4] = kernel_measureSparseMatMult(
    Sparse_size_M, Sparse_size_nz, min_time, R);
  res[5] = kernel_measureLU(LU_size, min_time, R);

  /* composite value */
  res[0] = (res[1] + res[2] + res[3] + res[4] + res[5]) / 5;

  Random_delete(R);
  return s_res;
}
