### How does the DevBoard handle received serial messages? How does this differ from the naïve approach?
It receives it by bytes instead of all at a time.

### What does `detached_callback` do? What would happen if it wasn't used?
detached callback is a decorator that creates a detached thread for a given function and executes them concurrently. If this is not used, the UI would freeze.

### What does `LockedSerial` do? Why is it _necessary_?
LockedSerial ensures that only one thread can access the serial port at a time, which prevents undefined behaviors.