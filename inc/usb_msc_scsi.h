#ifndef _USB_MSC_SCSI_H_
#define _USB_MSC_SCSI_H_


/**\name USB MSC SCSI commands
 * @{ */
#define SCSI_TEST_UNIT_READY        0x00    /**<\brief Request the device to report if it is ready*/
#define SCSI_REWIND                 0x01    /**<\brief Position a head of the drive to zero track*/
#define SCSI_REQUEST_SENSE          0x03    /**<\brief Transfer status sense data to the host*/
#define SCSI_FORMAT                 0x04    /**<\brief Format unformatted media*/
#define SCSI_INQUIRY                0x12    /**<\brief Get device information*/
#define SCSI_START_STOP             0x1B    /**<\brief Request a removable-media device to load or unload its media.*/
#define SCSI_SEND_DIAGNOSTIC        0x1D    /**<\brief Perform a hard reset and execute diagnostics*/
#define SCSI_ALLOW_MEDIA_REMOVE     0x1E    /**<\brief Prevent or allow the removal of media from a removable media device*/
#define SCSI_READ_FORMAT_CAPACITIES 0x23    /**<\brief Report formattable capacities supported by media*/
#define SCSI_READ_CAPACITY          0x25    /**<\brief Report current media capacity*/
#define SCSI_READ10                 0x28    /**<\brief Transfer binary data from the media to the host*/
#define SCSI_WRITE10                0x2A    /**<\brief Transfer binary data from the host to the media*/
#define SCSI_SEEK10                 0x2B    /**<\brief Seek the device to a specified address*/
#define SCSI_WRITE_VERIFY10         0x2E    /**<\brief Transfer binary data from the host to the media and verify*/
#define SCSI_VERIFY10               0x2F    /**<\brief Verify data on the media*/
#define SCSI_MODE_SELECT            0x55    /**< */
#define SCSI_MODE_SENSE             0x5A    /**< */
#define SCSI_READ12                 0xA8    /**<\brief Transfer binary data from the media to the host*/
#define SCSI_WRITE12                0xAA    /**<\brief Transfer binary data from the host to the media*/
/** @} */

#endif /* _USB_MSC_SCSI_H_ */
