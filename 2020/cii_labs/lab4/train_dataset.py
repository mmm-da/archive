import numpy as np

div = {
    'input': np.array([
        0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0
    ]),
    'output': np.array([1.0, 0.0, 0.0, 0.0, 0.0, 0.0]),
}

minus = {
    'input': np.array([
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0
    ]),
    'output': np.array([0.0, 1.0, 0.0, 0.0, 0.0, 0.0])
}

mult = {
    'input': np.array([
        0, 0, 1, 0, 1, 0, 0,
        1, 0, 0, 1, 0, 0, 1,
        0, 1, 0, 1, 0, 1, 0,
        0, 0, 1, 1, 1, 0, 0,
        0, 1, 0, 1, 0, 1, 0,
        1, 0, 0, 1, 0, 0, 1,
        0, 0, 1, 0, 1, 0, 0
    ]),
    'output': np.array([0.0, 0.0, 1.0, 0.0, 0.0, 0.0])
}

plus = {
    'input': np.array([
        0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0
    ]),
    'output': np.array([0.0, 0.0, 0.0, 1.0, 0.0, 0.0])
}

proc = {
    'input': np.array([
        0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 1, 0,
        0, 1, 0, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 0, 0,
        0, 0, 1, 0, 0, 1, 0,
        0, 1, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 1, 0
    ]),
    'output': np.array([0.0, 0.0, 0.0, 0.0, 1.0, 0.0])
}

root = {
    'input': np.array([
        0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0,
        1, 1, 0, 0, 0, 1, 0,
        0, 0, 1, 0, 1, 0, 0,
        0, 0, 1, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 0, 0
    ]),
    'output': np.array([0.0, 0.0, 0.0, 0.0, 0.0, 1.0])
}

M = [div,minus,mult,plus,proc,root]