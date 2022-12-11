class Baz():
    x = 43

    def __init__(self):
        self.thing1 = "thing"

    def get_x(self):
        return self.x

class Foo(Baz):
    x = 43

    def __init__(self):
        Baz.__init__(self)
        self.thing = "thing"

    def get_x(self):
        return self.x