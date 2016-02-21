#ifndef QLNET_TRANSFERFUNC_H_
#define QLNET_TRANSFERFUNC_H_

#include <cstdint>
#include <cmath>
#include <limits>

namespace qlnet {

template<typename T, std::intmax_t ParamNum = 1, std::intmax_t ParamDen = 1>
class TransferFunc
{
public:
    constexpr static T param_value() {
        return ParamDen == 0 ? (T)ParamNum : (T)ParamNum / (T)ParamDen;
    }

    class Identity
    {
    public:
        static T eval(T net) {
            return net;
        }

        static T derivative(T) {
            return 1;
        }

        static constexpr T min() {
            return std::numeric_limits<T>::has_infinity
                    ? -std::numeric_limits<T>::infinity()
                    : std::numeric_limits<T>::min();
        }

        static constexpr T max() {
            return std::numeric_limits<T>::has_infinity
                    ? -std::numeric_limits<T>::infinity()
                    : std::numeric_limits<T>::max();
        }
    };

    class Linear
    {
    public:
        static T eval(T net) {
            return net * param_value();
        }

        static T derivative(T /*x*/) {
            return 1;
        }

        static constexpr T min() {
            return std::numeric_limits<T>::has_infinity
                    ? -std::numeric_limits<T>::infinity()
                    : std::numeric_limits<T>::min();
        }

        static constexpr T max() {
            return std::numeric_limits<T>::has_infinity
                    ? -std::numeric_limits<T>::infinity()
                    : std::numeric_limits<T>::max();
        }
    };

    class DHamming
    {
    public:
        static T eval(T net) {
            return (net + param_value()) / (2 * param_value());
        }
    };

    class SigmoidalUnipolar
    {
    public:
        static T eval(T net) {
            return max() / ( 1 + std::exp(-param_value() * net));
        }

        static T derivative(T x) {
            T fx = eval(x);
            return param_value() * fx * (1 - fx);
        }

        static constexpr T min() {
            return 0;
        }

        static constexpr T max() {
            return 1;
        }
    };

    class SigmoidalBipolar
    {
    public:
        static T eval(T net) {
            return (1 - std::exp(param_value() * net)) / (1 + std::exp(-param_value() * net));
        }

        static T derivative(T x) {
            T fx = eval(x);
            return param_value() * (1 - fx * fx);
        }

        static constexpr T min() {
            return -1;
        }

        static constexpr T max() {
            return 1;
        }
    };

    class BinaryStep
    {
    public:
        static T eval(T net) {
            return net < min() ? min() : max();
        }

        static T derivative(T x) {
            T fx = eval(x);
            return param_value() * (1 - fx * fx);
        }

        static constexpr T min() {
            return 0;
        }

        static constexpr T max() {
            return 1;
        }
    };

    class UnipolarStep
    {
    public:
        static T eval(T net) {
            return net < param_value() ? min() : max();
        }

        static T derivative(T x) {
            T fx = eval(x);
            return param_value() * (1 - fx * fx);
        }

        static constexpr T min() {
            return 0;
        }

        static constexpr T max() {
            return 1;
        }
    };

    class BipolarStep
    {
    public:
        static T eval(T net) {
            return net < param_value() ? min() : max();
        }

        static T derivative(T x) {
            T fx = eval(x);
            return param_value() * (1 - fx * fx);
        }

        static constexpr T min() {
            return -1;
        }

        static constexpr T max() {
            return 1;
        }
    };
};

#if 0
// TODO: these transfer functions need a revisit
double Node::tangensoidal() {
  return tanh(_param * _potential / 2) * (1 - exp(-_param * _potential)) / (1 + exp(-_param * _potential));
}
double Node::signum() {
  return _potential > 0 ? 1 : -1;
}
#endif //0

} // namespace qlnet

#endif // QLNET_TRANSFERFUNC_H_

