#include <iostream>
extern "C" {
#include <pci/pci.h>
}

#define PCI_ANY_ID   (0xffff)

int main() {
	pci_dev *p_dev = nullptr;
	pci_access *p_access = nullptr;

	p_access = pci_alloc();
	pci_init(p_access);
	pci_scan_bus(p_access);
	for (p_dev = p_access->devices; p_dev; p_dev = p_dev->next) {
		pci_fill_info(p_dev, PCI_FILL_IDENT | PCI_FILL_BASES);
	}

	pci_cleanup(p_access);
}
