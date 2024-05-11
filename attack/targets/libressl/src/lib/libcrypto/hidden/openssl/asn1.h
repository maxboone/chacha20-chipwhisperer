/* $OpenBSD: asn1.h,v 1.13 2024/04/10 14:55:12 beck Exp $ */
/*
 * Copyright (c) 2023 Bob Beck <beck@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _LIBCRYPTO_ASN1_H
#define _LIBCRYPTO_ASN1_H

#ifndef _MSC_VER
#include_next <openssl/asn1.h>
#else
#include "../include/openssl/asn1.h"
#endif
#include "crypto_namespace.h"

LCRYPTO_USED(d2i_ASN1_SEQUENCE_ANY);
LCRYPTO_USED(i2d_ASN1_SEQUENCE_ANY);
LCRYPTO_USED(d2i_ASN1_SET_ANY);
LCRYPTO_USED(i2d_ASN1_SET_ANY);
LCRYPTO_USED(ASN1_TYPE_new);
LCRYPTO_USED(ASN1_TYPE_free);
LCRYPTO_USED(d2i_ASN1_TYPE);
LCRYPTO_USED(i2d_ASN1_TYPE);
LCRYPTO_USED(ASN1_TYPE_get);
LCRYPTO_USED(ASN1_TYPE_set);
LCRYPTO_USED(ASN1_TYPE_set1);
LCRYPTO_USED(ASN1_TYPE_cmp);
LCRYPTO_USED(ASN1_OBJECT_new);
LCRYPTO_USED(ASN1_OBJECT_free);
LCRYPTO_USED(i2d_ASN1_OBJECT);
LCRYPTO_USED(d2i_ASN1_OBJECT);
LCRYPTO_USED(ASN1_STRING_new);
LCRYPTO_USED(ASN1_STRING_free);
LCRYPTO_USED(ASN1_STRING_copy);
LCRYPTO_USED(ASN1_STRING_dup);
LCRYPTO_USED(ASN1_STRING_type_new);
LCRYPTO_USED(ASN1_STRING_cmp);
LCRYPTO_USED(ASN1_STRING_set);
LCRYPTO_USED(ASN1_STRING_set0);
LCRYPTO_USED(ASN1_STRING_length);
LCRYPTO_USED(ASN1_STRING_length_set);
LCRYPTO_USED(ASN1_STRING_type);
LCRYPTO_USED(ASN1_STRING_data);
LCRYPTO_USED(ASN1_STRING_get0_data);
LCRYPTO_USED(ASN1_BIT_STRING_new);
LCRYPTO_USED(ASN1_BIT_STRING_free);
LCRYPTO_USED(d2i_ASN1_BIT_STRING);
LCRYPTO_USED(i2d_ASN1_BIT_STRING);
LCRYPTO_USED(ASN1_BIT_STRING_set);
LCRYPTO_USED(ASN1_BIT_STRING_set_bit);
LCRYPTO_USED(ASN1_BIT_STRING_get_bit);
LCRYPTO_USED(ASN1_INTEGER_new);
LCRYPTO_USED(ASN1_INTEGER_free);
LCRYPTO_USED(d2i_ASN1_INTEGER);
LCRYPTO_USED(i2d_ASN1_INTEGER);
LCRYPTO_USED(d2i_ASN1_UINTEGER);
LCRYPTO_USED(ASN1_INTEGER_dup);
LCRYPTO_USED(ASN1_INTEGER_cmp);
LCRYPTO_USED(ASN1_ENUMERATED_new);
LCRYPTO_USED(ASN1_ENUMERATED_free);
LCRYPTO_USED(d2i_ASN1_ENUMERATED);
LCRYPTO_USED(i2d_ASN1_ENUMERATED);
LCRYPTO_USED(ASN1_UTCTIME_check);
LCRYPTO_USED(ASN1_UTCTIME_set);
LCRYPTO_USED(ASN1_UTCTIME_adj);
LCRYPTO_USED(ASN1_UTCTIME_set_string);
LCRYPTO_USED(ASN1_GENERALIZEDTIME_check);
LCRYPTO_USED(ASN1_GENERALIZEDTIME_set);
LCRYPTO_USED(ASN1_GENERALIZEDTIME_adj);
LCRYPTO_USED(ASN1_GENERALIZEDTIME_set_string);
LCRYPTO_USED(ASN1_OCTET_STRING_new);
LCRYPTO_USED(ASN1_OCTET_STRING_free);
LCRYPTO_USED(d2i_ASN1_OCTET_STRING);
LCRYPTO_USED(i2d_ASN1_OCTET_STRING);
LCRYPTO_USED(ASN1_OCTET_STRING_dup);
LCRYPTO_USED(ASN1_OCTET_STRING_cmp);
LCRYPTO_USED(ASN1_OCTET_STRING_set);
LCRYPTO_USED(ASN1_VISIBLESTRING_new);
LCRYPTO_USED(ASN1_VISIBLESTRING_free);
LCRYPTO_USED(d2i_ASN1_VISIBLESTRING);
LCRYPTO_USED(i2d_ASN1_VISIBLESTRING);
LCRYPTO_USED(ASN1_UNIVERSALSTRING_new);
LCRYPTO_USED(ASN1_UNIVERSALSTRING_free);
LCRYPTO_USED(d2i_ASN1_UNIVERSALSTRING);
LCRYPTO_USED(i2d_ASN1_UNIVERSALSTRING);
LCRYPTO_USED(ASN1_UTF8STRING_new);
LCRYPTO_USED(ASN1_UTF8STRING_free);
LCRYPTO_USED(d2i_ASN1_UTF8STRING);
LCRYPTO_USED(i2d_ASN1_UTF8STRING);
LCRYPTO_USED(ASN1_NULL_new);
LCRYPTO_USED(ASN1_NULL_free);
LCRYPTO_USED(d2i_ASN1_NULL);
LCRYPTO_USED(i2d_ASN1_NULL);
LCRYPTO_USED(ASN1_BMPSTRING_new);
LCRYPTO_USED(ASN1_BMPSTRING_free);
LCRYPTO_USED(d2i_ASN1_BMPSTRING);
LCRYPTO_USED(i2d_ASN1_BMPSTRING);
LCRYPTO_USED(ASN1_PRINTABLE_new);
LCRYPTO_USED(ASN1_PRINTABLE_free);
LCRYPTO_USED(d2i_ASN1_PRINTABLE);
LCRYPTO_USED(i2d_ASN1_PRINTABLE);
LCRYPTO_USED(DIRECTORYSTRING_new);
LCRYPTO_USED(DIRECTORYSTRING_free);
LCRYPTO_USED(d2i_DIRECTORYSTRING);
LCRYPTO_USED(i2d_DIRECTORYSTRING);
LCRYPTO_USED(DISPLAYTEXT_new);
LCRYPTO_USED(DISPLAYTEXT_free);
LCRYPTO_USED(d2i_DISPLAYTEXT);
LCRYPTO_USED(i2d_DISPLAYTEXT);
LCRYPTO_USED(ASN1_PRINTABLESTRING_new);
LCRYPTO_USED(ASN1_PRINTABLESTRING_free);
LCRYPTO_USED(d2i_ASN1_PRINTABLESTRING);
LCRYPTO_USED(i2d_ASN1_PRINTABLESTRING);
LCRYPTO_USED(ASN1_T61STRING_new);
LCRYPTO_USED(ASN1_T61STRING_free);
LCRYPTO_USED(d2i_ASN1_T61STRING);
LCRYPTO_USED(i2d_ASN1_T61STRING);
LCRYPTO_USED(ASN1_IA5STRING_new);
LCRYPTO_USED(ASN1_IA5STRING_free);
LCRYPTO_USED(d2i_ASN1_IA5STRING);
LCRYPTO_USED(i2d_ASN1_IA5STRING);
LCRYPTO_USED(ASN1_GENERALSTRING_new);
LCRYPTO_USED(ASN1_GENERALSTRING_free);
LCRYPTO_USED(d2i_ASN1_GENERALSTRING);
LCRYPTO_USED(i2d_ASN1_GENERALSTRING);
LCRYPTO_USED(ASN1_UTCTIME_new);
LCRYPTO_USED(ASN1_UTCTIME_free);
LCRYPTO_USED(d2i_ASN1_UTCTIME);
LCRYPTO_USED(i2d_ASN1_UTCTIME);
LCRYPTO_USED(ASN1_GENERALIZEDTIME_new);
LCRYPTO_USED(ASN1_GENERALIZEDTIME_free);
LCRYPTO_USED(d2i_ASN1_GENERALIZEDTIME);
LCRYPTO_USED(i2d_ASN1_GENERALIZEDTIME);
LCRYPTO_USED(ASN1_TIME_new);
LCRYPTO_USED(ASN1_TIME_free);
LCRYPTO_USED(d2i_ASN1_TIME);
LCRYPTO_USED(i2d_ASN1_TIME);
LCRYPTO_USED(ASN1_TIME_to_tm);
LCRYPTO_USED(ASN1_TIME_compare);
LCRYPTO_USED(ASN1_TIME_cmp_time_t);
LCRYPTO_USED(ASN1_TIME_normalize);
LCRYPTO_USED(ASN1_TIME_set_string_X509);
LCRYPTO_USED(ASN1_TIME_diff);
LCRYPTO_USED(ASN1_TIME_set);
LCRYPTO_USED(ASN1_TIME_adj);
LCRYPTO_USED(ASN1_TIME_check);
LCRYPTO_USED(ASN1_TIME_to_generalizedtime);
LCRYPTO_USED(ASN1_TIME_set_string);
LCRYPTO_USED(i2a_ASN1_INTEGER);
LCRYPTO_USED(a2i_ASN1_INTEGER);
LCRYPTO_USED(i2a_ASN1_ENUMERATED);
LCRYPTO_USED(a2i_ASN1_ENUMERATED);
LCRYPTO_USED(i2a_ASN1_OBJECT);
LCRYPTO_USED(a2i_ASN1_STRING);
LCRYPTO_USED(i2a_ASN1_STRING);
LCRYPTO_USED(i2t_ASN1_OBJECT);
LCRYPTO_USED(a2d_ASN1_OBJECT);
LCRYPTO_USED(ASN1_OBJECT_create);
LCRYPTO_USED(ASN1_INTEGER_get_uint64);
LCRYPTO_USED(ASN1_INTEGER_set_uint64);
LCRYPTO_USED(ASN1_INTEGER_get_int64);
LCRYPTO_USED(ASN1_INTEGER_set_int64);
LCRYPTO_USED(ASN1_INTEGER_set);
LCRYPTO_USED(ASN1_INTEGER_get);
LCRYPTO_USED(BN_to_ASN1_INTEGER);
LCRYPTO_USED(ASN1_INTEGER_to_BN);
LCRYPTO_USED(ASN1_ENUMERATED_get_int64);
LCRYPTO_USED(ASN1_ENUMERATED_set_int64);
LCRYPTO_USED(ASN1_ENUMERATED_set);
LCRYPTO_USED(ASN1_ENUMERATED_get);
LCRYPTO_USED(BN_to_ASN1_ENUMERATED);
LCRYPTO_USED(ASN1_ENUMERATED_to_BN);
LCRYPTO_USED(ASN1_PRINTABLE_type);
LCRYPTO_USED(ASN1_get_object);
LCRYPTO_USED(ASN1_put_object);
LCRYPTO_USED(ASN1_put_eoc);
LCRYPTO_USED(ASN1_object_size);
LCRYPTO_USED(ASN1_item_dup);
LCRYPTO_USED(ASN1_d2i_fp);
LCRYPTO_USED(ASN1_item_d2i_fp);
LCRYPTO_USED(ASN1_i2d_fp);
LCRYPTO_USED(ASN1_item_i2d_fp);
LCRYPTO_USED(ASN1_STRING_print_ex_fp);
LCRYPTO_USED(ASN1_STRING_to_UTF8);
LCRYPTO_USED(ASN1_d2i_bio);
LCRYPTO_USED(ASN1_item_d2i_bio);
LCRYPTO_USED(ASN1_i2d_bio);
LCRYPTO_USED(ASN1_item_i2d_bio);
LCRYPTO_USED(ASN1_UTCTIME_print);
LCRYPTO_USED(ASN1_GENERALIZEDTIME_print);
LCRYPTO_USED(ASN1_TIME_print);
LCRYPTO_USED(ASN1_STRING_print);
LCRYPTO_USED(ASN1_STRING_print_ex);
LCRYPTO_USED(ASN1_parse);
LCRYPTO_USED(ASN1_parse_dump);
LCRYPTO_USED(ASN1_tag2bit);
LCRYPTO_USED(ASN1_tag2str);
LCRYPTO_USED(ASN1_UNIVERSALSTRING_to_string);
LCRYPTO_USED(ASN1_TYPE_set_octetstring);
LCRYPTO_USED(ASN1_TYPE_get_octetstring);
LCRYPTO_USED(ASN1_TYPE_set_int_octetstring);
LCRYPTO_USED(ASN1_TYPE_get_int_octetstring);
LCRYPTO_USED(ASN1_item_pack);
LCRYPTO_USED(ASN1_item_unpack);
LCRYPTO_USED(ASN1_STRING_set_default_mask);
LCRYPTO_USED(ASN1_STRING_set_default_mask_asc);
LCRYPTO_USED(ASN1_STRING_get_default_mask);
LCRYPTO_USED(ASN1_mbstring_copy);
LCRYPTO_USED(ASN1_mbstring_ncopy);
LCRYPTO_USED(ASN1_STRING_set_by_NID);
LCRYPTO_USED(ASN1_STRING_TABLE_get);
LCRYPTO_USED(ASN1_item_new);
LCRYPTO_USED(ASN1_item_free);
LCRYPTO_USED(ASN1_item_d2i);
LCRYPTO_USED(ASN1_item_i2d);
LCRYPTO_USED(ASN1_generate_nconf);
LCRYPTO_USED(ASN1_generate_v3);
LCRYPTO_USED(ASN1_item_print);
LCRYPTO_USED(SMIME_crlf_copy);
LCRYPTO_USED(SMIME_text);
LCRYPTO_USED(ERR_load_ASN1_strings);
LCRYPTO_UNUSED(ASN1_UTCTIME_cmp_time_t);
LCRYPTO_UNUSED(ASN1_dup);

#endif /* _LIBCRYPTO_ASN1_H */
