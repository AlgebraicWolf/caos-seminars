#!/usr/bin/env python

import os

print(os.read(4, 10000000).decode('utf-8'))
