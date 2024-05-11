#!/usr/bin/env perl

# ====================================================================
# Written by Andy Polyakov <appro@fy.chalmers.se> for the OpenSSL
# project. The module is, however, dual licensed under OpenSSL and
# CRYPTOGAMS licenses depending on where you obtain it. For further
# details see http://www.openssl.org/~appro/cryptogams/.
# ====================================================================

# SHA1 block procedure for Alpha.

# On 21264 performance is 33% better than code generated by vendor
# compiler, and 75% better than GCC [3.4], and in absolute terms is
# 8.7 cycles per processed byte. Implementation features vectorized
# byte swap, but not Xupdate.

@X=(	"\$0",	"\$1",	"\$2",	"\$3",	"\$4",	"\$5",	"\$6",	"\$7",
	"\$8",	"\$9",	"\$10",	"\$11",	"\$12",	"\$13",	"\$14",	"\$15");
$ctx="a0";	# $16
$inp="a1";
$num="a2";
$A="a3";
$B="a4";	# 20
$C="a5";
$D="t8";
$E="t9";	@V=($A,$B,$C,$D,$E);
$t0="t10";	# 24
$t1="t11";
$t2="ra";
$t3="t12";
$K="AT";	# 28

sub BODY_00_19 {
my ($i,$a,$b,$c,$d,$e)=@_;
my $j=$i+1;
$code.=<<___ if ($i==0);
	ldq_u	@X[0],0+0($inp)
	ldq_u	@X[1],0+7($inp)
___
$code.=<<___ if (!($i&1) && $i<14);
	ldq_u	@X[$i+2],($i+2)*4+0($inp)
	ldq_u	@X[$i+3],($i+2)*4+7($inp)
___
$code.=<<___ if (!($i&1) && $i<15);
	extql	@X[$i],$inp,@X[$i]
	extqh	@X[$i+1],$inp,@X[$i+1]

	or	@X[$i+1],@X[$i],@X[$i]	# pair of 32-bit values are fetched

	srl	@X[$i],24,$t0		# vectorized byte swap
	srl	@X[$i],8,$t2

	sll	@X[$i],8,$t3
	sll	@X[$i],24,@X[$i]
	zapnot	$t0,0x11,$t0
	zapnot	$t2,0x22,$t2

	zapnot	@X[$i],0x88,@X[$i]
	or	$t0,$t2,$t0
	zapnot	$t3,0x44,$t3
	sll	$a,5,$t1

	or	@X[$i],$t0,@X[$i]
	addl	$K,$e,$e
	and	$b,$c,$t2
	zapnot	$a,0xf,$a

	or	@X[$i],$t3,@X[$i]
	srl	$a,27,$t0
	bic	$d,$b,$t3
	sll	$b,30,$b

	extll	@X[$i],4,@X[$i+1]	# extract upper half
	or	$t2,$t3,$t2
	addl	@X[$i],$e,$e

	addl	$t1,$e,$e
	srl	$b,32,$t3
	zapnot	@X[$i],0xf,@X[$i]

	addl	$t0,$e,$e
	addl	$t2,$e,$e
	or	$t3,$b,$b
___
$code.=<<___ if (($i&1) && $i<15);
	sll	$a,5,$t1
	addl	$K,$e,$e
	and	$b,$c,$t2
	zapnot	$a,0xf,$a

	srl	$a,27,$t0
	addl	@X[$i%16],$e,$e
	bic	$d,$b,$t3
	sll	$b,30,$b

	or	$t2,$t3,$t2
	addl	$t1,$e,$e
	srl	$b,32,$t3
	zapnot	@X[$i],0xf,@X[$i]

	addl	$t0,$e,$e
	addl	$t2,$e,$e
	or	$t3,$b,$b
___
$code.=<<___ if ($i>=15);	# with forward Xupdate
	sll	$a,5,$t1
	addl	$K,$e,$e
	and	$b,$c,$t2
	xor	@X[($j+2)%16],@X[$j%16],@X[$j%16]

	zapnot	$a,0xf,$a
	addl	@X[$i%16],$e,$e
	bic	$d,$b,$t3
	xor	@X[($j+8)%16],@X[$j%16],@X[$j%16]

	srl	$a,27,$t0
	addl	$t1,$e,$e
	or	$t2,$t3,$t2
	xor	@X[($j+13)%16],@X[$j%16],@X[$j%16]

	sll	$b,30,$b
	addl	$t0,$e,$e
	srl	@X[$j%16],31,$t1

	addl	$t2,$e,$e
	srl	$b,32,$t3
	addl	@X[$j%16],@X[$j%16],@X[$j%16]

	or	$t3,$b,$b
	zapnot	@X[$i%16],0xf,@X[$i%16]
	or	$t1,@X[$j%16],@X[$j%16]
___
}

