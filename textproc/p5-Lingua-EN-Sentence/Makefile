# $NetBSD: Makefile,v 1.19 2016/08/09 13:46:25 mef Exp $

DISTNAME=	Lingua-EN-Sentence-0.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-EN-Sentence/
COMMENT=	Perl module for splitting English text into sentences
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Lingua/EN/Sentence/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

# TODO: also package Lingua-DE-Sentence, Lingua-HE-Sentence
