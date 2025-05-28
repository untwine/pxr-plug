# Copyright 2016 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
# Modified by Jeremy Retailleau.

from pxr import Plug, Tf
from plug_test import TestPlugBase2

class TestPlugPythonDerived2(TestPlugBase2):
    def GetTypeName(self):
        return 'TestPlugModule2.TestPlugPythonDerived2'

Tf.Type.Define(TestPlugPythonDerived2)
