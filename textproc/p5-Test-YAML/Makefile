# $NetBSD: Makefile,v 1.6 2016/06/08 19:24:36 wiz Exp $

DISTNAME=	Test-YAML-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-YAML/
COMMENT=	Testing Module for YAML Implementations
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-Base>=0.86:../../devel/p5-Test-Base

PERL5_PACKLIST=		auto/Test/YAML/.packlist

USE_TOOLS+=	bash:run
REPLACE_BASH+=	bin/test-yaml

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
