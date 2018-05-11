#pragma once

#include <cmath>

#define MATH_WRAPPER(NAME)\
template <typename T>\
inline double NAME(T X) noexcept\
{\
    static_assert(is_ac_basic_type<T>::value, "T must be ac basic type");\
    return NAME(X.to_double());\
}
#define MATH_WRAPPER_2(NAME)\
template <typename T,typename T2>\
inline double NAME(T X,T2 Y) noexcept\
{\
    static_assert(is_ac_basic_type<T>::value, "T must be ac basic type");\
    return NAME(X.to_double(),Y.to_double);\
}

#define MATH_WRAPPER_INT(NAME)\
template <typename T>\
inline double NAME(T X, int Y) noexcept\
{\
    static_assert(is_ac_basic_type<T>::value, "T must be ac basic type");\
    return NAME(X.to_double(),Y);\
}
MATH_WRAPPER(acos);
MATH_WRAPPER(acosh);
MATH_WRAPPER(asin);
MATH_WRAPPER(asinh);
MATH_WRAPPER(atan);
MATH_WRAPPER(atanh);
MATH_WRAPPER_2(atan2);
MATH_WRAPPER(cbrt);
MATH_WRAPPER(ceil);
MATH_WRAPPER_2(copysign);
MATH_WRAPPER(cos);
MATH_WRAPPER(cosh);
MATH_WRAPPER(erf);
MATH_WRAPPER(erfc);
MATH_WRAPPER(exp);
MATH_WRAPPER(exp2);
MATH_WRAPPER(expm1);
MATH_WRAPPER(fabs);
MATH_WRAPPER_2(fdim);
MATH_WRAPPER(floor);
MATH_WRAPPER_2(fma);
MATH_WRAPPER_2(fmax);
MATH_WRAPPER_2(fmin);
MATH_WRAPPER_2(fmod);
MATH_WRAPPER_2(frexp);
MATH_WRAPPER_2(hypot);
MATH_WRAPPER(ilogb);
MATH_WRAPPER_2(ldexp);
MATH_WRAPPER(lgamma);
MATH_WRAPPER(llrint);
MATH_WRAPPER(llround);
MATH_WRAPPER(log);
MATH_WRAPPER(log10);
MATH_WRAPPER(log1p);
MATH_WRAPPER(log2);
MATH_WRAPPER(logb);
MATH_WRAPPER(lrint);
MATH_WRAPPER(lround);
MATH_WRAPPER(nearbyint);
MATH_WRAPPER_2(nextafter);
MATH_WRAPPER_2(nexttoward);
MATH_WRAPPER_2(pow);
MATH_WRAPPER_2(remainder);
MATH_WRAPPER(rint);
MATH_WRAPPER(round);
MATH_WRAPPER_INT(scalbln);
MATH_WRAPPER(sin);
MATH_WRAPPER(sinh);
MATH_WRAPPER(sqrt);
MATH_WRAPPER(tan);
MATH_WRAPPER(tanh);
MATH_WRAPPER(tgamma);
MATH_WRAPPER(trunc);


#undef  MATH_WRAPPER
#undef MATH_WRAPPER_2
#undef MATH_WRAPPER_INT
