#ifndef QLNET_NODEOUTPUT_H_
#define QLNET_NODEOUTPUT_H_

#include <cstddef>
#include <cstdint>
#include <cmath>
#include <limits>

namespace qlnet {

/**
 * @brief The NodeOutput class
 * a reference wrapper around
 * the Nodes' response value
 */
template<typename T>
class NodeOutput
{
public:
    inline NodeOutput(const T& value_ref) noexcept;
    NodeOutput(T&&) = delete;
    NodeOutput(const NodeOutput&) noexcept = default;
    NodeOutput& operator=(const NodeOutput&) noexcept = default;

    operator const T&() const noexcept;
private:
    const T* value_ptr_;
};

template<typename T>
using NodeInput = NodeOutput<T>;

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

        static T derivative(T /*x*/) {
            return 1;
        }

        constexpr T min() const {
            return std::numeric_limits<T>::has_infinity
                    ? -std::numeric_limits<T>::infinity()
                    : std::numeric_limits<T>::min();
        }

        constexpr T max() const {
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

        constexpr T min() const {
            return std::numeric_limits<T>::has_infinity
                    ? -std::numeric_limits<T>::infinity()
                    : std::numeric_limits<T>::min();
        }

        constexpr T max() const {
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
            return 1 / ( 1 + std::exp(-param_value() * net));
        }

        static T derivative(T x) {
            T fx = eval(x);
            return param_value() * fx * (1 - fx);
        }

        constexpr T min() const {
            return 0;
        }

        constexpr T max() const {
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

        constexpr T min() const {
            return -1;
        }

        constexpr T max() const {
            return 1;
        }
    };

    class BinaryStep
    {
    public:
        static T eval(T net) {
            return net < 0 ? 0 : 1;
        }

        static T derivative(T x) {
            T fx = eval(x);
            return param_value() * (1 - fx * fx);
        }

        constexpr T min() const {
            return 0;
        }

        constexpr T max() const {
            return 1;
        }
    };

    class UnipolarStep
    {
    public:
        static T eval(T net) {
            return net < param_value() ? 0 : 1;
        }

        static T derivative(T x) {
            T fx = eval(x);
            return param_value() * (1 - fx * fx);
        }

        constexpr T min() const {
            return 0;
        }

        constexpr T max() const {
            return 1;
        }
    };

    class BipolarStep
    {
    public:
        static T eval(T net) {
            return net < param_value() ? -1 : 1;
        }

        static T derivative(T x) {
            T fx = eval(x);
            return param_value() * (1 - fx * fx);
        }

        constexpr T min() const {
            return -1;
        }

        constexpr T max() const {
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

#endif // QLNET_NODEOUTPUT_H_
