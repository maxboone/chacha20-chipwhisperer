/**
 * \file config-symmetric-only.h
 *
 * \brief Configuration without any asymmetric cryptography.
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

/* System support */
#define MBEDTLS_HAVE_ASM
#define MBEDTLS_HAVE_TIME
#define MBEDTLS_HAVE_TIME_DATE
#define MBEDTLS_NO_PLATFORM_ENTROPY

/* Mbed TLS feature support */
#define MBEDTLS_VERSION_FEATURES

/* Mbed TLS modules */
#define MBEDTLS_TIMING_C
#define MBEDTLS_CHACHA20_C
#define MBEDTLS_VERSION_C
