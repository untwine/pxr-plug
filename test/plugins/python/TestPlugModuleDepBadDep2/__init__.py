#
# Copyright 2016 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
from pxr import Plug
from plug_test import TestPlugBase3

class TestPlugPythonDepBadDep2(TestPlugBase3):
    def GetTypeName(self):
        return 'TestPlugPythonDepBadDep2'

