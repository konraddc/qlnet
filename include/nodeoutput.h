#ifndef QLNET_NODEOUTPUT_H_
#define QLNET_NODEOUTPUT_H_

namespace  qlnet {

/**
 * @brief The NodeOutput class
 * a reference wrapper around
 * the Nodes' response value
 */
template<typename T>
class NodeOutput
{
public:
    inline NodeOutput(T& value_ref) noexcept;
    NodeOutput(T&&) = delete;
    NodeOutput(const NodeOutput&) noexcept = default;
    NodeOutput& operator=(const NodeOutput&) noexcept = default;

    inline operator T&() const noexcept;

    static T func_a(T v) { return v; }

private:
    T* value_ptr_;
};

template<typename T>
using NodeInput = NodeOutput<T>;

template<typename T, int Param = 0, int InputsCount = 0>
class HammingDistance
{

};
#if 0
double Node::dhamming() {
  double r = (_potential + _inputsCount) / (2 * _inputsCount);
  //         qDebug() << this << "potencial =" << potencial << endl << "dhamming" << r;
  return r;
}

double Node::unipolar() {
  return _potential > _param ? 1 : 0;
}

double Node::bipolar() {
  return _potential > _param ? 1 : -1;
}

double Node::sigmoidal() {
  return 1. / ( 1. + exp(-_param * _potential));
}

double Node::tangensoidal() {
  return tanh(_param * _potential / 2) * (1 - exp(-_param * _potential)) / (1 + exp(-_param * _potential));
}

double Node::signum() {
  return _potential > 0 ? 1 : -1;
}

double Node::linear() {
  return _param * _potential;
}

#endif //0
} // namespace  qlnet

#endif // QLNET_NODEOUTPUT_H_
