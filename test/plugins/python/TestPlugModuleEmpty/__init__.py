# Copyright 2016 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
# Modified by Jeremy Retailleau.

from pxr import Plug
from plug_test import TestPlugBase3

# This plugin is coded correctly, but will have an empty plugInfo.json
class TestPlugPythonEmpty(TestPlugBase3):
    def GetTypeName(self):
        return 'TestPlugPythonEmpty'

