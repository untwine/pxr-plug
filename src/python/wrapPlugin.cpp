// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/plug/plugin.h>
#include <pxr/js/converter.h>
#include <pxr/tf/pyContainerConversions.h>
#include <pxr/tf/pyPtrHelpers.h>
#include <pxr/tf/pyResultConversions.h>
#include <pxr/tf/iterator.h>

#include <pxr/boost/python.hpp>
#include <string>

using std::string;
using std::vector;

using namespace pxr;

using namespace pxr::boost::python;

namespace {

static dict
_ConvertDict( const JsObject & dictionary )
{
    dict result;
    TF_FOR_ALL(i, dictionary) {
        const string & key = i->first;
        const JsValue & val = i->second;

        result[key] = JsConvertToContainerType<object, dict>(val);
    }
    return result;
}

static dict
_GetMetadata(PlugPluginPtr plugin)
{
    return _ConvertDict(plugin->GetMetadata());
}

static dict
_GetMetadataForType(PlugPluginPtr plugin, const TfType &type)
{
    return _ConvertDict(plugin->GetMetadataForType(type));
}

} // anonymous namespace 

void wrapPlugin()
{
    typedef PlugPlugin This;
    typedef PlugPluginPtr ThisPtr;

    class_<This, ThisPtr, noncopyable> ( "Plugin", no_init )
        .def(TfPyWeakPtr())
        .def("Load", &This::Load)

        .add_property("isLoaded", &This::IsLoaded)
        .add_property("isPythonModule", &This::IsPythonModule)
        .add_property("isResource", &This::IsResource)

        .add_property("metadata", _GetMetadata)

        .add_property("name",
                      make_function(&This::GetName,
                                    return_value_policy<return_by_value>()))
        .add_property("path",
                      make_function(&This::GetPath,
                                    return_value_policy<return_by_value>()))
        .add_property("resourcePath",
                      make_function(&This::GetResourcePath,
                                    return_value_policy<return_by_value>()))

        .def("GetMetadataForType", _GetMetadataForType)
        .def("DeclaresType", &This::DeclaresType,
             (arg("type"), 
              arg("includeSubclasses") = false))

        .def("MakeResourcePath", &This::MakeResourcePath)
        .def("FindPluginResource", &This::FindPluginResource,
             (arg("path"), 
              arg("verify") = true))
        ;
        TfPyRegisterStlSequencesFromPython<PlugPluginPtr>();

    // The call to JsConvertToContainerType in _ConvertDict creates
    // vectors of pxr::boost::python::objects for array values, so register
    // a converter that turns that vector into a Python list.
    pxr::boost::python::to_python_converter<std::vector<object>,
        TfPySequenceToPython<std::vector<object> > >();
}
