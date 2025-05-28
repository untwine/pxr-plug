# Copyright 2016 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
# Modified by Jeremy Retailleau.

from pxr import Plug
from plug_test import TestPlugBase1

# This plugin is coded correctly, but will have a pluginfo.json in a
# unicode path
class TestPlugPythonUnicode(TestPlugBase1):
    def GetTypeName(self):
        return 'TestPlugPythonUnicode'

