#ifndef __VECTOR4_HPP
#define __VECTOR4_HPP

#include "builtin.hpp"

using namespace __shedskin__;
namespace __Vector4__ {


class Vector4;


extern Vector4 *v;
extern str *__name__;

extern class_ *cl_Vector4;
class Vector4 : public pyobj {
public:
    Vector4() { this->__class__ = cl_Vector4; }
    PyObject *__to_py__();
};

void __init();

} // module namespace
#endif
