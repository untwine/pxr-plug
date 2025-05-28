// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include "./testPlugBase.h"
#include <pxr/plug/registry.h>
#include <pxr/tf/diagnostic.h>
#include <pxr/tf/type.h>
#include <pxr/tf/stringUtils.h>
#include <pxr/tf/type.h>

namespace pxr {

template <int N>
TfRefPtr< TestPlugBase<N> >
TestPlugBase<N>::Manufacture(const std::string & subclass)
{
    // Lookup TfType for subclass
    const TfType & t = PlugRegistry::FindTypeByName(subclass);
    if (t.IsUnknown()) {
        TF_CODING_ERROR("Failed to find TfType for %s", subclass.c_str());
        return TfNullPtr;
    }

    // Manufacture an instance.
    if (_TestPlugFactoryBase<N>* factory =
            t.GetFactory<_TestPlugFactoryBase<N> >()) {
        return factory->New();
    }

    return TfNullPtr;
}

// XXX -- These shouldn't be in the library or used by the Python module.
template class TestPlugBase<1>;
template class TestPlugBase<2>;
template class TestPlugBase<3>;
template class TestPlugBase<4>;

// This derived class should be discovered as an available subclass
// of TestPlugBase1 even though it is compiled into the base library.
class _TestPlugDerived0 : public TestPlugBase1 {
  public:
    typedef _TestPlugDerived0 This;
    typedef TfRefPtr<This> RefPtr;
    typedef TfWeakPtr<This> Ptr;

    virtual ~_TestPlugDerived0() {}

    // Return our base type, since this class is not wrapped for Python.
    static TfRefPtr<TestPlugBase1> New() {
        return TfCreateRefPtr(new This());
    }

  protected:
    _TestPlugDerived0() {}
};

TF_REGISTRY_FUNCTION(pxr::TfType)
{
    TfType::Define< TestPlugBase1 >()
        .SetFactory<_TestPlugFactory<TestPlugBase1> >();
    TfType::Define< TestPlugBase2 >()
        .SetFactory<_TestPlugFactory<TestPlugBase2> >();
    TfType::Define< TestPlugBase3 >()
        .SetFactory<_TestPlugFactory<TestPlugBase3> >();
    TfType::Define< TestPlugBase4 >()
        .SetFactory<_TestPlugFactory<TestPlugBase4> >();

    TfType::Define< _TestPlugDerived0, TfType::Bases<TestPlugBase1> >()
        .SetFactory<_TestPlugFactory<_TestPlugDerived0> >();
}

}  // namespace pxr
