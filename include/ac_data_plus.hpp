#pragma once

class ac_base_type
{
}; // base class for ac_int ac_fixed ac_channel ac_complex ac_float

template <typename T>
struct is_ac_type : std::is_base_of<ac_base_type, T>
{
};

template <typename T>
struct is_ac_type_helper :
    std::conditional<
        is_ac_type<T>::value,
        typename T::is_ac_basic_type,
        std::false_type
    >::type
{
};

template <typename T>
struct is_ac_basic_type :
    std::conditional<
        std::is_class<T>::value,
        is_ac_type_helper<T>,
        std::false_type
    >::type
{
};
