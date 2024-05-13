#include "mbedtls/chacha20.h"
#include "simpleserial.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>

// check size of input bytes!
#define INPUT_SIZE 64
#define KEY_SIZE 32
#define NONCE_SIZE 12
#define COUNT_SIZE 4

uint8_t set_nonce(uint8_t* nc, uint8_t len){
    if (len != NONCE_SIZE+COUNT_SIZE) return 1;
    uint8_t encrypt[INPUT_SIZE];
    uint8_t key[KEY_SIZE] = {
            0x00, 0x01, 0x02, 0x03,
            0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b,
            0x0c, 0x0d, 0x0e, 0x0f,
            0x10, 0x11, 0x12, 0x13,
            0x14, 0x15, 0x16, 0x17,
            0x18, 0x19, 0x1a, 0x1b,
            0x1c, 0x1d, 0x1e, 0x1f
    }; // key size 256 bit (32 bytes)

    // 12 bytes initial vector => 96 bit (in original 64 bit, but see: https://datatracker.ietf.org/doc/html/rfc7539#section-2.3)
    // => to be set in the attack scenario
    /*uint8_t nonce[NONCE_SIZE] = {
            nc[0], nc[1], nc[2], nc[3],
            nc[4], nc[5], nc[6], nc[7],
            nc[8], nc[9], nc[10], nc[11]
    };*/
    uint8_t nonce[NONCE_SIZE] = {
            nc[4], nc[5], nc[6], nc[7],
            nc[8], nc[9], nc[10], nc[11],
            nc[12], nc[13], nc[14], nc[15]
    };

    // 4 bytes counter
    // use function to get uint32_t LE counter
    /*uint8_t count_arr[COUNT_SIZE] = {
            nc[12], nc[13], nc[14], nc[15]
    };
    uint32_t counter = u8t32le(count_arr); */
    // conversion from uint8_t to uint32_t with shifting => BE?
    // https://forum.arduino.cc/t/convert-4-uint8_t-into-one-uint32_t/577243
    //uint32_t counter = nc[12] | (nc[13] << 8) | (nc[14] << 16) | (nc[15] << 24);
    uint32_t counter = nc[0] | (nc[1] << 8) | (nc[2] << 16) | (nc[3] << 24);

    // Hello from Chipwhispererer, I'm only here to get encrypted and yo(u?)
    uint8_t input[INPUT_SIZE] = {
            0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x66, 0x72,
            0x6f, 0x6d, 0x20, 0x43, 0x68, 0x69, 0x70, 0x77,
            0x68, 0x69, 0x73, 0x70, 0x65, 0x72, 0x65, 0x72,
            0x65, 0x72, 0x2c, 0x20, 0x49, 0x6d, 0x20, 0x6f,
            0x6e, 0x6c, 0x79, 0x20, 0x68, 0x65, 0x72, 0x65,
            0x20, 0x74, 0x6f, 0x20, 0x67, 0x65, 0x74, 0x20,
            0x65, 0x6e, 0x63, 0x72, 0x79, 0x70, 0x74, 0x65,
            0x64, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x79, 0x6f,
            //0x75, 0x3f
    };

    // MBEDTLS
    mbedtls_chacha20_crypt(key, nonce, counter, INPUT_SIZE, input, encrypt);    // encrypt

    // put encrypted/decrypted to simple serial
    simpleserial_put('r', INPUT_SIZE, encrypt);

    return 0;
}


int main(void) {
    platform_init();
    init_uart();
    trigger_setup();

    simpleserial_init();
    // 12 Bytes for nonce, 4 Bytes for counter
    simpleserial_addcmd('p', 16, set_nonce);

    while(1)
        simpleserial_get();

    return 0;
}
