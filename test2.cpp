#include "test2.hpp"

namespace __test2__ {

str *const_0;

Vector4 *v;
str *__name__;


Vector4 *test2(Vector4 *v) {
    
    print2(0,1, const_0);
    return v;
}

void __init() {
    const_0 = new str("ok2");

    __name__ = new str("test2");

    v = test2((new Vector4()));
}

} // module namespace

/* extension module glue */

extern "C" {
#include <Python.h>
#include <structmember.h>

namespace __test2__ { /* XXX */

PyObject *Global_test2(PyObject *self, PyObject *args, PyObject *kwargs) {
    try {
        Vector4 *arg_0 = __ss_arg<Vector4 *>("v", 0, 0, NULL, args, kwargs);

        return __to_py(__test2__::test2(arg_0));

    } catch (Exception *e) {
        PyErr_SetString(__to_py(e), ((e->msg)?(e->msg->unit.c_str()):""));
        return 0;
    }
}

static PyNumberMethods Global_test2_as_number = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

static PyMethodDef Global_test2Methods[] = {
    {(char *)"test2", (PyCFunction)Global_test2, METH_VARARGS | METH_KEYWORDS, (char *)""},
    {NULL}
};

PyMODINIT_FUNC inittest2(void) {
    //__shedskin__::__init();
    PyImport_ImportModule("Vector4");
    //__Vector4__::__init();
    __test2__::__init();

    PyObject *mod = Py_InitModule((char *)"test2", Global_test2Methods);
    if(!mod)
        return;


    PyModule_AddObject(mod, (char *)"v", __to_py(__test2__::v));

}

} // namespace __test2__

} // extern "C"
