# $NetBSD: Makefile,v 1.11 2016/06/08 19:22:49 wiz Exp $

DISTNAME=	Devel-EvalContext-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-EvalContext/
COMMENT=	Perl 5 module to save lexicals and hints between calls to eval
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Alias>=1.01:../../devel/p5-Data-Alias
DEPENDS+=	p5-PadWalker>=1.0:../../devel/p5-PadWalker
DEPENDS+=	p5-YAML>=0.62:../../textproc/p5-YAML

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/EvalContext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
