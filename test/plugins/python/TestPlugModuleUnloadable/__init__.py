# Copyright 2016 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
# Modified by Jeremy Retailleau.

from pxr import Plug
from plug_test import TestPlugBase1

# This plugin depends on an undefined external function
# and so will be unloadable.
something = TestPlugDoSomethingUndefined()

class TestPlugPythonUnloadable(TestPlugBase1):
    def GetTypeName(self):
        return 'TestPlugPythonUnloadable'

