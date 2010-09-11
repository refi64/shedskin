#include "test1.hpp"

namespace __test1__ {

str *const_0;

Vector4 *v;
str *__name__;


Vector4 *test1(Vector4 *v) {
    
    print2(0,1, const_0);
    return v;
}

void __init() {
    const_0 = new str("ok1");

    __name__ = new str("test1");

    v = test1((new Vector4()));
}

} // module namespace

/* extension module glue */

extern "C" {
#include <Python.h>
#include <structmember.h>

namespace __test1__ { /* XXX */

PyObject *Global_test1(PyObject *self, PyObject *args, PyObject *kwargs) {
    try {
        Vector4 *arg_0 = __ss_arg<Vector4 *>("v", 0, 0, NULL, args, kwargs);

        return __to_py(__test1__::test1(arg_0));

    } catch (Exception *e) {
        PyErr_SetString(__to_py(e), ((e->msg)?(e->msg->unit.c_str()):""));
        return 0;
    }
}

static PyNumberMethods Global_test1_as_number = {
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

static PyMethodDef Global_test1Methods[] = {
    {(char *)"test1", (PyCFunction)Global_test1, METH_VARARGS | METH_KEYWORDS, (char *)""},
    {NULL}
};

PyMODINIT_FUNC inittest1(void) {
    printf("init t1\n");
    __shedskin__::__init();
    PyImport_ImportModule("Vector4");
    //__Vector4__::__init();
    __test1__::__init();

    PyObject *mod = Py_InitModule((char *)"test1", Global_test1Methods);
    if(!mod)
        return;


    PyModule_AddObject(mod, (char *)"v", __to_py(__test1__::v));

}

} // namespace __test1__

} // extern "C"
