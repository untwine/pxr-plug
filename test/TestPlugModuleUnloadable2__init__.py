# Copyright 2016 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.
#
# Modified by Jeremy Retailleau.

from pxr import Plug

class TestPlugPythonUnloadable2(Plug._TestPlugBase1):
    def GetTypeName(self):
        return 'TestPlugPythonUnloadable2'

