// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <plugTest/testPlugBase.h>

namespace pxr {

// This plugin is coded correctly, but will have an empty plugInfo.json
class TestPlugEmpty : public TestPlugBase3 {
  public:
    typedef TestPlugEmpty This;
    typedef TfRefPtr<This> RefPtr;
    typedef TfWeakPtr<This> Ptr;

    virtual ~TestPlugEmpty() {}

    virtual std::string GetTypeName() { return "TestPlugEmpty"; }

    static RefPtr New() {
        return TfCreateRefPtr(new This());
    }

  protected:
    TestPlugEmpty() {}
};

TF_REGISTRY_FUNCTION(pxr::TfType)
{
    TfType::Define<TestPlugEmpty,
                   TfType::Bases<TestPlugBase3> >()
        .SetFactory<_TestPlugFactory<TestPlugEmpty> >()
        ;
}

}  // namespace pxr
