# Copyright 2016 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
# Modified by Jeremy Retailleau.

from pxr import Plug, Tf
from plug_test import TestPlugBase1

class TestPlugPythonDerived1(TestPlugBase1):
    def GetTypeName(self):
        return 'TestPlugModule1.TestPlugPythonDerived1'

Tf.Type.Define(TestPlugPythonDerived1)