sub BODY_20_39 {
my ($i,$a,$b,$c,$d,$e)=@_;
my $j=$i+1;
$code.=<<___ if ($i<79);	# with forward Xupdate
	sll	$a,5,$t1
	addl	$K,$e,$e
	zapnot	$a,0xf,$a
	xor	@X[($j+2)%16],@X[$j%16],@X[$j%16]

	sll	$b,30,$t3
	addl	$t1,$e,$e
	xor	$b,$c,$t2
	xor	@X[($j+8)%16],@X[$j%16],@X[$j%16]

	srl	$b,2,$b
	addl	@X[$i%16],$e,$e
	xor	$d,$t2,$t2
	xor	@X[($j+13)%16],@X[$j%16],@X[$j%16]

	srl	@X[$j%16],31,$t1
	addl	$t2,$e,$e
	srl	$a,27,$t0
	addl	@X[$j%16],@X[$j%16],@X[$j%16]

	or	$t3,$b,$b
	addl	$t0,$e,$e
	or	$t1,@X[$j%16],@X[$j%16]
___
$code.=<<___ if ($i<77);
	zapnot	@X[$i%16],0xf,@X[$i%16]
___
$code.=<<___ if ($i==79);	# with context fetch
	sll	$a,5,$t1
	addl	$K,$e,$e
	zapnot	$a,0xf,$a
	ldl	@X[0],0($ctx)

	sll	$b,30,$t3
	addl	$t1,$e,$e
	xor	$b,$c,$t2
	ldl	@X[1],4($ctx)

	srl	$b,2,$b
	addl	@X[$i%16],$e,$e
	xor	$d,$t2,$t2
	ldl	@X[2],8($ctx)

	srl	$a,27,$t0
	addl	$t2,$e,$e
	ldl	@X[3],12($ctx)

	or	$t3,$b,$b
	addl	$t0,$e,$e
	ldl	@X[4],16($ctx)
___
}

sub BODY_40_59 {
my ($i,$a,$b,$c,$d,$e)=@_;
my $j=$i+1;
$code.=<<___;	# with forward Xupdate
	sll	$a,5,$t1
	addl	$K,$e,$e
	zapnot	$a,0xf,$a
	xor	@X[($j+2)%16],@X[$j%16],@X[$j%16]

	srl	$a,27,$t0
	and	$b,$c,$t2
	and	$b,$d,$t3
	xor	@X[($j+8)%16],@X[$j%16],@X[$j%16]

	sll	$b,30,$b
	addl	$t1,$e,$e
	xor	@X[($j+13)%16],@X[$j%16],@X[$j%16]

	srl	@X[$j%16],31,$t1
	addl	$t0,$e,$e
	or	$t2,$t3,$t2
	and	$c,$d,$t3

	or	$t2,$t3,$t2
	srl	$b,32,$t3
	addl	@X[$i%16],$e,$e
	addl	@X[$j%16],@X[$j%16],@X[$j%16]

	or	$t3,$b,$b
	addl	$t2,$e,$e
	or	$t1,@X[$j%16],@X[$j%16]
	zapnot	@X[$i%16],0xf,@X[$i%16]
___
}

$code=<<___;
#include <machine/asm.h>

.text

.set	noat
.set	noreorder
.globl	sha1_block_data_order
.align	5
.ent	sha1_block_data_order
sha1_block_data_order:
	lda	sp,-64(sp)
	stq	ra,0(sp)
	stq	s0,8(sp)
	stq	s1,16(sp)
	stq	s2,24(sp)
	stq	s3,32(sp)
	stq	s4,40(sp)
	stq	s5,48(sp)
	stq	fp,56(sp)
	.mask	0x0400fe00,-64
	.frame	sp,64,ra
	.prologue 0

	ldl	$A,0($ctx)
	ldl	$B,4($ctx)
	sll	$num,6,$num
	ldl	$C,8($ctx)
	ldl	$D,12($ctx)
	ldl	$E,16($ctx)
	addq	$inp,$num,$num

.Lloop:
	.set	noreorder
	ldah	$K,23170(zero)
	zapnot	$B,0xf,$B
	lda	$K,31129($K)	# K_00_19
___
for ($i=0;$i<20;$i++) { &BODY_00_19($i,@V); unshift(@V,pop(@V)); }

$code.=<<___;
	ldah	$K,28378(zero)
	lda	$K,-5215($K)	# K_20_39
___
for (;$i<40;$i++) { &BODY_20_39($i,@V); unshift(@V,pop(@V)); }

$code.=<<___;
	ldah	$K,-28900(zero)
	lda	$K,-17188($K)	# K_40_59
___
for (;$i<60;$i++) { &BODY_40_59($i,@V); unshift(@V,pop(@V)); }

$code.=<<___;
	ldah	$K,-13725(zero)
	lda	$K,-15914($K)	# K_60_79
___
for (;$i<80;$i++) { &BODY_20_39($i,@V); unshift(@V,pop(@V)); }

$code.=<<___;
	addl	@X[0],$A,$A
	addl	@X[1],$B,$B
	addl	@X[2],$C,$C
	addl	@X[3],$D,$D
	addl	@X[4],$E,$E
	stl	$A,0($ctx)
	stl	$B,4($ctx)
	addq	$inp,64,$inp
	stl	$C,8($ctx)
	stl	$D,12($ctx)
	stl	$E,16($ctx)
	cmpult	$inp,$num,$t1
	bne	$t1,.Lloop

	.set	noreorder
	ldq	ra,0(sp)
	ldq	s0,8(sp)
	ldq	s1,16(sp)
	ldq	s2,24(sp)
	ldq	s3,32(sp)
	ldq	s4,40(sp)
	ldq	s5,48(sp)
	ldq	fp,56(sp)
	lda	sp,64(sp)
	ret	(ra)
.end	sha1_block_data_order
.align	2
___
$output=shift and open STDOUT,">$output";
print $code;
close STDOUT;
