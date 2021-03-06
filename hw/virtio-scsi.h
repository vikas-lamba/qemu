/*
 * Virtio SCSI HBA
 *
 * Copyright IBM, Corp. 2010
 *
 * Authors:
 *  Stefan Hajnoczi    <stefanha@linux.vnet.ibm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
 */

#ifndef _QEMU_VIRTIO_SCSI_H
#define _QEMU_VIRTIO_SCSI_H

#include "virtio.h"
#include "pci/pci.h"

/* The ID for virtio_scsi */
#define VIRTIO_ID_SCSI  8

/* Feature Bits */
#define VIRTIO_SCSI_F_INOUT                    0
#define VIRTIO_SCSI_F_HOTPLUG                  1
#define VIRTIO_SCSI_F_CHANGE                   2

struct VirtIOSCSIConf {
    uint32_t num_queues;
    uint32_t max_sectors;
    uint32_t cmd_per_lun;
};

#define DEFINE_VIRTIO_SCSI_PROPERTIES(_state, _features_field, _conf_field) \
    DEFINE_VIRTIO_COMMON_FEATURES(_state, _features_field), \
    DEFINE_PROP_UINT32("num_queues", _state, _conf_field.num_queues, 1), \
    DEFINE_PROP_UINT32("max_sectors", _state, _conf_field.max_sectors, 0xFFFF), \
    DEFINE_PROP_UINT32("cmd_per_lun", _state, _conf_field.cmd_per_lun, 128), \
    DEFINE_PROP_BIT("hotplug", _state, _features_field, VIRTIO_SCSI_F_HOTPLUG, true), \
    DEFINE_PROP_BIT("param_change", _state, _features_field, VIRTIO_SCSI_F_CHANGE, true)

#endif /* _QEMU_VIRTIO_SCSI_H */
