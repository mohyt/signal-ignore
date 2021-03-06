# signal-ignore

NodeJS extension to set SIG_IGN as handler for a given signal.

When a handler is set to SIG_IGN, the behavior of that handler is inherited within sub-processes
created by execve:

From - http://man7.org/linux/man-pages/man7/signal.7.html

> A child created via fork(2) inherits a copy of its parent's signal
> dispositions. During an execve(2), the dispositions of handled
> signals are reset to the default; the dispositions of ignored signals
> are left unchanged.

# Typescript Usage
````
import * as os from "os"
import { ignoreSignal } from "signal-ignore";

// set SIGTERM to SIG_IGN
ignoreSignal(os.constants.signals["SIGTERM"]);
````

## LICENSE
[Apache 2.0](https://github.com/unscrambl/signal-ignore/blob/master/LICENSE)
