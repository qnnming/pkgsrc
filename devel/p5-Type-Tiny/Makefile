# $NetBSD: Makefile,v 1.4 2016/06/08 19:23:44 wiz Exp $

DISTNAME=	Type-Tiny-1.000005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Type-Tiny/
COMMENT=	Tiny, yet Moo(se)-compatible type constraint
LICENSE=	gnu-gpl-v1 OR artistic

DEPENDS+=	p5-Exporter-Tiny-[0-9]*:../../devel/p5-Exporter-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Type/Tiny/.packlist

BUILD_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
BUILD_DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
BUILD_DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
BUILD_DEPENDS+=	p5-Mouse-[0-9]*:../../devel/p5-Mouse
# and many more

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
