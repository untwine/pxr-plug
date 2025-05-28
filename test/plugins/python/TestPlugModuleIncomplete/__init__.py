# Copyright 2016 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
# Modified by Jeremy Retailleau.

from pxr import Plug
from plug_test import TestPlugBase1

# This plugin is coded correctly, but will be incomplete
# because it won't have a plugInfo.json
class TestPlugPythonIncomplete(TestPlugBase1):
    def GetTypeName(self):
        return 'TestPlugPythonIncomplete'

