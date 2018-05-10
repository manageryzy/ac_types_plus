#pragma once

#include <string>
#include <iostream>
#include <bitset>

template <class _Elem,
          class _Traits = std::char_traits<_Elem>,
          class _Alloc = std::allocator<_Elem>>
class ac_hex_basic_string :public std::basic_string<_Elem, _Traits, _Alloc>
{
public:
    using std::basic_string<_Elem, _Traits, _Alloc>::basic_string;
    using std::basic_string<_Elem, _Traits, _Alloc>::operator=;

    template <typename Ty>
    static inline std::basic_string<_Elem, _Traits, _Alloc> to_hex_string(const Ty& ref)
    {
        auto const _Bits = ref.width;
        auto bits        = ac_convert::to_bitset(ref);

        const size_t num = (_Bits + 3) / 4;
        std::basic_ostringstream<_Elem, _Traits, _Alloc> ss;

        for (size_t i = num; i != 0; --i)
        {
            auto start = i * 4;
            if (start > _Bits)
                start = _Bits;

            const int end = (i - 1) * 4;

            auto buf   = 0;
            for (int j = start - 1; j >= end; --j)
            {
                buf <<= 1;
                buf |= bits.test(j);
            }

            ss << std::hex << buf;
        }

        return ss.str();
    }

    template <int W, bool S>
    ac_hex_basic_string(const ac_int<W, S>& ref)
    {
        operator=(to_hex_string(ref));
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    ac_hex_basic_string(const ac_fixed<W, I, S, Q, O>& ref)
    {
        operator=(to_hex_string(ref));
    }

    template <int W, int I, int E, ac_q_mode Q>
    ac_hex_basic_string(const ac_float<W, I, E, Q>& ref)
    {
        operator=(to_hex_string(ref));
    }

    template <int W, bool S>
    ac_hex_basic_string(const ac_complex<ac_int<W, S>>& ref)
    {
        operator=(to_hex_string(ref.r()) + to_hex_string(ref.i()));
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    ac_hex_basic_string(const ac_complex<ac_fixed<W, I, S, Q, O>>& ref)
    {
        operator=(to_hex_string(ref.r()) + to_hex_string(ref.i()));
    }

    template <int W, int I, int E, ac_q_mode Q>
    ac_hex_basic_string(const ac_complex<ac_float<W, I, E, Q>>& ref)
    {
        operator=(to_hex_string(ref.r()) + to_hex_string(ref.i()));
    }

    template <int W, int I, int E, ac_q_mode Q>
    ac_hex_basic_string(const ac_complex<ac_float<W, I, E, Q>>&& ref)
    {
        operator=(to_hex_string(ref.r()) + to_hex_string(ref.i()));
    }

    template <typename T>
    operator T() const
    {
        T t;
        t.bit_fill_hex(this->c_str());
        return t;
    }

    template <typename T>
    operator const T&() const
    {
        T t;
        t.bit_fill_hex(this->c_str());
        return t;
    }
};


using ac_hex_string = ac_hex_basic_string<char, std::char_traits<char>, std::allocator<char>>;
using ac_hex_wstring = ac_hex_basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>;
using ac_hex_u16string = ac_hex_basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>;
using ac_hex_u32string = ac_hex_basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>;

