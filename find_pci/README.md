# Scanning PCI devices

## Key point
- Use `extern "C"` when you include pci.h

```cpp
extern "C" {
#include <pci/pci.h>
}
```
