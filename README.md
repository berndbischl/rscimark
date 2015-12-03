# rscimark

This package offers a single function `rscimark`, which is a simple wrapper
around the [ANSI C version of the SciMark2 benchmark](http://math.nist.gov/scimark2/download_c.html). [SciMark](http://math.nist.gov/scimark) is a benchmark for numerical computing and scientific computing. Concicely the computational kernels Fast Fourier Transformation (FFT), Gauss-Seidel relaxation, Sparse matrix-multiply, Monte Carlo integration, and dense LU factorization are used as indicators for the performance.

[![CRAN Status Badge](http://www.r-pkg.org/badges/version/rscimark)](http://cran.r-project.org/web/packages/rscimark)
[![CRAN Downloads](http://cranlogs.r-pkg.org/badges/rscimark)](http://cran.rstudio.com/web/packages/rscimark/index.html)
[![Build Status](https://travis-ci.org/berndbischl/rscimark.svg)](https://travis-ci.org/berndbischl/rscimark)
[![Build status](https://ci.appveyor.com/api/projects/status/4b468f5phkb4lmeq/branch/master?svg=true)](https://ci.appveyor.com/project/berndbischl/rscimark/branch/master)
[![Coverage Status](https://coveralls.io/repos/berndbischl/rscimark/badge.svg)](https://coveralls.io/r/berndbischl/rscimark)

# Installation

Run the following command in R to install the current GitHub version. For further installation instructions take a glance at our [guide](https://github.com/rdatsci/PackagesInfo/wiki/Installation-Information).
```r
devtools::install_github("berndbischl/rscimark")
```

# HowTo

To run the SciMark 2.0 benchmark from within R just open a R session and type
the following:
```r
library(rscimark)
rscimark()
```

To address performance of the memory subsystem with problems sizes which to not fit in the cache set the `large` parameter to `TRUE`.
```r
rscimark(large = TRUE)
```

