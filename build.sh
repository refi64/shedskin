#!/bin/sh
shedskin -e -m Vector4.make Vector4 && make -f Vector4.make
shedskin -e -m test1.make test1 && make -f test1.make
shedskin -e -m test2.make test2 && make -f test2.make
