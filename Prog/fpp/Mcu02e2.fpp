NVMIF2  MC9S12XS64_V2  0x2E2 "hcs12xe_common.fpp"
WORKSPACE 0x3000 0x1000 3 2
DATABUFFER 0x3260 0x3FFF
MODULEIMPORT MC9S12XE_FLASH_4000
MODULEIMPORT MC9S12XE_FLASH_FLAT_8000_PPAGE_FE
MODULEIMPORT MC9S12XE_FLASH_C000
MODULEIMPORT MC9S12XE_FLASH_FTM1024K	MODULEREMAP 0xFC8000 0xFFBFFF
MODULEIMPORT DFLASH_12X_FTM1024K	MODULEREMAP 0x000800 0x030BFF