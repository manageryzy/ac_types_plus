#pragma once

#include <bitset>

struct ac_convert
{
    template <int W, typename Ty_ac, typename Ty_target = Ty_ac>
    union internal_convert
    {
        Ty_ac convert_ac_val;
        Ty_target convert_target;
        std::bitset<W> convert_bitset;

        internal_convert()
            : convert_ac_val(0)
        {
        }
    };

    template <int W, bool S>
    constexpr static std::bitset<W> to_bitset(const ac_int<W, S> &ref)
    {
        internal_convert<W, ac_int<W, S>> cov;
        cov.convert_ac_val = ref;
        return cov.convert_bitset;
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    constexpr static std::bitset<W> to_bitset(const ac_fixed<W, I, S, Q, O> &ref)
    {
        internal_convert<W, ac_fixed<W, I, S, Q, O>> cov;
        cov.convert_ac_val = ref;
        return cov.convert_bitset;
    }

    template <int W, int I, int E, ac_q_mode Q>
    constexpr static std::bitset<W> to_bitset(const ac_float<W, I, E, Q> &ref)
    {
        internal_convert<W, ac_float<W, I, E, Q>> cov;
        cov.convert_ac_val = ref;
        return cov.convert_bitset;
    }

    template <int W, bool S>
    constexpr static std::bitset<2 * W> to_bitset(const ac_complex<ac_int<W, S>> &ref)
    {
        internal_convert<W * 2, ac_complex<ac_int<W, S>>> cov;

        cov.convert_ac_val     = ref.r();
        std::bitset<2 * W> res = cov.convert_bitset << W;
        cov.convert_ac_val     = ref.i();
        res |= cov.convert_bitset;

        return res;
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    constexpr static std::bitset<2 * W> to_bitset(const ac_complex<ac_fixed<W, I, S, Q, O>> &ref)
    {
        internal_convert<W * 2, ac_complex<ac_fixed<W, I, S, Q, O>>> cov;

        cov.convert_ac_val     = ref.r();
        std::bitset<2 * W> res = cov.convert_bitset << W;
        cov.convert_ac_val     = ref.i();
        res |= cov.convert_bitset;

        return res;
    }

    template <int W, int I, int E, ac_q_mode Q>
    constexpr static std::bitset<2 * W> to_bitset(const ac_complex<ac_float<W, I, E, Q>> &ref)
    {
        internal_convert<W * 2, ac_complex<ac_float<W, I, E, Q>>> cov;

        cov.convert_ac_val     = ref.r();
        std::bitset<2 * W> res = cov.convert_bitset << W;
        cov.convert_ac_val     = ref.i();
        res |= cov.convert_bitset;

        return res;
    }

    template <int W, bool S>
    constexpr static ac_int<W, false> to_ac_int(const ac_int<W, S> &ref)
    {
        internal_convert<W, ac_int<W, S>, ac_int<W, false>> cov;
        cov.convert_ac_val = ref;
        return cov.convert_bitset;
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    constexpr static ac_int<W, false> to_ac_int(const ac_fixed<W, I, S, Q, O> &ref)
    {
        internal_convert<W, ac_fixed<W, I, S, Q, O>, ac_int<W, false>> cov;
        cov.convert_ac_val = ref;
        return cov.convert_bitset;
    }

    template <int W, int I, int E, ac_q_mode Q>
    constexpr static ac_int<W, false> to_ac_int(const ac_float<W, I, E, Q> &ref)
    {
        internal_convert<W, ac_float<W, I, E, Q>, ac_int<W, false>> cov;
        cov.convert_ac_val = ref;
        return cov.convert_bitset;
    }

    template <int W, bool S>
    constexpr static ac_int<W * 2, false> to_ac_int(const ac_complex<ac_int<W, S>> &ref)
    {
        internal_convert<W * 2, ac_complex<ac_int<W, S>>, ac_int<W * 2, false>> cov;

        cov.convert_ac_val     = ref.r();
        std::bitset<2 * W> res = cov.convert_bitset << W;
        cov.convert_ac_val     = ref.i();
        res |= cov.convert_bitset;

        return res;
    }

    template <int W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    constexpr static ac_int<W * 2, false> to_ac_int(const ac_complex<ac_fixed<W, I, S, Q, O>> &ref)
    {
        internal_convert<W * 2, ac_complex<ac_fixed<W, I, S, Q, O>>, ac_int<W * 2, false>> cov;

        cov.convert_ac_val     = ref.r();
        std::bitset<2 * W> res = cov.convert_bitset << W;
        cov.convert_ac_val     = ref.i();
        res |= cov.convert_bitset;

        return res;
    }

    template <int W, int I, int E, ac_q_mode Q>
    constexpr static ac_int<W * 2, false> to_ac_int(const ac_complex<ac_float<W, I, E, Q>> &ref)
    {
        internal_convert<W * 2, ac_complex<ac_float<W, I, E, Q>>, ac_int<W * 2, false>> cov;

        cov.convert_ac_val     = ref.r();
        std::bitset<2 * W> res = cov.convert_bitset << W;
        cov.convert_ac_val     = ref.i();
        res |= cov.convert_bitset;

        return res;
    }

    template <size_t W>
    constexpr static ac_int<W, false> to_ac_int(const std::bitset<W> &ref)
    {
        internal_convert<static_cast<int>(W), ac_int<W, false>> cov;
        cov.convert_bitset = ref;
        return cov.convert_target;
    }

    template <size_t W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    constexpr static ac_fixed<W, I, S, Q, O> to_ac_fixed(const std::bitset<W> &ref)
    {
        internal_convert<static_cast<int>(W), ac_fixed<W, I, S, Q, O>> cov;
        cov.convert_bitset = ref;
        return cov.convert_target;
    }

    template <size_t W, int I, int E, ac_q_mode Q>
    constexpr static ac_float<W, I, E, Q> to_ac_float(const std::bitset<W> &ref)
    {
        internal_convert<static_cast<int>(W), ac_float<W, I, E, Q>> cov;
        cov.convert_bitset = ref;
        return cov.convert_target;
    }

    template <size_t W, int I, bool S, ac_q_mode Q, ac_o_mode O>
    constexpr static ac_fixed<W, I, S, Q, O> to_ac_fixed(const ac_int<W, false> &ref)
    {
        internal_convert<static_cast<int>(W), ac_int<W, false>, ac_fixed<W, I, S, Q, O>> cov;
        cov.convert_ac_val = ref;
        return cov.convert_target;
    }

    template <size_t W, int I, int E, ac_q_mode Q>
    constexpr static ac_float<W, I, E, Q> to_ac_float(const ac_int<W, false> &ref)
    {
        internal_convert<static_cast<int>(W), ac_int<W, false>, ac_float<W, I, E, Q>> cov;
        cov.convert_ac_val = ref;
        return cov.convert_target;
    }
};

template <size_t W>
constexpr std::bitset<W * 2> join_bitset(const std::bitset<W> &ref1, const std::bitset<W> &ref2)
{
    ac_int<static_cast<int>(W) * 2, false> res;
    res.set_slc(0, ac_convert::to_ac_int(ref2));
    res.set_slc(static_cast<int>(W), ac_convert::to_ac_int(ref1));

    return ac_convert::to_bitset(res);
}
