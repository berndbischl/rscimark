test_that("rscimark", {
  y = rscimark(minimum.time = 0.2)
  expect_true(is.numeric(y))
  expect_true(length(y) == 6L)
  expect_true(!any(is.na(y) | is.nan(y)))
})
