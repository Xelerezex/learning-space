class LoggableList(Loggable, list):
    def append(self, arg):
        super(LoggableList, self).append(arg)
        self.log(arg)
