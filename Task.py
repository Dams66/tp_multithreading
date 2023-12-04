import json
import time

import numpy as np


class Task:
    def __init__(self, identifier, size=None):
        self.identifier = identifier
        # choosee the size of the problem
        self.size = size or np.random.randint(300, 3_000)
        # Generate the input of the problem
        self.a = np.random.rand(self.size, self.size)
        self.b = np.random.rand(self.size)
        # prepare room for the results
        self.x = np.zeros((self.size))
        self.time = 0

    def work(self):
        start = time.perf_counter()
        self.x = np.linalg.solve(self.a, self.b)
        self.time = time.perf_counter() - start

    def to_json(self) -> str:
        data = {
            "identifier": self.identifier,
            "size": self.size,
            "a": self.a.tolist(),
            "b": self.b.tolist(),
        }
        return json.dumps(data)

    @classmethod
    def from_json(cls, text: str) -> "Task":
        data = json.loads(text)
        task = cls(identifier=data["identifier"], size=data["size"])
        task.a = np.array(data["a"])
        task.b = np.array(data["b"])
        task.x = np.array(data["x"])
        task.time = data["time"]
        return task

    def __eq__(self, other: "Task") -> bool:
        if not isinstance(other, Task):
            return False

        are_basic_attrs_equal = (
            self.identifier == other.identifier
            and self.size == other.size
            and self.time == other.time
        )

        if not are_basic_attrs_equal:
            return False

        are_arrays_equal = (
            np.array_equal(self.a, other.a)
            and np.array_equal(self.b, other.b)
            and np.array_equal(self.x, other.x)
        )

        return are_arrays_equal
