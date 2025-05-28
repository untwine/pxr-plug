# Copyright 2016 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
# Modified by Jeremy Retailleau.

from pxr import Plug, Tf
from plug_test import TestPlugBase3, TestPlugBase4

class TestPlugPythonDerived3_3(TestPlugBase3):
    def GetTypeName(self):
        return 'TestPlugModule3.TestPlugPythonDerived3_3'
Tf.Type.Define(TestPlugPythonDerived3_3)

class TestPlugPythonDerived3_4(TestPlugBase4):
    def GetTypeName(self):
        return 'TestPlugModule3.TestPlugPythonDerived3_4'
Tf.Type.Define(TestPlugPythonDerived3_4)
