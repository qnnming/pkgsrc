# $NetBSD: Makefile,v 1.3 2016/09/08 01:11:28 wen Exp $
#

DISTNAME=	Geo-Ellipsoid-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Geo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~pjacklam/Geo-Ellipsoid-1.13/lib/Geo/Ellipsoid.pm
COMMENT=	Longitude and latitude calculations using an ellipsoid model
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Number-Delta>=0.16:../../math/p5-Test-Number-Delta

PERL5_PACKLIST=	auto/Geo/Ellipsoid/.packlist

MAKE_PARAMS+=	--skipdeps

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
