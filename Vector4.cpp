#include "Vector4.hpp"

namespace __Vector4__ {

Vector4 *v;
str *__name__;


/**
class Vector4
*/

class_ *cl_Vector4;

void __init() {
    __name__ = new str("Vector4");

    cl_Vector4 = new class_("Vector4", 45, 45);
    v = (new Vector4());
}

} // module namespace

