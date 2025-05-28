// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <plugTest/testPlugBase.h>

namespace pxr {

class TestPlugDerived2 : public TestPlugBase2 {
  public:
    typedef TestPlugDerived2 This;
    typedef TfRefPtr<This> RefPtr;
    typedef TfWeakPtr<This> Ptr;

    virtual ~TestPlugDerived2() {}

    virtual std::string GetTypeName() { return "TestPlugDerived2"; }

    static RefPtr New() {
        return TfCreateRefPtr(new This());
    }

  protected:
    TestPlugDerived2() {}
};

TF_REGISTRY_FUNCTION(pxr::TfType)
{
    TfType::Define<TestPlugDerived2,
                   TfType::Bases<TestPlugBase2> >()
        .SetFactory<_TestPlugFactory<TestPlugDerived2> >()
        ;
}

}  // namespace pxr
