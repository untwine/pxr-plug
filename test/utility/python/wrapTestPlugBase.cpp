// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <plugTest/testPlugBase.h>
#include <pxr/boost/python/def.hpp>
#include <pxr/boost/python/args.hpp>
#include <pxr/tf/makePyConstructor.h>
#include <pxr/tf/pyPtrHelpers.h>
#include <pxr/tf/pyContainerConversions.h>

#include <pxr/boost/python.hpp>

using namespace pxr;

using namespace pxr::boost::python;

namespace {

template <class T>
void wrapTestPlugBase(const std::string & name)
{
    typedef T This;
    typedef TfWeakPtr<T> ThisPtr;
    class_<This, ThisPtr, noncopyable> ( name.c_str(), no_init )
        .def(TfPyRefAndWeakPtr())
        .def(TfMakePyConstructor(&This::New))

        // Expose Manufacture as another initializer.
        .def(TfMakePyConstructor(&This::Manufacture))

        .def("GetTypeName", &This::GetTypeName)

        .def("TestAcceptPluginSequence", &This::TestAcceptPluginSequence,
             (arg("plugins")));

        ;
}

} // anonymous namespace 

void wrapTestPlugBase()
{
    wrapTestPlugBase<TestPlugBase1>("TestPlugBase1");
    wrapTestPlugBase<TestPlugBase2>("TestPlugBase2");
    wrapTestPlugBase<TestPlugBase3>("TestPlugBase3");
    wrapTestPlugBase<TestPlugBase4>("TestPlugBase4");
}
