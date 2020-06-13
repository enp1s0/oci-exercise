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
	std::printf("vender_id:device_id\n");
	for (p_dev = p_access->devices; p_dev; p_dev = p_dev->next) {
		pci_fill_info(p_dev, PCI_FILL_IDENT | PCI_FILL_BASES);
		const unsigned device_id = p_dev->device_id;
		const unsigned vender_id = p_dev->vendor_id;

		std::printf("%9x:%9x\n", vender_id, device_id);
	}

	pci_cleanup(p_access);
}
