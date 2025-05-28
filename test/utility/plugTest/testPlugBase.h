// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// Modified by Jeremy Retailleau.

#ifndef PXR_PLUG_TEST_PLUG_BASE_H
#define PXR_PLUG_TEST_PLUG_BASE_H

#include <pxr/plug/api.h>
#include <pxr/tf/refBase.h>
#include <pxr/tf/stringUtils.h>
#include <pxr/tf/type.h>
#include <pxr/tf/weakBase.h>
#include <pxr/plug/plugin.h>

#include <string>

namespace pxr {

template <int M>
class TestPlugBase : public TfRefBase, public TfWeakBase {
  public:
    typedef TestPlugBase This;
    typedef TfRefPtr<This> RefPtr;
    typedef TfWeakPtr<This> Ptr;
    constexpr static int N = M;

    virtual ~TestPlugBase() {}

    virtual std::string GetTypeName() {
        return TfType::Find(this).GetTypeName();
    }

    static RefPtr New() {
        return TfCreateRefPtr(new This());
    }

    bool TestAcceptPluginSequence(const PlugPluginPtrVector &plugins) {
        return true;
    }

    PLUG_API
    static RefPtr Manufacture(const std::string & subclass);

  protected:
    TestPlugBase() {}
};

template <int N>
class _TestPlugFactoryBase : public TfType::FactoryBase {
public:
    virtual TfRefPtr<TestPlugBase<N> > New() const = 0;
};

template <typename T>
class _TestPlugFactory : public _TestPlugFactoryBase<T::N> {
public:
    virtual TfRefPtr<TestPlugBase<T::N> > New() const
    {
        return T::New();
    }
};

typedef TestPlugBase<1> TestPlugBase1;
typedef TestPlugBase<2> TestPlugBase2;
typedef TestPlugBase<3> TestPlugBase3;
typedef TestPlugBase<4> TestPlugBase4;

}  // namespace pxr

#endif // PXR_PLUG_TEST_PLUG_BASE_H
