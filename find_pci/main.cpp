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
		const unsigned device_id = p_dev->device_id;
		const unsigned vender_id = p_dev->vendor_id;

		const unsigned bus = p_dev->bus;
		const unsigned dev = p_dev->dev;
		const unsigned func = p_dev->func;

		char class_name[128];
		pci_lookup_name(p_access, class_name, sizeof(class_name), PCI_LOOKUP_CLASS, p_dev->device_class);

		char device_name[128];
		pci_lookup_name(p_access, device_name, sizeof(device_name), PCI_LOOKUP_DEVICE, p_dev->device_id);

		char vender_name[128];
		pci_lookup_name(p_access, vender_name, sizeof(vender_name), PCI_LOOKUP_VENDOR, p_dev->vendor_id);

		std::printf("%x:%x, path = %02x.%02x.%d, class_name = %40s, device_name = %20s, vender_name = %20s\n", vender_id, device_id, bus, dev, func, class_name, device_name, vender_name);
	}

	pci_cleanup(p_access);
}
