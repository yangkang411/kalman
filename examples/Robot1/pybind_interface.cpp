#include <string>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include "SystemModel.hpp"

namespace rb = KalmanExamples::Robot1;
typedef float T;
typedef rb::State<T> State;

class _State {
  private:
      Eigen::Vector3f m_data;

  public:
      _State(const Eigen::Vector3f& state) : m_data(state) { }
      Eigen::Vector3f get() const { return m_data; }
      void set(const Eigen::Vector3f& _state) { m_data = _state; }
      std::string repr() const {
          return "state data: [x=" + std::to_string(m_data[0]) + ", y=" + std::to_string(m_data[1]) + ", theta=" + std::to_string(m_data[2]) + "]";
      }
};

namespace py = pybind11;

PYBIND11_MODULE(example_robot1_pybind, m) {
    m.doc() = "python bindings for Example1";
    py::class_<_State>(m, "_State")
        .def(py::init<Eigen::Vector3f>())
        .def_property("m_data", &_State::get, &_State::set)
        .def("__repr__", &_State::repr);
}
