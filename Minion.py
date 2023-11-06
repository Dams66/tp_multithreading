class Minion:
    def __init__(self, taskID=None):
        if taskID is None:
            self.hasTask = False
        else:
            self.taskID = taskID
            self.hasTask = True
