//
//  gemm.hpp
//  framework
//
//  Created by Admin on 2019/12/2.
//  Copyright © 2019 Admin. All rights reserved.
//

#ifndef gemm_hpp
#define gemm_hpp

#include <stdio.h>
#include <vector>

namespace framework{


void gemm(int TA, int TB, int M, int N, int K, float ALPHA,
          float *A, int lda,
          float *B, int ldb,
          float BETA,
          float *C, int ldc);


void axpy_cpu(int N, float ALPHA, float *X, int INCX,
              float *Y, int INCY);


void scal_cpu(int N, float ALPHA, float *X, int INCX);

void fill_cpu(int N, float ALPHA, float *X, int INCX);


} // namespace framework

#endif /* gemm_hpp */
