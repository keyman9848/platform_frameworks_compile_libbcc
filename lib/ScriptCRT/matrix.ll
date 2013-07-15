target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:64:128-a0:0:64-n32-S64"
target triple = "armv7-none-linux-gnueabi"


%struct.rs_matrix4x4 = type { [16 x float] }
%struct.rs_matrix3x3 = type { [9 x float] }
%struct.rs_matrix2x2 = type { [4 x float] }

define internal <4 x float> @smear_f(float %in) nounwind readnone alwaysinline {
  %1 = insertelement <4 x float> undef, float %in, i32 0
  %2 = insertelement <4 x float> %1, float %in, i32 1
  %3 = insertelement <4 x float> %2, float %in, i32 2
  %4 = insertelement <4 x float> %3, float %in, i32 3
  ret <4 x float> %4
}

