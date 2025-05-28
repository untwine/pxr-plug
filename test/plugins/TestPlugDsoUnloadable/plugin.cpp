// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#include <plugTest/testPlugBase.h>
#include <pxr/tf/tf.h>

// This plugin depends on an undefined external function and so will be
// unloadable.  That's the whole point of this test.
//
// If you see an unresolved external symbol build error on Windows about
// this symbol, please do as the symbol says and ignore the error.  The
// link was successful, it just reported the error anyway.
extern int Unresolved_external_symbol_error_is_expected_Please_ignore();

namespace pxr {

static int something =
    Unresolved_external_symbol_error_is_expected_Please_ignore();

class TestPlugUnloadable : public TestPlugBase1 {
  public:
    typedef TestPlugUnloadable This;
    typedef TfRefPtr<This> RefPtr;
    typedef TfWeakPtr<This> Ptr;

    virtual ~TestPlugUnloadable() {}

    virtual std::string GetTypeName() { return "TestPlugUnloadable"; }

    static RefPtr New() {
        return TfCreateRefPtr(new This());
    }

  protected:
    TestPlugUnloadable() {}
};

TF_REGISTRY_FUNCTION(pxr::TfType)
{
    // Ensure that the static something gets "used" to avoid compiler
    // warnings.
    TF_UNUSED(something);

    TfType::Define<TestPlugUnloadable,
                   TfType::Bases<TestPlugBase1> >()
        .SetFactory<_TestPlugFactory<TestPlugUnloadable> >()
        ;
}

}  // namespace pxr
