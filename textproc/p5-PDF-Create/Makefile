# $NetBSD: Makefile,v 1.43 2016/09/17 11:21:10 mef Exp $
#

DISTNAME=	PDF-Create-1.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-Create/
COMMENT=	Perl5 module for creating pdf documents
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/PDF/Create/.packlist

DEPENDS+=	p5-File-Share>=0.25:../../devel/p5-File-Share
DEPENDS+=	p5-File-ShareDir>=0:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-ShareDir-Install>=0:../../devel/p5-File-ShareDir-Install
DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON

BUILD_DEPENDS=	p5-Test-LeakTrace>=0.14:../../devel/p5-Test-LeakTrace
BUILD_DEPENDS+=	p5-Test-CheckManifest>=0.9:../../devel/p5-Test-CheckManifest

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
