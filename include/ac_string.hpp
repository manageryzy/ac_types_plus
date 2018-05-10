#pragma once

#include <string>
#include <iostream>
#include <bitset>

template <class _Elem,
          class _Traits = std::char_traits<_Elem>,
          class _Alloc = std::allocator<_Elem>>
class ac_hex_basic_string : public std::basic_string<_Elem, _Traits, _Alloc>
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

    void adjust()
    {
        this->erase(remove(this->begin(), this->end(), ' '), this->end());
        this->erase(remove(this->begin(), this->end(), '_'), this->end());
        this->erase(remove(this->begin(), this->end(), '-'), this->end());
        this->erase(remove(this->begin(), this->end(), 'h'), this->end());
        this->erase(remove(this->begin(), this->end(), 'H'), this->end());
        if (this->substr(0, 2) == "0x")
            this->erase(0, 2);
    }

    template <int W, bool S>
    ac_hex_basic_string(const ac_int<W, S>& ref)
    {
        operator=(to_hex_string(ref));
        adjust();
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    ac_hex_basic_string(const ac_fixed<W, I, S, Q, O>& ref)
    {
        operator=(to_hex_string(ref));
        adjust();
    }

    template <int W, int I, int E, ac_q_mode Q>
    ac_hex_basic_string(const ac_float<W, I, E, Q>& ref)
    {
        operator=(to_hex_string(ref));
        adjust();
    }

    template <int W, bool S>
    ac_hex_basic_string(const ac_complex<ac_int<W, S>>& ref)
    {
        operator=(to_hex_string(ref.r()) + to_hex_string(ref.i()));
        adjust();
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    ac_hex_basic_string(const ac_complex<ac_fixed<W, I, S, Q, O>>& ref)
    {
        operator=(to_hex_string(ref.r()) + to_hex_string(ref.i()));
        adjust();
    }

    template <int W, int I, int E, ac_q_mode Q>
    ac_hex_basic_string(const ac_complex<ac_float<W, I, E, Q>>& ref)
    {
        operator=(to_hex_string(ref.r()) + to_hex_string(ref.i()));
        adjust();
    }

    template <int W, int I, int E, ac_q_mode Q>
    ac_hex_basic_string(const ac_complex<ac_float<W, I, E, Q>>&& ref)
    {
        operator=(to_hex_string(ref.r()) + to_hex_string(ref.i()));
        adjust();
    }

    template <typename T>
    operator T()
    {
        adjust();
        T t;
        t.bit_fill_hex(this->c_str());
        return t;
    }

    template <typename T>
    operator const T&()
    {
        adjust();
        T t;
        t.bit_fill_hex(this->c_str());
        return t;
    }
};


using ac_hex_string = ac_hex_basic_string<char, std::char_traits<char>, std::allocator<char>>;
using ac_hex_wstring = ac_hex_basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>;
using ac_hex_u16string = ac_hex_basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>;
using ac_hex_u32string = ac_hex_basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>;

template <class _Elem,
          class _Traits = std::char_traits<_Elem>,
          class _Alloc = std::allocator<_Elem>>
class ac_bin_basic_string : public std::basic_string<_Elem, _Traits, _Alloc>
{
public:
    using std::basic_string<_Elem, _Traits, _Alloc>::basic_string;
    using std::basic_string<_Elem, _Traits, _Alloc>::operator=;

    void adjust()
    {
        this->erase(remove(this->begin(), this->end(), ' '), this->end());
        this->erase(remove(this->begin(), this->end(), '_'), this->end());
        this->erase(remove(this->begin(), this->end(), '-'), this->end());
        this->erase(remove(this->begin(), this->end(), 'b'), this->end());
        this->erase(remove(this->begin(), this->end(), 'B'), this->end());
    }

    template <typename Ty>
    static inline std::basic_string<_Elem, _Traits, _Alloc> to_bin_string(const Ty& ref)
    {
        auto bits = ac_convert::to_bitset(ref);

        return bits;
    }

    template <int W, bool S>
    ac_bin_basic_string(const ac_int<W, S>& ref)
    {
        operator=(to_bin_string(ref));
        adjust();
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    ac_bin_basic_string(const ac_fixed<W, I, S, Q, O>& ref)
    {
        operator=(to_bin_string(ref));
        adjust();
    }

    template <int W, int I, int E, ac_q_mode Q>
    ac_bin_basic_string(const ac_float<W, I, E, Q>& ref)
    {
        operator=(to_bin_string(ref));
        adjust();
    }

    template <int W, bool S>
    ac_bin_basic_string(const ac_complex<ac_int<W, S>>& ref)
    {
        operator=(to_bin_string(ref.r()) + to_bin_string(ref.i()));
        adjust();
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    ac_bin_basic_string(const ac_complex<ac_fixed<W, I, S, Q, O>>& ref)
    {
        operator=(to_bin_string(ref.r()) + to_bin_string(ref.i()));
        adjust();
    }

    template <int W, int I, int E, ac_q_mode Q>
    ac_bin_basic_string(const ac_complex<ac_float<W, I, E, Q>>& ref)
    {
        operator=(to_bin_string(ref.r()) + to_bin_string(ref.i()));
        adjust();
    }

    template <int W, int I, int E, ac_q_mode Q>
    ac_bin_basic_string(const ac_complex<ac_float<W, I, E, Q>>&& ref)
    {
        operator=(to_bin_string(ref.r()) + to_bin_string(ref.i()));
        adjust();
    }

    template <typename T>
    operator T()
    {
        adjust();

        std::bitset<T::width> bits{ *static_cast<std::basic_string<_Elem, _Traits, _Alloc>*>(this) };
        T t;
        t.bit_fill(ac_convert::to_ac_int(bits));
        return t;
    }

    template <typename T>
    operator const T&()
    {
        adjust();

        std::bitset<T::width> bits{ *static_cast<std::basic_string<_Elem, _Traits, _Alloc>*>(this) };
        T t;
        t.set_slc(0,ac_convert::to_ac_int(bits));
        return t;
    }
};


using ac_bin_string = ac_bin_basic_string<char, std::char_traits<char>, std::allocator<char>>;
using ac_bin_wstring = ac_bin_basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>;
using ac_bin_u16string = ac_bin_basic_string<char16_t, std::char_traits<char16_t>, std::allocator<char16_t>>;
using ac_bin_u32string = ac_bin_basic_string<char32_t, std::char_traits<char32_t>, std::allocator<char32_t>>;
