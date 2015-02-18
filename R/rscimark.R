#' @title rscimark
#' @description
#' fdd
#' @param large [logical(1)]\cr
#'  Run large version of benchmark?
#'  Default is \code{FALSE}.
#' @param minimum.time [numeric(1)]\cr
#'   Minimum time to run each of the benchmarks, in seconds.
#'   Default is 2.
#' @export
#' @useDynLib rscimark c_rscimark
rscimark = function(large = FALSE, minimum.time = 2) {
  assertFlag(large)
  assertNumber(minimum.time, lower = 0)
  y = .Call(c_rscimark, large, minimum.time)
  names(y) = c("CompositeScore", "FFT", "SOR", "MonteCarlo", "SparseMatMult", "LU")
  return(y)
}
