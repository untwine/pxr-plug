//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//

#include <pxr/plug/pxr.h>
#include <plugTest/testPlugBase.h>

PLUG_NAMESPACE_OPEN_SCOPE

class TestPlugDerived1 : public TestPlugBase1 {
  public:
    typedef TestPlugDerived1 This;
    typedef TfRefPtr<This> RefPtr;
    typedef TfWeakPtr<This> Ptr;

    virtual ~TestPlugDerived1() {}

    virtual std::string GetTypeName() { return "TestPlugDerived1"; }

    static RefPtr New() {
        return TfCreateRefPtr(new This());
    }

  protected:
    TestPlugDerived1() {}
};

TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<TestPlugDerived1,
                   TfType::Bases<TestPlugBase1> >()
        .SetFactory<_TestPlugFactory<TestPlugDerived1> >()
        ;
}

PLUG_NAMESPACE_CLOSE_SCOPE
