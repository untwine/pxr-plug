// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <pxr/plug/testPlugBase.h>

namespace pxr {

// This plugin is coded correctly, but will be incomplete
// because it won't have a plugInfo.json
class TestPlugIncomplete : public _TestPlugBase1 {
  public:
    typedef TestPlugIncomplete This;
    typedef TfRefPtr<This> RefPtr;
    typedef TfWeakPtr<This> Ptr;

    virtual ~TestPlugIncomplete() {}

    virtual std::string GetTypeName() { return "TestPlugIncomplete"; }

    static RefPtr New() {
        return TfCreateRefPtr(new This());
    }

  protected:
    TestPlugIncomplete() {}
};

TF_REGISTRY_FUNCTION(pxr::TfType)
{
    TfType::Define<TestPlugIncomplete,
                   TfType::Bases<_TestPlugBase1> >()
        .SetFactory<_TestPlugFactory<TestPlugIncomplete> >()
        ;
}

}  // namespace pxr
