/* This file is the part of the Lightweight USB device Stack for STM32 microcontrollers
 *
 * Copyright ©2016 Dmitry Filimonchuk <dmitrystu[at]gmail[dot]com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _USB_MSC_H_
#define _USB_MSC_H_

#if defined(__cplusplus)
    extern "C" {
#endif

/** \addtogroup USB_MODULE_MSC USB Mass Storage class
 * \brief This module contains USB Mass Storage class definitions.
 * \details This module based on
 * + [Universal Serial Bus Mass Storage Class Specification Overview. Revision 1.4]
 *   (http://www.usb.org/developers/docs/devclass_docs/Mass_Storage_Specification_Overview_v1.4_2-19-2010.pdf)
 * + [Universal Serial Bus Mass Storage Class Bulk-Only Transport. Revision 1.0]
 *   (http://www.usb.org/developers/docs/devclass_docs/usbmassbulk_10.pdf)
 * + [Universal Serial Bus Mass Storage Class Control/Bulk/Interrupt (CBI) Transport. Revision 1.1]
 *   ([http://www.usb.org/developers/docs/devclass_docs/usb_msc_cbi_1.1.pdf)
 * @{ */

/**\name USB MSC class subclass and protocol definitions
 * @{ */
#define USB_CLASS_MSC               0x08    /**<\brief USB MSC class*/
#define USB_MSC_SUBCLASS_RBC        0x01    /**<\brief USB MSC subclass for RBC*/
#define USB_MSC_SUBCLASS_ATAPI      0x02    /**<\brief USB MSC subclass for ATAPI (MMC-5)*/
#define USB_MSC_SUBCLASS_QIC157     0x03    /**<\brief USB MSC subclass for QIC-157 \note Obsolete*/
#define USB_MSC_SUBCLASS_UFI        0x04    /**<\brief USB MSC subclass for UFI*/
#define USB_MSC_SUBCLASS_SSF1870I   0x05    /**<\brief USB MSC subclass for SSF-8070i \note Obsolete*/
#define USB_MSC_SUBCLASS_SCSI       0x06    /**<\brief USB MSC subclass for SCSI*/
#define USB_MSC_SUBCLASS_LSDFS      0x07    /**<\brief USB MSC subclass for LSD FS*/
#define USB_MSC_SUBCLASS_IEEE1667   0x08    /**<\brief USB MSC subclass for IEEE-1667*/
#define USB_MSC_PROTO_CBI           0x00    /**<\brief USB MSC CBI transport. With command completion interrupt*/
#define USB_MSC_PROTO_CBINOINT      0x01    /**<\brief USB MSC CBI transport. With no command completion interrupt*/
#define USB_MSC_PROTO_BBB           0x50    /**<\brief USB MSC Bulk-Only transport*/
#define USB_MSC_PROTO_UAS           0x62    /**<\brief USB MSC UAS*/
/** @{ */

/**\name USB MSC descriptor types */
#define USB_DTYPE_MSC_PIPE          0x24    /**<\brief Pipe Usage Class Specific Descriptor*/

/**\name USB MSC class-specific requests
 * @{ */
#define USB_MSC_ADCS                0x00    /**<\brief Accept Device-Specific Command.*/
#define USB_MSC_GETREQ              0xFC    /**<\brief Get Requests*/
#define USB_MSC_PUTREQ              0xFD    /**<\brief Put Requests*/
#define USB_MSC_GML                 0xFE    /**<\brief Get Max LUN*/
#define USB_MSC_BOMSR               0xFF    /**<\brief Bulk-Only Mass Storage Reset*/
/** @} */

/**\name USB MSC CSW status codes and CBI command block status
 * @{ */
#define MSC_STATUS_OK               0x00    /**<\brief Command Passed ("good status") */
#define MSC_STATUS_FAIL             0x01    /**<\brief Command Failed */
#define MSC_STATUS_PHASE_ERR        0x02    /**<\brief Phase Error */
#define MSC_STATUS_PERSIST_FAIL     0x03    /**<\brief Persistent Failure */
/** @} */

/**\name USB MSC Misc macro
 * @{ */
#define USB_MSC_CBW_SIGN        0x43425355  /**<\brief CBW signature. Shall contain 43425355h LE*/ 
#define USB_MSC_CSW_SIGN        0x53425355  /**<\brief CSW signature. Shall contain 53425355h LE*/
#define USB_MSC_CBW_HOSTTODEV   0x00        /**<\brief CBW direction HOST to DEVICE */
#define USB_MSC_CBW_DEVTOHOST   0x80        /**<\brief CBW direction DEVICE to HOST*/
 /** @} */

/** \brief Interrupt data block for CBI transport */
struct usb_msc_idb {
    uint8_t     bType;                      /**<\brief 00 - Command completion Interrupt*/
    uint8_t     bValue;                     /**<\brief Bitfield value, command block status */
};

/** \brief Command Block Wrapper (CBW). */
struct usb_msc_cbw {
    uint32_t    dCBWSignature;              /**<\brief CBW signature. Shall contain 43425355h LE*/
    uint32_t    dCBWTag;                    /**<\brief A Command Block Tag sent by the host.*/
    uint32_t    dCBWDataTransferLength;     /**<\brief The data length that the host expects for bulk transfer*/
    uint8_t     bmCBWFlags;                 /**<\brief Bitfield */
    uint8_t     bCBWLUN;                    /**<\brief The device Logical Unit Number (LUN).*/
    uint8_t     bCBWCBLength;               /**<\brief The valid length of the CBWCB in bytes.*/
    uint8_t     CBWCB[16];                  /**<\brief The command block to be executed by the device */
} __attribute__ ((packed));

/** \brief Command Status Wrapper (CSW).
 */
struct usb_msc_csw {
    uint32_t    dCSWSignature;              /**<\brief CSW signature. Shall contain 53425355h LE*/
    uint32_t    dCSWTag;                    /**<\brief dCBWTag of the associated CBW.*/
    uint32_t    dCSWDataResidue;            /**<\brief Difference between expected and actual amount of data*/
    uint8_t     bCSWStatus;                 /**<\brief Indicates the success or failure of the command.*/
} __attribute__ ((packed));

/** @} */

#if defined(__cplusplus)
    }
#endif
#endif /* _USB_MSC_H_ */
